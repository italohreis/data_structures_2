#include "Linked_List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _node {
    struct _node *next;
    char *name;
    char *tel;
    unsigned int ID;
};

struct _list {
    Node *begin;
    unsigned int size;
};

List* createList(){
    List *list = (List*) malloc(sizeof(List));
    list->begin = NULL;
    return list;
}

Node *createNode(char *name, char *tel, unsigned int ID) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) 
        return NULL;
    node->name = name;
    node->tel = tel;
    node->ID = ID;
    node->next = NULL;

    return node;
}

//ordernar por nome
void list_insert(char *name, char *tel, unsigned int ID, List *list) {
    Node *node = createNode(name, tel, ID);
    if (list->begin == NULL) {
        list->begin = node;
        list->size++;
    } else {
        Node *aux = list->begin;
        Node *prev = NULL;

        while (aux != NULL && strcmp(node->name, aux->name) > 0) {
            prev = aux;
            aux = aux->next;
        }

        if (prev == NULL) {
            node->next = list->begin;
            list->begin = node;
        } else {
            prev->next = node;
            node->next = aux;
        }
    }
}

void verificar_agenda(List *list, char *str) {
    Node *aux = list->begin;
    size_t len = strlen(str);

    while (aux != NULL) {
        if (strncmp(aux->name, str, len) == 0) {
            printf("%s\n", aux->name);
        }
        aux = aux->next;
    }
}

void list_print(List *list) {
    Node *aux = list->begin;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->name);
        printf("Telefone: %s\n", aux->tel);
        printf("ID: %d\n", aux->ID);
        aux = aux->next;
    }
}

unsigned int list_size(List *list) {
    return list->size;
}
