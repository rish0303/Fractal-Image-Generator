#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include "Zoom.h"

using namespace std;

namespace caveofprogramming
{
    class FractalCreator
    {
        public:
            FractalCreator(int width, int height);
            virtual ~FractalCreator();

            void calculateIteration();
            void drawFractal();
            void addZoom(const Zoom& zoom);
            void writeBitmap(string name);
    };
}

#endif // FRACTALCREATOR_H
