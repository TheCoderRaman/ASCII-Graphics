    const char GR_PIXEL(void)
    {
        return 219;
    }

    PIXEL::PIXEL(int color2, char image2)
    {
        color=color2; image=image2;
    }
    PIXEL::PIXEL()
    {
        color=0x00;
        image=219;
    }

    void PIXEL::setColor(int color2)
    {
        color=color2;
    }
    void PIXEL::setImage(char image2)
    {
        image=image2;
    }
    void PIXEL::setInfo(int color2, char image2)
    {
        image=image2; color=color2;
    }
    int PIXEL::getColor(void)
    {
        return color;
    }
    int PIXEL::getImage(void)
    {
        return image;
    }
