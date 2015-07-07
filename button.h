#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

class button
{
    int x; int y; image buttonimage; int width; int height;
public:
    bool isIn(int mousex, int mousey);
    button();
    button(std::string image2);
    button(int x2, int y2, int width2, int height2);
    button(image mainimage);
    button(int x2, int y2, image mainimage);
    button(int x2, int y2, std::string filename);
    void setImage(image mainimage);
    void setPosition(int x2, int y2);
    void setSize(int width2, int height2);
    int getWidth(void);
    int getHeight(void);
    int getX(void);
    int getY(void);
    image getImage(void);
};

#include "button.cpp"
#endif // BUTTON_H_INCLUDED
