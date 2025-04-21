#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura da carta
typedef struct {
    char pais[50];               // Nome do país
    char codigo[10];             // Código da carta
    int populacao;               // População em habitantes
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões de US$
    int pontos_turisticos;       // Número de pontos turísticos
    float densidade_demografica; // Calculado: população/área
} Carta;

// Função para exibir o menu e obter a escolha do usuário
int exibirMenu() {
    int opcao;
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1. Comparar por População\n");
    printf("2. Comparar por Área\n");
    printf("3. Comparar por PIB\n");
    printf("4. Comparar por Pontos Turísticos\n");
    printf("5. Comparar por Densidade Demográfica\n");
    printf("0. Sair\n");
    printf("Escolha o atributo para comparação: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para comparar duas cartas com base no atributo selecionado
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s\n", carta1.pais);
    printf("País 2: %s\n", carta2.pais);
    
    switch(atributo) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.pais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.pais, carta2.populacao);
            
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);
            
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões de US$\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhões de US$\n", carta2.pais, carta2.pib);
            
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.pais, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.pais, carta2.pontos_turisticos);
            
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 5: // Densidade Demográfica
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.pais, carta1.densidade_demografica);
            printf("%s: %.2f hab/km²\n", carta2.pais, carta2.densidade_demografica);
            
            // Regra invertida: menor densidade vence
            if (carta1.densidade_demografica < carta2.densidade_demografica) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.densidade_demografica > carta2.densidade_demografica) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    // Criando duas cartas pré-definidas (poderia ser substituído por cadastro interativo)
    Carta carta1 = {
        .pais = "Brasil",
        .codigo = "BR001",
        .populacao = 213000000,
        .area = 8515767.049,
        .pib = 1847.02,
        .pontos_turisticos = 25,
        .densidade_demografica = 213000000 / 8515767.049
    };
    
    Carta carta2 = {
        .pais = "Argentina",
        .codigo = "AR001",
        .populacao = 45380000,
        .area = 2780400,
        .pib = 445.47,
        .pontos_turisticos = 18,
        .densidade_demografica = 45380000 / 2780400
    };
    
    int opcao;
    
    printf("=== SUPER TRUNFO DE PAÍSES ===\n");
    printf("Cartas disponíveis:\n");
    printf("1. %s\n", carta1.pais);
    printf("2. %s\n", carta2.pais);
    
    do {
        opcao = exibirMenu();
        
        if (opcao >= 1 && opcao <= 5) {
            compararCartas(carta1, carta2, opcao);
        } else if (opcao != 0) {
            printf("Opção inválida! Por favor, escolha uma opção entre 0 e 5.\n");
        }
    } while (opcao != 0);
    
    printf("Encerrando o programa...\n");
    return 0;
}
