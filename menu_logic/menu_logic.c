#include <stdio.h>
#include "menu_logic.h"
#include "../menus/menu.h"
#include "../menus/top.h"
#include "../menus/pause.h"
#include <unistd.h>
#include "../game/game_logic.h" 
#include "../audio/soundTrack.h"
#include "../driv/disdrv.h"

bestPlayers_t jugadores = {{"VIC","SAN","LOR","MARC","AGU","PAP","SOS","MAT","NO","JOR"},{"2021","100","89","76","67","43","25","10","7","3"}};

void menu_1 (int option){
    
    switch (option){
        case START:
            while(1)
            {   
                music();
                gameTick(100);
                usleep(100000);
            }
            break;
        case TOP:
            usleep(500000);
            topTen(jugadores);
            usleep(500000);
            open_menu_1 ();
            break;
        case END:
            disp_clear();
            disp_update();
            break;
    }

}


// void menu_2 (int option){
    
//     switch (option){
//         case CONTINUE:
//             resume_game_logic ();
//             break;
//         case RESTART:
//             start_game_logic ();
//             break;
//         case QUIT:
//             open_menu_1();
//             break;
//     }

// }


void open_menu_1 (void){
    int option = menu(); // Funcion de Wainer y Sosa que me entrega que se oprime en el menu principal
    sleep(0.2);
    if (option){                    // Si recibo una opcion != 0 (osea que se oprimio una opcion)
        menu_1 (option);
    }
}


// void open_menu_2 (void){
//     int option = pause ();     // Funcion de Wainer y Sosa que me entrega que se oprime en el menu de pausa

//     if (option){            // Si recibo una opcion != 0 (osea que se oprimio una opcion)
//         menu_2 (option);
//     }
// }