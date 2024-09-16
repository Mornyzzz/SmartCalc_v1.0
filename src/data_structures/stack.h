#ifdef STACK_H
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node {
  char *data;
  struct stack_node *next;
} stack_node_t;

typedef struct stack {
  stack_node_t *top;
  int size;
} stack_t;

stack_t *stack_create();
void stack_push(stack_t *stack, char *data);
char *stack_pop(stack_t *stack);
char *stack_peek(stack_t *stack);
// int stack_size(stack_t *stack);
void stack_destroy(stack_t *stack);
int stack_is_empty(stack_t *stack);
// void stack_print(stack_t *stack);

#ifdef STACK_H
}
#endif