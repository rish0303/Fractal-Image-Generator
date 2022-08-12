#ifndef ZOOMLIST_H
#define ZOOMLIST_H
#include "Zoom.h"

#include <vector>
#include <utility>

using namespace std;

namespace caveofprogramming
{
    class ZoomList
    {
        private:
            double _xCenter = 0.0;
            double _yCenter = 0.0;
            double _scale = 1.0;

            int _width = 0;
            int _height = 0;
            vector<Zoom> _zooms;

        public:
            ZoomList(int width, int height);
            void add(const Zoom& zoom);
            pair<double, double> doZoom(int x, int y);
    };
}

#endif // ZOOMLIST_H
