#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include "textbox.h"
class BUFFER
{
    CHAR_INFO* m_buffer;
    short width;
    short height;
    int cursorx;
    int cursory;
    int fcolor;
    int bcolor;
public:
    BUFFER(int x=1, int y=1);
    ~BUFFER();
    void putPixel(int x, int y, PIXEL pix);
    void putPixel(int x, int y, int color, char image);
    void resize(int x, int y);
    void display(void);
    void clear(int color=0x00);
    void draw(image mainimage);
    void draw(image mainimage, int x2, int y2);
    void draw(int x, int y, std::string text3,int color=0x0f);
    void draw(int x, int y, int text, int color);
    void draw(textbox textb);
    void operator << (std::string text);
    void operator << (int text);
    void setCursorPosition(int x, int y);
    void setFColor(int color, int backcolor);
    bool isSelected(void);
    void drawLine(int x, int y, int x2, int y2, char charecter, int color);
    void drawRectangle(int x, int y, int width, int height, char charecter, int color);
    void drawCircle(int x,int y,int radius,int color, char character);
    void drawHRectangle(int x, int y, int width, int height, char charecter, int color);
};
#include "buffer.cpp"
#endif // BUFFER_H_INCLUDED
