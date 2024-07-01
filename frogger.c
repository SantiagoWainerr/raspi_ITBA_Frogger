#include <stdio.h>
#include <stdlib.h>
#include "game/game_logic.h"
#include <time.h>
#include "mundo/renderWorld.h"
#include "inicialization/inicialization.h"
#include "menus/menu.h"
#include "audio/soundTrack.h"
#include "menu_logic/menu_logic.h"

int main(int argc, char **argv)
{
    inicialization();
    puts("frogger");
    initializeGameLogic(); 

    open_menu_1();

    return 0;
}
