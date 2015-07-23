#ifndef UMJI_VG101_PROJECT_FOR_TEXTBOX_H
#define UMJI_VG101_PROJECT_FOR_TEXTBOX_H
#include <windows.h>
#include "form_control.h"

class TextBox:public cControl{
public:
    TextBox(COORD *lPOS,
            COORD *csize_,
            std::string *text_,
            void (*foo)(COORD)=0);
    COORD getControlSize();
    void setDblClkHandler(void (*foo)(COORD));
    void setClkHandler(void (*foo)(COORD));
    void OnDoubleClick(COORD);
    void OnClick(COORD);
    void Draw();
    void ChangeText(std::string*);
    ~TextBox();

private:
    std::string* text;
    void (*dblclickHandler)(COORD);
    void (*clickHandler)(COORD);
    static const std::string empty_string;
    COORD csize;
};
#endif //UMJI_VG101_PROJECT_FOR_TEXTBOX_H
