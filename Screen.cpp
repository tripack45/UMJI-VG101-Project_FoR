#include "headers/hw8.h"
#include <cstring>
#include <iostream>
Screen::Screen(){
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
	hin = GetStdHandle(STD_INPUT_HANDLE);
	//std::cout<<hin<<' ';
	HANDLE herr = GetStdHandle(STD_ERROR_HANDLE);
	GetConsoleScreenBufferInfo(hout, &bInfo);
	GetConsoleCursorInfo(hin,&cursorinfo);
	cbuffer=new CHAR_INFO[bInfo.dwSize.X*bInfo.dwSize.Y];
	memset(cbuffer,0,bInfo.dwSize.X * bInfo.dwSize.Y);
}

void Screen::setCursorPos(short x,short y){
    COORD cpos={x,y};
    SetConsoleCursorPosition(hout,cpos);
}

void Screen::setCursorVisibility(bool isvisible){
    GetConsoleCursorInfo(hout,&cursorinfo);
    cursorinfo.bVisible=isvisible;
    SetConsoleCursorInfo(hout,&cursorinfo);
}

void Screen::setForm(cForm* pform_){
    pform=pform_;
}

COORD Screen::getScreenSize(){
    return bInfo.dwSize;
}

void Screen::Draw(){
    (*pform).Draw();
    CHAR_INFO* pformbuff=(*pform).getBuffer();
    COORD fsize=(*pform).FormSize;
    COORD formpos=(*pform).FormPos;
    for(int i=0;i<fsize.Y;i++)
        memcpy(cbuffer + (formpos.Y+i) * bInfo.dwSize.X + formpos.X,
                pformbuff + i * fsize.X,
                fsize.X*sizeof(CHAR_INFO)
                );
    SMALL_RECT ret={0,0,bInfo.dwSize.X,bInfo.dwSize.Y};
    COORD crhome={0,0};
    if(!WriteConsoleOutput(hout,cbuffer,bInfo.dwSize,crhome,&ret));

}

void Screen::DispatchMouseInput(){
    ReadConsoleInput(hin, &mouseRec, 1, &res);
    if (mouseRec.EventType == MOUSE_EVENT){
        if (mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
            if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK){
                COORD crPos=mouseRec.Event.MouseEvent.dwMousePosition;
                crPos.X=crPos.X-(*pform).FormPos.X;
                crPos.Y=crPos.Y-(*pform).FormPos.Y;
                (*pform).OnDoubleClick(crPos);
            }
        }
        /*
        if(mouseRec.Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED){
            if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
					(*pform).OnDoubleRClick();
        }*/
    }

}

void Screen::Update(){
    DispatchMouseInput();
}

Screen::~Screen(){
    CloseHandle(hin);
    CloseHandle(hout);
    CloseHandle(herr);
    delete cbuffer;
}
