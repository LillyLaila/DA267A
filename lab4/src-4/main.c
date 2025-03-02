#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"
#include "double_linked_list.h"

void app_main()
{
    struct singleLinkedList myList;
    initSingleLinkedList(&myList);

    printf("\n!!!!!!Printing SingleLinkedLists!!!!!!\n");

//Test1 lägga till elements och sortera, minst till högst
    printf("After adding 5 elements to the list: \n");

    addElementSingleLinkedList(&myList, 2);
    addElementSingleLinkedList(&myList, 6);
    addElementSingleLinkedList(&myList, 1);
    addElementSingleLinkedList(&myList, 9);
    addElementSingleLinkedList(&myList, 4);
    printTheWholeList(&myList);

//Test2 tar bort den första elementen från listan  
    printf("After removing the first element from the list: \n");

    removeFirstElementSingleLinkedList(&myList);
    printTheWholeList(&myList);

//Test3 tar bort den sista elementen från listan 
    printf("After removing the last element from the list: \n");
    removeLastElementSingleLinkedList(&myList);
    printTheWholeList(&myList);


    printf("\n!!!!!!Printing DoubleLinkedLists!!!!!!\n");

    struct doubleLinkedList minLista;
    initDoubleLinkedList(&minLista);

//Test1 lägga till elements och sortera, minst till högst
    printf("After adding 5 elements to the list: \n");

    addElementDoubleLinkedList(&minLista, 6);
    addElementDoubleLinkedList(&minLista, 3);
    addElementDoubleLinkedList(&minLista, 1);
    addElementDoubleLinkedList(&minLista, 8);
    addElementDoubleLinkedList(&minLista, 5);
    printTheWholeListDouble(&minLista);


//Test2 tar bort den första elementen från listan  
    printf("After removing the first element from the list: \n");

    removeFirstElementDoubleLinkedList(&minLista);
    printTheWholeListDouble(&minLista);

//Test3 tar bort den sista elementen från listan 
    printf("After removing the last element from the list: \n");
    removeLastElementDoubleLinkedList(&minLista);
    printTheWholeListDouble(&minLista);


}