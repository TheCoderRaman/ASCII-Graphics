    std::string textbox::getBackText()
    {
        return backgroundtext;
    }

    void textbox::backspace(void)
    {
        if(currenttext.size()>0)
            currenttext.erase(currenttext.end()-1);
    }

    void textbox::setPosition(int x1, int y1, int width1)
    {
    x=x1; y=y1; width=width1;
    }

    void textbox::setSize(int width2)
    {
        width=width2;
    }

    int textbox::getWidth(void)
    {
        return width;
    }

    bool textbox::isIn(int mousex, int mousey)
    {
    if(mousex>=x && mousey==y && mousex<=x+width)
        return true;
    else
        return false;
    }

    std::string textbox::getText(void)
    {
        return currenttext;
    }
    void textbox::setText(std::string text)
    {
        currenttext=text;
    }
    void textbox::append(char text)
    {
        currenttext+=text;
    }
    void textbox::setBackText(std::string text)
    {
        backgroundtext=text;
    }
    int textbox::getX(void)
    {
        return x;
    }
    int textbox::getY(void)
    {
        return y;
    }
    void textbox::setSelect(bool selected2)
    {
        selected=selected2;
    }
    void textbox::setColor(int color2)
    {
        color=color2;
    }
    int textbox::getColor(void)
    {
        return color;
    }
    textbox::textbox()
    {
        currenttext=""; x=0; y=0; selected=false; width=1; color=0x0f;
    }


    textbox::textbox(int x1, int y1, int width1, int color1, std::string backt)
    {
    currenttext=""; x=x1, y=y1; width=width1; color=color1; backgroundtext=backt;
    selected=false;
    }

    bool textbox::isSelected(void)
    {
        return selected;
    }
