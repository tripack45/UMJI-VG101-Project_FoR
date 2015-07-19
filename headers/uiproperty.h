#ifndef UIPROPERTY_H_INCLUDED
#define UIPROPERTY_H_INCLUDED
#include "hw8.h"
class UI{
public:
    static Screen* screen;
    static cForm* current_form;

    static COORD button1_pos;
    static std::string button1_text;
    static COORD button2_pos;
    static std::string button2_text;
    static COORD Label1_pos;
    static std::string Label1_text;

};
#endif // UIPROPERTY_H_INCLUDED
