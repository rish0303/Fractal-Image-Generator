#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"

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


        public:
            FractalCreator(int width, int height);
            virtual ~FractalCreator();

            void calculateIteration();
            void calculateTotalIterations();
            void drawFractal();
            void addZoom(const Zoom& zoom);
            void writeBitmap(string name);
    };
}

#endif // FRACTALCREATOR_H
