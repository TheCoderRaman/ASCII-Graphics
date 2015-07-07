#include <vector>

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

class image
{
std::vector<PIXEL> pixelset;
int width;
int height;
public:
image(int width2, int height2);
image();
void resize(int width2, int height2);
PIXEL getpixel(int x, int y);
int getcolor(int x, int y);
char getimage(int x, int y);
int getwidth(void);
int getheight(void);
void clear(int color);
void putpixel(int x, int y, int color, char charecter);
bool loadfromfile(std::string file);
bool savetofile(std::string file);
void clear(int color=255, char image=GR_PIXEL());
};
#include "image.cpp"
#endif
