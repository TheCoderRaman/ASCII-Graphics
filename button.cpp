    bool button::isIn(int mousex, int mousey)
    {
    if(mousex>=x && mousey>=y && mousex<=x+width &&mousey<=y+height)
        return true;
    else
        return false;
    }

    button::button()
    {
        x=0; y=0; width=0; height=0; buttonimage.clear(0x00,GR_PIXEL());
    }

    button::button(std::string image2)
    {
        x=0; y=0; buttonimage.loadfromfile(image2); width=buttonimage.getwidth(); height=buttonimage.getheight();
    }

    button::button(int x2, int y2, int width2, int height2)
    {
        x=x2; y=y2; width=width2; height=height2;
    }

    button::button(image mainimage)
    {
        x=0; y=0; buttonimage=mainimage; width=mainimage.getwidth(); height=mainimage.getheight();
    }

    button::button(int x2, int y2, image mainimage)
    {
        x=x2; y=y2; buttonimage=mainimage; width=mainimage.getwidth(); height=mainimage.getheight();
    }
    void button::setImage(image mainimage)
    {
        buttonimage=mainimage; width=mainimage.getwidth(); height=mainimage.getheight();
    }
    void button::setPosition(int x2, int y2)
    {
        x=x2; y=y2;
    }
    void button::setSize(int width2, int height2)
    {
        buttonimage.resize(width2,height2); width=width2; height=height2;
    }
    int button::getWidth(void)
    {
        return width;
    }
    int button::getHeight(void)
    {
        return height;
    }
    int button::getX(void)
    {
        return x;
    }
    int button::getY(void)
    {
        return y;
    }
    image button::getImage(void)
    {
        return buttonimage;
    }


    button::button(int x2, int y2, std::string filename)
    {
        image tempimage; tempimage.loadfromfile(filename);
        setImage(tempimage); setPosition(x2,y2);
    }
