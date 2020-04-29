#include <stdio.h>
#include <iostream>
#include <windows.h>

void ClearScreen(HDC hdc) {
    HPEN hpen = CreatePen(PS_SOLID, 2, RGB(65, 59, 106));
    SelectObject(hdc, hpen);
    HBRUSH hbrush = CreateSolidBrush(RGB(65, 59, 106));
    SelectObject(hdc, hbrush);
    Rectangle(hdc, 0, 0, 1000, 500);
}
void DrawRectangle(HDC hdc) {
    SelectObject(hdc, GetStockObject(WHITE_PEN));
    MoveToEx(hdc, 200, 100, NULL); 
    LineTo(hdc, 800, 100); 
    LineTo(hdc, 800, 300);
    LineTo(hdc, 200, 300);
    LineTo(hdc, 200, 100);
}
void MoveTriangle(HDC hdc, int x, int y) {
    int x1 = 185, y1 = 85, x2 = 215, y2 = 85, x3 = 215, y3 = 115, x4 = 185, y4 = 115;
    SelectObject(hdc, GetStockObject(WHITE_PEN)); 
    MoveToEx(hdc, x1 + x, y1 + y, NULL);
    LineTo(hdc, x2 + x, y2 + y);
    LineTo(hdc, x3 + x, y3 + y);
    LineTo(hdc, x4 + x, y4 + y);
    LineTo(hdc, x1 + x, y1 + y);
}

int main()
{

    while (true){
        HDC hdc = GetDC(GetConsoleWindow());
        int x = 0, y = 0;
        while (x < 600) {
            ClearScreen(hdc);
            DrawRectangle(hdc);
            MoveTriangle(hdc, x++, y);
            Sleep(10);
        }
        while (y < 200){
            ClearScreen(hdc);
            DrawRectangle(hdc);
            MoveTriangle(hdc, x, y++);
            Sleep(10);
        }
        while (x != 0){
            ClearScreen(hdc);
            DrawRectangle(hdc);
            MoveTriangle(hdc, x--, y);
            Sleep(10);
        }
        while (y != 0){
            ClearScreen(hdc);
            DrawRectangle(hdc);
            MoveTriangle(hdc, x, y--);
            Sleep(10);
        }
    }
        
}


