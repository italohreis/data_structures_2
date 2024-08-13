#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Linked_List.h"

int main() {
    List *list = createList();  
    list_insert("joao", "123456789", 1, list);
    list_insert("maria", "987654321", 2, list);
    list_insert("marcos", "555555555", 3, list);
    list_insert("jose", "555555555", 3, list);
    list_insert("ana", "444444444", 4, list);
    list_insert("pedro", "333333333", 5, list);
    list_insert("carlos", "222222222", 6, list);
    list_insert("lucas", "111111111", 7, list);

    char str[100] = "";
    char str2[100] = "";
    char ch;
    int i = 0;
    while (1) {
        str2[i++] = ch;
        printf("Digite o nome que deseja buscar: %s", str);
        ch = getch(); // Captura o caractere sem necessidade de pressionar Enter


        if (ch == '\r') { // Verifica se foi pressionado Enter (opcional)
            break;
        } else if (ch == '\b') { // Se Backspace for pressionado, remove o último caractere
            if (strlen(str) > 0) {
                str[strlen(str) - 1] = '\0';
            }
        } else if (ch == 27) { // Se ESC for pressionado, sai do loop
            break;
        } else {
            strncat(str, &ch, 1); // Adiciona o caractere ao final da string
        }
        
        system("cls"); // Limpa a tela
        verificar_agenda(list, str); // Verifica e exibe os nomes que coincidem
    }

    return 0;
}