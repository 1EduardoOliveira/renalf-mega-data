#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Usuario{
    char Nome[100];
    char CPF[15];
    char nascimento[11];
    struct Usuario *proximo;
}Usuario;


int main() {

    Usuario *lista = NULL;
    int escolha;

    // Do While Para Manter o Sistema para Consulta Até Encerrar
    do{
    
    // Parte Das Opções:
    printf("\n===== RENALF MEGA DATA =====\n");
    printf("1 - Inclusao de usuario\n");
    printf("2 - Consulta de usuario\n");
    printf("3 - Alteracao de usuario\n");
    printf("4 - Remocao de usuario\n");
    printf("5 - Listar todos os usuarios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%i", &escolha);
    getchar();

    
    switch (escolha) {

case 1: {

    // 1. Alocar memoria suficiente para um novo usuario
    Usuario *novo = malloc(sizeof(Usuario));

    // 2. Verificar se a alocacao de memoria funcionou
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        break;
    }

    // 3. Solicitar e armazenar os dados do novo usuario
    printf("Informe o nome: ");
    fgets(novo->Nome, 100, stdin);

    printf("Informe o CPF: ");
    fgets(novo->CPF, 15, stdin);

    printf("Informe a data de nascimento: ");
    fgets(novo->nascimento, 11, stdin);

    // 4. Inicializar o ponteiro proximo como NULL
    // Isso indica que inicialmente o novo usuario nao aponta para outro.
    novo->proximo = NULL;

    // 5. Verificar se a lista esta vazia
    if (lista == NULL) {

        // Se estiver vazia, o novo usuario sera o primeiro da lista
        lista = novo;

    } else {

        // 6. Criar um ponteiro auxiliar que comeca no primeiro usuario
        Usuario *atual = lista;

        // 7. Percorrer a lista ate encontrar o ultimo usuario
        // O ultimo usuario sempre possui proximo apontando para NULL
        while (atual->proximo != NULL) {

            // Avancar para o proximo usuario
            atual = atual->proximo;
        }

        // 8. Conectar o ultimo usuario ao novo usuario
        atual->proximo = novo;
    }

    // 9. Confirmar que o cadastro foi realizado
    printf("\n--- USUARIO CADASTRADO COM SUCESSO ---\n");

    break;
}

case 2: {
        
    char cpfBuscar[15];

    // Solicitar o CPF para Busca!
    printf("Informe O CPF: ");
    fgets(cpfBuscar, 15, stdin);

    // Criar um Ponteiro Auxiliar no Inicio da Lista
    Usuario *atual = lista;

    // Verificar se o Usuario foi encontrado
    int encontrado = 0;

    // Percorrer a Lista
    while (atual != NULL){

        // Verifica se o campo de CPF nao estiver nulo , faça a busca!
        if (strcmp(atual->CPF, cpfBuscar) == 0){

            printf("\n--- USUARIO ENCONTRADO ---\n");
            printf("Nome: %s", atual->Nome);
            printf("CPF: %s", atual->CPF);
            printf("Nascimento: %s\n", atual->nascimento);

            encontrado = 1;
            break;
        }
        // Atualize e busque o proximo
        atual = atual->proximo;
    }
        // Verificar se esta nulo , se estiver da erro
        if (encontrado == 0){
            printf("Usuario nao encontrado!");
        }
        break;
    }

case 3: {

    // praticamente o codigo do case 2 porem atualiza kkjkjk

    char cpfBuscar[15];

    // Solicitar o CPF do usuario que deseja alterar
    printf("Informe o CPF do usuario: ");
    fgets(cpfBuscar, 15, stdin);

    // Criar um ponteiro auxiliar no inicio da lista
    Usuario *atual = lista;

    // Verificar se o usuario foi encontrado
    int encontrado = 0;

    // Percorrer a lista
    while (atual != NULL) {

        // Comparar o CPF informado com o CPF armazenado
        if (strcmp(atual->CPF, cpfBuscar) == 0) {

            printf("\n--- USUARIO ENCONTRADO ---\n");

            // Mostrar os dados atuais
            printf("Nome atual: %s", atual->Nome);
            printf("CPF atual: %s", atual->CPF);
            printf("Nascimento atual: %s\n", atual->nascimento);

            // Solicitar os novos dados
            printf("\nInforme o novo nome: ");
            fgets(atual->Nome, 100, stdin);

            printf("Informe o novo CPF: ");
            fgets(atual->CPF, 15, stdin);

            printf("Informe a nova data de nascimento: ");
            fgets(atual->nascimento, 11, stdin);

            printf("\n--- USUARIO ALTERADO COM SUCESSO ---\n");

            encontrado = 1;
            break;
        }

        // Avancar para o proximo usuario
        atual = atual->proximo;
    }

    // Caso o CPF nao seja encontrado
    if (encontrado == 0) {
        printf("\nUsuario nao encontrado!\n");
    }

    break;
}

case 4: {

    char cpfBuscar[15];

    // Solicitar o CPF do usuario que deseja remover
    printf("Informe o CPF do usuario: ");
    fgets(cpfBuscar, 15, stdin);

    // Ponteiro auxiliar que comeca no inicio da lista
    Usuario *atual = lista;

    // Ponteiro que guarda o usuario anterior
    Usuario *anterior = NULL;

    // Verificar se o usuario foi encontrado
    int encontrado = 0;

    // Percorrer a lista
    while (atual != NULL) {

        // Comparar o CPF informado com o CPF armazenado
        if (strcmp(atual->CPF, cpfBuscar) == 0) {

            // Verificar se o usuario esta no inicio da lista
            if (anterior == NULL) {

                // Atualizar o inicio da lista
                lista = atual->proximo;

            } else {

                // Fazer o anterior apontar para o proximo do atual
                anterior->proximo = atual->proximo;
            }

            // Liberar a memoria do usuario removido
            free(atual);

            printf("\n--- USUARIO REMOVIDO COM SUCESSO ---\n");

            encontrado = 1;
            break;
        }

        // Guardar o usuario atual como anterior
        anterior = atual;

        // Avancar para o proximo usuario
        atual = atual->proximo;
    }

    // Caso o usuario nao seja encontrado
    if (encontrado == 0) {
        printf("\nUsuario nao encontrado!\n");
    }

    break;
}

case 5: {

    // Criar um ponteiro auxiliar no inicio da lista
    Usuario *atual = lista;

    // Verificar se a lista esta vazia
    if (lista == NULL) {

        printf("\nNenhum usuario cadastrado!\n");

    } else {

        printf("\n===== LISTA DE USUARIOS CADASTRADOS =====\n");

        // Percorrer todos os usuarios da lista
        while (atual != NULL) {

            printf("\n-----------------------------------\n");
            printf("Nome: %s", atual->Nome);
            printf("CPF: %s", atual->CPF);
            printf("Nascimento: %s\n", atual->nascimento);

            // Avancar para o proximo usuario
            atual = atual->proximo;
        }

        printf("-----------------------------------\n");
    }

    break;
}

    case 0:{
        printf("Encerrando o programa...\n");
        break;}

    default:
        printf("Opcao invalida!\n");
        break;
}

    }while (escolha != 0);
    return 0; 
}