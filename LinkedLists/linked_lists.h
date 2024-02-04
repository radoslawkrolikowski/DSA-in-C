#ifndef LINKED_LISTS_TYPES_
#define LINKED_LISTS_TYPES_

#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct LinkedLists {
	int size;
	Node *head;
} LinkedLists;

// make_node creates a new Node with a value, allocates the memory 
// for the node and returns the pointer
static Node* make_node(int value);

// make_linked_lists creates an empty LinkedLists, allocate the memory
// and returns the pointer
LinkedLists* make_linked_lists();

// size function returns the number of nodes in the linked lists
int size(LinkedLists *list);

// empty function returns tue if empty, false otherwise
bool empty(LinkedLists *list);

// push_front adds an item to the front of the list
void push_front(LinkedLists *list, int value);

// push_back adds an item to the end of the list
void push_back(LinkedLists *list, int value);

// front function writes the front value to a pointer result argument
// and returns 0; if list is empty it returns -1
int front(LinkedLists *list, int *result);

// back function writes the last value to a pointer result argument
// and returns 0; if list is empty it returns -1
int back(LinkedLists *list, int *result);

// value_at function returns the value at given index if index exists,
// otherwise it returns -1
int value_at(LinkedLists *list, int index);

// pop_front removes the front item, writes its value to a pointer
// result argument and returns 0; if list is empty it returns -1
int pop_front(LinkedLists *list, int *result);

// pop_back removes the last item, writes its value to a pointer
// result argument and returns 0; if list is empty it returns -1
int pop_back(LinkedLists *list, int *result);

// value_n_from_end writes the value of the nth node from the end
// of the list into a pointer result argument and returns 0;
// if list is empty or incorrect n provided, it returns -1
int value_n_from_end(LinkedLists *list, int n, int *result);

// insert function inserts a new node at given position and
// returns 0 if operation was succesful, -1 otherwise
int insert(LinkedLists *list, int index, int value);

// remove_value function removes the first item in the list
// with this value
void remove_value(LinkedLists *list, int value);

// reverse function reverses the linked list
void reverse(LinkedLists *list);

// delete_node function removes the node at given index
void delete_node(LinkedLists *list, int index);

// print_list function prints the contents of the list
void print_list(LinkedLists *list);

// destroy_list function releases the memory for all the nodes
//  and the LinkedLists struct
void destroy_list(LinkedLists *list);

// allocateMemoryError prints the error message and exits
void allocateMemoryError(void);

#endif // LINKED_LISTS_TYPES_
