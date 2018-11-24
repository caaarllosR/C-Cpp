#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define maxSizeAeroVector 12

using namespace std;

struct voo{ //estrutura criada para o voo
    int indexDestino;
    string numVoo;
    struct voo*prox = NULL;
};

typedef struct voo Voo;

char printTxt[INT_MAX];

class Aeroporto
{
    private:
    string cidade;
    string codAero;
    Voo *destino = NULL;

    public:
    void setCidade(string nome)
    {
        cidade = nome;
    }
    string getCidade()
    {
        return cidade;
    }

    void setCodAero(string codigo)
    {
        codAero = codigo;
    }

    string getCodAero()
    {
        return codAero;
    }

    Voo *getDestino()
    {
        return destino;
    }
    void setDestino(Voo* voo)
    {
        destino = voo;
    }
};


class Lista
{
    private:
    Aeroporto aeroportos[maxSizeAeroVector]; //criando um vetor de aeroportos
    int sizeIndexAero = 0;

    public:
    void cadastrarAeroporto(string cidade, string codAero);
    Aeroporto getAeroporto(int indexAero);
    void cadastrarVoo(string numVoo, string codAeroOrigem, string codAeroDestino);
    void exibeVoosDoAeroporto(string codAero);
    void exibeTodosOsVoos();
    void removerVoo(string numVoo);

    int getSizeIndexAero()
    {
        return sizeIndexAero;
    }
};

