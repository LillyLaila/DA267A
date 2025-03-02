#include <stdio.h>
#include <stdlib.h>
#include <esp32/rom/ets_sys.h>
#include "circular_buffer.h"

/*
 * Change the value of BUFFER_SIZE if you want to change the size of the buffer.
 */
#define BUFFER_SIZE 4
#define INT_MIN 0

// Den här metoden lägger till en element och tar bort en element.
// Därefter kontrollerar man ifall elementen som tas bort o läggs till är densamma.
void blackBox_1()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 1);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);


    int removedElement1 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    if (addElements1 == removedElement1)
    {
        printf("\nElementen som lades till och togs bort är på rätt ordning \n");
    }
    else
    {
        printf("\nElementen som lades till och togs bort är inte samma\n");
    }

    free(buffer_data);
}

// Den här metoden lägger till en element, och sedan en annan element med ett annat värde, tar bort en element, tar bort en annan element,
// Därefter kontrolleras att elementen som togs bort och lades till är på rätt ordning.
void blackBox_2()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 1);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);


    int addElements2 = addElement(&buffer, 2);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);


    int removedElement1 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    int removedElement2 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    if (addElements1 == removedElement1 && addElements2 == removedElement2)
    {
        printf("\nElementen som lades till och togs bort är på rätt ordning \n");
    }
    else
    {
        printf("\nElementen som lades till och togs bort är inte samma\n");
    }

    free(buffer_data);
}

void blackBox_3()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    for(int i=1; i<BUFFER_SIZE; i++) {
    addElement(&buffer, i);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);
    }

    for(int i = 1;i < BUFFER_SIZE;i++) {
        removeValue(&buffer, i);
        printf("\n I bufferten togs elementen bort \n");
        printBuffer(&buffer);

    }

/*
    int addElements1 = addElement(&buffer, 23);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);
    int addElements2 = addElement(&buffer, 43);
    printf("\n I bufferten lades till en element: \n");
    printBuffer(&buffer);
    int addElements3 = addElement(&buffer, 11);
    printf("\n I bufferten lades till 3 element sammanlagt (Bufferten har endast plats för 3 element): \n");
    printBuffer(&buffer);

    int removedElement1 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);
    int removedElement2 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);
    int removedElement3 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    if (addElements1 == removedElement1 && addElements2 == removedElement2 && addElements3 == removedElement3)
    {
        printf("\nElementen som lades till och togs bort är på rätt ordning \n");
    }
    else
    {
        printf("\nElementen som lades till och togs bort är inte samma\n");
    }
    */

    free(buffer_data);
}

void blackBox_4()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

       for (int i = 1; i < BUFFER_SIZE +1 ; i++){
        addElement(&buffer, i);
        printBuffer(&buffer);
    }
    for (int i = 1; i < BUFFER_SIZE +1 ; i++){
    removeValue(&buffer, i);
    printBuffer(&buffer);
    }
    free(buffer_data);
}

// Den här metoden har lägger till mer element i bufferten än storleken och sedan kontrollerar ifall de tas bort i rätt ordning.
void blackBox_5()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 1);
    int addElements2 = addElement(&buffer, 2);
    int addElements3 = addElement(&buffer, 3);
    int addElements4 = addElement(&buffer, 4);
    printf("\n I bufferten lades till 4 element (Bufferten har endast plats för 3 element): \n");
    printBuffer(&buffer);

    int removedElement1 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    int removedElement2 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    int removedElement3 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    int removedElement4 = removeHead(&buffer);
    printf("\nI bufferten efter att man har tagit bort en element: \n");
    printBuffer(&buffer);

    if (addElements1 == removedElement1 && addElements2 == removedElement2 && addElements3 == removedElement3 && addElements4 == removedElement4)
    {
        printf("\nElementen som lades till och togs bort är på rätt ordning \n");
    }
    else
    {
        printf("\nElementen som lades till och togs bort är inte samma\n");
    }
    free(buffer_data);
}

// Den här metoden kör contains() metoden i en tom buffert och kollar om den returnerar INT_MIN
void blackBox_6()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int containsmetod = contains(&buffer, 1);
    printf("\n Bufferten innehåller: ");
    printBuffer(&buffer);

    free(buffer_data);
}

// Den här metoden lägger en element till bufferten och sedan kollar om bufferten innehåller en element med samma värde.
void blackBox_7()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 1);
    printf("\n I bufferten lades till: \n");
    printBuffer(&buffer);

    printf("\n Bufferten innehåller: ");
    int containsmetod = contains(&buffer, 1);
    if (containsmetod == INT_MIN)
    {
        printf("\n Bufferten innehåller inte det värdet \n");
    }
    else
    {
        printf("\n Buffert innehåller: %d \n" + containsmetod);
    }

    free(buffer_data);
}

// Den här metoden lägger till två element. Sedan kollar man ifall bufferten innehåller värdet på den andra elementen som du la till.
void blackBox_8()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 1);
    int addElements2 = addElement(&buffer, 2);
    printf("\n I bufferten lades till: \n");
    printBuffer(&buffer);

    int containsmetod = contains(&buffer, 2);
    if (containsmetod == INT_MIN)
    {
        printf("\n Bufferten innehåller inte det värdet \n");
    }
    else
    {
        printf("\n Buffert innehåller: %d \n" + containsmetod);
    }
    free(buffer_data);
}

// Den här metoden ger buffert elementerna olika värden
void blackBox_9()
{
    struct circularBuffer buffer;
    int buffer_data = (int)malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    int addElements1 = addElement(&buffer, 35);
    int addElements2 = addElement(&buffer, 77);
    int addElements3 = addElement(&buffer, 3);

    printf("\n I bufferten lades till: \n");
    printBuffer(&buffer);

    int containsmetod = contains(&buffer, 3);
    if (containsmetod == INT_MIN)
    {
        printf("\n Bufferten innehåller inte det värdet \n");
    }
    else
    {
        printf("\n Buffert innehåller: %d \n" + containsmetod);
    }

    free(buffer_data);
}

void app_main()
{
     //printf("Testar BlackBox test 1:\n");
     //blackBox_1();

    // printf("Testar BlackBox test 2:\n");
     //blackBox_2();

     printf("\nTestar BlackBox test 3: \n");
     blackBox_3();

     //printf("\nTestar BlackBox test 4: \n");
     //blackBox_4();

    // printf("\nTestar BlackBox test 5: \n");
    // blackBox_5();

    // printf("\nTestar BlackBox test 6: \n");
    // blackBox_6();

    // printf("\nTestar BlackBox test 7: \n");
    //  blackBox_7();

   // printf("\nTestar BlackBox test 8: \n");
    //blackBox_8();

    // printf("\nTestar BlackBox test 9: \n");
    // blackBox_9();
}
