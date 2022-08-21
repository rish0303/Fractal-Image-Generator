#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace caveofprogramming
{
    class FractalCreator
    {
        private:
            int _width;
            int _height;
            unique_ptr<int[]> _histogram;
            unique_ptr<int[]> _fractal;
            Bitmap _bitmap;
            ZoomList _zoomList;
            int _total = 0;

            vector<int> _ranges;
            vector<RGB> _colors;
            vector<int> _rangeTotals;

            bool _bGotFirstRange = false;

            void calculateIteration();
            void calculateTotalIterations();
            void calculateRangeTotals();
            void drawFractal();
            void writeBitmap(string name);
            int getRange(int iterations) const;


        public:
            FractalCreator(int width, int height);
            virtual ~FractalCreator();

            void addRange(double rangeEnd, const RGB& rgb);
            void addZoom(const Zoom& zoom);
            void run(string name);
    };

}

#endif // FRACTALCREATOR_H
