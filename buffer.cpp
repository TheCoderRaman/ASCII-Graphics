    #include <string>
    #include <stdlib.h>
    #include <sstream>

    void BUFFER::draw(textbox textb)
    {
        std::string t; t=textb.getText();
        if(t.size()>0)
        {
        if(t.size()>(unsigned)textb.getWidth())
            t.erase(t.begin()+textb.getWidth(),t.end());
        draw(textb.getX(),textb.getY(),t,textb.getColor());
        }
        else
            draw(textb.getX(),textb.getY(),textb.getBackText(),textb.getColor());
    }
    BUFFER::BUFFER(int x, int y)
    {
    m_buffer=new CHAR_INFO[x*y];
    width=x; height=y;
    cursorx=0; cursory=0;
    clear();
    }

    BUFFER::~BUFFER()
    {
    delete[] m_buffer;
    }

    void BUFFER::putPixel(int x, int y, PIXEL pix)
    {
    if(x>=0 && x<width && y>=0 && y<height && pix.getColor()<256)
    {
    m_buffer[(y*width)+x].Char.AsciiChar=pix.getImage();
    m_buffer[(y*width)+x].Attributes=pix.getColor();
    }
    }

    void BUFFER::putPixel(int x, int y, int color, char image)
    {
    if(x>=0 && x<width && y>=0 && y<height && color<256)
    {
    m_buffer[(y*width)+x].Char.AsciiChar=image;
    m_buffer[(y*width)+x].Attributes=color;
    }
    }

    void BUFFER::resize(int x, int y)
    {
    clear();
    delete[] m_buffer;
    m_buffer=new CHAR_INFO[x*y];
    width=x; height=y;
    }

    void BUFFER::display(void)
    {
    COORD dwBufferSize = { (short)width, (short)height };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, width, height };
    HANDLE hOutput = (HANDLE)GetStdHandle( STD_OUTPUT_HANDLE );
    WriteConsoleOutput( hOutput, m_buffer, dwBufferSize,
    dwBufferCoord, &rcRegion );
    }

    void BUFFER::clear(int color)
    {
    for(int counterx=0; counterx<width; counterx++)
        for(int countery=0; countery<height; countery++)
    {
        putPixel(counterx,countery,color,GR_PIXEL());
    }
    cursorx=0; cursory=0;
    }

    void BUFFER::draw(image mainimage)
    {
        for(int counterx=0; counterx<mainimage.getwidth(); counterx++)
            for(int countery=0; countery<mainimage.getheight(); countery++)
                if(counterx>=0 && counterx<=width && countery>=0 && countery<=height)
            putPixel(counterx,countery,mainimage.getcolor(counterx,countery),mainimage.getimage(counterx,countery));
    }

        void BUFFER::draw(image mainimage, int x2, int y2)
    {
        for(int counterx=0; counterx<mainimage.getwidth(); counterx++)
            for(int countery=0; countery<mainimage.getheight(); countery++)
                if(counterx>=0 && counterx<=width && countery>=0 && countery<=height)
            putPixel(counterx+x2,countery+y2,mainimage.getcolor(counterx,countery),mainimage.getimage(counterx,countery));
    }

    void MaximizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SMALL_RECT rc;
	rc.Left = rc.Top = 0;
	rc.Right = (short)(std::min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
	rc.Bottom = (short)(std::min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
}

void BUFFER::draw(int x, int y, std::string text3,int color)
{
for(unsigned int counter=0; counter<text3.size(); counter++)
{
    if(text3[counter]!='\0')
    putPixel(counter+x,y,color,text3[counter]);
}
}
/*
void BUFFER::draw(int x, int y, int text, int color)
{
int represent; char texts[10]; itoa(text,texts,represent);
draw(x,y,color,texts);
}*/

void BUFFER::operator<< (std::string text)
{
int tempx=cursorx;
for(unsigned int counter=0; counter<text.size(); counter++)
{
    if(text[counter]=='\n')
    {
        cursorx=tempx; cursory++;
    }
    else
    {
        putPixel(cursorx,cursory,bcolor+fcolor,text[counter]);
        cursorx++;
    }
}
}

void BUFFER::operator<< (int text)
{
int represent=0; char texts[10]; itoa(text,texts,represent);
std::string texter;
int tempx=cursorx;
for(unsigned int counter=0; counter<texter.size(); counter++)
{
    if(texter[counter]=='\n')
    {
        cursorx=tempx; cursory++;
    }
    else
    {
        putPixel(cursorx,cursory,bcolor+fcolor,texter[counter]);
        cursorx++;
    }
}
}


void BUFFER::setCursorPosition(int x, int y)
{
    cursorx=x;
    cursory=y;
}

void BUFFER::setFColor(int color, int backcolor=(15*15))
{
    fcolor=color; bcolor=backcolor;
}


  void gotoxy( short x, short y )
    {
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }

void BUFFER::draw(int x, int y, int text,int color)
{
    std::stringstream ss;
    ss<<text;
    std::string text2; text2=ss.str();
    draw(x,y,text2,color);
}


void BUFFER::drawLine(int x, int y, int x2, int y2, char charecter, int color)
{
    int w = x2 - x ;
    int h = y2 - y ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
    if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
    if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;
    int longest = abs(w) ;
    int shortest = abs(h) ;
    if (!(longest>shortest)) {
        longest = abs(h) ;
        shortest = abs(w) ;
        if (h<0) dy2 = -1 ; else if (h>0) dy2 = 1 ;
        dx2 = 0 ;
    }
    int numerator = longest >> 1 ;
    for (int i=0;i<=longest;i++) {
        putPixel(x,y,color , charecter) ;
        numerator += shortest ;
        if (!(numerator<longest)) {
            numerator -= longest ;
            x += dx1 ;
            y += dy1 ;
        } else {
            x += dx2 ;
            y += dy2 ;
        }
    }
}

void BUFFER::drawRectangle(int x, int y, int width, int height, char charecter, int color)
{
    for(int counterx=x; counterx<x+width; counterx++)
        for(int countery=y; countery<y+height; countery++)
        putPixel(counterx,countery,charecter,color);
}

void BUFFER::drawCircle(int x,int y,int radius,int color, char character)
{
       int discriminant =(5-radius<<2)>>2 ;
    int i = 0, j = radius;
    while (i<=j)
    {
        putPixel(x+i,y-j,color,character);
        putPixel(x+j,y-i,color,character);
        putPixel(x+i,y+j,color,character);
        putPixel(x+j,y+i,color,character);
        putPixel(x-i,y-j,color,character);
        putPixel(x-j,y-i,color,character);
        putPixel(x-i,y+j,color,character);
        putPixel(x-j,y+i,color,character);
        i++ ;
        if (discriminant<0) {
            discriminant += (i<<1) + 1 ;
        } else {
            j-- ;
            discriminant += (1 + i - j)<<1 ;
        }
    }
}

void BUFFER::drawHRectangle(int x, int y, int width, int height, char charecter, int color)
{
    drawLine(x,y,x+width,y,charecter,color);
    drawLine(x,y,x,y+height,charecter,color);
    drawLine(x+width,y,x+width,y+height,charecter,color);
    drawLine(x,y+height,x+width,y+height,charecter,color);
}
