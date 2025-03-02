#include <esp_task_wdt.h>
#include "pins.h"
#include "random.h"

/*
Waits for "millis" milliseconds without upsetting the watchdog timer
*/
void waitMs(unsigned int millis)
{
    TickType_t delay = millis / portTICK_PERIOD_MS;
    vTaskDelay(delay);
}
void app_main()
{
    initPins();
    while (1)
    { 
    //Sålänge man exekverar koden så börjar man med att lysa båda LEDS
        setLEDA(1);
        setLEDB(1);
        waitMs(1000);
    //Därefter lyser de i 1 sekund ungefär och efter det så släcks de

        setLEDA(0);
        setLEDB(0);
    //Det visar att spelet börjar
    // Här hämtas en random duration mellan 3 och 5 sekunder mha metoden i random.c klassen
        int r = getRandommsecs(3000, 5000);
        waitMs(r);

    //LEDS lyser igen
        setLEDA(1);
        setLEDB(1);

        uint8_t winner = 0;
        
        while (!winner)
        { 
            //Om en knapp A eller B är nertryckt 
            if (isButtonAPressed())
            {
                winner = 1;
            }
            else if (isButtonBPressed())
            {
                winner = 2;

            }
        }

        if(winner == 1) {
            setLEDB(1); // LED B släcks
            setLEDA(0); //LED A tänds
            waitMs(3000);

        }
         if(winner == 2) {
             setLEDA(1); // LED A släcks
             setLEDB(0); //LED B tänds
             waitMs(3000);

        }

    

        waitMs(1000); //ändra detta till mindre antal sekunder.

        setLEDA(0);
        setLEDB(0);
        //När ett nytt spel ska börja så släcks LED-lamporna och börjar om i while loopen


    }
}
