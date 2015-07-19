#ifndef __FORM_H__
#define __FORM_H__
#include "hw8.h"
#include <vector>

class cControl{
public:
    cControl(COORD* cpos);
    virtual COORD getDrawSize()=0;
             COORD getControlPos();
    virtual void Draw()=0;
    CHAR_INFO* getBuffer();
    void setPosition(COORD newpos);
    void movePosition(COORD vec);
    ~cControl();
    virtual void OnDoubleClick(COORD){};
    virtual void OnClick(COORD){};
protected:
    COORD* controlpos;
    CHAR_INFO* cbuffer;

    void DrawRectangle(COORD,COORD);
};

class cForm{
public:
    cForm(COORD fsize,COORD fpos);
    void OnDoubleClick(COORD);
    void OnClick(COORD);
    void AddControl(cControl*);
    void Draw();
    CHAR_INFO* getBuffer();
    COORD FormPos;
    COORD FormSize;
    ~cForm();
private:
    CHAR_INFO* fbuffer;
    std::vector<cControl*> controls;
    int getRecieverIndex(COORD mpos);
};
#endif
