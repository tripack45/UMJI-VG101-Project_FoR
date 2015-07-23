#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <windows.h>
#include <set>
#include "form_control.h"

class Screen{
public:
    Screen();
    ~Screen();
    void setCursorPos(short,short);
    void setCursorVisibility(bool);
    void Update();
    void setForm(cForm*);
    void Draw();
    COORD getScreenSize();
private:
    HANDLE hin,hout,herr;
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    INPUT_RECORD mouseRec;
	DWORD res;
	COORD crPos, crHome;
	CONSOLE_CURSOR_INFO cursorinfo;

	CHAR_INFO* sbuffer;

	cForm* pform;
	void DispatchMouseInput();
};
#endif // __SCREEN_H__
