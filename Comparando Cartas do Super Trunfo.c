#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[3];              // Sigla do estado (ex: SP)
    char codigo[10];             // Código da carta
    char cidade[50];             // Nome da cidade
    int populacao;               // População em habitantes
    float area;                  // Área em km²
    float pib;                   // PIB em milhões de R$
    int pontos_turisticos;       // Número de pontos turísticos
    float densidade_populacional;// Calculado: população/área
    float pib_per_capita;        // Calculado: PIB/população
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nCadastro de Carta:\n");
    printf("Estado (sigla): ");
    scanf("%2s", carta->estado);
    printf("Código da carta: ");
    scanf("%9s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);  // Lê até encontrar uma quebra de linha
    printf("População (habitantes): ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (milhões de R$): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcula densidade populacional e PIB per capita
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000) / carta->populacao; // Convertendo PIB para R$ e dividindo pela população
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("\nCarta: %s (%s)\n", carta.cidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões de R$\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f R$\n", carta.pib_per_capita);
}

// Função para comparar duas cartas com base em um atributo escolhido
void compararCartas(Carta carta1, Carta carta2) {
    // Escolha do atributo para comparação (altere aqui para testar diferentes atributos)
    // Opções: "populacao", "area", "pib", "densidade", "pib_per_capita"
    char atributo_escolhido[] = "populacao";
    
    printf("\nComparação de cartas (Atributo: %s):\n", atributo_escolhido);
    
    // Exibe os valores do atributo escolhido para ambas as cartas
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    } else if (strcmp(atributo_escolhido, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.area);
    } else if (strcmp(atributo_escolhido, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib);
    } else if (strcmp(atributo_escolhido, "densidade") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);
    } else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
    }
    
    // Lógica de comparação
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "area") == 0) {
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "pib") == 0) {
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "densidade") == 0) {
        // Para densidade, o menor valor vence
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    Carta carta1, carta2;
    
    printf("=== Super Trunfo - Comparação de Cartas ===\n");
    
    // Cadastro das duas cartas
    printf("\nCadastro da Carta 1:");
    cadastrarCarta(&carta1);
    
    printf("\nCadastro da Carta 2:");
    cadastrarCarta(&carta2);
    
    // Exibe os dados das cartas
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Compara as cartas
    compararCartas(carta1, carta2);
    
    return 0;
}
