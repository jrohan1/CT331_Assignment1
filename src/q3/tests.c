#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

void printChar(void *data) {
	printf("%c -> ", *((char*)data));
}

void printStr(void *data) {
	printf("%s -> ", (char*)data);
}

void printInt(void *data) {
	printf("%d -> ", *((int*)data));
}

void printDouble(void *data) {
	printf("%lf -> ", *((double*)data));
}
void runTests() {
	printf("Tests running...\n");

	//testing char print function and traverse
	listElement* l = createEl("Test String (1).", 30, &printStr);
	traverse(l);
	printf("\n");

	//Test insert after
	char x = 'x';
	int y = 50;
	double z = 100.00;

	listElement *l2 = insertAfter(l, &x, sizeof(char), &printChar);
	listElement *l3 = insertAfter(l2, &y, sizeof(y), &printInt);
	listElement *l4 = insertAfter(l3, &z, sizeof(z), &printDouble);
 	traverse(l);
	printf("\n");
	
	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");

	// Test length
	printf("Test length of list=%d\n\n", length(l));
	printf("\n");

	//Test pushing to the head of the list
	int num = 100;
	push(&l, &num, sizeof(int), &printInt);
	traverse(l);
	printf("\n");

	//Test popping
	listElement* node = pop(&l);
	freeListElement(node);
	traverse(l);
	printf("\n");

	//Test enqueuing
	push(&l, "a new string (0)", 30, &printStr);
	traverse(l);
	printf("\n");

	//Test dequeue
	node = dequeue(&l);
	traverse(l);
	freeListElement(node);
	printf("\n");

	printf("\nTests complete.\n");
}