#ifndef INPUT_H
#define INPUT_H

typedef enum {EMPTY,  LEFT, RIGHT, PAUSE, UP, DOWN}dato_entrada;
dato_entrada input_reader (void);

#endif