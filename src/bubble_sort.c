/*
** EPITECH PROJECT, 2022
** bubble_sort.c
** File description:
** bootstrap : bubble_sort part
*/

#include "my.h"
#include "bspushswap.h"
#include <stdio.h>
#include <stdlib.h>

void swap_elem(int *array , int index1 , int index2) {
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

void bubble_sort_array(int *array , int size) {
  // On parcourt le tableau de la première à la dernière valeur
  for (int i = 0; i < size - 1; i++) {
    // On parcourt le tableau de la première à l'avant-dernière valeur
    for (int j = 0; j < size - i - 1; j++) {
      // Si l'élément d'indice j est supérieur à l'élément d'indice j+1, on les échange
      if (array[j] > array[j+1]) {
        swap_elem(array, j, j+1);
      }
    }
  }
}

void my_amazing_sorter(int *array , int size) {
  // On parcourt le tableau de la première à la dernière valeur
  for (int i = 0; i < size - 1; i++) {
    // On parcourt le tableau de la première à l'avant-dernière valeur
    for (int j = 0; j < size - i - 1; j++) {
      // Si l'élément d'indice j est supérieur à l'élément d'indice j+1, on les échange
      if (array[j] > array[j+1]) {
        mini_printf("Echanger les éléments d'indice %d et %d\n", j, j+1);
        swap_elem(array, j, j+1);
      }
    }
  }
}


// int main(void) {
//   // On crée un tableau d'entiers à trier
//   int array[] = {5, 1, 3, 2, 4};
//   int size = sizeof(array) / sizeof(array[0]);

//   // On affiche le tableau avant tri
//   mini_printf("Tableau avant tri :\n");
//   for (int i = 0; i < size; i++) {
//     mini_printf("%d ", array[i]);
//   }
//   mini_printf("\n");

//   // On trie le tableau en utilisant l'algorithme de tri à bulles
//   bubble_sort_array(array, size);

//   // On affiche le tableau après tri
//   mini_printf("Tableau après tri :\n");
//   for (int i = 0; i < size; i++) {
//     mini_printf("%d ", array[i]);
//   }
//   mini_printf("\n");

//   return 0;
// }

int main() {
  // On crée un tableau d'entiers à trier
  int array[] = {5, 1, 3, 2, 4};
  int size = sizeof(array) / sizeof(array[0]);

  // On affiche le tableau avant tri
  mini_printf("Tableau avant tri :\n");
  for (int i = 0; i < size; i++) {
    mini_printf("%d ", array[i]);
  }
  mini_printf("\n");

  // On trie le tableau en utilisant l'algorithme de tri à bulles
  my_amazing_sorter(array, size);

  // On affiche le tableau après tri
  mini_printf("Tableau après tri :\n");
  for (int i = 0; i < size; i++) {
    mini_printf("%d ", array[i]);
  }
  mini_printf("\n");

  return 0;
}

