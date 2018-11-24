
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

#define TAM 26

using namespace std;

typedef struct trie_no{
	int folha;
	bool ehZip = false;
    string indice;
    int qtdFilhos;
    string valor;
	struct trie_no *filhos[TAM];
} Trie_No;

string numToString(int n){
    int m = 0, i = 0, countN = 0;
    string s;

    if(n>0){
        while (n>0){

            m = n%10;
            n = n/10;

            s.push_back('0'+m);
            i++;
        }
        reverse(s.begin(),s.end());
    }else{
        s.push_back('0');
    }
    return s;
}

Trie_No* cria_no()
{
	Trie_No *no = new Trie_No();
	int i;
	no->folha = 0;
    no->indice = "(";
    no->qtdFilhos = 0;
    no->valor = "";

	for (i = 0; i < TAM; i++)
	{
		no->filhos[i] = NULL;
	}
	return no;
}

void insere(Trie_No *no, char *palavra,int index)
{
	int tam = strlen(palavra);
	int i, indice;
	Trie_No *atual = no;
	for (i = 0; i < tam; i++)
	{
		indice = ((int)palavra[i] - (int)'a');
		if (atual->filhos[indice] == NULL)
		{
			atual->filhos[indice] = cria_no();
			atual->qtdFilhos++;
		}
		atual = atual->filhos[indice];
		atual->valor = palavra[i];
	}
	atual->folha = 1;
    atual->indice.append(numToString(index));
    atual->indice.append(";");

}

string busca(Trie_No *no, string palavra)
{
	int tam = palavra.size();
	int i, indice;
	Trie_No *atual = no;
	for (i = 0; i < tam; i++)
	{
		indice = ((int)palavra[i] - (int)'a');
		if (atual->filhos[indice] == NULL)
		{
            return "word not found";
		}
        atual = atual->filhos[indice];
        if(atual->valor == palavra.substr(i, atual->valor.size())){
            i += atual->valor.size() - 1;
        }
        else{
            return "word not found";
        }
	}
	if(atual->folha){
        i = atual->indice.size()-1;
        atual->indice.erase(i);
        atual->indice.append(")");

        if(atual->ehZip){
            return "sim";
        }else{
            return atual->indice; //returns the index of each occurrence of the word in the text used to generate the Trie
        }
	}
	 else{
        return "word not found";
    }
}

void comprimeTrie(Trie_No* raiz, Trie_No* atual){
    if(atual->folha){
        atual->ehZip = true;
        return;
    }
    else{
        atual->ehZip = true;
        for(int i = 0 ; i < TAM ; i++){
            if(atual->filhos[i] != NULL){
                comprimeTrie(raiz, atual->filhos[i]);
                if(atual->qtdFilhos < 2 && atual != raiz){
                        atual->valor += atual->filhos[i]->valor;

                        if(atual->filhos[i]->folha){
                            atual->folha = 1;
                        }
                        atual->qtdFilhos = 0;
                        for(int k = 0 ; k < TAM ; k++){
                            if((atual->filhos[i])->filhos[k] != NULL){
                                atual->filhos[k] = (atual->filhos[i])->filhos[k];
                                atual->filhos[i]->filhos[k] = NULL;
                            }
                        }
                        for(int k = 0 ; k < TAM ; k++){
                            if((atual->filhos[k]) != NULL){
                                atual->qtdFilhos++;
                            }
                        }
                        atual->filhos[i] = NULL;
                        atual->qtdFilhos--;
                }
            }
        }
    }
}

int main()
{
	//"root bell bear bell bid bull bell buy sell stock stop bell bell bid";

    set<string> w;
    set<string>::iterator it;

	int i = 0, sizeP = 0;
	string opt = "s", str, strText;

	printf("\nEnter input text: ");
	getline(cin,strText);

	char *text = (char*)malloc(strText.size());

    copy(strText.begin(), strText.end(), text);

	char *palavras[strlen(text)];
	Trie_No *trie1 = cria_no();
	Trie_No *trie2 = cria_no();

	char *word = strtok(text," ");

    while (word != NULL)
    {
        palavras[i] = word;
        word = strtok (NULL, " ");
        i++;
        sizeP++;
    }

	for (int i = 0; i < sizeP; i++)
	{
		insere(trie1, palavras[i],i);
		insere(trie2, palavras[i],i);
		w.insert(palavras[i]);
	}

    comprimeTrie(trie2, trie2);

    for (it=w.begin(); it!=w.end(); ++it)
	{
        str = *it;
        printf("\nIndex of occurrences of the word \"%s\" in the text (uncompressed): %s\n", str.c_str(), busca(trie1, str).c_str());
        printf("Is the word in Trie compressed?: %s\n", busca(trie2, str).c_str());
    }

    printf("\n");
    while (opt!=("n")&&opt!=("N"))
    {
        printf("\nDo you want to search for another word? (Y|N) :");
        cin >> opt;
        if(opt==("s")||opt==("S")){
            printf("\n\n\nText: %s", strText.c_str());
            printf("\n\nEnter the word to be found: ");
            cin >> str;
            printf("\nIndex of occurrences of the word \"%s\" in the text (uncompressed): %s\n", str.c_str(), busca(trie1, str).c_str());
			printf("Is the word in Trie compressed?: %s\n\n\n", busca(trie2, str).c_str());
        }

    }

	return 0;
}
