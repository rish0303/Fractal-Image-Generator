
#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming
{
    Bitmap::Bitmap(int width, int height): _width(width), _height(height), _pPixels(new uint8_t[width * height * 3]{}){}

    Bitmap::~Bitmap()
    {

    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
    {
        uint8_t* pPixel = _pPixels.get();

        pPixel += (y * 3) * _width + (x * 3);

        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }

    bool Bitmap::write(string filename)
    {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + _width * _height * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

        infoHeader.width = _width;
        infoHeader.height = _height;

        ofstream file;
        file.open(filename, ios:: out|ios::binary);

        if (!file)
        {
            return false;
        }

        file.write((char*)&fileHeader, sizeof(fileHeader));
        file.write((char*)&infoHeader, sizeof(infoHeader));
        file.write((char*)_pPixels.get(), _width * _height * 3);

        file.close();

        if (!file)
        {
            return false;
        }

        return false;
    }
}


