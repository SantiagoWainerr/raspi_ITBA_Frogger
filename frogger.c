#include <stdio.h>
#include <stdlib.h>
#include "game/game_logic.h"
#include <time.h>
#include "mundo/renderWorld.h"
#include "inicialization/inicialization.h"
#include "menus/menu.h"
#include "audio/soundTrack.h"

int main(int argc, char **argv)
{
    inicialization();
    puts("frogger");
    initializeGameLogic();
    menu();
    music();   
    while(1)
    {
        gameTick(100);
        usleep(100000);
    }
    return 0;
}
