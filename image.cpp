#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
image::image(int width2, int height2)
{
width=width2;
height=height2;
pixelset.resize(width*height);
clear(0x00,GR_PIXEL());
}

image::image()
{
    resize(1,1);
    clear(0x00,GR_PIXEL());
}

void image::resize(int width2, int height2)
{
width=width2;
height=height2;
pixelset.resize(width*height);
}

PIXEL image::getpixel(int x, int y)
{
return pixelset[(x*height)+y];
}

int image::getwidth(void)
{
return width;
}

int image::getheight(void)
{
return height;
}

void image::clear(int color)
{
for(int counterx=0; counterx<width; counterx++)
for(int countery=0; countery<height; countery++)
putpixel(counterx,countery,color,GR_PIXEL());
}

void image::putpixel(int x, int y, int color, char charecter)
{
if(x>=0 && y>=0 && x<width && y<height)
{
pixelset[(x*height)+y].setColor(color);
pixelset[(x*height)+y].setImage(charecter);
}
}

int image::getcolor(int x, int y)
{
PIXEL dummy=getpixel(x,y);
return dummy.getColor();
}

char image::getimage(int x, int y)
{
PIXEL dummy=getpixel(x,y);
return dummy.getImage();
}

bool image::loadfromfile(std::string file)
{
    std::ifstream load_file;
    int temp_width;
    int temp_height;
    int color1; char charecter;
    load_file.open(file.c_str());
    if(load_file.is_open())
	{
    load_file>> temp_width;
    load_file>> temp_height;
    resize(temp_width,temp_height);
    for(int counterx=0; counterx<width; counterx++)
        for(int countery=0; countery<height; countery++)
    {
        load_file>>color1;
        putpixel(counterx,countery,color1,getimage(counterx,countery));
    }
    load_file.get();
    for(int counterx=0; counterx<width; counterx++)
        for(int countery=0; countery<height; countery++)
    {
    load_file.get(charecter);
    putpixel(counterx,countery,getcolor(counterx,countery),charecter);
    }
    load_file.close();
    return true;
}
else
return false;
}

int ASCIItranslate(char ch) {
    return ch;
}

char INTtranslate(int ch)
{
    return ch;
}

bool image::savetofile(std::string file)
{
std::ofstream save_file;
save_file.open(file.c_str(),std::ios_base::trunc | std::ios_base::out);
if(save_file.is_open())
{
save_file<<width <<"\n" <<height <<"\n";
for(int counterx=0; counterx<width; counterx++)
{
    for(int countery=0; countery<height; countery++)
    {
    save_file<<getcolor(counterx,countery)<<" ";
    }
}
for(int counterx=0; counterx<width; counterx++)
{
    for(int countery=0; countery<height; countery++)
    {
        save_file.put(getimage(counterx,countery));
    }
}
save_file.close();
return true;
}
else
return false;
}

void image::clear(int color, char image)
{
for(int counterx=0; counterx<width; counterx++)
    for(int countery=0; countery<height; countery++)
{
    putpixel(counterx,countery,color,image);
}
}
