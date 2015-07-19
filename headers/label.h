#ifndef __UILABLE_H__
#define __UILABLE_H__
#include "form.h"
#include <string>

class Label:public cControl{
public:
    Label(COORD* lPOS,std::string* text_,void (*foo)(COORD)=0);
    COORD getControlSize();
    void setDblClkHandler(void (*foo)(COORD));
    void setClkHandler(void (*foo)(COORD));
    void OnDoubleClick(COORD);
    void OnClick(COORD);
    void Draw();
    void ChangeText(std::string*);
    ~Label();
private:
    std::string* text;
    void (*dblclickHandler)(COORD);
    void (*clickHandler)(COORD);
    static const std::string empty_string;
    COORD csize;
};
#endif
