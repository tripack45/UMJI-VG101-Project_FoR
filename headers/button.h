#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__
#include "form.h"
#include <string>

class Button:public cControl{
public:
    Button(COORD* bPOS,std::string* text_,void (*foo)(COORD)=0);
    COORD getControlSize();
    void setDblClkHandler(void (*foo)(COORD));
    void setClkHandler(void (*foo)(COORD));
    void OnDoubleClick(COORD);
    void OnClick(COORD);
    void Draw();
    void ChangeText(std::string*);
    ~Button();
private:
    std::string* text;
    void (*dblclickHandler)(COORD);
    void (*clickHandler)(COORD);
    static const int TxtMaxLength;
    static const int TxtMaxLine;
};
#endif
