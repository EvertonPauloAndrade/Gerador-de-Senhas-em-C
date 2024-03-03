#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int gerar(int tipo);
int salvar_senha();
void sobre(void);

int senha_numerica[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

char senha_carac[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char senha_carac_especiais[18] = {'_', '.', '-', '$', '%', '/', '&', '(', ')', '[', ']', '?', '!', '@', '=', '+', '*'};

int main()
{

    int opcao;
    int opcao1;

    /*
    Essas funções serão usadas em um 'menu' da aplicação para a escolha do tipo de senha
    */

    /*
    Menu inicial
    */
    printf("Gerador de Senhas 0.1v, por Everton, O Brabo\n");
    printf("Escolha a opção..\n");
    printf("[1]Gerar senha!\n");
    printf("[2]Sobre o Gerador de Senhas.\n");
    printf("[3]Sair da aplicação!\n");
    scanf("%d", &opcao);

    /*
    Menu de criação de senha
    */
    if (opcao == 1)
    {
        printf("Escolha o tipo de senha desejada: \n");
        printf("[1]Senha alfabética.\n");
        printf("[2]Senha numérica.\n");
        printf("[3]Senha alfanumérica.\n");
        printf("[4]Senha alfanumérica com caracteres especiais.\n");
        scanf("%d", &opcao1);

        if (opcao1 >= 1 && opcao1 <= 4)
            gerar(opcao1);
    }

    if (opcao == 2)
        sobre();

    if (opcao == 3)
        exit(0);

    return (0);
}

int gerar(int tipo)
{
    char *senha;
    int tamanho;
    int qnt;
    int n = 0;

    srand(time(NULL));
    senha = (char *)malloc(sizeof(char));

    if (tipo == 1)
    {
        printf("Qual o tamanho da senha?\n");
        scanf("%d", &tamanho);

        for (n = 0; n < tamanho; n++)
        {
            printf("%c", senha_carac[rand() % 52]);
            sleep(1);
        }
        printf("\n");
    }

    if (tipo == 2)
    {
        printf("Qual o tamanho da senha?\n");
        scanf("%d", &tamanho);

        for (n = 0; n < tamanho; n++)
        {
            printf("%d", senha_numerica[rand() % 10]);
            sleep(1);
        }
        printf("\n");
    }

    if (tipo == 3)
    {
        printf("Qual o tamanho da senha?\n");
        scanf("%d", &tamanho);
        qnt = tamanho / 2;

        for (n = 0; n < tamanho; n++)
        {
            printf("%c", senha_carac[rand() % 52]);
            printf("%d", senha_numerica[rand() % 10]);
            sleep(1);
        }
        printf("\n");
    }

    if (tipo == 4)
    {
        printf("Qual o tamanho da senha?\n");
        scanf("%d", &tamanho);
        qnt = tamanho / 2;

        for (n = 0; n < tamanho; n++)
        {
            printf("%c", senha_carac[rand() % 52]);

            if (n % 2 == 0)
            {
                if ((rand() % 11) % 2 == 0)
                    printf("%c", senha_carac_especiais[rand() % 18]);
                else
                    printf("%d", senha_numerica[rand()%11]);
            }

            else
                printf("%d", senha_numerica[rand()%11]);


            sleep(1);
        }
        printf("\n");
    }

    free(senha);
    return(0);
}

void sobre(void){

    printf("Gerador de senha 0.1v\n");
    printf("Autor: Everton, O Brabo\n");
    printf("Contato: everton.paulo.ep18@gmail.com\n");
    printf("Discord: everton_paulo\n");
    printf("Em breve mais atualizações!...\n");
}