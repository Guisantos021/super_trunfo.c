#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para exibir o menu de atributos
int exibirMenuAtributos(bool disponiveis[5]) {
    int opcao;
    printf("\nEscolha um atributo:\n");
    if (disponiveis[0]) printf("1. População\n");
    if (disponiveis[1]) printf("2. Área\n");
    if (disponiveis[2]) printf("3. PIB\n");
    if (disponiveis[3]) printf("4. Pontos Turísticos\n");
    if (disponiveis[4]) printf("5. Densidade Demográfica\n");
    printf("0. Cancelar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    // Verifica se a opção é válida e está disponível
    if (opcao < 0 || opcao > 5 || (opcao != 0 && !disponiveis[opcao-1])) {
        printf("Opção inválida ou indisponível!\n");
        return -1;
    }
    return opcao;
}

// Função para comparar um único atributo
int compararAtributo(Carta c1, Carta c2, int atributo, float *valor1, float *valor2) {
    switch(atributo) {
        case 1: // População
            *valor1 = c1.populacao;
            *valor2 = c2.populacao;
            return (*valor1 > *valor2) ? 1 : (*valor1 < *valor2) ? 2 : 0;
            
        case 2: // Área
            *valor1 = c1.area;
            *valor2 = c2.area;
            return (*valor1 > *valor2) ? 1 : (*valor1 < *valor2) ? 2 : 0;
            
        case 3: // PIB
            *valor1 = c1.pib;
            *valor2 = c2.pib;
            return (*valor1 > *valor2) ? 1 : (*valor1 < *valor2) ? 2 : 0;
            
        case 4: // Pontos Turísticos
            *valor1 = c1.pontos_turisticos;
            *valor2 = c2.pontos_turisticos;
            return (*valor1 > *valor2) ? 1 : (*valor1 < *valor2) ? 2 : 0;
            
        case 5: // Densidade Demográfica (menor vence)
            *valor1 = c1.densidade;
            *valor2 = c2.densidade;
            return (*valor1 < *valor2) ? 1 : (*valor1 > *valor2) ? 2 : 0;
            
        default:
            return -1;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para obter a unidade do atributo
const char* unidadeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "habitantes";
        case 2: return "km²";
        case 3: return "bilhões US$";
        case 4: return "pontos";
        case 5: return "hab/km²";
        default: return "";
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {
        .pais = "Brasil",
        .populacao = 213000000,
        .area = 8515767.049,
        .pib = 1847.02,
        .pontos_turisticos = 25,
        .densidade = 213000000 / 8515767.049
    };
    
    Carta carta2 = {
        .pais = "Argentina",
        .populacao = 45380000,
        .area = 2780400,
        .pib = 445.47,
        .pontos_turisticos = 18,
        .densidade = 45380000 / 2780400
    };
    
    printf("=== SUPER TRUNFO AVANÇADO ===\n");
    printf("Comparando:\n");
    printf("1. %s\n", carta1.pais);
    printf("2. %s\n", carta2.pais);
    
    bool atributosDisponiveis[5] = {true, true, true, true, true};
    int atributo1 = 0, atributo2 = 0;
    
    // Seleção do primeiro atributo
    while (true) {
        atributo1 = exibirMenuAtributos(atributosDisponiveis);
        if (atributo1 == -1) continue;
        if (atributo1 == 0) return 0;
        break;
    }
    
    // Marca o primeiro atributo como indisponível
    atributosDisponiveis[atributo1-1] = false;
    
    // Seleção do segundo atributo
    while (true) {
        printf("\nPrimeiro atributo selecionado: %s\n", nomeAtributo(atributo1));
        atributo2 = exibirMenuAtributos(atributosDisponiveis);
        if (atributo2 == -1) continue;
        if (atributo2 == 0) return 0;
        break;
    }
    
    printf("\n=== COMPARAÇÃO ===\n");
    printf("Países: %s vs %s\n", carta1.pais, carta2.pais);
    printf("Atributos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    
    // Comparação dos atributos
    float valor1_atr1, valor2_atr1, valor1_atr2, valor2_atr2;
    int resultado_atr1 = compararAtributo(carta1, carta2, atributo1, &valor1_atr1, &valor2_atr1);
    int resultado_atr2 = compararAtributo(carta1, carta2, atributo2, &valor1_atr2, &valor2_atr2);
    
    // Exibe resultados individuais
    printf("\n%s:\n", nomeAtributo(atributo1));
    printf("%s: %.2f %s\n", carta1.pais, valor1_atr1, unidadeAtributo(atributo1));
    printf("%s: %.2f %s\n", carta2.pais, valor2_atr1, unidadeAtributo(atributo1));
    printf("Vencedor: %s\n", 
        resultado_atr1 == 0 ? "Empate!" : 
        resultado_atr1 == 1 ? carta1.pais : carta2.pais);
    
    printf("\n%s:\n", nomeAtributo(atributo2));
    printf("%s: %.2f %s\n", carta1.pais, valor1_atr2, unidadeAtributo(atributo2));
    printf("%s: %.2f %s\n", carta2.pais, valor2_atr2, unidadeAtributo(atributo2));
    printf("Vencedor: %s\n", 
        resultado_atr2 == 0 ? "Empate!" : 
        resultado_atr2 == 1 ? carta1.pais : carta2.pais);
    
    // Soma dos atributos
    float soma1 = valor1_atr1 + valor1_atr2;
    float soma2 = valor2_atr1 + valor2_atr2;
    
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos para %s: %.2f\n", carta1.pais, soma1);
    printf("Soma dos atributos para %s: %.2f\n", carta2.pais, soma2);
    
    if (soma1 > soma2) {
        printf("Vencedor final: %s!\n", carta1.pais);
    } else if (soma1 < soma2) {
        printf("Vencedor final: %s!\n", carta2.pais);
    } else {
        printf("Resultado final: Empate!\n");
    }
    
    return 0;
}
