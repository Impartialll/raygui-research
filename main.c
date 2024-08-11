#include "start_menu.h"
#include "raylib.h"

int main()
{
    InitWindow(SCREEN_W, SCREEN_H, "Pong Online");
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    SetTargetFPS(60);

    start_menu();

    return 0;
}