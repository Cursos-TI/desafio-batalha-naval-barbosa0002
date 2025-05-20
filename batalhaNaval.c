#include <stdio.h>


// Desafio: Batalha Naval - Habilidades e todos os requisitos de todas etapas implementadas.

// Função para mostrar o tabuleiro
void mostrarTabuleiro(int tab[10][10], char* nome) {
    printf("\n%s\n\n", nome);
    
    // Mostrando as letras das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    
    // Mostrando o tabuleiro com os números das linhas
    for (int i = 0; i < 10; i++) {
        printf(" %d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    
    // Mostrando o que significa cada número
    printf("\nO que significa cada número:\n");
    printf("0 - Água\n");
    printf("3 - Navio\n");
    if (nome[0] != 'T') {  // Se não for o tabuleiro original
        printf("5 - Área afetada pela habilidade\n");
    }
}

// Função para usar uma habilidade no tabuleiro
void usarHabilidade(int tabuleiro[10][10], int habilidade[5][5], 
                    int linha, int coluna, char* nomeHabilidade) {
    // Fazendo uma cópia do tabuleiro
    int tabuleiroNovo[10][10];
    
    // Copiando o tabuleiro original
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiroNovo[i][j] = tabuleiro[i][j];
        }
    }
    
    // Colocando a habilidade no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calculando onde vai ficar no tabuleiro grande
            int linhaNova = linha - 5/2 + i;
            int colunaNova = coluna - 5/2 + j;
            
            // Verificando se não saiu do tabuleiro
            if (linhaNova >= 0 && linhaNova < 10 && 
                colunaNova >= 0 && colunaNova < 10) {
                // Se a posição tem efeito da habilidade, marca com 5
                if (habilidade[i][j] == 1) {
                    tabuleiroNovo[linhaNova][colunaNova] = 5;
                }
            }
        }
    }
    
    // Criando o nome para mostrar
    char titulo[50];
    sprintf(titulo, "Tabuleiro com Habilidade %s", nomeHabilidade);
    
    // Mostrando o resultado
    mostrarTabuleiro(tabuleiroNovo, titulo);
}

int main() {
    // Criando o tabuleiro 10x10
    int tabuleiro[10][10];
    
    // Enchendo o tabuleiro com água (valor 0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Colocando um navio horizontal
    int linhaH = 1, colunaH = 2;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }
    
    // Colocando um navio vertical
    int linhaV = 5, colunaV = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }
    
    // Colocando um navio diagonal para baixo
    int linhaD1 = 2, colunaD1 = 5;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }
    
    // Colocando um navio diagonal para cima
    int linhaD2 = 7, colunaD2 = 8;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }
    
    // Criando as habilidades especiais
    
    // Habilidade Cone (como um triângulo de cabeça para baixo)
    int habilidadeCone[5][5] = {0};
    printf("\n=== Habilidade Cone ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= (5/2) - i && j <= (5/2) + i) {
                habilidadeCone[i][j] = 1;
            }
            printf("%d ", habilidadeCone[i][j]);
        }
        printf("\n");
    }
    
    // Habilidade Cruz (formato de cruz)
    int habilidadeCruz[5][5] = {0};
    printf("\n=== Habilidade Cruz ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 5/2 || j == 5/2) {
                habilidadeCruz[i][j] = 1;
            }
            printf("%d ", habilidadeCruz[i][j]);
        }
        printf("\n");
    }
    
    // Habilidade Octaedro (formato de losango)
    int habilidadeOctaedro[5][5] = {0};
    printf("\n=== Habilidade Octaedro ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calculando a distância do centro
            int distancia = 0;
            if (i > 5/2) {
                distancia = distancia + (i - 5/2);
            } else {
                distancia = distancia + (5/2 - i);
            }
            
            if (j > 5/2) {
                distancia = distancia + (j - 5/2);
            } else {
                distancia = distancia + (5/2 - j);
            }
            
            if (distancia <= 5/2) {
                habilidadeOctaedro[i][j] = 1;
            }
            printf("%d ", habilidadeOctaedro[i][j]);
        }
        printf("\n");
    }
    
    // Onde vamos usar cada habilidade
    int linhaCone = 4, colunaCone = 4;
    int linhaCruz = 6, colunaCruz = 5;
    int linhaOctaedro = 3, colunaOctaedro = 7;
    
    // Mostrando o tabuleiro original
    mostrarTabuleiro(tabuleiro, "Tabuleiro Original");
    
    // Usando cada habilidade e mostrando o resultado
    usarHabilidade(tabuleiro, habilidadeCone, linhaCone, colunaCone, "Cone");
    usarHabilidade(tabuleiro, habilidadeCruz, linhaCruz, colunaCruz, "Cruz");
    usarHabilidade(tabuleiro, habilidadeOctaedro, linhaOctaedro, colunaOctaedro, "Octaedro");
    
    printf("\nPrograma finalizado com sucesso!\n");
    
    return 0;
}