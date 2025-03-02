#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "double_linked_list.h"

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
 * When adding an element to your double linked list, you have the choice to start either
 * from the beginning or the end of the list when searching for the position where to
 * insert a new element. It is up to you how to decide which search strategy to use.
 *
 *
 * Return values:
 *   'value' - If a new element with value 'value' successfully added to the list.
 *   INT_MIN (defined in limits.h) - If a new element could not be added to the list.
 */
int addElementDoubleLinkedList(struct doubleLinkedList *list, int value)
{
  struct doubleLinkedListElement *newElement = (struct doubleLinkedListElement *)malloc(sizeof(struct doubleLinkedListElement));
  if (newElement == NULL)
  {
    printf("The element could not be added to the list \n");
    return INT_MIN; // om denna är null å finns det inget minne att tilldela.
  }

  newElement->data = value;
  newElement->next = NULL;
  newElement->previous = NULL;

  if (list->first == NULL)
  {                           // kollar ifall listan är tom
    list->first = newElement; // om den är null så tilldelas den det nya värdet.
    list->last = newElement;
    return value;
  }
  if (value <= list->first->data)
  {                                 // kollar om det nya value är mindre eller lika med det som finns i listan
    newElement->next = list->first; // då läggs den först i listan
    list->first->previous = newElement;
    list->first = newElement;
    return value;
  }

  struct doubleLinkedListElement *currentElement = list->first;
  while (currentElement->next != NULL && currentElement->next->data < value)
  {
    currentElement = currentElement->next;
  }
  newElement->next = currentElement->next;
  if (currentElement->next != NULL)
  {
    currentElement->next->previous = newElement;
  }
  newElement->previous = currentElement;
  currentElement->next = newElement;
  if (currentElement == list->last) //om sista elementen läggs till .
  {
    list->last = newElement;
  }
  return value;

}


/*
 * This function should initialize the linked list structure that is given as
 * argument to the function, that is setting list->first and list->last to NULL
 */
void initDoubleLinkedList(struct doubleLinkedList *list)
{
  list->first = NULL;
  list->last = NULL;
}
/* 
 * This function should remove the first element in the linked list, i.e., list->first.
 * 
 * Don't forget to free memory (using free) of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeFirstElementDoubleLinkedList(struct doubleLinkedList *list)
{
  if(list->first == NULL) {
    printf("No element could be removed, the first element is empty! \n");
      return INT_MIN;
  }
    struct doubleLinkedListElement* removeFirstElement = list->first;

  int printList = list->first->data;

if(list->first == list->last ) {
  list->first =  NULL;
  list->last = NULL;
}
else{
  list->first = list->first->next;
  list->first->previous  = NULL;
}
  free(removeFirstElement);
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
int removeLastElementDoubleLinkedList(struct doubleLinkedList *list)
{
      if (list->last == NULL || list == NULL) {
        printf("List is empty! \n");
        return INT_MIN;
    }

    struct doubleLinkedListElement* removeLastElement = list->last;
    int printList = removeLastElement->data;

    if (list->first == list->last) {      //Om det finns endast ett element i listan
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = list->last->previous;
        list->last->next = NULL;
    }

    free(removeLastElement);
    return printList;
  
}


void printTheWholeListDouble(struct doubleLinkedList *list)
{

  if (list == NULL || list->first == NULL )
  {
    printf("There is nothing in the list, it's empty! \n");
    return;
  }

  struct doubleLinkedListElement *currentElement = list->first; // pointer till första elementen

  while (currentElement != NULL)
  {
    printf("%d ", currentElement->data);   // skriver ut det element som pointer är på
    currentElement = currentElement->next; // pointer flyttar
  }
  printf("\n");
}
