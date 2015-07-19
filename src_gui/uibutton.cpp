#include "../headers/hw8.h"
//===============BUTTON======================
const int Button::TxtMaxLength=5;
const int Button::TxtMaxLine=1;

Button::Button(COORD* bPOS,std::string* text_,void (*foo)(COORD))
    :cControl(bPOS){
    cbuffer=new CHAR_INFO[(2+TxtMaxLine)*(TxtMaxLength+2)];
    memset(cbuffer,0,(TxtMaxLength+2) * (2+TxtMaxLine) * sizeof(CHAR_INFO));
    ChangeText(text_);
    clickHandler=foo;
    dblclickHandler=0;
}

COORD Button::getControlSize(){
                //====X========,=======Y=====
    COORD bSize={TxtMaxLength+2,2+TxtMaxLine};
    return bSize;
}

void Button::Draw(){
    COORD dwsize=getControlSize();
    DrawRectangle({0,0},{6,2});
    PutString({1,1},text,5);
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

void Button::OnClick(COORD mpos){
    if(clickHandler!=0)
        clickHandler(mpos);
};

void Button::setDblClkHandler(void (*foo)(COORD)){
    dblclickHandler=foo;
}

void Button::setClkHandler(void (*foo)(COORD)){
    clickHandler=foo;
}
//=====================BUTTON END=========================
