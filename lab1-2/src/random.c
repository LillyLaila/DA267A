#include "random.h"
#include <esp_random.h>
#include <stdint.h>
#include <stdlib.h>

#define UINT32_MAX_FLOAT ((float)UINT32_MAX)


int getRandommsecs(int min, int max){
    uint32_t randomTal = esp_random();

    // Konverterar random tal till ett float mellan 0-1
    float randomFloat = (float)randomTal / UINT32_MAX_FLOAT;

    // Räknar ut ett random tal mellan min och max
    int randomsecs = min + (int)(randomFloat * (max - min + 1));

    return randomsecs;
}