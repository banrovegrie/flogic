#include "node.h"

/**
 * Here, my_dll is double linked list structure with a pointer to root.
 * Functionalities implemented:
 * insert(list, x) - insert a node at the end of the list
 * insert_at(list, x, i) - insert a node at the i-th position
 * del(list, i) - delete the node at the i-th position
 * find(list, x) - return pos of first occurrence of x in list else return -1
 * print(list) - print the list
 * prune(list) - delete all nodes at odd indexes
 * print_reverse(list) - print the list in reverse order
 * get_size(list) - return the size of the list
 */

struct my_dll {
  struct node *root;
};

void insert(struct my_dll *dll, int data);

void insert_at(struct my_dll *dll, int data, int i);

void del(struct my_dll *dll, int i);

int find(struct my_dll *dll, int x);

void print(struct my_dll *dll);

void prune(struct my_dll *dll);

void print_reverse(struct my_dll *dll);

int get_size(struct my_dll *dll);