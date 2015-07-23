#include "../headers_gui/hw8_gui.h"
//===============BUTTON======================
const int Button::TxtMaxLength=5;
const int Button::TxtMaxLine=1;

Button::Button(COORD* bPOS,std::string* text_,void (*foo)(COORD))
    :cControl(bPOS){
    COORD csize=getControlSize();
    InitializeBuffer(csize.X*csize.Y);
    ChangeText(text_);
    setClkHandler(foo);
    setDblClkHandler(0);
}

COORD Button::getControlSize(){
                //====X========,=======Y=====
    COORD bSize={TxtMaxLength+2,2+TxtMaxLine};
    return bSize;
}

void Button::Draw(){
    DrawRectangle( {0,0} , {6,2});
    PutString({0,0}, text, 5 );
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
