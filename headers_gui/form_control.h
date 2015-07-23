#ifndef __FORM_H__
#define __FORM_H__
#include <vector>
#include <string>

class cControl{
public:
    cControl(COORD* cpos);
    virtual COORD getControlSize()=0;
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

    void InitializeBuffer(int);

    void DrawRectangle(COORD,COORD);
    void PutString(COORD pos,std::string* str=0,int len=1);
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
