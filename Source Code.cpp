#include <Windows.h>

int main() {

    HWND taskbar = FindWindowW(L"Shell_TrayWnd", NULL);


    if (taskbar == NULL) {
        MessageBox(NULL, L"Taskbar not found!", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }


    LONG style = GetWindowLong(taskbar, GWL_EXSTYLE);

    SetWindowLong(taskbar, GWL_EXSTYLE, style | WS_EX_LAYERED);


    BYTE transparency = 120;  // Change value 180 semi transparent
    SetLayeredWindowAttributes(taskbar, 0, transparency, LWA_ALPHA);

    return 0;
}