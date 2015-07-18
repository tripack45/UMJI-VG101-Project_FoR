#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "headers/hw8.h"

int main(void)
{
    Screen screen;
    cForm form(screen.getScreenSize(),{0,0});
    screen.setForm(&form);
    screen.setCursorVisibility(false);
    while(1){
        screen.Update();
        screen.Draw();
    }
	return 0;
}

