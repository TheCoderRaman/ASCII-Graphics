InputClass::InputClass()
{
    for(int counter=0; counter<256; counter++)
        keys[counter]=false;
    mousex=0; mousey=0;
    ldown=false; rdown=false;
}

void InputClass::setKeyDown(int key)
{
    keys[key]=true;
}

void InputClass::setKeyUp(int key)
{
    keys[key]=false;
}

bool InputClass::getKey(int key)
{
    return keys[key];
}

DWORD getEvents(INPUT_RECORD **record)
{
HANDLE rHnd= GetStdHandle(STD_INPUT_HANDLE);
DWORD numEvents=0;
DWORD numEventsRead=0;
GetNumberOfConsoleInputEvents(rHnd, &numEvents);
if(numEvents)
{
*record=new INPUT_RECORD[numEvents];
ReadConsoleInput(rHnd, *record, numEvents, &numEventsRead);
}
return numEventsRead;
}


void InputClass::Update(void)
{
INPUT_RECORD* record;
DWORD numEventsRead=getEvents(&record); bool pressed=false;
if(numEventsRead)
for(unsigned int counter=0; counter<numEventsRead; counter++)
{
    switch(record[counter].EventType)
    {
    case KEY_EVENT:
    if(record[counter].Event.KeyEvent.bKeyDown)
    {
    setKeyDown(record[counter].Event.KeyEvent.wVirtualKeyCode);
    }
    else
    {
    setKeyUp(record[counter].Event.KeyEvent.wVirtualKeyCode);
    }
    break;

    case MOUSE_EVENT:
    mousex = record[counter].Event.MouseEvent.dwMousePosition.X;
    mousey = record[counter].Event.MouseEvent.dwMousePosition.Y;
    if(record[counter].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
    {
    ldown=true;
    }
    else
    {
        ldown=false;
    }
    if(record[counter].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
    {
        rdown=true;
    }
    else
    {
        rdown=false;
    }
    break;
    }
    }
}

COORD InputClass::getMousePosition(void)
{
    return COORD{mousex,mousey};
}

bool InputClass::RightClicked(void)
{
    return rdown;
}

bool InputClass::LeftClicked(void)
{
    return ldown;
}
