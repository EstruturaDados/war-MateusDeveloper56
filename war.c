// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Construir uma base de dados de territórios utilizando uma estrutura de dados composta.
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 5

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    int id;
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Protótipos das Funções ---

/**
 * Limpar o buffer de entrada
 */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    /**
     * Define um vetor Mapa com 3 posições e o contador de territórios.
     */
    struct Territorio Mapa[NUM_TERRITORIOS];
    int totalTerritorios = 0;

    /**
     * Define na estrutura o território
     */
    struct Territorio novo_territorio;

    printf("Jogo War \n");

    /**
     * Laço de entrada, espera que sejam registrados 5 registros.
     */
    do {
        /**
         * Atribui ID para o novo território.
         */
        novo_territorio.id = totalTerritorios;

        /**
         * Obtém os dados de entrada no programa.
         */
        printf("___________________ \n Cadastro de território: \n");

        printf("Informe o nome do território: \n");
        fgets(novo_territorio.nome, 30, stdin);
        novo_territorio.nome[strcspn(novo_territorio.nome, "\n")] = 0;

        printf("Informe a cor do território: \n");
        fgets(novo_territorio.cor, 10, stdin);
        novo_territorio.cor[strcspn(novo_territorio.cor, "\n")] = 0;

        printf("Informe a quantidade de tropas: \n");
        scanf("%i", &novo_territorio.tropas);

        /**
         * Limpa buffer de entrada.
         */
        limparBufferEntrada();

        /**
         * Atribui novo território ao vetor e incrementa + 1.
         */
        Mapa[totalTerritorios] = novo_territorio;
        totalTerritorios++;

    } while (totalTerritorios < 5); // Condição do laço de repetição antes de ir para instrução seguinte.

    /*
    * Lista todos os territórios no final da execução.
    */
    printf("\n ___________________ \n Lista de Territórios: \n");

    for(int i = 0; i < totalTerritorios; i++) {
        printf("___________________ \n Território %i: \n\n", i + 1);
        printf("Nome: %s \n", Mapa[i].nome);
        printf("Cor: %s \n", Mapa[i].cor);
        printf("Quantidade de Tropas: %i \n", Mapa[i].tropas);
    }

    // Aguarda o usuário apertar enter.
    getchar();

    return 0;
}


