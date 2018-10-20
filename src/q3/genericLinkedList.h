#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct {
	void* data;
	size_t size;
	void(*printFunction)(void* data);
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void(*printer)(void*));

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void(*printer)(void*));

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list
int length(listElement *list);

//Pushes a new element onto the head of a list 
//Updates the list reference using side effects
void push(listElement** list, void* data, size_t size, void(*printer)(void*));

//Pops an element from the head of the list
//Updates the list reference using side effects 
listElement *pop(listElement **list);

//Enqueues a new element onto the head of the list
//Updates the list reference using side effects
void enqueue(listElement** list, void* data, size_t size, void(*printer)(void*));

//Dequeues an element from the tail of the list
listElement* dequeue(listElement** list);

// Free nodes
void freeListElement(listElement* delete);
#endif
