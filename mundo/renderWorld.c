#include "../driv/disdrv.h"
#include "../driv/formas.h"
#include <stdio.h>
#include "renderWorld.h"

#define OFFSET(v) (11 - v)
#define OFFSET_y(v) (15 - v)
#define COORDENADA(x,y) ((dcoord_t) {x, y})

#define DIVISOR 4

int contador = 0;
int flag_parpadeo = 1;

void renderWorld (map_t * map, independent_object_t * frog[], int size, int tiempoRestante){
    disp_clear();
    int contador = (tiempoRestante * 1000 * 16)/TIME_PER_LEVEL_MS;
    
    verticalLine(contador, COORDENADA(0, 16 - contador));
    verticalLine(contador, COORDENADA(15, 16 - contador));
    
    int aux, existe, position;
    
    horizontalLine(12, (dcoord_t) {2, 15});

    for(int row = 0; row < LANES_COUNT; row++){
        if(map->lanes[row].kind == &empty_object || map->lanes[row].kind == NULL){
            continue;
        }
        for(int p = 0; p < MAX_OBJECTS_PER_LANE; p++){
            // TAMAÑO DEL OBJETO SI ES QUE LO HAY
            existe = map->lanes[row].objects[p].doesExist;
            position = map->lanes[row].objects[p].position;
            if(existe){
                aux = map->lanes[row].kind->hitbox_width;
            }    
            switch ((map->lanes[row]).background){
                case finish_line:
                    if (!existe)
                    {
                        disp_write(COORDENADA(OFFSET(position) + 2,OFFSET_y(row)), D_OFF);
                    }
                    break;

                case water:
                    horizontalLine(12,COORDENADA(2, OFFSET_y(row)));
                    // *********************************************************************************
                    // *********************************************************************************
                    
                    if(existe && OFFSET(position) < 12){
                        for(int led = 0; led < aux; led++){
                            if((position + led < 12)){
                                disp_write(COORDENADA(OFFSET(position) - led + 2, OFFSET_y(row)), D_OFF);
                            }else{
                                led = aux;
                            }
                        }
                    }
                    
                    // if(existe && OFFSET(position) < 12){
                    //     if(aux + position + 1 < 12){
                    //             horizontalLineOff(aux, COORDENADA(OFFSET(position) + 2, OFFSET_y(row)));
                    //     }else{
                    //         horizontalLineOff(12 - position, COORDENADA(OFFSET(position) + 2, OFFSET_y(row)));
                    //     }
                    // }

                    // *********************************************************************************
                    // *********************************************************************************
                    break;
                default:
                    // *********************************************************************************
                    // *********************************************************************************
                    
                    if(existe && OFFSET(position) < 12){
                        for(int led = 0; led < aux; led++){
                            if((position + led < 12)){
                                disp_write(COORDENADA(OFFSET(position) + 2 - led, OFFSET_y(row)), D_ON);
                            }else{
                                led = aux;
                            }
                        }
                    }
                    // if(existe && OFFSET(position) < 12){
                    //     if(aux + position + 1 < 12){
                    //         horizontalLine(aux, COORDENADA(OFFSET(position) + 2, OFFSET_y(row)));
                    //     }else{
                    //         horizontalLine(LANE_X_PIXELS - position, COORDENADA(OFFSET(position) + 2, OFFSET_y(row)));
                    //     }
                    // }

                    // *********************************************************************************
                    // *********************************************************************************
                    break;
            }
        }
    }

    if (frog == NULL){

    }else{
        for(int i = 0; i < size; i++){
            if(flag_parpadeo){
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_ON);
            }else{
                disp_write((dcoord_t) {OFFSET(frog[i]->values.position + 2), OFFSET_y(frog[i]->y_position)}, D_OFF);
            }
            flag_parpadeo = !flag_parpadeo;
        } 
   
    
    }


    disp_update();
}