#include "stack.h"

stack_t *stack_create() {
  stack_t *stack = calloc(1, sizeof(stack_t));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void stack_push(stack_t *stack, char *data) {
  stack_node_t *new_node = calloc(1, sizeof(stack_node_t));
  new_node->data = malloc(strlen(data) + 1);
  strcpy(new_node->data, data);
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

// void stack_print(stack_t *stack) {
//     stack_node_t *current = stack->top;
//     while (current != NULL) {
//         printf("%s ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

char *stack_pop(stack_t *stack) {
  if (stack->top == NULL) {
    return NULL;
  }
  stack_node_t *old_top = stack->top;
  char *data = old_top->data;
  stack->top = old_top->next;
  stack->size--;
  free(old_top);
  return data;
}

int stack_is_empty(stack_t *stack) { return stack->top == NULL; }

char *stack_peek(stack_t *stack) {
  if (stack->top == NULL) {
    return NULL;
  }
  return stack->top->data;
}

// int stack_size(stack_t *stack) {
//     return stack->size;
// }

void stack_destroy(stack_t *stack) {
  while (stack->top != NULL) {
    stack_node_t *old_top = stack->top;
    stack->top = old_top->next;
    free(old_top->data);
    free(old_top);
  }
  free(stack);
}
