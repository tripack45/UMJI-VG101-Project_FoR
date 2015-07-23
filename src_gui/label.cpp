#include "../headers_gui/hw8_gui.h"

const std::string Label::empty_string=" ";
Label::Label(COORD* bPOS,std::string* text_,void (*foo)(COORD))
    :cControl(bPOS){
    ChangeText(text_);
    setClkHandler(foo);
    setDblClkHandler(0);
}

COORD Label::getControlSize(){
    COORD bSize=csize;
    return bSize;
}

void Label::Draw(){
    ChangeText(text);
    PutString({0,0},text,text->size());
}

void Label::ChangeText(std::string* str){
    text= str==0 ? (std::string*)&Label::empty_string : str;
    int textlen=text->size();
    csize={textlen,1};
    if(cbuffer!=0)delete cbuffer;
    cbuffer=new CHAR_INFO[textlen];
    memset(cbuffer,textlen,sizeof(CHAR_INFO));
    return;
};

void Label::OnDoubleClick(COORD mpos){
    if(dblclickHandler!=0)
        dblclickHandler(mpos);
};

void Label::OnClick(COORD mpos){
    if(clickHandler!=0)
        clickHandler(mpos);
};

void Label::setDblClkHandler(void (*foo)(COORD)){
    dblclickHandler=foo;
}

void Label::setClkHandler(void (*foo)(COORD)){
    clickHandler=foo;
}
