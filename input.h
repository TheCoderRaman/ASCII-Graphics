#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

class InputClass
{
public:
    InputClass();
    bool getKey(int key);
    void setKeyUp(int key);
    void setKeyDown(int key);
    void Update(void);
    COORD getMousePosition(void);
    bool RightClicked(void);
    bool LeftClicked(void);

private:
    int mousex, mousey; int vcode;
	bool keys[256];
	bool rdown;
	bool ldown;
};
#include "Input.cpp"
#endif // INPUT_H_INCLUDED
