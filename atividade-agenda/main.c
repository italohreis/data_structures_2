#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

int main() {
    List *list = createList();  
    list_insert("joao", "123456789", 1, list);
    list_insert("maria", "987654321", 2, list);
    list_insert("jose", "555555555", 3, list);
    list_insert("ana", "444444444", 4, list);
    list_insert("pedro", "333333333", 5, list);
    list_insert("carlos", "222222222", 6, list);
    list_insert("lucas", "111111111", 7, list);

    char str[100];
    while (scanf("%s", str) != EOF) {
        system("cls");
        if (strcmp(str, "sair") == 0) {
            break;
        }
        verificar_agenda(list, str);
    }

    return 0;
}