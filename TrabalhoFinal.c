#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct no {
    char nome[150], email[150];
    int cpf;
    int senha;
	struct no *prox;
} NOO;

typedef NOO* LISTA;

LISTA* criar_lista(){
    LISTA* li = (LISTA*)malloc(sizeof(LISTA));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

int lista_vazia(LISTA* li){
    if (li == NULL){
        return 1;
    }
    return 0;
}


int inserir_final(LISTA* li, NOO* c){
    if (li == NULL) return 0;
    NOO *no = (NOO*)malloc(sizeof(NOO));
    if (no == NULL) return 0;
    strcpy(no->nome, c->nome);
    strcpy(no->email, c->email);
    no->cpf = c->cpf;
    no->senha = c->senha;
    no->prox = NULL;
    if ((*li) == NULL){
        *li = no;
    }
    else{
    NOO *aux = *li;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
}
return 1;
}


int tamanho_lista(LISTA* li){
    NOO *aux = *li;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void destruir_lista(LISTA* li){
    NOO *aux = *li;
    while(aux != NULL){
        *li = aux->prox;
        free(aux);
        aux = *li;
    }
    *li = NULL;
}


int verificador_nome(LISTA* li, NOO* c){
    if (li == NULL) return 0;
    NOO* no = (NOO*)malloc(sizeof(NOO));
    if (no == NULL) return 0;
    no->cpf = c->cpf;
    no->prox = NULL;
    if ((*li) == NULL){
        return 0;
    }
    else{
    NOO *aux = *li;
    while (1){
        if (!(aux->cpf == no->cpf)){
            aux = aux->prox;
        } else{
            strcpy(c->nome, aux->nome);
            c->cpf = aux->cpf;
            c->senha = aux->senha;
            return 1;
            }
        }
    }
}


typedef struct{
    char nome[150], select, sexo;
    int idade;
    int deficiente, gravida;
} PACIENTE;

typedef struct to{
    PACIENTE dados;
    struct to *prox;
} NO;

typedef struct{
    NO *ini;
    NO *fim;
}FILA;

FILA* criar_fila(){
FILA *fi = (FILA*)malloc(sizeof(FILA));
    if (fi != NULL){
        fi->fim = NULL;
        fi->ini = NULL;
    }
    return fi;
}

int fila_vazia(FILA *f){
    if (f == NULL || f->ini == NULL){
        return 0;
    }
}

void enfileira_fila(FILA *f, PACIENTE p){
    NO *novo_no = (NO*)malloc(sizeof(NO));
    novo_no->dados = p;
    novo_no->prox = NULL;
    if (f->ini == NULL){
        f->ini = novo_no;
        f->fim = novo_no;
    } else {
        f->fim->prox = novo_no;
        f->fim = novo_no;
    }
}

int desenfileira(FILA *f, PACIENTE *p){
    if (f == NULL) return 0;
    NO *aux = f->ini;
    strcpy(p->nome, aux->dados.nome);
    p->idade = aux->dados.idade;
    p->sexo = aux->dados.sexo;
    p->deficiente = aux->dados.deficiente;
    p->gravida = aux->dados.gravida;
    f->ini = aux->prox;
    free(aux);
    return 1;
}

void destroi_fila(FILA *f){
    NO *aux = f->ini;
    while (aux == NULL){
        f->ini = aux->prox;
        free(aux);
        aux = f->ini;
    }
    f = NULL;
}


int main(){
FILA *fezes = criar_fila(), *urina = criar_fila(), *sangue = criar_fila();
LISTA *funcionarios = criar_lista();
NOO cadas, novo;
PACIENTE user, desif;
FILE *historico = fopen("arquivo.txt", "w+");
char trampo[150];
int n, c, botao,i, cadastro, key;
printf("BEM - VINDO A CLINICA SAO WESLEY\n");
printf("CASO SEJA FUNCIONARIO DIGITE 1, CASO NAO, DIGITE 0 PARA FAZER O CADASTRAMENTO DE TRABALHO\n");
scanf("%d", &n);
    if(n){
        system ("cls");
        login:
        printf("LOGIN(CPF):\n");
        scanf("%d", &cadas.cpf);
        c = verificador_nome(funcionarios, &cadas);
        if (c){
            system ("cls");
            printf("FUNCIONARIO CADASTRADO, DIGITE A SENHA, POR FAVOR\n");
            while (1){
            scanf("%d", &key);
            if (key == cadas.senha){
                printf("SENHA CORRETA, BOM TRABALHO\n");
                break;
            } else {
                continue;
            }
        }
    } else {
        printf("PRECISA FAZER O CADASTRAMENTO PARA ESSA JORNADA DE TRABALHO\n");
        printf("DIGITE SEU NOME, EMAIL, CPF E SENHA\n");
        scanf("%s",novo.nome);
        fflush(stdin);
        scanf("%s",novo.email);
        scanf("%d", &novo.cpf);
        scanf("%d", &novo.senha);
        c = inserir_final(funcionarios, &novo);
        if (c){
            printf("CADASTRO REALIZADO COM SUCESSO, DIGITE O CPF E A SENHA, POR FAVOR\n");
            while(1){
            scanf("%d", &key);
            if (key == novo.senha){
                printf("SENHA CORRETA, BOM TRABALHO\n");
                break;
            } else {
                continue;
            }
            }
            } else{
            printf("HOUVE UM ERRO, O SISTEMA IRA RENICIAR\n");
            return 0;
            }
        }
    }
 else {
        printf("DIGITE SEU NOME, EMAIL, CPF E SENHA\n");
        scanf(" %s", novo.nome);
        fprintf(historico, "%s\n", novo.nome);
        scanf(" %s",novo.email);
        fprintf(historico, "%s\n", novo.email);
        scanf("%d", &novo.cpf);
        fprintf(historico, "%d\n", novo.cpf);
        scanf("%d", &novo.senha);
        fprintf(historico, "%d\n", novo.senha);
        c = inserir_final(funcionarios, &novo);
        if (c){
            printf("CADASTRO REALIZADO COM SUCESSO, DIGITE O CPF E A SENHA, POR FAVOR\n");
            goto login;
        } else{
            printf("HOUVE UM ERRO, O SISTEMA IRA RENICIAR\n");
            return 0;
        }
    }
    system ( "cls" );
    printf("CADASTRAMENTO DE PACIENTES, DIGITE A QUANTIDADE DE FICHAS QUE SERAO DISTRIBUIDAS HOJE\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("DIGITE O NOME, IDADE, SEXO(M/F), 0 SE NAO FOR, 1 SE FOR GRAVIDA OU DEFICIENTE\n");
        scanf(" %s", user.nome);
        fprintf(historico, "%s\n", user.nome);
        scanf("%d", &user.idade);
        fprintf(historico, "%d\n", user.idade);
        scanf(" %c", &user.sexo);
        fprintf(historico, "%c\n", user.sexo);
        scanf("%d", &user.gravida);
        fprintf(historico, "%d\n", user.gravida);
        scanf("%d", &user.deficiente);
        fprintf(historico, "%d\n", user.deficiente);
        printf("DIGITE F, SE O PACIENTE IRA FAZER EXAME DE FEZES, U, URINA E S PARA SANGUE\n");
        scanf(" %c", &user.select);
        fprintf(historico, "%c\n", user.select);
        if (user.gravida && user.select == 'F'){
            enfileira_fila(fezes, user);
        } else if (user.gravida && user.select == 'U'){
            enfileira_fila(urina, user);
        } else if (user.gravida && user.select == 'S'){
            enfileira_fila(sangue, user);
        }else if(user.idade > 60 && user.select == 'S'){
            enfileira_fila(sangue, user);
        } else if(user.idade > 60 && user.select == 'U'){
            enfileira_fila(urina, user);
        } else if(user.idade > 60 && user.select == 'F'){
            enfileira_fila(fezes, user);
        }else if (user.deficiente && user.select == 'F'){
            enfileira_fila(fezes, user);
        }else if (user.deficiente && user.select == 'S'){
            enfileira_fila(sangue, user);
        } else if (user.deficiente && user.select == 'U'){
            enfileira_fila(urina, user);
        }
    }

    for(i = 0; i < n; i++){
        chance:
        printf("DIGITE QUAL EXAME O PROXIMO PACIENTE SERA ENCAMINHADO\n");
        printf("1: FEZES || 2: URINA || 3: SANGUE\n");
        scanf("%d", &botao);
        if (botao){
            c = desenfileira(fezes, &desif);
            if (c){
            printf("SENHOR(a) %s, DIRIJA - SE A SALA LABORATORIAL\n", desif.nome);
            } else {
                printf("A FILA ESTA VAZIA\n");
                goto chance;
            }
        } else if (botao == 2){
            c = desenfileira(urina, &desif);
            if (c){
            printf("SENHOR(a) %s, DIRIJA - SE A SALA LABORATORIAL\n", desif.nome);
            } else {
                printf("A FILA ESTA VAZIA\n");
                goto chance;
            }
        } else if (botao == 3){
            c = desenfileira(sangue, &desif);
            if (c){
            printf("SENHOR(a) %s, DIRIJA - SE A SALA LABORATORIAL\n", desif.nome);
            } else {
                printf("A FILA ESTA VAZIA\n");
                goto chance;
            }
        }
    }
    printf("OTIMO TRABALHO, EM ARQUIVO ESTA GRAVADO TODOS OS QUE FORAM ATENDIDOS HOJE E O FUNCIONARIO QUE ATENDEU, ATE AMANHA\n");
    fclose(historico);
}
