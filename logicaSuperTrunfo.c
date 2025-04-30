#include <stdio.h>
#include <string.h>

int main() {
    // Declaração de variáveis para as cartas
    char estado1[20], estado2[20];
    char cidade1[20], cidade2[20];
    long long int populacao1, populacao2;
    float areakm1, areakm2;
    double pib1, pib2;
    int pontosturisticos1, pontosturisticos2;
    double densidade1, densidade2;
    double pibpercapita1, pibpercapita2;

    // Dados da carta 1
    printf("Insira os dados da carta 1\n");
    printf("Nome do estado: ");
    fgets(estado1, sizeof(estado1), stdin);
    estado1[strcspn(estado1, "\n")] = '\0';

    printf("Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    printf("População: ");
    while (scanf("%lld", &populacao1) != 1) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("Área em km²: ");
    while (scanf("%f", &areakm1) != 1 || areakm1 <= 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("PIB (em bilhões de reais): ");
    while (scanf("%lf", &pib1) != 1 || pib1 < 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("Pontos turísticos: ");
    while (scanf("%d", &pontosturisticos1) != 1 || pontosturisticos1 < 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }
    getchar();

    // Dados da carta 2
    printf("Insira os dados da carta 2\n");
    printf("Nome do estado: ");
    fgets(estado2, sizeof(estado2), stdin);
    estado2[strcspn(estado2, "\n")] = '\0';

    printf("Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("População: ");
    while (scanf("%lld", &populacao2) != 1) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("Área em km²: ");
    while (scanf("%f", &areakm2) != 1 || areakm2 <= 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("PIB (em bilhões de reais): ");
    while (scanf("%lf", &pib2) != 1 || pib2 < 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    printf("Pontos turísticos: ");
    while (scanf("%d", &pontosturisticos2) != 1 || pontosturisticos2 < 0) {
        printf("Entrada inválida! Digite novamente: ");
        while (getchar() != '\n');
    }

    // Cálculo da densidade e PIB per capita
    densidade1 = populacao1 / areakm1;
    pibpercapita1 = pib1 / populacao1;
    densidade2 = populacao2 / areakm2;
    pibpercapita2 = pib2 / populacao2;

    // Escolha de atributos
    int opcao1, opcao2;

    printf("\nEscolha o primeiro atributo para comparar as cartas:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    
    while (scanf("%d", &opcao1) != 1 || opcao1 < 1 || opcao1 > 6) {
        printf("Entrada inválida! Digite novamente (1-6): ");
        while (getchar() != '\n');
    }

    printf("\nEscolha o segundo atributo para comparar as cartas (diferente do primeiro):\n");
    
    while (scanf("%d", &opcao2) != 1 || opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
        printf("Entrada inválida ou repetida! Digite novamente (1-6): ");
        while (getchar() != '\n');
    }

    // Comparação dos atributos escolhidos
    double valor1, valor2;
    
    switch(opcao1) {
        case 1: valor1 = populacao1; break;
        case 2: valor1 = areakm1; break;
        case 3: valor1 = pib1; break;
        case 4: valor1 = pontosturisticos1; break;
        case 5: valor1 = densidade1; break;
        case 6: valor1 = pibpercapita1; break;
    }

    switch(opcao2) {
        case 1: valor2 = populacao2; break;
        case 2: valor2 = areakm2; break;
        case 3: valor2 = pib2; break;
        case 4: valor2 = pontosturisticos2; break;
        case 5: valor2 = densidade2; break;
        case 6: valor2 = pibpercapita2; break;
    }

    printf("\nCarta 1 - %s (%s): %.2lf\n", cidade1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2lf\n", cidade2, estado2, valor2);

    // Comparação final
    if (valor1 > valor2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (valor1 < valor2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}