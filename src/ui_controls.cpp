#include "../headers/hw8.h"
//===============BUTTON======================
const int Button::TxtMaxLength=5;
const int Button::TxtMaxLine=1;
/*
Button::Button(COORD* bPOS)
    :cControl(bPOS){
    cbuffer=new CHAR_INFO[(2+TxtMaxLine)*(TxtMaxLength+2)];
    memset(cbuffer,0,(TxtMaxLength+2) * (2+TxtMaxLine) * sizeof(CHAR_INFO));
    dblclickHandler=0;
}

Button::Button(COORD* bPOS,std::string& text_)
    :cControl(bPOS){
    Button(bPOS);
    ChangeText(text_);
}*/

Button::Button(COORD* bPOS,std::string* text_,void (*foo)(COORD))
    :cControl(bPOS){
    cbuffer=new CHAR_INFO[(2+TxtMaxLine)*(TxtMaxLength+2)];
    memset(cbuffer,0,(TxtMaxLength+2) * (2+TxtMaxLine) * sizeof(CHAR_INFO));
    ChangeText(text_);
    dblclickHandler=foo;
}

COORD Button::getDrawSize(){
                //====X========,=======Y=====
    COORD bSize={TxtMaxLength+2,2+TxtMaxLine};
    return bSize;
}

void Button::Draw(){
    COORD dwsize=getDrawSize();
    DrawRectangle({0,0},{6,2});
    CHAR_INFO blank={' ',7};
    for(int i=0;i<TxtMaxLength;i++){
        *(cbuffer+dwsize.X+1+i)=blank;
    }//initialize all text spaces;
    for(int i=0;i<TxtMaxLength;i++)
        if((*text)[i]=='\0'){
           return;
        }else{
           CHAR_INFO tCHAR={(*text)[i],7};
            *(cbuffer+dwsize.X+1+i)=tCHAR;
        }
}

Button::~Button(){
    delete cbuffer;
}

void Button::ChangeText(std::string* str){
    text=str;
};

void Button::OnDoubleClick(COORD mpos){
    if(dblclickHandler!=0)
        dblclickHandler(mpos);
};

void Button::setDblClkHandler(void (*foo)(COORD)){
    dblclickHandler=foo;
}
//=====================BUTTON END=========================
