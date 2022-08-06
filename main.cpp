#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;
    Bitmap bitmap(WIDTH, HEIGHT);

    for(int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            bitmap.setPixel (i, j, 255, 0, 0);
        }
    }

    //bitmap.setPixel (WIDTH / 2, HEIGHT / 2, 255, 255, 255);
    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
