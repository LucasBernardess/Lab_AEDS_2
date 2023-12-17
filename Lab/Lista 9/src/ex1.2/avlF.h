#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct Funcionario {
    char nome[50];
    double salario;
    int anoContratacao;
} Funcionario;

typedef struct NO {
    Funcionario info;
    int fb, alt;
    struct NO *esq;
    struct NO *dir;
} NO;

typedef struct NO *AVL;

AVL *criaAVL();
int estaVazia(AVL *raiz);
NO *alocarNO();
NO *alocarNOFuncionario(char nome[], double salario, int anoContratacao);
int insereRec(AVL *raiz, NO *novo);
int insereFuncionario(AVL *raiz, char nome[], double salario, int anoContratacao);
void rotacaoLL(AVL *raiz);
void rotacaoRR(AVL *raiz);
void rotacaoLR(AVL *raiz);
void rotacaoRL(AVL *raiz);
int altura(AVL no);
void avl_AuxFE(AVL *raiz);
NO *pesquisaFuncionario(AVL *raiz, double salario);
NO *pesquisaFuncionarioRec(AVL *raiz, double salario);
void imprimeFuncionario(Funcionario funcionario);
void imprimeMaiorSalario(AVL *raiz);
NO *encontraMaiorSalarioRec(NO *raiz);
void imprimeMenorSalario(AVL *raiz);
NO *encontraMenorSalarioRec(NO *raiz);
int removeFuncionarioPorNome(AVL *raiz, char nome[]);
void imprimeTodosFuncionarios(AVL *raiz);
void imprimeTodosFuncionariosRec(NO *raiz);
void destroiAVL(AVL *raiz);
void destroiRec(NO *no);
void liberarNO(NO *no);

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int estaVazia(AVL *raiz) {
    return *raiz == NULL;
}

NO *alocarNO() {
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo != NULL) {
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        novo->alt = 1;
    }
    return novo;
}

