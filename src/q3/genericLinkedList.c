#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"


//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memcpy(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->printFunction = printFunction;
	e->next = NULL;
	return e;
}
void printChar(void* data)
{
	printf("%c\n", *(char*)data);
}
void printStr(void* data)
{
	printf("%s\n", (char*)data);
}
void printInt(void* data)
{
	printf("%d\n", *(int*)data);
}
void printDouble(void* data)
{
	printf("%lf\n", *(double*)data);
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current->printFunction(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size,void* printFunction) {
	listElement* newEl = createEl(data, size, printFunction);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

// Returns the number of elements in a linked list
int length(listElement* list) {
	
	if (list == NULL) {
		return 0;
	}
	else {
		return length(list->next) + 1;
	}
}


//Push a new element onto the head of a list
void push(listElement** list, void* data, size_t size, void* printFunction) {
	// create a new element and inset at head of the list
	listElement* newHead = createEl(data, size, printFunction);
	newHead->next = *list;
	*list = newHead;
}

//Pop an element from the head of a list
listElement* pop(listElement** list) {
	// check if list is empty
	if (list == NULL) {
		return NULL;
	}
	listElement* oldHead = *list;
	*list = oldHead->next;
	oldHead->next = NULL;
	return oldHead;
}

//Enqueue a new element onto the head of the list
void enqueue(listElement** list, void* data, size_t size, void* printFunction) {
	// create a new element and inset at head of the list
	listElement* newHead = createEl(data, size, printFunction);
	newHead->next = *list;
	*list = newHead;
}

//Dequeue an element from the tail of the list, and return that element
listElement* dequeue(listElement** list) {
	
	// check if list is empty
	if (list == NULL) {
		return NULL;
	}

	// Find tail of list and the element befor it
	listElement* tail = *list;
	listElement* newTail = NULL;

	while (tail->next != NULL) {
		newTail = tail;
		tail = tail->next;
	}
	// Remove tail from the list
	newTail->next = NULL;
	return tail;
}

void freeListElement(listElement* delete) {
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}
