#include <windows.h>
#include "../headers/hw8.h"
#include <cstring>
#include <iostream>

cControl::cControl(COORD* cpos){
    controlpos=cpos;
}

CHAR_INFO* cControl::getBuffer(){
    return cbuffer;
}

COORD cControl::getControlPos(){
    return *controlpos;
}

void cControl::setPosition(COORD newpos){
    (*controlpos)=newpos;
}

void cControl::movePosition(COORD vec){
    (*controlpos).X+=vec.X;
    (*controlpos).Y+=vec.Y;
}

cControl::~cControl(){
    delete cbuffer;
}

void cControl::DrawRectangle(COORD u,COORD v){//v>u required
    static const CHAR_INFO luchar={'A',7};
    static const CHAR_INFO ruchar={'B',7};
    static const CHAR_INFO ldchar={'C',7};
    static const CHAR_INFO rdchar={'D',7};
    static const CHAR_INFO hchar={'|',7};
    static const CHAR_INFO vchar={'=',7};
    COORD dwsize=getDrawSize();
    #define BUF(x,y) *(cbuffer + y * dwsize.X + x )
    for(int i=u.X;i<=v.X;i++){
        BUF(i   , u.Y)=vchar;
        BUF(i   , v.Y)=vchar;
    }
    for(int i=u.Y;i<v.Y;i++){
        BUF(u.X , i)=hchar;
        BUF(v.X , i)=hchar;
    }
    BUF(u.X,u.Y)=luchar;   BUF(v.X,u.Y)=ruchar;
    BUF(u.X,v.Y)=ldchar;   BUF(v.X,v.Y)=rdchar;
    #undef BUF
}
