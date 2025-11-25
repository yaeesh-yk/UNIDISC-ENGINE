#include <windows.h>

// Sets the console text color (Windows only)
// just used it to enhance visuals of the program somewhat


inline void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  //this fucntion is part of windows.h library
}
