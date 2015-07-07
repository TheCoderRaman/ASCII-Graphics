#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED

class textbox
{
    std::string currenttext;
    bool outline;
    bool selected;
    std::string backgroundtext;
    int x; int y;
    int width;
    int color;
    public:
    void setPosition(int x1, int y1, int width1);
    bool isIn(int mousex, int mousey);
    std::string getText(void);
    void setText(std::string text);
    void append(char text);
    void setBackText(std::string text);
    int getX(void);
    int getY(void);
    void setSelect(bool selected2);
    void setColor(int color2);
    int getColor(void);
    void setSize(int width2);
    bool isSelected(void);
    void backspace(void);
    int getWidth(void);
    std::string getBackText(void);
    ////////////////////////////////////////////////////////////////
    /////////////////////Constructors//////////////////////////////
    textbox();
    textbox(int x1, int y1, int width1, int color1, std::string backt);
};

#include "textbox.cpp"
#endif // TEXTBOX_H_INCLUDED
