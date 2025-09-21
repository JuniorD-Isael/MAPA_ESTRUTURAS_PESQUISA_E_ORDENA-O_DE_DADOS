// Aluno: Isael Dorneles Junior
// RA: 24522518-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da Árvore Binária de Busca
typedef struct No {
    char ra[20];
    struct No *esquerda;
    struct No *direita;
} No;

// Função para criar um novo nó
No* criarNo(char* ra) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o no.\n");
        exit(1);
    }
    strcpy(novoNo->ra, ra);
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um nó na Árvore Binária de Busca (ABB)
No* inserir(No* raiz, char* ra) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (raiz == NULL) {
        return criarNo(ra);
    }

    // Caso contrário, percorre a árvore recursivamente
    if (strcmp(ra, raiz->ra) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, ra);
    } else if (strcmp(ra, raiz->ra) > 0) {
        raiz->direita = inserir(raiz->direita, ra);
    }

    // Retorna o ponteiro da raiz (inalterado)
    return raiz;
}

// Função para buscar um prefixo na árvore
// Retorna 1 se o prefixo existe, 0 caso contrário
int buscarPrefixoNaArvore(No* raiz, char* prefixo) {
    if (raiz == NULL) {
        return 0; // Prefixo não encontrado
    }

    int len = strlen(prefixo);

    // strncmp compara os 'len' primeiros caracteres
    if (strncmp(prefixo, raiz->ra, len) == 0) {
        return 1; // Prefixo encontrado
    }

    if (strncmp(prefixo, raiz->ra, len) < 0) {
        return buscarPrefixoNaArvore(raiz->esquerda, prefixo);
    } else {
        return buscarPrefixoNaArvore(raiz->direita, prefixo);
    }
}

// Função para buscar o RA completo (verificação final)
// Retorna 1 se o RA completo existe, 0 caso contrário
int buscarRACompleto(No* raiz, char* ra) {
    if (raiz == NULL) {
        return 0;
    }

    if (strcmp(ra, raiz->ra) == 0) {
        return 1;
    }

    if (strcmp(ra, raiz->ra) < 0) {
        return buscarRACompleto(raiz->esquerda, ra);
    } else {
        return buscarRACompleto(raiz->direita, ra);
    }
}


int main() {
    No* raiz = NULL;

    // 1. Base de dados simulada de RAs
    // 2. Incluindo seu próprio RA
    char* ras_database[] = {
        "1987654-1",
        "2034567-2",
        "1801234-3",
        "2154321-4",
        "24522518-5", // <-- SEU RA JÁ ESTÁ AQUI
        "2009876-6",
        "1991234-7"
    };
    int num_ras = sizeof(ras_database) / sizeof(ras_database[0]);

    // Insere os RAs na árvore
    for (int i = 0; i < num_ras; i++) {
        raiz = inserir(raiz, ras_database[i]);
    }

    // 3. Solicita que o usuário digite um RA para consulta
    char ra_consulta[20];
    printf("Sistema de Verificacao de RA\n");
    printf("-----------------------------\n");
    printf("Digite o RA para consulta: ");
    scanf("%s", ra_consulta);

    printf("\n--- Iniciando verificacao ---\n");

    int len_consulta = strlen(ra_consulta);
    char prefixo_atual[20];
    int encontrado = 1; // Flag para controlar se a busca continua válida

    // 4. Realiza a busca caractere por caractere (prefixo)
    for (int i = 0; i < len_consulta; i++) {
        // Monta o prefixo atual
        strncpy(prefixo_atual, ra_consulta, i + 1);
        prefixo_atual[i + 1] = '\0'; // Finaliza a string

        printf("Verificando prefixo: '%s'...\n", prefixo_atual);

        if (!buscarPrefixoNaArvore(raiz, prefixo_atual)) {
            printf(">> Prefixo '%s' nao corresponde a nenhum RA no sistema.\n", prefixo_atual);
            encontrado = 0;
            break; // Interrompe o loop se o prefixo não for encontrado
        } else {
            printf(">> Prefixo '%s' valido. Continuando...\n", prefixo_atual);
        }
    }
    
    printf("--- Fim da verificacao por prefixo ---\n\n");

    // 5. Informa se o RA foi localizado com sucesso ou não
    if (encontrado) {
        // Verificação final para garantir que o RA completo existe
        if (buscarRACompleto(raiz, ra_consulta)) {
             printf("Resultado: RA '%s' localizado com sucesso no sistema!\n", ra_consulta);
        } else {
             printf("Resultado: O RA '%s' e um prefixo valido, mas nao corresponde a um RA completo.\n", ra_consulta);
        }
    } else {
        printf("Resultado: RA '%s' NAO foi localizado no sistema.\n", ra_consulta);
    }

    return 0;
}