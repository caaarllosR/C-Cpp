
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

    printf("\nEnter the size of the backpack: ");
    scanf("%f", &bagSize);
    printf("\nEnter the quantity of items available: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; ++i)
    {
        printf("\nEnter item weight %d: ", i);
        scanf("%f", &weight);
        printf("\nEnter the value of the item %d: ", i);
        scanf("%f", &value);

        if(weight<= bagSize){ //eliminate items of weight above the supported

            weights.push_back(weight);

            auxItem.weight = weight;
            auxItem.value = value;

            item.push_back(auxItem);
        }
    }

    sort (weights.begin(), weights.end());

    sizeV = weights.size();

    while(l<sizeV){ //determines the qtd max of items that fit in the backpack

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

        listComb = comb(sizeV, i); //generates a combination of indexes and lists them

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
    printf("\n\nThe index of the best choice items are: %s", sList.c_str());
    printf("\nTotal item weight: %.2f", weight);
    printf("\nTotal value of items: %.2f", value);
}