NO *alocarNOFuncionario(char nome[], double salario, int anoContratacao) {
    NO *novo = alocarNO();
    if (novo != NULL) {
        strcpy(novo->info.nome, nome);
        novo->info.salario = salario;
        novo->info.anoContratacao = anoContratacao;
        novo->fb = 0, novo->alt = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

int insereRec(AVL *raiz, NO *novo) {
    if (*raiz == NULL) {
        *raiz = novo;
        return 1; 
    }

    if (novo->info.salario < (*raiz)->info.salario) {
        int inseriu = insereRec(&(*raiz)->esq, novo);

        (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
        (*raiz)->fb = altura((*raiz)->esq) - altura((*raiz)->dir);

        if ((*raiz)->fb > 1) {
            if (novo->info.salario < (*raiz)->esq->info.salario) {
                rotacaoLL(raiz);
            } else {
                rotacaoLR(raiz);
            }
        }
        
        return inseriu;
    } else if (novo->info.salario > (*raiz)->info.salario) {
        int inseriu = insereRec(&(*raiz)->dir, novo);
        (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
        (*raiz)->fb = altura((*raiz)->esq) - altura((*raiz)->dir);

        if ((*raiz)->fb < -1) {
            if (novo->info.salario > (*raiz)->dir->info.salario) {
                rotacaoRR(raiz);
            } else {
                rotacaoRL(raiz);
            }
        }

        return inseriu;
    } else {
        return 0; 
    }
}

int insereFuncionario(AVL *raiz, char nome[], double salario, int anoContratacao) {
    Funcionario funcionario;
    strcpy(funcionario.nome, nome);
    funcionario.salario = salario;
    funcionario.anoContratacao = anoContratacao;

    if (raiz == NULL || *raiz == NULL) {
        *raiz = alocarNOFuncionario(nome, salario, anoContratacao);
        if (*raiz == NULL) return 0;
        return 1;
    }

    NO *novo = alocarNOFuncionario(nome, salario, anoContratacao);
    if (novo == NULL) return 0;

    int ok = insereRec(raiz, novo);

    if (ok) {
        switch ((*raiz)->fb) {
            case -1:
                (*raiz)->fb = 0;
                ok = 0;
                break;
            case 0:
                (*raiz)->fb = +1;
                (*raiz)->alt++;
                break;
            case +1:
                avl_AuxFE(raiz);
                ok = 0;
                break;
        }
    }

    return ok;
}

void rotacaoLL(AVL *raiz) {
    AVL temp = (*raiz)->esq;

    if (temp == NULL) {
        return;
    }

    (*raiz)->esq = temp->dir;
    temp->dir = *raiz;

    // Atualizar alturas
    (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    temp->alt = MAIOR(altura(temp->esq), altura(temp->dir)) + 1;

    *raiz = temp;
}


void rotacaoRR(AVL *raiz) {
    AVL temp = (*raiz)->dir;
    
    if (temp == NULL) {
        return;
    }

    (*raiz)->dir = temp->esq;
    temp->esq = *raiz;


    (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    temp->alt = MAIOR(altura(temp->esq), altura(temp->dir)) + 1;

    *raiz = temp;
}

void rotacaoLR(AVL *raiz) {
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(AVL *raiz) {
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int altura(AVL no) {
    if (no == NULL) {
        return -1; 
    } else {
        return no->alt;
    }
}

void avl_AuxFE(AVL *raiz) {
    if (*raiz != NULL) {
        int fb = altura((*raiz)->esq) - altura((*raiz)->dir);

        if (fb > 1) {
            if (altura((*raiz)->esq->esq) >= altura((*raiz)->esq->dir)) {
                rotacaoLL(raiz);
            } else {
                rotacaoLR(raiz);
            }
        } else if (fb < -1) {
            if (altura((*raiz)->dir->dir) >= altura((*raiz)->dir->esq)) {
                rotacaoRR(raiz);
            } else {
                rotacaoRL(raiz);
            }
        }

        avl_AuxFE(&(*raiz)->esq);
        avl_AuxFE(&(*raiz)->dir);

        (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    }
}

NO *pesquisaFuncionario(AVL *raiz, double salario) {
    if (raiz == NULL) return NULL;
    if (estaVazia(raiz)) return NULL;
    return pesquisaFuncionarioRec(raiz, salario);
}

NO *pesquisaFuncionarioRec(AVL *raiz, double salario) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->info.salario == salario) return *raiz;
    if (salario < (*raiz)->info.salario)
        return pesquisaFuncionarioRec(&(*raiz)->esq, salario);
    else
        return pesquisaFuncionarioRec(&(*raiz)->dir, salario);
}

void imprimeFuncionario(Funcionario funcionario) {
    printf("Nome: %s, Salario: %.2lf, Ano de Contratacao: %d\n",
           funcionario.nome, funcionario.salario, funcionario.anoContratacao);
}

void imprimeMaiorSalario(AVL *raiz) {
    if (raiz == NULL || estaVazia(raiz)) {
        printf("Arvore Vazia!\n");
        return;
    }
    NO *maiorSalarioNode = encontraMaiorSalarioRec(*raiz);
    if (maiorSalarioNode != NULL) {
        imprimeFuncionario(maiorSalarioNode->info);
    }
}

NO *encontraMaiorSalarioRec(NO *raiz) {
    if (raiz->dir == NULL) return raiz;
    return encontraMaiorSalarioRec(raiz->dir);
}

void imprimeMenorSalario(AVL *raiz) {
    if (raiz == NULL || estaVazia(raiz)) {
        printf("Arvore Vazia!\n");
        return;
    }
    NO *menorSalarioNode = encontraMenorSalarioRec(*raiz);
    if (menorSalarioNode != NULL) {
        imprimeFuncionario(menorSalarioNode->info);
    }
}

NO *encontraMenorSalarioRec(NO *raiz) {
    if (raiz->esq == NULL) return raiz;
    return encontraMenorSalarioRec(raiz->esq);
}

int removeFuncionarioPorNome(AVL *raiz, char nome[]) {
    if (*raiz == NULL) {
        return 0;
    }

    int removido = 0;
    if (strcmp(nome, (*raiz)->info.nome) < 0) {
        removido = removeFuncionarioPorNome(&(*raiz)->esq, nome);
    } else if (strcmp(nome, (*raiz)->info.nome) > 0) {
        removido = removeFuncionarioPorNome(&(*raiz)->dir, nome);
    } else {
        NO *temp;

        if ((*raiz)->esq == NULL) {
            temp = *raiz;
            *raiz = (*raiz)->dir;
            free(temp);
            removido = 1;
        } else if ((*raiz)->dir == NULL) {
            temp = *raiz;
            *raiz = (*raiz)->esq;
            free(temp);
            removido = 1;
        } else {
            temp = encontraMenorSalarioRec((*raiz)->dir);
            (*raiz)->info = temp->info;
            removido = removeFuncionarioPorNome(&(*raiz)->dir, temp->info.nome);
        }
    }

    if (*raiz != NULL) {
        (*raiz)->alt = MAIOR(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
        int fb = altura((*raiz)->esq) - altura((*raiz)->dir);

        if (fb > 1) {
            if (altura((*raiz)->esq->esq) >= altura((*raiz)->esq->dir)) {
                rotacaoLL(raiz);
            } else {
                rotacaoLR(raiz);
            }
        } else if (fb < -1) {
            if (altura((*raiz)->dir->dir) >= altura((*raiz)->dir->esq)) {
                rotacaoRR(raiz);
            } else {
                rotacaoRL(raiz);
            }
        }
    }

    return removido;
}

void imprimeTodosFuncionarios(AVL *raiz) {
    if (raiz == NULL || estaVazia(raiz)) {
        printf("Arvore Vazia!\n");
        return;
    }
    imprimeTodosFuncionariosRec(*raiz);
}

void imprimeTodosFuncionariosRec(NO *raiz) {
    if (raiz != NULL) {
        imprimeTodosFuncionariosRec(raiz->esq);
        imprimeFuncionario(raiz->info);
        imprimeTodosFuncionariosRec(raiz->dir);
    }
}

void destroiAVL(AVL *raiz) {
    if (raiz != NULL) {
        destroiRec(*raiz);
        free(raiz);
    }
}

void destroiRec(NO *no) {
    if (no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void liberarNO(NO *no) {
    free(no);
}