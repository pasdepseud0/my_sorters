/*
** EPITECH PROJECT, 2022
** copy_on_memory.c
** File description:
** check file is readable
*/

#include "my.h"
#include "memory.h"

void check_openread(struct_t *check, char *path)
{
    char *buf = malloc(sizeof(char) * 2);
    int i = 0;
    int file_descriptor = open(path, O_RDONLY);

    if (file_descriptor == -1) {
        exit(84);
    }
    for (i = 0; read(file_descriptor, buf, 1); i++) ;
    i++;
    close(file_descriptor);
    check->fd = open(path, O_RDONLY);
    check->buffer = NULL;
    check->buffer = malloc((sizeof(char) * i));
    read(check->fd, check->buffer, i);
    check->buffer[i] = '\0';
    close(check->fd);
}

void check_buff_map(struct_t *check)
{
    for (int i = 0; check->buffer[i];) {
        if (check->buffer[i] == '#' || check->buffer[i] == '\n' ||
            check->buffer[i] == ' ' || check->buffer[i] == 'P' ||
            check->buffer[i] == 'X' || check->buffer[i] == 'O' ||
            check->buffer[i] == '\0') {
            i++;
        } else
            exit(84);
    }
}

int check_index(struct_t *check, int index)
{
    int count = 0;
    for (;check->buffer[index] != '\n' && check->buffer[index] != '\0'; count++)
        index++;
    return (count);
}

void copy_on_memory(struct_t *check)
{
    int row = 0;
    int pil = 0;
    int col = 0;
    int index = 0;

    check->map = malloc(sizeof(char *) * (check->row) + 1);
    check->save = malloc(sizeof(char *) * (check->row) + 1);
    for (; row < check->row; row++) {
        pil = check_index(check, index);
        check->map[row] = malloc(sizeof(char) * pil + 1);
        check->save[row] = malloc(sizeof(char) * pil + 1);
        for (col = 0; col < pil; col += 1) {
            check->map[row][col] = check->buffer[index];
            check->save[row][col] = check->buffer[index];
            index++;
        }
        index++;
    }
}

void get_memory(struct_t *check)
{
    int index = 0;
    int memory = 0;
    int count = 0;

    for (; check->buffer[memory] != '\n'; memory++) {
    }
    check->col = memory;
    for (; check->buffer[index] != '\0'; index++) {
        if (check->buffer[index] == '\n')
            count++;
    }
    if (check->buffer[index - 1] != '\n')
        count++;
    check->row = count;
}
