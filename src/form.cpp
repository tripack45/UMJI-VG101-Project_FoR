#include <windows.h>
#include "../headers/hw8.h"
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
    int index=getRecieverIndex(mpos);
    if(index!=-1)
        controls[index]->OnDoubleClick(mpos);
    //*(fbuffer+ 1 * FormSize.X + 1)={'A',7};
    return;
}

void cForm::Draw(){
    COORD fsize=FormSize;
    memset(fbuffer,0,fsize.X * fsize.Y * sizeof(CHAR_INFO));
    for(int i=0;i<controls.size();i++){
        //iterate through all controls
        controls[i]->Draw();
        CHAR_INFO* cbuffer=controls[i]->getBuffer();
        COORD csize=controls[i]->getDrawSize();
        COORD cpos=controls[i]->getControlPos();
        for(int i=0;i<csize.Y;i++)
            memcpy(fbuffer + (cpos.Y+i) * FormSize.X + cpos.X,
                cbuffer + i * csize.X,
                csize.X*sizeof(CHAR_INFO)
                );
    }
}

CHAR_INFO* cForm::getBuffer(){
    return fbuffer;
}

void cForm::AddControl(cControl* ctl){
    controls.push_back(ctl);
}

cForm::~cForm(){
    delete fbuffer;
}

int cForm::getRecieverIndex(COORD mpos){
    for(int i=controls.size()-1;i>=0;i--){
        COORD cpos=controls[i]->getControlPos();
        COORD csize=controls[i]->getDrawSize();
        if(mpos.X>=cpos.X && mpos.X<cpos.X+csize.X)
            if(mpos.Y>=cpos.Y && mpos.Y<cpos.Y+csize.Y)
                return i;
    }
    return -1;
}

