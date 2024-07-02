#ifndef CONFIG_H
#define CONFIG_H

//hola
#define LANES_COUNT 16
#define MAX_OBJECTS_PER_LANE 5


#if !defined(PC) && !defined(RPI)
    #define RPI
#endif

#if defined(PC)
    #define LANE_X_PIXELS (TOTAL_WIDTH)
    #define LANE_Y_PIXELS ((int32_t)REZISE(NORMAL_SIZE * LANES_COUNT))
    #define MS_RANITA_MOVEMENT_COOLDOWN 20
    #define MS_BASE_OBJECT_SPEED 30
    #define TIME_PER_LEVEL_MS 30000

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
    #define MS_BASE_OBJECT_SPEED 400
    #define TIME_PER_LEVEL_MS 32000

#else
    #error "No platform defined"
#endif



#define LANE_PIXEL_HEIGHT (LANE_Y_PIXELS/LANES_COUNT)
#define CELL_PIXEL_WIDTH (LANE_X_PIXELS / )
#endif
