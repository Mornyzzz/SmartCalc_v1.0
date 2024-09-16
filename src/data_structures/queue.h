#ifdef QUEUE_H
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node {
  char *data;
  struct queue_node *next;
} queue_node_t;

typedef struct queue {
  queue_node_t *head;
  queue_node_t *tail;
  int size;
} queue_t;

queue_t *queue_create();
void queue_push(queue_t *queue, char *data);
char *queue_peek(queue_t *queue);
char *queue_pop(queue_t *queue);
// int queue_size(queue_t *queue);
void queue_destroy(queue_t *queue);
// void queue_print(queue_t *queue);
int queue_is_empty(queue_t *queue);

#ifdef QUEUE_H
}
#endif