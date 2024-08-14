#include "game.h"

int start_menu(void);
void PopWelcome(Rectangle pop);
void PopIPSettings(Rectangle pop, IpSettings *sets, char ip_str[],
                   char port_str[], bool ip_active, bool port_active);