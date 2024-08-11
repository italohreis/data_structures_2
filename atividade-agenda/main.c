#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

int main() {
    List *list = createList();  
    list_insert("Joao", "123456789", 1, list);
    list_insert("Maria", "987654321", 2, list);
    list_insert("Jose", "555555555", 3, list);
    list_insert("Ana", "444444444", 4, list);

    char str[100];
    while (str != '0') {
        system("cls");
        scanf("%s", str);
        verificar_agenda(list, str);
        system("pause");
    }

    return 0;
}