#include <windows.h>
#include <iostream>
#include "headers/hw8.h"

void foo(COORD mpos);
void foo2(COORD mpos);
int main(void)
{
    Screen screen;
    cForm form(screen.getScreenSize(),{0,0});
    screen.setForm(&form);
    screen.setCursorVisibility(false);
    Button button1(&UI::button1_pos,&UI::button1_text,foo);
    Button button2(&UI::button2_pos,&UI::button2_text,foo2);
    Label label1(&UI::Label1_pos,&UI::Label1_text);
    form.AddControl(&button1);
    form.AddControl(&button2);
    form.AddControl(&label1);
    while(1){
        screen.Update();
        screen.Draw();
    }
	return 0;
}

void foo(COORD mpos){
    UI::Label1_pos.X+=1;
    UI::Label1_pos.Y+=1;
}

void foo2(COORD mpos){
    UI::Label1_text+="Q";
}

