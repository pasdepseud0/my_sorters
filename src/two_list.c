/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** two_list
*/

#include "my.h"

void sort_numbers(int *array1, int *array2, int size)
{
    // Initialiser le deuxième tableau avec des valeurs -1
    for (int i = 0; i < size; i++)
        array2[i] = -1;

    // Tri par insertion
    for (int i = 0; i < size; i++) {
        int current = array1[i];
        int j = i - 1;

        while (j >= 0 && array2[j] > current) {
            array2[j + 1] = array2[j];
            j--;
        }
        array2[j + 1] = current;
    }

    // Copier les valeurs triées du deuxième tableau dans le premier
    for (int i = 0; i < size; i++)
        array1[i] = array2[i];
}

/*

La fonction utilise l'algorithme de tri par insertion, qui est efficace pour des tailles de tableau relativement petites.
La fonction prend en entrée deux tableaux d'entiers array1 et array2 et leur taille size.
Le premier tableau contient des nombres non négatifs à trier, tandis que le second tableau est initialisé avec des valeurs -1.
La fonction trie les nombres du premier tableau dans l'ordre croissant et stocke les valeurs triées dans le deuxième tableau.
Enfin, elle copie les valeurs du deuxième tableau dans le premier pour retourner les résultats triés.

*/

int main(void)
{
    // Déclarer les tableaux
    int array1[10] = {5, 3, 8, 1, 9, 6, 2, 0, 7, 4};
    int array2[10];

    // Afficher les valeurs avant le tri
    mini_printf("Avant le tri : [ ");
    for (int i = 0; i < 10; i++)
        mini_printf("%d ", array1[i]);
    mini_printf("]\n");

    // Trier les valeurs
    sort_numbers(array1, array2, 10);

    // Afficher les valeurs après le tri
    mini_printf("Après le tri : [ ");
    for (int i = 0; i < 10; i++)
        mini_printf("%d ", array1[i]);
    mini_printf("]\n");

    return 0;
}

/*

Ce main() déclare deux tableaux d'entiers array1 et array2, puis les initialise avec des valeurs.
Il affiche les valeurs avant et après le tri en utilisant la fonction sort_numbers().
Le programme devrait afficher les valeurs triées dans l'ordre croissant.

*/
