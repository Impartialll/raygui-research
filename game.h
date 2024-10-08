#include "raylib.h"
#include <string.h>
#include <sys/types.h>

#define SCREEN_W 640
#define SCREEN_H 480

// Types
typedef struct Ball
{
  Vector2 position;
  Vector2 speed;
  float radius;
} Ball;

typedef struct Paddle
{
  int paddleWidth;
  int paddleHeight;
  int leftPaddleX;
  int rightPaddleX;
} Paddle;

typedef struct Player
{
  short position_y;
  int score;
} Player;

typedef struct WindowRect
{
  int rectWidth;
  int rectHeight;
  int rectX;
  int rectY;
} WindowRect;

typedef struct GameState
{
  int countdown;
  float countdownTimer;
  bool gamePaused;
} GameState;

typedef u_int32_t u32;

typedef struct WindowSettings
{
  char *title;
  char *footer;
  u32 screenWidth;
  u32 screenHeight;
  u32 targetFPS;
  u32 fontSize;
} WindowSettings;

// IP Settings structure
typedef struct
{
  unsigned char ip[4];
  short port;
} IpSettings;

extern bool show_start_popup;
extern bool show_ipset_popup;
extern bool on_window_quit;
extern bool singleplayer;

Vector2 GetRandomBallSpeed(int minSpeed, int maxSpeed);
void ResetBall(Ball *ball, int screenWidth, int screenHeight);

int main_loop(Player player1, Player player2, WindowRect rect, Paddle pd,
              GameState state, Ball ball, WindowSettings window);
