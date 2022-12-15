/*
** EPITECH PROJECT, 2022
** memory.h
** File description:
** header of copy_on_memory.c
*/

#ifndef MEMORY_H_
    #define MEMORY_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>

    typedef struct {
        int fd;
        char *buffer;
        int size;
    }struct_t;

    void check_openread(struct_t *file, char *path);
    void check_buff_map(struct_t *check);
    int check_index(struct_t *check, int index);
    void copy_on_memory(struct_t *check);

#endif
