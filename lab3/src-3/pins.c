#include <soc/adc_channel.h>
#include <driver/gpio.h>
#include "driver/gptimer.h"
#include <esp_task_wdt.h>
#include <esp_adc/adc_oneshot.h>
#include "esp_timer.h"
#include "rom/ets_sys.h"


#define LED_PINA 12
#define LED_PINB 13
#define BUTTON_PIN 18
#define ESP_INTR_FLAG_DEFAULT 0
#define debounceTime 250000 //250ms
static uint64_t lastPressTime = 0;
static uint64_t prevDebounceTime = -debounceTime;
//static int LED_PINA 



/* Initierar led pins */
void initLEDPin()
{
    printf("Led pins init..!\n");

    // Initialize the 2 LEDs pins as output
    gpio_config_t ledConfig;
    ledConfig.pin_bit_mask = (((uint64_t)1 << LED_PINA | (uint64_t)1 << LED_PINB));
    ledConfig.mode = GPIO_MODE_OUTPUT;
    ledConfig.pull_down_en = 0;
    ledConfig.pull_up_en = 1;

    esp_err_t result = gpio_config(&ledConfig);
    esp_err_t gpio_config();

}

/* Initierar button pin */
void initButtonPin(uint8_t pinN)
{
    printf("Button init..!\n");
    //buttonConfig.GPIO_MODE_OUTPUT;
    gpio_config_t buttonConfig;
    buttonConfig.mode = GPIO_MODE_INPUT;
    buttonConfig.pin_bit_mask = (u_int64_t)1 << pinN;
    buttonConfig.pull_up_en = 1;
    buttonConfig.pull_down_en = 0;
    buttonConfig.intr_type = GPIO_INTR_NEGEDGE;

    gpio_config(&buttonConfig);

}

/* switches LED on if level!=0 or off if level==0*/
void setLEDpinA(uint8_t pinN, uint8_t level)
{
    if (level)
    {
        // PINA ON
        gpio_set_level(LED_PINA, 1);
    }
    else
    {
        // PINA OFF
        gpio_set_level(LED_PINA, 0);
    }

}
/* switches LED on if level!=0 or off if level==0*/
void setLEDpinB(uint8_t pinN, uint8_t level)
{
    if (level)
    {
        // PINB ON
        gpio_set_level(LED_PINB, 1);
    }
    else
    {
        // PINB OFF
        gpio_set_level(LED_PINB, 0);
    }

}


void flashLEDS(){
  setLEDpinA(LED_PINA, 1);
  setLEDpinB(LED_PINB, 1);
  vTaskDelay(50);
  setLEDpinA(LED_PINA, 0);
  setLEDpinB(LED_PINB, 0);
  vTaskDelay(50);
  setLEDpinA(LED_PINA, 1);
  setLEDpinB(LED_PINB, 1);
  vTaskDelay(50);
  setLEDpinA(LED_PINA, 0);
  setLEDpinB(LED_PINB, 0);
  vTaskDelay(50);
  setLEDpinA(LED_PINA, 1);
  setLEDpinB(LED_PINB, 1);
  vTaskDelay(50);
  setLEDpinA(LED_PINA, 0);
  setLEDpinB(LED_PINB, 0);
}



