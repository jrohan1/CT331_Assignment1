#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  // Test length
  printf("Test length of list=%d\n\n", length(l));

  //Test pushing to the head of the list
  push(&l, "a string (0)", 30);
  traverse(l);
  printf("\n");

  //Test popping
  listElement* node = pop(&l);
  traverse(l);
  freeListElement(node);
  printf("\n");

  //Test enqueuing
  push(&l, "a new string (0)", 30);
  traverse(l);
  printf("\n");

  //Test dequeue
  node = dequeue(&l);
  traverse(l);
  freeListElement(node);
  printf("\n");

  printf("\nTests complete.\n");
}
