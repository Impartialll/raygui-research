#include "raylib.h"

typedef struct
{
    unsigned char ip[4];
    short port;
} IpSettings;

#define SCREEN_W 640
#define SCREEN_H 480

int start_menu();
void PopWelcome(Rectangle pop);
void PopIPSettings(Rectangle pop, IpSettings *sets, char ip_str[], char port_str[], bool ip_active, bool port_active);