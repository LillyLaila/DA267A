#include "sampler.h"
#include <stdio.h>
#include <esp_task_wdt.h>
#include "driver/gpio.h"
#include <esp_timer.h>
#include "notes.h"
#include "pins.h"

//--------------------Main klassen-----------------
//
#define LED_PINA 12
#define LED_PINB 13
#define BUTTON_PIN 18
#define MICROPHONE_PIN 32
#define ESP_INTR_FLAG_DEFAULT 0
#define debounceTimeForButton 250000 // 250ms. Om det går mindre än 250ms mellan knapptrycket så ignoreras det

float targetfrequencies[6] = {329.63f, 246.94f, 196.00f, 146.83f, 110.00f, 82.41f}; // en array av alla frekvenser för varje gitarr string.
int currentString = 0;                                                              // Index of the currently tuned string

static uint64_t prevdebounceTimeForButton = -debounceTimeForButton; // kontrollerar tiden sen det senaste knapptrycket.
static volatile float fr;

/*
 * Den här metoden är en set-metod som kollar om frekvensen är större eller likamed minsta och även mindre eller likamed det största.
 * Om den är det så anropas LEDpinA och även LEDpinB.
 */
void setLEDAB(float frequence, float min, float max)
{
   if (frequence >= min && frequence <= max)
   {
      setLEDpinA(LED_PINA, 1);
      setLEDpinB(LED_PINB, 1);
   }
   else if (frequence < min)
   {
      setLEDpinA(LED_PINA, 1);
   }
   else if (frequence > max)
   {
      setLEDpinB(LED_PINB, 1);
   }
}

/*
 * Den här metoden tar hand om knapptryckningen - kollar om det har gått tillräckligt med tid sen det senaste knapptrycket och tilldelar det de nya värdet
 * Disablar också interrups för pin och aktiverar den igen.*/
static void buttonPress_handler(void *arg)
{
   uint64_t CurrentTime = esp_timer_get_time();
   if ((CurrentTime - prevdebounceTimeForButton) > debounceTimeForButton)
   {
      prevdebounceTimeForButton = CurrentTime;
      if (currentString < 5)
      {
         currentString++; // går till nästa string.
      }
      else if (currentString == 5)
      {
         currentString = 0;
      }
   }
}

void app_main()
{

   initLEDPin();              // init Ledpins
   initButtonPin(BUTTON_PIN); // initierar buttonpins
   // en ISR-service för GPIO-interrupts. lägger till en isr för en specifik gpio-pin, (knappen)
   // För att kunna hantera och reagera på knapptryckningar och
   gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
   gpio_isr_handler_add(BUTTON_PIN, buttonPress_handler, NULL);
   vTaskDelay(pdMS_TO_TICKS(4000));

   flashLEDS(); //flash led lights 3 times. 

   while (1)
   {
      setLEDpinA(LED_PINA, 0);
      setLEDpinB(LED_PINB, 0);

      vTaskDelay(pdMS_TO_TICKS(2000));
      printf("\n!!!!!!!Starting test!!!!!!!!!\n");

      startSampling(6000);
      vTaskDelay(pdMS_TO_TICKS(1000));

      stopSampling();
      fr = getFrequency();

      // String: 1 (E), frequence: 329.63 Hz, Note: E4
      if (currentString == 0)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target");
         printf("Note E4 \n");
         setLEDAB(fr, 326.63, 332.63);

         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
      // String: 2 (B), frequence: 246.94 Hz, Note: B3
      else if (currentString == 1)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target\n");
         printf("Note B3 \n");
         setLEDAB(fr, 243.94, 249.94);

         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
      // String: 3 (G), frequence: 196.00 Hz, Note: G3
      else if (currentString == 2)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target\n");
         printf("Note G3 \n");
         setLEDAB(fr, 193.00, 199.00);
         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
      // String: 4 (D), frequence: 146.83 Hz, Note: D3
      else if (currentString == 3)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target\n");
         printf("Note D3 \n");
         setLEDAB(fr, 143.83, 149.83);
         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
      // String: 5 (A), frequence: 110.00 Hz, Note: A2
      else if (currentString == 4)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target\n");
         printf("Note A2 \n");
         setLEDAB(fr, 107.00, 113.00);
         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
      // String: 6 (E), frequence: 82.41 Hz, Note: E2
      else if (currentString == 5)
      {
         printf("--------------\n");
         printf("if blue lights -> the note is low, red -> note high, together -> close to target\n");
         printf("Note E2 \n");
         setLEDAB(fr, 79.41, 85.41);
         printf("frequence is: %.2f\n\n", fr);
         printf("--------------\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         resetSampling();
      }
   }
}
