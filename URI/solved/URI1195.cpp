/**
* IMPORTANT:
*      O nome da classe deve ser "Main" para que a sua solu��o execute
*      Class name must be "Main" for your solution to execute
*      El nombre de la clase debe ser "Main" para que su soluci�n ejecutar
*/


//URI Online Judge | 1195
//�rvore Bin�ria de Busca
//Por Neilor Tonin, URI  Brasil
//Timelimit: 1
//
//Em computa��o, a �rvores bin�ria de busca ou �rvore bin�ria de pesquisa � uma estrutura baseada em n�s (nodos), onde todos os n�s da
//sub�rvore esquerda possuem um valor num�rico inferior ao n� raiz e todos os n�s da sub�rvore direita possuem um valor superior ao
//n� raiz (e assim sucessivamente). O objetivo desta �rvore � estruturar os dados de forma flex�vel, permitindo a busca bin�ria de
//um elemento qualquer da �rvore.
//
//A grande vantagem das �rvores de busca bin�ria sobre estruturas de dados convencionais � que os algoritmos de ordena��o (percurso
//infixo) e pesquisa que as utilizam s�o muito eficientes.
//
//Para este problema, voc� receber� v�rios conjuntos de n�meros e a partir de cada um dos conjuntos, dever� construir uma �rvore
//bin�ria de busca. Por exemplo, a sequ�ncia de valores: 8 3 10 14 6 4 13 7 1 resulta na seguinte �rvore bin�ria de busca:
//
//
//
//Entrada
//
//A entrada cont�m v�rios casos de teste. A primeira linha da entrada cont�m um inteiro C (C <= 1000), indicando o n�mero de casos
//de teste que vir�o a seguir. Cada caso de teste � composto por 2 linhas. A primeira linha cont�m um inteiro N (1 <= N <= 500) que
//indica a quantidade de n�meros que deve compor cada �rvore e a segunda linha cont�m N inteiros distintos e n�o negativos, separados
//por um espa�o em branco.
//
//Sa�da
//
//Cada linha de entrada produz 3 linhas de sa�da. Ap�s construir a �rvore bin�ria de busca com os elementos de entrada, voc� dever�
//imprimir a mensagem "Case n:", onde n indica o n�mero do caso de teste e fazer os tr�s percursos da �rvore: prefixo, infixo e
//posfixo, apresentando cada um deles em uma linha com uma mensagem correspondente conforme o exemplo abaixo, separando cada um
//dos elementos por um espa�o em branco.
//
//Obs: N�o deve haver espa�o em branco ap�s o �ltimo item de cada linha e h� uma linha em branco ap�s cada caso de teste, inclusive
//ap�s o �ltimo.
//
//Exemplo de Entrada	                Exemplo de Sa�da
//
//2                                     Case 1:
//3                                     Pre.: 5 2 7
//5 2 7                                 In..: 2 5 7
//9                                     post: 2 7 5
//8 3 10 14 6 4 13 7 1
//                                      Case 2:
//                                      Pre.: 8 3 1 6 4 7 10 14 13
//                                      In..: 1 3 4 6 7 8 10 13 14
//                                      Post: 1 4 7 6 3 13 14 10 8


/**
* @author Carlos Roger
*
*   URI Online Judge | 1195
*	RESPOSTA: Accepted
*	TEMPO: 0.188s
*	SUBMISS�O: 21/08/17 03:16:13
*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node Node;
struct node{
    int num;
    struct node *left;
    struct node *right;
};

class BTree {

public:

    void insert(Node **root, int num){
        if(*root == NULL){
            *root = (Node *) malloc(sizeof(Node));
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->num = num;
        }else{
            if(num < (*root)->num)
                insert(&(*root)->left, num);
            if(num > (*root)->num)
                insert(&(*root)->right, num);
        }
    }

    void inOrder(Node *root){
        if(root != NULL){
            inOrder(root->left);
            printf (" %i", root->num);
            inOrder(root->right);
        }
    }

    void postOrder(Node *root){
        if(root != NULL){
            postOrder(root->left);
            postOrder(root->right);
            printf (" %i", root->num);
        }
    }

    void preOrder(Node *root){
        if(root != NULL){
            printf (" %i", root->num);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main() {

    BTree bTree;

    int C, N, value, i = 0;
    scanf("%d", &C);


    while(i<C)
    {
        Node *root = NULL;
        scanf("%d", &N);

        for(int j = 0; j < N; j++)
        {
            scanf("%d", &value);
            bTree.insert(&root,value);
        }


        i++;


        printf ("Case %d:\n", i);

        printf ("Pre.:");
        bTree.preOrder(root);
        printf ("\n");

        printf ("In..:");
        bTree.inOrder(root);
        printf ("\n");

        printf ("Post:");
        bTree.postOrder(root);
        printf ("\n\n");
    }

    return 0;

}
