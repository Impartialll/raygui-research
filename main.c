#include "start_menu.h"
#include <stdbool.h>

WindowSettings window = {
    .title = "Ping pong",
    .footer = "Created by two geniuses",
    .screenWidth = SCREEN_W,
    .screenHeight = SCREEN_H,
    .targetFPS = 60,
    .fontSize = (SCREEN_W / SCREEN_H) * 50,
};
WindowRect rect = {
    .rectWidth = SCREEN_W / 2 + 200,
    .rectHeight = SCREEN_H / 2 + 40,
    .rectX = (SCREEN_W - (SCREEN_W / 2 + 200)) / 2,
    .rectY = (SCREEN_H - (SCREEN_H / 2 + 40)) / 2,
};

GameState state = {.countdown = 3, .countdownTimer = 0.0f, .gamePaused = true};

// Ball properties
Ball ball = {.position = {SCREEN_H / 2.0f, SCREEN_H / 2.0f},
             .speed = {350},
             .radius = 15.0f};

// Paddles properties
Paddle pd = {.paddleWidth = 20,
             .paddleHeight = 100,
             .leftPaddleX = 100,
             .rightPaddleX = SCREEN_W - 120};

Player player1 = {
    .score = 0,
    .position_y = (SCREEN_H - 100) / 2,
};

Player player2 = {
    .score = 0,
    .position_y = (SCREEN_H - 100) / 2,
};

int main() {
  InitWindow(SCREEN_W, SCREEN_H, "Pong Online");
  SetMouseCursor(MOUSE_CURSOR_ARROW);
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    if (singleplayer) {
      int mode = 0;
      do {
        switch (mode) {
        case WINDOW_QUIT:
          CloseWindow();
          return 0;
          break;

        default:
          break;
        }
        mode =
            main_loop(&player1, &player2, &rect, &pd, &state, &ball, &window);
      } while (mode != LOOP_CLOSED);
    }

    if (show_start_popup) {
      int mode = 0;
      do {
        switch (mode) {
        case WINDOW_QUIT:
          CloseWindow();
          return 0;
          break;

        default:
          break;
        }
        mode = start_menu();
      } while (mode != LOOP_CLOSED);
    }
  }
  CloseWindow();
  return 0;
}