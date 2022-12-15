/*
** CODEWARS PROJECT, 2022
** queue_list.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct {
  node_t *first;
  node_t *last;
} tail_t;

bool queue_empty(const tail_t *queue) {
  return queue->first == 0; // when nobody is at front of the queue
}
void queue_enqueue(tail_t *queue, int data) {
  bool was_empty = queue_empty(queue);
  node_t *ptrnode = malloc(sizeof(node_t));
  ptrnode->data = data;
  ptrnode->next = NULL;
  if (!was_empty) queue->last->next = ptrnode; // link tail
  queue->last = ptrnode;
  if (was_empty) queue->first = ptrnode;
}
int queue_dequeue(tail_t *queue)
{
  node_t *ptrnode = queue->first;
  queue->first = ptrnode->next;
  if (queue_empty(queue)) queue->last = NULL;
  int data = ptrnode->data;
  free(ptrnode);
  return data;
}
int queue_first(const tail_t *queue)
{
  return queue->first->data;
}

/*

Ceci est un programme écrit en C qui implémente une structure de données appelée "queue", qui est une file d'attente simple.

Le programme déclare une structure de nœud, qui contient des données entières et un pointeur vers le nœud suivant. Il déclare également une structure de queue, qui contient des pointeurs vers le premier et le dernier nœud dans la queue.

Le programme contient des fonctions pour vérifier si la queue est vide, pour ajouter des éléments à la queue, pour supprimer des éléments de la queue, et pour accéder au premier élément de la queue.


*/