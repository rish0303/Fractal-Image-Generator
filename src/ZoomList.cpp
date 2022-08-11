#include "ZoomList.h"

namespace caveofprogramming
{
    ZoomList::ZoomList(int width, int height): _width(width), _height(height){}

    void ZoomList::add(const Zoom& zoom)
    {
        _zooms.push_back(zoom);
    }

    pair<double, double> ZoomList::doZoom(int x, int y)
    {
        return pair<double, double>(0.0, 0.0);
    }
}
