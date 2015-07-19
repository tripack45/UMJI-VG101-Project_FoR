#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
#include "../headers/hw8.h"
void foo(COORD mpos);
int main(void)
{
    Screen screen;
    cForm form(screen.getScreenSize(),{0,0});
    screen.setForm(&form);
    screen.setCursorVisibility(false);
    Button button1(&UI::button1_pos,&UI::button1_text,foo);
    form.AddControl(&button1);
    while(1){
        screen.Update();
        screen.Draw();
    }
	return 0;
}

void foo(COORD mpos){
    srand(time(NULL));
    (UI::button1_pos).X=rand()%70;
    (UI::button1_pos).Y=rand()%20;
    std::string str="µ„Œ“";
    UI::button1_text=str;
}