void Lista::cadastrarAeroporto(string cidade, string codAero)
{
    Aeroporto aeroporto;
    bool valorEhRepetido = false;
    string print = "";

    if(sizeIndexAero < maxSizeAeroVector)
    {
        for(int i = 0; i < sizeIndexAero; i++)
        {
            if(aeroportos[i].getCidade() == cidade)
            {
                valorEhRepetido = true;
                print = "Cadastro de aeroporto não efetuado, a cidade já está cadastrada.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                break;
            }
            if(aeroportos[i].getCodAero() == codAero)
            {
                valorEhRepetido = true;
                print = "Cadastro de aeroporto não efetuado, este código de aeroporto já existe.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                break;
            }
        }
        if(!valorEhRepetido)
        {
            aeroporto.setCidade(cidade);
            aeroporto.setCodAero(codAero);
            aeroportos[sizeIndexAero] = aeroporto;
            sizeIndexAero++;
            print = "Cadastro de aeroporto efetuado.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }
    else
    {
        print = "O vetor já contém 12 elementos\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void Lista::cadastrarVoo(string numVoo, string codAeroOrigem, string codAeroDestino)
{
    bool origemExiste = false;
    bool destinoExiste = false;
    int indexAeroOrigem;
    int indexAeroDestino;
    string print;

    for(int i = 0; i < getSizeIndexAero(); i++)
    {
        if(aeroportos[i].getCodAero() == codAeroOrigem)
        {
            origemExiste = true;
            indexAeroOrigem = i;
        }
        if(aeroportos[i].getCodAero() == codAeroDestino)
        {
            destinoExiste = true;
            indexAeroDestino = i;
        }
    }

    if(!origemExiste && !destinoExiste)
    {
        print = "A cidade de destino e a cidade de origem não exitem.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
    else
    {
        if(!origemExiste)
        {
            print = "A cidade de origem não existe.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
        if(!destinoExiste)
        {
            print = "A cidade de destino não existe.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }

    if(origemExiste && destinoExiste)
    {
        voo *atual = NULL;
        for (atual = aeroportos[indexAeroOrigem].getDestino(); atual != NULL; atual = atual->prox)
        {
            if(atual->indexDestino == indexAeroDestino)
            {
                print = "Este trajeto já está coberto por um voo!\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                return;
            }
        }

        for(int i = 0; i < getSizeIndexAero(); i++)
        {
            for (atual = aeroportos[i].getDestino(); atual != NULL; atual = atual->prox)
            {
                if(atual->numVoo == numVoo)
                {
                    print = "O número de voo escolhido já existe, digite outro!\n\n";
                    strcat(printTxt, print.c_str());
                    cout << print << endl;
                    return;
                }
            }
        }

        Voo* novoVoo = new Voo();
        novoVoo->indexDestino = indexAeroDestino;
        novoVoo->numVoo = numVoo;
        novoVoo->prox = aeroportos[indexAeroOrigem].getDestino();
        aeroportos[indexAeroOrigem].setDestino(novoVoo);

        print = "Cadastro de voo efetuado.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

Aeroporto Lista::getAeroporto(int indexAero)
{
    return aeroportos[indexAero];
}

void Lista::removerVoo(string numVoo){
    Voo *atual = NULL;
    Voo *anterior = NULL;
    int indexAero;
    string print = "";

    for(int i = 0; i < getSizeIndexAero(); i++)
    {
        atual = aeroportos[i].getDestino();
        if(atual != NULL)
        {
            if(atual != NULL && atual->numVoo == numVoo)
            {
                indexAero = i;
                anterior = NULL;
            }

            for (atual; atual != NULL && atual->numVoo != numVoo; atual = atual->prox)
            {
                anterior = atual;
            }

            if(anterior!=NULL)
            {
                if(anterior->prox!=NULL)
                {
                    if(anterior->prox->numVoo == numVoo)
                    {
                        Voo *lixo;
                        lixo = anterior->prox;
                        anterior->prox = lixo->prox;
                        print = "Voo " + numVoo + ", removido.\n\n";
                        strcat(printTxt, print.c_str());
                        cout << print << endl;
                        free (lixo);
                        return;
                    }
                }
            }
            else
            {
                aeroportos[indexAero].setDestino(aeroportos[indexAero].getDestino()->prox);
                print = "Voo " + numVoo + ", removido.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                return;
            }
        }
    }
    print = "O voo de número " + numVoo + ", não existe.\n\n";
    strcat(printTxt, print.c_str());
    cout << print << endl;
}

void Lista::exibeTodosOsVoos(){
    Voo *atual = NULL;
    int countVoos = 0;
    string print;

    for(int i = 0; i < getSizeIndexAero(); i++)
    {
        for (atual = aeroportos[i].getDestino(); atual != NULL; atual = atual->prox)
        {
            print = "Número do voo: " + atual->numVoo + "; Nome da cidade origem: " + aeroportos[i].getCidade() + "; Nome da cidade destino: " + aeroportos[atual->indexDestino].getCidade() + "\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
            countVoos++;
        }
    }
    if(countVoos <= 0)
    {
        print = "Não existem voos para serem exibidos.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
    else
    {
        print="\nExecução completa!\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void Lista::exibeVoosDoAeroporto(string codAero) {
    int indexAero = 13;
    string print;

    for(int i = 0; i < getSizeIndexAero(); i++)
    {
        if(aeroportos[i].getCodAero() == codAero)
        {
            indexAero = i;
            break;
        }
    }
    if(indexAero < 13)
    {
        Voo *atual = aeroportos[indexAero].getDestino();
        if(atual!=NULL)
        {
            for(atual; atual != NULL; atual = atual->prox)
            {
                print = "Número do voo: " + atual->numVoo + "; Nome da cidade destino: " + aeroportos[atual->indexDestino].getCidade() + "\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
            }
        }
        else
        {
            print = "O aeroporto não possui voos cadastrados.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }
    else
    {
        print = "Código do aeroporto inválido.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void imprimeVoosDoAeroporto (Voo *lista) {
   Voo *atual;
   for (atual = lista; atual != NULL; atual = atual->prox)
   {
      printf ("%d   ", atual->indexDestino);
   }
   printf ("\n\n");
}

int main()
{
    Lista l;
    string cidade, codAero1, codAero2, numVoo;

    l.cadastrarAeroporto("Belo Horizonte", "PLU");
    l.cadastrarAeroporto("Vitória", "VIX");
    l.cadastrarAeroporto("São Paulo", "GRU");
    l.cadastrarAeroporto("Rio de Janeiro", "SDU");
    l.cadastrarAeroporto("Curitiba", "CWB");
    l.cadastrarAeroporto("Porto Alegre", "POA");
    l.cadastrarAeroporto("Florianópolis", "FLN");

    l.cadastrarVoo("0024","PLU", "VIX");
    l.cadastrarVoo("1489","PLU", "GRU");

    l.cadastrarVoo("5736","VIX", "SDU");

    l.cadastrarVoo("5487","GRU", "SDU");
    l.cadastrarVoo("3452","GRU", "CWB");
    l.cadastrarVoo("7545","GRU", "POA");

    l.cadastrarVoo("3456","SDU", "PLU");
    l.cadastrarVoo("1278","SDU", "GRU");

    l.cadastrarVoo("4238","CWB", "GRU");
    l.cadastrarVoo("1700","CWB", "FLN");

    l.cadastrarVoo("2181","POA", "GRU");
    l.cadastrarVoo("3004","POA", "CWB");

    l.cadastrarVoo("6300","FLN", "SDU");


    int opcao = 1;

    while(opcao!=0)
    {

    FILE *arquivoTxt;
    arquivoTxt=fopen("saidaTestes.txt","w+");
    fprintf(arquivoTxt,"%s",printTxt);
    fclose(arquivoTxt);


        printf ("\n\nEscolha uma opção:\n");
        printf ("1. Cadastrar novo aeroporto.\n");
        printf ("2. Cadastrar vôo.\n");
        printf ("3. Remover um vôo.\n");
        printf ("4. Exibir todos os vôos registrados.\n");
        printf ("5. Exibir todos os vôos de um determinado aeroporto.\n");
        printf ("0. Digite 0 (zero) para sair.\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0 :
            break;

            case 1 :
            printf ("\nDigite o nome da cidade a ser cadastrada:\n");
            cin >> cidade;
            printf ("\nDigite o o codigo do aeroporto\n");
            cin >> codAero1;
            printf ("\n");
            l.cadastrarAeroporto(cidade, codAero1);
            break;

            case 2 :
            printf ("\nDigite o número do vôo a ser registrado\n");
            cin >> numVoo;
            printf("\nDigite o código do aeroporto de origem\n");
            cin>> codAero1;
            printf("\nDigite o código do aeroporto de destino\n");
            cin>> codAero2;
            printf ("\n");
            l.cadastrarVoo(numVoo, codAero1, codAero2);
            break;

            case 3 :
            printf ("\nDigite o número do vôo a ser removido:\n");
            cin >> numVoo;
            printf ("\n");
            l.removerVoo(numVoo);
            break;

            case 4 :
            printf ("\n");
            l.exibeTodosOsVoos();
            break;

            case 5 :
            printf ("\nDigite o código do aeroporto:\n");
            cin >> codAero1;
            printf ("\n");
            l.exibeVoosDoAeroporto(codAero1);
            break;

            default :
            printf ("\nOpção invalida!\n");
        }
    }

    return 0;
}
