#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace caveofprogramming;

int main()
{
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 50));
    fractalCreator.addRange(0.1, RGB(255, 0, 0));
    fractalCreator.addRange(0.8, RGB(255, 255, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
