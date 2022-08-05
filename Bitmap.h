#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

namespace caveofprogramming
{
    class Bitmap
    {
        private:
            int _width{0};
            int _height{0};
            unique_ptr<uint8_t[]> _pPixels{nullptr};

        public:
            Bitmap(int width, int height);
            virtual ~Bitmap();

            void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
            bool write(string filename);
    };
}

#endif // BITMAP_H
