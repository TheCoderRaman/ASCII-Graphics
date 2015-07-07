#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

class PIXEL
{
    int color; char image;
public:
    PIXEL(int color2, char image2);
    PIXEL();
    void setColor(int color2);
    void setImage(char image2);
    void setInfo(int color2, char image2);
    int getColor(void);
    int getImage(void);
};

#include "pixel.cpp"
#endif // PIXEL_H_INCLUDED
