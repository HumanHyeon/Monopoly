/*BOOL gettext(int left, int top, int right, int bottom, void *destin)    // 영역 저장하기
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coordBufSize = {right-left+1, bottom-top+1};
 COORD coordBufCoord = {0, 0};
 SMALL_RECT region = {left, top, right, bottom};

 return ReadConsoleOutput(hConsole, destin, coordBufSize, coordBufCoord, &region);
}

 

BOOL puttext(int left, int top, int right, int bottom, void *source)    // 저장한 영역 되돌리기
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coordBufSize = {right-left+1, bottom-top+1};
 COORD coordBufCoord = {0, 0};
 SMALL_RECT region = {left, top, right, bottom};

 return WriteConsoleOutput(hConsole, source, coordBufSize, coordBufCoord, &region);
}

 

int getscr(int x, int y)    // x, y 좌표 지점의 아스키코드를 조사
{
 CHAR_INFO dest;

 gettext(x, y, x, y, &dest);
    
    return dest.Char.AsciiChar;
}

 

int getattr(int x, int y)   // x, y 좌표 지점의 속성(색상)을 조사
{
 CHAR_INFO dest;

 gettext(x, y, x, y, &dest);
    
    return dest.Attributes;
}

 

int getcolor(int x, int y) // 글자 색상 설정 getcolor(글자색);
{
    short   attr;
    DWORD   dummy;
    COORD   pos = {x, y};

    ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &dummy );

    return (attr & 0xf);
}

 

int getbkcolor(int x, int y) // 배경 색상 설정 getcolor(배경색);
{
    short   attr;
    DWORD   dummy;
    COORD   pos = {x, y};

    ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &dummy );

    return (attr & 0xf0) >> 4;
}

 

void textattr(int color)  // 색상 설정 : textattr(글자색|배경색<<4)
{
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(color) );
}

 

void setcolor(int textcolor)    // 글자 색상 설정 setcolor(글자색);
{
    WORD    attr;
    DWORD   dummy;
    CONSOLE_SCREEN_BUFFER_INFO BufInfo; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &BufInfo);
    ReadConsoleOutputAttribute(hConsole, &attr, 1, BufInfo.dwCursorPosition, &dummy );

    attr = textcolor | (attr & 0xf0);
    SetConsoleTextAttribute( hConsole, (WORD)(attr) );
}

 

void setbkcolor(int color)        // 배경 색상 설정 setbkcolor(배경색);
{
    WORD    attr;
    DWORD   dummy;
    CONSOLE_SCREEN_BUFFER_INFO BufInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &BufInfo);
    ReadConsoleOutputAttribute(hConsole, &attr, 1, BufInfo.dwCursorPosition, &dummy );

    attr = (attr & 0xf) | (color << 4);
    SetConsoleTextAttribute( hConsole, (WORD)(attr) );
}*/
