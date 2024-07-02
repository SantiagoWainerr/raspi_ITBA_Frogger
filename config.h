#ifndef CONFIG_H
#define CONFIG_H

//hola
#define LANES_COUNT 16
#define MAX_OBJECTS_PER_LANE 5


#if !defined(PC) && !defined(RPI)
    #define RPI
#endif

#if defined(PC)
    #define LANE_X_PIXELS (LANES_COUNT * 1)
    #define LANE_Y_PIXELS (LANES_COUNT * 1)
    #define MS_RANITA_MOVEMENT_COOLDOWN 100

#elif defined(RPI)
    #define LANE_X_PIXELS 12
    #define LANE_Y_PIXELS 16
    #define ENDSLOT_1 2
    #define ENDSLOT_2 4
    #define ENDSLOT_3 6
    #define ENDSLOT_4 8
    #define ENDSLOT_5 10
    #define LILYPAD_SIZE 1
    #define MS_RANITA_MOVEMENT_COOLDOWN 100

#else
    #error "No platform defined"
#endif


#define TIME_PER_LEVEL_MS 32000
#define LANE_PIXEL_HEIGHT (LANE_Y_PIXELS/LANES_COUNT)
#define CELL_PIXEL_WIDTH (LANE_X_PIXELS / )
#endif
