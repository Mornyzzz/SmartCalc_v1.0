#include "queue.h"

queue_t *queue_create() {
  queue_t *queue = calloc(1, sizeof(queue_t));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

void queue_push(queue_t *queue, char *data) {
  queue_node_t *new_node = calloc(1, sizeof(queue_node_t));
  new_node->data = malloc(strlen(data) + 1);
  strcpy(new_node->data, data);
  new_node->next = NULL;
  if (queue->tail == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
  queue->size++;
}

char *queue_pop(queue_t *queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  queue_node_t *old_head = queue->head;
  char *data = old_head->data;
  queue->head = old_head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  queue->size--;
  free(old_head);
  return data;
}

char *queue_peek(queue_t *queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  return queue->head->data;
}

// void queue_print(queue_t *queue) {
//     queue_node_t *current = queue->head;
//     while (current != NULL) {
//         printf("%s ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }
//
// int queue_size(queue_t *queue) {
//     return queue->size;
// }

void queue_destroy(queue_t *queue) {
  while (queue->head != NULL) {
    queue_node_t *old_head = queue->head;
    queue->head = old_head->next;
    free(old_head->data);
    free(old_head);
  }
  free(queue);
}

int queue_is_empty(queue_t *queue) { return queue->size == 0; }
