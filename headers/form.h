#ifndef __FORM_H__
#define __FORM_H__
#include "hw8.h"
#include <vector>

class cForm{
public:
    cForm(COORD fsize,COORD fpos);
    void OnDoubleClick(COORD);
    void AddControl();
    void Draw();
    CHAR_INFO* getBuffer();
    COORD FormPos;
    COORD FormSize;
    ~cForm();
private:
    CHAR_INFO* fbuffer;
    //vector<int> controls;
};

class cControl{
public:
    cControl(COORD cpos);
    void OnDoubleClick(COORD);
    void Draw();
    CHAR_INFO* getBuffer();
    ~cControl();
private:
    CHAR_INFO* fbuffer;
};
#endif
