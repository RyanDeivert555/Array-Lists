#pragma once
#include<stdlib.h>
#include<stdio.h>
#define BASE_CAPACITY 10

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
} TYPE;
 
typedef struct ArrayList {
    void* data; // points to beginning of array
    int size;
    int capacity;
    TYPE type;
} array_list;

array_list* create_array_list(TYPE type) {
    array_list* new_array_list = (array_list*)malloc(sizeof(array_list)); // malloc data for struct, not data
    new_array_list->capacity = BASE_CAPACITY; // used for reallocing memory to array
    new_array_list->size = 0; // since we start with 0 items, used for adding items
    switch (type) {
        case CHAR:
            new_array_list->data = calloc(new_array_list->capacity, sizeof(char));
            break;
        case INT:
            new_array_list->data = calloc(new_array_list->capacity, sizeof(int));
            break;
        case FLOAT:
            new_array_list->data = calloc(new_array_list->capacity, sizeof(float));
            break;
        case DOUBLE:
            new_array_list->data = calloc(new_array_list->capacity, sizeof(double));
            break;  
    }
    new_array_list->type = type;
    return new_array_list;
}

// val must be address that matches data type of array list
void append(array_list* array_list, void* val) {
    switch (array_list->type) {
        case CHAR:
            ((char*)array_list->data)[array_list->size] = *(char*)val;
            break;
        case INT:
            ((int*)array_list->data)[array_list->size] = *(int*)val;
            break;
        case FLOAT:
            ((float*)array_list->data)[array_list->size] = *(float*)val;
            break;
        case DOUBLE:
            ((double*)array_list->data)[array_list->size] = *(double*)val;
            break;
    }
    array_list->size++;
    if (array_list->size == array_list->capacity) {
        array_list->capacity *= 2;
        switch (array_list->type) {
            case CHAR:
                array_list->data = realloc(array_list->data, sizeof(char) * array_list->capacity);
                break;
            case INT:
                array_list->data = realloc(array_list->data, sizeof(int) * array_list->capacity);
                break;
            case FLOAT:
                array_list->data = realloc(array_list->data, sizeof(float) * array_list->capacity);
                break;
            case DOUBLE:
                array_list->data = realloc(array_list->data, sizeof(double) * array_list->capacity);
                break;  
        }
    }
}
 
void print_array_list(array_list* array_list) {
    for (int i = 0; i < array_list->size; i++) {
        switch (array_list->type) {
            case CHAR:
                printf("%c ", ((char*)array_list->data)[i]);
                break;
            case INT:
                printf("%d ", ((int*)array_list->data)[i]);
                break;
            case FLOAT:
                printf("%f ", ((float*)array_list->data)[i]);
                break;
            case DOUBLE:
                printf("%f ", ((double*)array_list->data)[i]);
                break;  
        }      
    }
    printf("\n");
}
 
void pop(array_list* array_list, int index) {
    if ((index < array_list->size) && (index >= 0)) {
        for (int i = index; i < array_list->size - 1; i++) {
            switch (array_list->type) {
                case CHAR:
                    ((char*)array_list->data)[i] = ((char*)array_list->data)[i + 1];
                    break;
                case INT:
                    ((int*)array_list->data)[i] = ((int*)array_list->data)[i + 1];
                    break;
                case FLOAT:
                    ((float*)array_list->data)[i] = ((float*)array_list->data)[i + 1];
                    break;
                case DOUBLE:
                    ((double*)array_list->data)[i] = ((double*)array_list->data)[i + 1];
                    break;  
            }
        }
        array_list->size--;
    }
}

// val must be address of appropriate data
void insert(array_list* array_list, void* val, int index) {
    if ((index < array_list->size) && (index >= 0)) {
        array_list->size++;
        if (array_list->size == array_list->capacity) {
            array_list->capacity *= 2;
            switch (array_list->type) {
                case CHAR:
                    array_list->data = realloc(array_list->data, sizeof(char) * array_list->capacity);
                    break;
                case INT:
                    array_list->data = realloc(array_list->data, sizeof(int) * array_list->capacity);
                    break;
                case FLOAT:
                    array_list->data = realloc(array_list->data, sizeof(float) * array_list->capacity);
                    break;
                case DOUBLE:
                    array_list->data = realloc(array_list->data, sizeof(double) * array_list->capacity);
                    break;  
            }
        }
        for (int i = array_list->size - 1; i >= index - 1; i--) {
            switch (array_list->type) {
                case CHAR:
                    ((char*)array_list->data)[i + 1] = ((char*)array_list->data)[i];
                    break;
                case INT:
                    ((int*)array_list->data)[i + 1] = ((int*)array_list->data)[i];
                    break;
                case FLOAT:
                    ((float*)array_list->data)[i + 1] = ((float*)array_list->data)[i];
                    break;
                case DOUBLE:
                    ((double*)array_list->data)[i + 1] = ((double*)array_list->data)[i];
                    break;  
            }
        }
        switch (array_list->type) {
            case CHAR:
                ((char*)array_list->data)[index] = *(char*)val;
                break;
            case INT:
                ((int*)array_list->data)[index] = *(int*)val;
                break;
            case FLOAT:
                ((float*)array_list->data)[index] = *(float*)val;
                break;
            case DOUBLE:
                ((double*)array_list->data)[index] = *(double*)val;
                break;
        }
    }
}

void clear(array_list* array_list) {
    array_list->size = 0;
    //array_list->capacity = BASE_CAPACITY;
    switch (array_list->type) {
        case CHAR:
            array_list->data = realloc(array_list->data, sizeof(char) * array_list->capacity);
            break;
        case INT:
            array_list->data = realloc(array_list->data, sizeof(int) * array_list->capacity);
            break;
        case FLOAT:
            array_list->data = realloc(array_list->data, sizeof(float) * array_list->capacity);
            break;
        case DOUBLE:
            array_list->data = realloc(array_list->data, sizeof(double) * array_list->capacity);
            break;  
    }
}

// target needs to be address of appropriate data type
int contains(array_list* array_list, void* target) {
    for (int i = 0; i < array_list->size; i++) {
        switch (array_list->type) { // cases have their own scopes so that val is never redefined
            case CHAR:
            {
                char val = ((char*)array_list->data)[i];
                if (val == *(char*)target) {
                    return 1;
                }
                break;
            }
            case INT:
            {
                int val = ((int*)array_list->data)[i];
                if (val == *(int*)target) {
                    return 1;
                }
                break;
            }
            case FLOAT:
            {
                float val = ((float*)array_list->data)[i];
                if (val == *(float*)target) {
                    return 1;
                }
                break;
            }
            case DOUBLE:
            {
                double val = ((double*)array_list->data)[i];
                if (val == *(double*)target) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

int getIndex(array_list* array_list, void* target) {
        for (int i = 0; i < array_list->size; i++) {
        switch (array_list->type) { // cases have their own scopes so that val is never redefined
            case CHAR:
            {
                char val = ((char*)array_list->data)[i];
                if (val == *(char*)target) {
                    return i;
                }
                break;
            }
            case INT:
            {
                int val = ((int*)array_list->data)[i];
                if (val == *(int*)target) {
                    return i;
                }
                break;
            }
            case FLOAT:
            {
                float val = ((float*)array_list->data)[i];
                if (val == *(float*)target) {
                    return i;
                }
                break;
            }
            case DOUBLE:
            {
                double val = ((double*)array_list->data)[i];
                if (val == *(double*)target) {
                    return i;
                }
                break;
            }
        }
    }
    return -1;
}
 
void free_array_list(array_list* array_list) {
    free(array_list->data);
    free(array_list);
}