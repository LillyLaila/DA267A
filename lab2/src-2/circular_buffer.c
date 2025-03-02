#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"



void initCircularBuffer(struct circularBuffer* bufferPtr, int* data, int maxLength) {
  bufferPtr->data = data;
  bufferPtr->head = 0;
  bufferPtr->tail = 0;
  bufferPtr->maxLength = maxLength;
}
/* 
 * This function should check if the buffer pointed to by bufferPtr
 * contains one or more elements with the value specified by the 
 * 'value' argument.
 *
 * The function should return:
 *  - 'value' if the an element with the argument value was found in the queue.
 *  - INT_MIN (defined in limits.h) if value was not found.
 */ 
int contains(struct circularBuffer* bufferPtr, int value) {

  
  for (int count = 0; count < bufferPtr->maxLength; count++) {
    if (bufferPtr->data[count] == value) {
      return value;
    }
  }
  return INT_MIN; // Value not found
}
/*
 * This function should add the value specified by the 'value' 
 * argument at the tail of the buffer.
 *
 * The function should return:
 *  - 'value' if the value was successfully added to the queue.
 *  - INT_MIN (defined in limits.h) if the value was not added.
 */
int addElement(struct circularBuffer* bufferPtr, int value) {
  if ((bufferPtr->tail + 1) % bufferPtr->maxLength == bufferPtr->head) {
    // Buffer is full
    return INT_MIN;
  }

  bufferPtr->data[bufferPtr->tail] = value;
  bufferPtr->tail = (bufferPtr->tail + 1) % bufferPtr->maxLength;
  return value;
}

int removeValue(struct circularBuffer* bufferPtr, int value){
  int removed = 0;
  for (int count = 0; count < bufferPtr->maxLength; count++) {
    if (bufferPtr->data[count] == value) {
      // Shift elements to remove the value
      for (int i = count; i < bufferPtr->tail - 1; i++) {
        bufferPtr->data[i] = bufferPtr->data[i + 1];
      }
      bufferPtr->tail = (bufferPtr->tail - 1 + bufferPtr->maxLength) % bufferPtr->maxLength;
      removed = 1;
    }
  }
  return removed ? value : INT_MIN;
}

int removeHead(struct circularBuffer* bufferPtr) {
  if (bufferPtr->head == bufferPtr->tail) {
    // Buffer is empty
    return INT_MIN;
  }

  int value = bufferPtr->data[bufferPtr->head];
  bufferPtr->head = (bufferPtr->head + 1) % bufferPtr->maxLength;
  return value;
}

void printBuffer(struct circularBuffer* bufferPtr) {
  printf("Circular Buffer: ");
  int current = bufferPtr->head;
  while (current != bufferPtr->tail) {
    printf("%d ", bufferPtr->data[current]);
    current = (current + 1) % bufferPtr->maxLength;
  }
  printf("\n");

  printf("Header : %d\n", bufferPtr->head);
  printf("tail : %d\n", bufferPtr->tail);
}







