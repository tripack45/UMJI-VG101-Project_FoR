#include <windows.h>
#include "headers/hw8.h"
#include <cstring>
#include <iostream>
cForm::cForm(COORD fsize,COORD fpos){
    fbuffer=new CHAR_INFO[fsize.X * fsize.Y];
    memset(fbuffer,0,fsize.X * fsize.Y * sizeof(CHAR_INFO));
    FormSize=fsize;
    FormPos=fpos;
}

void cForm::OnDoubleClick(COORD mpos){
    //system("PAUSE");
    CHAR_INFO t={'A',7};
    *(fbuffer+ mpos.Y * FormSize.X + mpos.X)=t;
    //*(fbuffer+ 1 * FormSize.X + 1)={'A',7};
    return;
}

void cForm::Draw(){
}

CHAR_INFO* cForm::getBuffer(){
    return fbuffer;
}

cForm::~cForm(){
    delete fbuffer;
}


