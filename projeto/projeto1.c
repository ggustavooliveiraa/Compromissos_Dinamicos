#include <stdio.h>
#include <string.h>

typedef struct {
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    float duracao;
    int prioridade;
    char nome[100];
    char descricao[200];
    char local[100];
} Compromisso;


void removerQuebraLinha(char *str){
    str[strcspn(str, "\n")] = 0;
}


void lerArquivo(Compromisso lista[], int *total){

    FILE *arquivo = fopen("entrada.csv", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    *total = 0;

    while(fscanf(arquivo,
        "%d;%d;%d;%d;%d;%f;%d;%99[^;];%199[^;];%99[^\n]\n",
        &lista[*total].ano,
        &lista[*total].mes,
        &lista[*total].dia,
        &lista[*total].hora,
        &lista[*total].minuto,
        &lista[*total].duracao,
        &lista[*total].prioridade,
        lista[*total].nome,
        lista[*total].descricao,
        lista[*total].local) == 10){

        (*total)++;
    }

    fclose(arquivo);

    printf("Dados carregados do arquivo!\n");
}


void salvarArquivo(Compromisso lista[], int total){

    FILE *arquivo = fopen("entrada.csv", "w");

    if(arquivo == NULL){
        printf("Erro ao salvar o arquivo.\n");
        return;
    }

    for(int i = 0; i < total; i++){
        fprintf(arquivo,
            "%d;%d;%d;%d;%d;%.2f;%d;%s;%s;%s\n",
            lista[i].ano,
            lista[i].mes,
            lista[i].dia,
            lista[i].hora,
            lista[i].minuto,
            lista[i].duracao,
            lista[i].prioridade,
            lista[i].nome,
            lista[i].descricao,
            lista[i].local
        );
    }

    fclose(arquivo);

    printf("Arquivo salvo com sucesso!\n");
}


void ordenarPorData(Compromisso lista[], int total){
    Compromisso temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){

            if(lista[j].ano < lista[i].ano ||
              (lista[j].ano == lista[i].ano && lista[j].mes < lista[i].mes) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia < lista[i].dia)){

                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}


void ordenarPorDataHorario(Compromisso lista[], int total){
    Compromisso temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){

            if(lista[j].ano < lista[i].ano ||
              (lista[j].ano == lista[i].ano && lista[j].mes < lista[i].mes) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia < lista[i].dia) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia == lista[i].dia && lista[j].hora < lista[i].hora) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia == lista[i].dia && lista[j].hora == lista[i].hora && lista[j].minuto < lista[i].minuto)){

                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}


void ordenarPorDataPrioridade(Compromisso lista[], int total){
    Compromisso temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){

            if(lista[j].ano < lista[i].ano ||
              (lista[j].ano == lista[i].ano && lista[j].mes < lista[i].mes) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia < lista[i].dia) ||
              (lista[j].ano == lista[i].ano && lista[j].mes == lista[i].mes && lista[j].dia == lista[i].dia &&
               lista[j].prioridade > lista[i].prioridade)){

                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}


void ordenarPorLocalPrioridadeDuracao(Compromisso lista[], int total){
    Compromisso temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){

            if(strcmp(lista[j].local, lista[i].local) < 0 ||
              (strcmp(lista[j].local, lista[i].local) == 0 &&
               lista[j].prioridade > lista[i].prioridade) ||
              (strcmp(lista[j].local, lista[i].local) == 0 &&
               lista[j].prioridade == lista[i].prioridade &&
               lista[j].duracao > lista[i].duracao)){

                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}


void adicionar(Compromisso lista[], int *total){

    printf("Digite o dia: ");
    scanf("%d", &lista[*total].dia);

    printf("Digite o mes: ");
    scanf("%d", &lista[*total].mes);

    printf("Digite o ano: ");
    scanf("%d", &lista[*total].ano);

    printf("Digite a hora: ");
    scanf("%d", &lista[*total].hora);

    printf("Digite o minuto: ");
    scanf("%d", &lista[*total].minuto);

    printf("Digite a duracao (horas): ");
    scanf("%f", &lista[*total].duracao);

    do{
        printf("Digite a prioridade (1-5): ");
        scanf("%d", &lista[*total].prioridade);
    }while(lista[*total].prioridade < 1 || lista[*total].prioridade > 5);

    getchar();

    printf("Digite o nome: ");
    fgets(lista[*total].nome, 100, stdin);
    removerQuebraLinha(lista[*total].nome);

    printf("Digite a descricao: ");
    fgets(lista[*total].descricao, 200, stdin);
    removerQuebraLinha(lista[*total].descricao);

    printf("Digite o local: ");
    fgets(lista[*total].local, 100, stdin);
    removerQuebraLinha(lista[*total].local);

    (*total)++;

    printf("\nCompromisso adicionado com sucesso!\n");
}


void remover(Compromisso lista[], int *total){

    if(*total == 0){
        printf("\nNao ha compromissos para remover.\n");
        return;
    }

    printf("\n--- Lista de Compromissos ---\n");
    for(int i = 0; i < *total; i++){
        printf("%d - %s\n", i, lista[i].nome);
    }

    int indice;
    printf("Digite o numero do compromisso que deseja remover: ");
    scanf("%d", &indice);

    if(indice < 0 || indice >= *total){
        printf("Indice invalido!\n");
        return;
    }

    for(int i = indice; i < *total - 1; i++){
        lista[i] = lista[i + 1];
    }

    (*total)--;

    printf("Compromisso removido com sucesso!\n");
}


void listar(Compromisso lista[], int total){

    if(total == 0){
        printf("Nao ha compromissos cadastrados.\n");
        return;
    }

    for(int i = 0; i < total; i++){

        printf("\n--- Compromisso %d ---\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Descricao: %s\n", lista[i].descricao);
        printf("Local: %s\n", lista[i].local);
        printf("Data: %02d/%02d/%d\n", lista[i].dia, lista[i].mes, lista[i].ano);
        printf("Horario: %02d:%02d\n", lista[i].hora, lista[i].minuto);
        printf("Duracao: %.2f horas\n", lista[i].duracao);
        printf("Prioridade: %d\n", lista[i].prioridade);
        printf("----------------------\n");
    }
}


int main(){

    Compromisso lista[1000];
    int total = 0;
    int opcao;

    lerArquivo(lista, &total);

    do {

        printf("\n--- MENU ---\n");
        printf("1 - Adicionar compromisso\n");
        printf("2 - Remover compromisso\n");
        printf("3 - Ordenar por data\n");
        printf("4 - Ordenar por data e horario\n");
        printf("5 - Ordenar por data e prioridade\n");
        printf("6 - Ordenar por local, prioridade e duracao (decrescente)\n");
        printf("7 - Listar compromissos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                adicionar(lista, &total);
                salvarArquivo(lista, total);
                break;

            case 2:
                remover(lista, &total);
                salvarArquivo(lista, total);
                break;

            case 3:
                ordenarPorData(lista, total);
                break;

            case 4:
                ordenarPorDataHorario(lista, total);
                break;

            case 5:
                ordenarPorDataPrioridade(lista, total);
                break;

            case 6:
                ordenarPorLocalPrioridadeDuracao(lista, total);
                break;

            case 7:
                listar(lista, total);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}