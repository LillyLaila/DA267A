#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "single_linked_list.h"
/* 
 * This function should add a new element with value 'value' to the argument linked list.
 * A new value should be added even if the list already contains an element with the 
 * argument value. 
 *
 * When adding elements, you should make sure that the linked list is sorted based on the
 * 'data' field in the linkedListElements, so that the element with smallest value is the
 * first element in the list, followed by the second smallest element, etc. 
 *
 * Please note that you need to dynamically allocate memory (using malloc or calloc) to 
 * your new element. 
 * 
 * Return values:
 *   'value' - If a new element with value 'value' successfully added to the list.
 *   INT_MIN (defined in limits.h) - If a new element could not be added to the list.
 */
int addElementSingleLinkedList(struct singleLinkedList *list, int value)
{

  // malloc metoden anväds för att dynamiskt tilldela en del av minnet med en specifierad storlek för en array. Den returnerar en pointer av typen void
  struct singleLinkedListElement *newElement = (struct singleLinkedListElement *)malloc(sizeof(struct singleLinkedListElement));
  if (newElement == NULL)
  {
    return INT_MIN; // om den e null så finns det inget minne att tilldela
  }

  newElement->data = value;
  newElement->next = NULL;

  if (list->first == NULL)
  {                           // kollar ifall den första elementen är null
    list->first = newElement; // om den är null så tilldelas den det nya värdet. Alltså
    return value;
  }

  if (value <= list->first->data) // om value som elementen har är mindre eller lika med de andra element
  {
    newElement->next = list->first; //då flyttas de till början av listan.
    list->first = newElement;
    return value;
  }

  struct singleLinkedListElement *currentElement = list->first;
  while (currentElement->next != NULL && currentElement->next->data < value) 
  {
    currentElement = currentElement->next;
  }
  newElement->next = currentElement->next;
  currentElement->next = newElement;
  return value;
}



/*
 * This function should initialize the linked list structure that is given as
 * argument to the function, that is setting list->first to NULL
 */

void initSingleLinkedList(struct singleLinkedList *list)
{
  list->first = NULL;
}

/*
 * This function should remove the first element in the linked list, i.e., list->first.
 *
 * Don't forget to free memory of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeFirstElementSingleLinkedList(struct singleLinkedList *list)
{
  if (list->first == NULL)
  {
    printf("The first element is empty: \n");
    return INT_MIN; // om den första elementen på listan är tom så tas inget bort
  }
  int printList = list->first->data;                         //lagra hela listan i denna variablen
  struct singleLinkedListElement *elemenToRemove = list->first; // lagrar en pointer till första elementen
  list->first = list->first->next; //
  free(elemenToRemove); // den tar bort minnet för den borttagna elementen.
  return printList;
}

/*
 * This function should remove the last element in the linked list.
 *
 * Don't forget to free memory (using free) of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeLastElementSingleLinkedList(struct singleLinkedList *list)
{

  if (list == NULL || list->first == NULL) 
  {
    printf("The list is empty! Nothing to remove! \n");
    return INT_MIN;
  }

  if (list->first->next == NULL) // kollar om det bara finns en element i listan
  {
    int printList1 = list->first->data; //skriver ut hela listan
    free(list->first);
    list->first = NULL; //gör listan null.
    return printList1;
  }

//Går igenom listan tills den hittar det element som har en granne som är null  
  struct singleLinkedListElement *current = list->first; 
  while (current->next->next != NULL) 
  {
    current = current->next;
  }

  int printList = current->next->data;
  free(current->next); //ta bort data av den elementen som togs bort. 
  current->next = NULL; // Lägger nästa pointerns till den näst-sista elementen till NULL.
  return printList;
}

void printTheWholeList(struct singleLinkedList *list)
{

  if (list == NULL || list->first == NULL)
  {
    printf("There is nothing in the list, it's empty!\n");
    return;
  }

  struct singleLinkedListElement *currentElement = list->first; // pointer till första element.

  while (currentElement != NULL)
  {
    printf("%d ", currentElement->data);   // skriver ut det element som pointern är på
    currentElement = currentElement->next; // pointer flyttas
  }
  printf("\n");
}
