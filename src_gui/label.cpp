#include "../headers/hw8.h"

const std::string Label::empty_string=" ";
Label::Label(COORD* bPOS,std::string* text_,void (*foo)(COORD))
    :cControl(bPOS){
    cbuffer=0;//IMPORTANT! Makesure proper allocation;
    ChangeText(text_);
    clickHandler=foo;
    dblclickHandler=0;

}

COORD Label::getControlSize(){
                //====X========,=======Y=====
    COORD bSize=csize;
    return bSize;
}

void Label::Draw(){
    ChangeText(text);
    PutString({0,0},text,text->size());
}

Label::~Label(){
    delete cbuffer;
}

void Label::ChangeText(std::string* str){
    if(str==0){
        text=(std::string*)&Label::empty_string;
    }else{
        text=str;
    }
    int strlen=str->size();
    csize={strlen,1};
    if(cbuffer!=0)delete cbuffer;
    cbuffer=new CHAR_INFO[strlen];
    memset(cbuffer,strlen,sizeof(CHAR_INFO));
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
