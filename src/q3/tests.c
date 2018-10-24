#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"


void runTests() {
	printf("Tests running...\n");

	//char c = 'c';
	//listElement* l = createEl(&c, sizeof(char), &printChar);
	listElement* l = createEl("Test String.", 30, &printStr);
	traverse(l);
	printf("\n");

	//Test insert after
	char x = 'x';
	listElement *l2 = insertAfter(l, &x, sizeof(char), &printChar);
	traverse(l);
	printf("char inserted \n\n");

	int y = 50;
	listElement *l3 = insertAfter(l2, &y, sizeof(int), &printInt);
	traverse(l);
	printf("int inserted \n\n");

	double z = 100.00;
	listElement *l4 = insertAfter(l3, &z, sizeof(double), &printDouble);
	traverse(l);
	printf("double inserted \n\n");	
 	
	
	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("element after given el deleted\n\n");

	// Test length
	printf("Test length of list=%d\n\n", length(l));
	printf("\n");

	//Test pushing to the head of the list
	int num = 100;
	push(&l, &num, sizeof(int), &printInt);
	traverse(l);
	printf("int pushed to head of list \n\n");

	//Test popping
	listElement* node = pop(&l);
	freeListElement(node);
	traverse(l);
	printf("int popped from head of list\n\n");

	//Test enqueuing
	enqueue(&l, "a new string (0)", 30, &printStr);
	traverse(l);
	printf("a string enqueued to head of list\n\n");

	//Test dequeue
	node = dequeue(&l);
	traverse(l);
	freeListElement(node);
	printf("element dequeued from tail of list\n\n");

	printf("\nTests complete.\n");
}