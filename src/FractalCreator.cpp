#include "FractalCreator.h"
#include <iostream>

namespace caveofprogramming
{
    FractalCreator::FractalCreator(int width, int height):
    _width(width),
    _height(height),
    _histogram(new int[Mandelbrot::MAX_ITERATIONS]()),
    _fractal(new int[_width * _height]()),
    _bitmap(_width, _height),
    _zoomList(_width, _height)
    {
        _zoomList.add(Zoom(_width / 2, _height / 2, 4.0 / _width));
    }


    FractalCreator::~FractalCreator(){}


    void FractalCreator::run(string name)
    {
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap("test.bmp");
    }


    void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
    {
        _ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        _colors.push_back(rgb);

        if (_bGotFirstRange)
            _rangeTotals.push_back(0);

        _bGotFirstRange = true;
    }


    void FractalCreator::addZoom(const Zoom& zoom)
    {
        _zoomList.add(zoom);
    }


    void FractalCreator::calculateRangeTotals()
    {
        int rangeIndex = 0;

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i)
        {
            int pixels = _histogram[i];

            if (i >= _ranges[rangeIndex + 1])
            {
                ++rangeIndex;
            }

            _rangeTotals[rangeIndex] += pixels;
        }

        for (int value: _rangeTotals)
        {
            cout << "Range total: " << value << endl;
        }
    }


    void FractalCreator::calculateIteration()
    {
        for (int x = 0; x < _width; ++x)
        {
            for (int y = 0; y < _height; ++y)
            {
                pair<double, double> coords = _zoomList.doZoom(x, y);

                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                _fractal[y * _width + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                    ++_histogram[iterations];
            }
        }
    }

    void FractalCreator::calculateTotalIterations()
    {
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i)
        {
            _total += _histogram[i];
        }
    }


    void FractalCreator::drawFractal()
    {
        RGB startColor(0, 0, 0);
        RGB endColor(0, 0, 255);
        RGB colorDiff  = endColor - startColor;

        for (int x = 0; x < _width; ++x)
        {
            for (int y = 0; y < _height; ++y)
            {
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                int iterations = _fractal[y * _width + x];

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                {
                    double hue = 0.0;
                    for (int i = 0; i <= iterations; ++i)
                    {
                        hue += (double)_histogram[i]/_total;
                    }

                    red = startColor.r + colorDiff.r * hue;
                    green = startColor.g + colorDiff.g * hue;
                    blue = startColor.b + colorDiff.b * hue;
                }

                _bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }


    void FractalCreator::writeBitmap(string name)
    {
        _bitmap.write(name);
    }
}
