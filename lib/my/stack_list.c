/*
** CODEWARS PROJECT, 2022
** stack_list.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>
#include <stddef.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct stack {
  node_t *root;
} stack_t;

void stack_push(stack_t *stack, int data)
{
  node_t *newdata = malloc(sizeof(node_t));
  newdata->data = data;
  newdata->next = stack->root;
  stack->root = newdata;
}
int stack_pop(stack_t *stack)
{
  int result = stack->root->data;
  node_t *tmp = stack->root->next;
  free(stack->root);
  stack->root = tmp;
  return result;
}
int stack_peek(const stack_t *stack)
{
  return stack->root->data;
}
bool stack_is_empty(const stack_t *stack)
{
  return stack->root == NULL;
}

/*

Ceci est un programme écrit en C qui implémente une structure de données appelée "pile", qui est une structure de données last-in-first-out (LIFO).

Le programme déclare une structure de nœud, qui contient des données entières et un pointeur vers le nœud suivant. Il déclare également une structure de pile, qui contient un pointeur vers le nœud racine de la pile.

Le programme contient des fonctions pour ajouter des éléments à la pile, pour supprimer des éléments de la pile, pour accéder au premier élément de la pile, et pour vérifier si la pile est vide.

*/