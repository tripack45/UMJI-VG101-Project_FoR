#include "../headers_gui/hw8_gui.h"
#include <cmath>

const std::string TextBox::empty_string=" ";
TextBox::TextBox(COORD *bPOS, COORD *csize, std::string *text_, void (*foo)(COORD))
        :cControl(bPOS){
    cbuffer=0;//IMPORTANT! Makesure proper allocation;
    ChangeText(text_);
    clickHandler=foo;
    dblclickHandler=0;
}

COORD TextBox::getControlSize(){
    //====X========,=======Y=====
    COORD bSize=csize;
    return bSize;
}

void TextBox::Draw(){
    ChangeText(text);
    PutString({0,0},text,text->size());
}

void TextBox::ChangeText(std::string* str){
    text= str==0 ? (std::string*)&TextBox::empty_string : str;
    int textlen=text->size();
    csize={textlen,1};
    if(cbuffer!=0)delete cbuffer;
    cbuffer=new CHAR_INFO[textlen];
    memset(cbuffer,textlen,sizeof(CHAR_INFO));
    return;
}

void TextBox::OnDoubleClick(COORD mpos){
    if(dblclickHandler!=0)
        dblclickHandler(mpos);
}

void TextBox::OnClick(COORD mpos){
    if(clickHandler!=0)
        clickHandler(mpos);
}

void TextBox::setDblClkHandler(void (*foo)(COORD)){
    dblclickHandler=foo;
}

void TextBox::setClkHandler(void (*foo)(COORD)){
    clickHandler=foo;
}

TextBox::~TextBox() {}
