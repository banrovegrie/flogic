#include "my_dll.h"

void insert(struct my_dll *dll, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;

  if (dll->root == NULL) {
    dll->root = new_node;
  } else {
    struct node *curr = dll->root;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
  }
};

void insert_at(struct my_dll *dll, int data, int i) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;

  if (dll->root == NULL) {
    dll->root = new_node;
  } else if (i == 0) {
    new_node->next = dll->root;
    dll->root->prev = new_node;
    dll->root = new_node;
  } else {
    struct node *curr = dll->root;
    int count = 1;
    while (curr->next != NULL && count < i) {
      curr = curr->next;
      count++;
    }
    if (count == i) {
      new_node->next = curr->next;
      curr->next = new_node;
      new_node->prev = curr;
      if (new_node->next != NULL) {
        new_node->next->prev = new_node;
      }
    }
  }
};

void del(struct my_dll *dll, int i) {
  if (dll->root == NULL) {
    return;
  } else if (i == 0) {
    dll->root = dll->root->next;
    dll->root->prev = NULL;
  } else {
    struct node *curr = dll->root;
    int count = 0;
    while (curr->next != NULL && count < i) {
      curr = curr->next;
      count++;
    }
    if (count == i) {
      if (curr->prev != NULL) {
        curr->prev->next = curr->next;
      }
      if (curr->next != NULL) {
        curr->next->prev = curr->prev;
      }
      free(curr);
    }
  }
};

int find(struct my_dll *dll, int x) {
  if (dll->root == NULL) {
    return -1;
  } else {
    struct node *curr = dll->root;
    int count = 0;
    while (curr->next != NULL && curr->data != x) {
      curr = curr->next;
      count++;
    }
    if (curr->data == x) {
      return count;
    } else {
      return -1;
    }
  }
};

void print(struct my_dll *dll) {
  if (dll->root == NULL) {
    return;
  } else {
    struct node *curr = dll->root;
    while (curr->next != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
    }
    printf("%d\n", curr->data);
  }
};

void prune(struct my_dll *dll) {
  if (dll->root == NULL) {
    return;
  } else {
    struct node *curr = dll->root;
    int count = 0;
    while (curr->next != NULL) {
      if (count % 2 == 1) {
        if (curr->prev != NULL) {
          curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
          curr->next->prev = curr->prev;
        }
      }

      curr = curr->next;
      count++;
    }

    if (count % 2 == 1) {
      if (curr->prev != NULL) {
        curr->prev->next = curr->next;
      }
      if (curr->next != NULL) {
        curr->next->prev = curr->prev;
      }
    }
  }
};

void print_reverse(struct my_dll *dll) {
  if (dll->root == NULL) {
    return;
  } else {
    struct node *curr = dll->root;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    while (curr->prev != NULL) {
      printf("%d ", curr->data);
      curr = curr->prev;
    }
    printf("%d\n", curr->data);
  }
};

int get_size(struct my_dll *dll) {
  if (dll->root == NULL) {
    return 0;
  } else {
    struct node *curr = dll->root;
    int count = 0;
    while (curr->next != NULL) {
      curr = curr->next;
      count++;
    }
    return count + 1;
  }
};