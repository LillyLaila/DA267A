#include "pins.h"
#include "driver/gpio.h"
#include <esp32/rom/ets_sys.h>


//initierar pins
void initPins()
{
    // init the 2 LEDs pins as output and the 2 buttons' pins as input
    // you will need to use gpio_config()
    gpio_config_t config;
    config.pin_bit_mask = (u_int64_t) 1 << 33; //led som output
    config.mode = GPIO_MODE_OUTPUT;
    config.pull_down_en = 0;
    config.pull_up_en = 0;
    gpio_config(&config);

    config.pin_bit_mask = (u_int64_t) 1 << 25; //led som output 
    config.mode = GPIO_MODE_OUTPUT;
    config.pull_down_en = 0;
    config.pull_up_en = 0;
    gpio_config(&config);

    config.pin_bit_mask = (u_int64_t) 1 << 27; //knapp som input
    config.mode = GPIO_MODE_INPUT;
    config.pull_down_en = 0;
    config.pull_up_en = 1;
    gpio_config(&config);

    config.pin_bit_mask = (u_int64_t) 1 << 26; //knapp som input 
    config.mode = GPIO_MODE_INPUT;
    config.pull_down_en = 0;
    config.pull_up_en = 1;
    gpio_config(&config);

}
/* switches LED A on if level!=0 or off if level==0*/
void setLEDA(uint8_t level)
{
    if (level)
    {
        gpio_set_level(33,1);
        // set the pin of LED A to ON
        // you probably need to use gpio_set_level()
    }
    else
    {
        gpio_set_level(33, 0);
        // set the pin of LED A to OFF
    }
}
/* switches LED B on if level!=0 or off if level==0*/
void setLEDB(uint8_t level)
{
    if (level){
        gpio_set_level(25,1);

    }
    else{
        gpio_set_level(25, 0);

    }
    // same as setLEDA()
}
/* tells if button A is currently being pressed */
uint8_t isButtonAPressed()
{
    //Om knapp är nertryckt returneras 1, annars returneras 0 
    if((gpio_get_level(26 ))==1){
        return 0;
        
    }
    else{ 
    printf("Knapp A!");
    return 1; 
}
}
/* tells if button A is currently being pressed */
uint8_t isButtonBPressed()
{
    // same as with button A, but another pin
    if((gpio_get_level(27 ))==1){
        return 0;
        
    }
    else{ 
    printf("Knapp B!");
    return 1; 
}
}