//MIT License
//
//Copyright (c) 2024 @NOTRICED

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.


//main code edit from here
#include <Windows.h>

int main() {

    HWND taskbar = FindWindowW(L"Shell_TrayWnd", NULL);


    if (taskbar == NULL) {
        MessageBox(NULL, L"Taskbar not found!", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }


    LONG style = GetWindowLong(taskbar, GWL_EXSTYLE);

    SetWindowLong(taskbar, GWL_EXSTYLE, style | WS_EX_LAYERED);


    BYTE transparency = 360;  // Change value 180 semi transparent
    SetLayeredWindowAttributes(taskbar, 0, transparency, LWA_ALPHA);

    return 0;
}
