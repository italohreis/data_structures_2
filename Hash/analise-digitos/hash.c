#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_KEYS 10000
#define DIGIT_COUNT 10
#define HASH_SIZE 10000

// função para contar a frequência dos dígitos em todas as chaves
void contarDigitos(int contagem[], char chaves[][11]) {
    for (int i = 0; i < MAX_KEYS; i++) {
        for (int j = 0; j < 10; j++) {
            contagem[chaves[i][j] - '0']++;
        }
    }
}

// função para calcular o desvio de cada dígito baseado na nova fórmula
void calcularDesvios(int contagem[], double desvios[]) {
    double media = (double)(MAX_KEYS * DIGIT_COUNT) / DIGIT_COUNT;  // média esperada
    for (int i = 0; i < DIGIT_COUNT; i++) {
        desvios[i] = fabs(contagem[i] - media);  // cálculo do desvio absoluto
        printf("Desvio do digito %d: %.2f\n", i, desvios[i]);
    } 
}

// função para encontrar os 4 dígitos com os menores desvios
void encontrarMenoresDesvios(double desvios[], int indices[]) {
    int usados[DIGIT_COUNT] = {0}; // Array para marcar dígitos já usados

    for (int i = 0; i < 4; i++) {
        int menor = -1;
        for (int j = 0; j < DIGIT_COUNT; j++) {
            if (!usados[j] && (menor == -1 || desvios[j] < desvios[menor])) {
                menor = j;
            }
        }
        indices[i] = menor;
        usados[menor] = 1; // Marcar dígito como selecionado
    }
}


// função de hash para armazenar as chaves no vetor baseado nos dígitos escolhidos
int armazenarChaves(char chaves[][11], int tabelaHash[HASH_SIZE], int indices[]) {
    int colisoes = 0;
    for (int i = 0; i < MAX_KEYS; i++) {
        int posicao = 0;
        for (int j = 0; j < 4; j++) {
            posicao = posicao * 10 + (chaves[i][indices[j]] - '0');
        }
        if (tabelaHash[posicao] != -1) {
            colisoes++; // se a posição já está ocupada, há uma colisão
        }
        tabelaHash[posicao] = i; // armazenar a chave no índice da posição calculada
    }
    return colisoes;
}

int main() {
    FILE *arquivo = fopen("chaves.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char chaves[MAX_KEYS][11]; // 10 dígitos + caractere nulo
    for (int i = 0; i < MAX_KEYS; i++) {
        fscanf(arquivo, "%s", chaves[i]);
    }
    fclose(arquivo);

    int contagem[DIGIT_COUNT] = {0};
    double desvios[DIGIT_COUNT] = {0};
    int menoresIndices[4];
    int tabelaHash[HASH_SIZE];

    // inicializar tabela hash com -1 para indicar posições vazias
    for (int i = 0; i < HASH_SIZE; i++) {
        tabelaHash[i] = -1;
    }

    // contagem de quantas vezes cada dígito aparece
    contarDigitos(contagem, chaves);

    // imprimir contagem
    printf("Contagem de digitos:\n");
    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("%d: %d\n", i, contagem[i]);
    }
    printf("\n");

    // calcular desvios
    calcularDesvios(contagem, desvios);

    // encontrar os 4 dígitos com os menores desvios
    encontrarMenoresDesvios(desvios, menoresIndices);

    // armazenar as chaves no vetor hash e contar colisões
    int colisoes = armazenarChaves(chaves, tabelaHash, menoresIndices);

    //resultados
    printf("\nDigitos com menor desvio: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", menoresIndices[i]);
    }
    printf("\n\n");
    printf("Total de colisoes: %d\n", colisoes);

    return 0;
}