
#include <stdio.h>
#include <iostream>
#include <float.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

struct Item
{
    float weight;
    float value;
};

deque<int> comb(int N, int K)
{
    deque<int> listComb;

    string bitMask(K, 1);
    bitMask.resize(N, 0);

    do {
        for (int i = 0; i < N; ++i)
        {
            if (bitMask[i]) listComb.push_back(i);
        }
    } while (prev_permutation(bitMask.begin(), bitMask.end()));

    return listComb;
}

int main()
{
    vector<Item> item;
    vector<float> weights;

    deque<int> listComb;

    Item auxItem;

    stringstream ss;
    string sList;

    float listWeight = 0, listValue = 0, bagSize, weight, value, sumWeight = 0;
    int n, sizeV, sizeL, l = 0, k = 0, nItens = 0;

    printf("\nDigite o tamanho da mochila: ");
    scanf("%f", &bagSize);
    printf("\nDigite a quantidade de itens a disposicao: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; ++i)
    {
        printf("\nDigite o peso do item %d: ", i);
        scanf("%f", &weight);
        printf("\nDigite o valor do item %d: ", i);
        scanf("%f", &value);

        if(weight<= bagSize){ //elimina itens de peso acima do suportado

            weights.push_back(weight);

            auxItem.weight = weight;
            auxItem.value = value;

            item.push_back(auxItem);
        }
    }

    sort (weights.begin(), weights.end());

    sizeV = weights.size();

    while(l<sizeV){ //determina a qtd max de itens q cabem na mochila

        if(sumWeight+weights[l] <= bagSize){
            sumWeight+=weights[l];
            l++;
            nItens++;
        }else{
            l = sizeV;
        }
    }

    sizeV = item.size();
    value = 0;

    for(int i = 1; i<=nItens; i++){

        listComb = comb(sizeV, i); //gera uma combinacao de indices e lista-os

        sizeL = listComb.size();

        for (int j = 0; j < sizeL; ++j)
        {
            auxItem = item[listComb.front()];

            ss << listComb.front() << " ";

            listWeight += auxItem.weight;
            listValue  += auxItem.value;

            listComb.pop_front();

            k++;
            if (k>=i)
            {
                if(listWeight<=bagSize){
                    if(listValue>=value){
                        weight = listWeight;
                        value = listValue;
                        sList = ss.str();
                    }
                }
                ss.str("");
                listWeight = 0;
                listValue  = 0;

                k = 0;
            }
        }
    }
    printf("\n\nO indice dos itens da melhor escolha sao: %s", sList.c_str());
    printf("\nPeso total dos itens: %.2f", weight);
    printf("\nValor total dos itens: %.2f", value);
}
