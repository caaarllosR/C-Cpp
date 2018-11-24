//1) Implemente um programa (em qualquer linguagem) que dada uma mochila de
//capacidade M e um conjunto de n posItens (onde cada item possui um weight (w1, w2, ...,
//wn) e um valor (v1, v2, …, vn)), seja capaz de exibir a quantidade mais valiosa de posItens
//que caibam dentro da mochila (problema da mochila fracionada). O seu programa
//deve basear-se na estratégia gulosa.



// 1) Implement a program (in any language) that given a backpack of
// capacity M and a set of n posItems (where each item has a weight (w1, w2, ...,
// wn) and a value (v1, v2, ..., vn)), is able to display the most valuable amount of posItens
// that fit inside the backpack (problem of the fractional backpack). Your program
// should be based on greedy strategy.

#include <stdio.h>
#include <string>       // string
#include <iostream>     // cout
#include <vector>
#include <algorithm>

using namespace std;


vector<double> mergeAll(vector<double> left, vector<double> right) {
    vector<double> result(left.size() + right.size(), -1);
    int left_pos = 0;
    int right_pos = 0;
    int result_pos = 0;
    while (left_pos < left.size() && right_pos < right.size()) {
        double left_value = left[left_pos];
        double right_value = right[right_pos];
        if (left_value < right_value) {
            result[result_pos++] =  left_value;
            left_pos++;
        } else {
            result[result_pos++] = right_value;
            right_pos++;
        }
    }
    while (left_pos < left.size()) {
        result[result_pos++] = left[left_pos++];
    }
    while (right_pos < right.size()) {
        result[result_pos++] = right[right_pos++];
    }
    return result;
}

vector<double> mergeSort(vector<double> vec){
    if (vec.size() < 2){
        return vec;
    }
    int middle = vec.size() / 2;
    vector<double> left(vec.begin(), vec.begin() + middle);
    vector<double> right(vec.begin() + middle, vec.end());

    left = mergeSort(left);
    right = mergeSort(right);
    vector<double> result = mergeAll(left, right);
    return result;
}


int main () {

    int n, i = 0, j = 0;
    double charge = 0, maxBudget, d1, d2, v, fv = 0, w, fw = 0, cb;

    vector<double> fractItens;
    vector<double> costBenefit;
    vector<double> oldCostB;

    printf("\nEnter the maximum weight supported by the backpack: ");
    scanf("%lf", &maxBudget);
    printf("\nEnter the number of items available: ");
    scanf("%d", &n);

    double weightOld[n];
    double weight[n];
    double value[n];
    int posItens[n];

    for (int i = 0; i < n; ++i)
    {
        printf("\n\nEnter item weight %d: ", i);
        scanf("%lf", &d1);
        printf("\nEnter the value of the item %d: ", i);
        scanf("%lf", &d2);
        weightOld[i] = d1;
        value[i] = d2;
    }

    for (int i = 0; i < n; ++i)
    {
        oldCostB.push_back(weightOld[i]/value[i]);
    }

    costBenefit = mergeSort(oldCostB);

    i = 0;
    j = 0;
    while(i<n){
            cb = costBenefit[i];
        while(oldCostB[j]!=cb){
            j++;
        }
        posItens[i] = j;
        weight[i] = weightOld[j];
        i++;
        j = 0;
    }

    i = 0;
    while((charge < maxBudget)&&(i < n)){
        if(weight[i] <= (maxBudget - charge)){
            fractItens.push_back(1);
            charge += weight[i];
        } else    {

            fractItens.push_back((maxBudget - charge)/weight[i]);
            charge = maxBudget - charge;
        }
        i++;
    }

    printf("\n\nIndex of items in order of collection :");

    for(int j = 0; j<i; j++){
        printf(" %d", posItens[j]);
    }

    printf("\n\nWeight of items in order of collection :");

    for(int j = 0; j<i; j++){
        printf(" %.3lf", weight[j]);
    }

    printf("\nWeight fraction collected from items in order of collection (0 to 1) :");

    for(int j = 0; j<i; j++){

        w = weight[j]*fractItens[j];
        fw += w;
        printf(" %.3lf", w);
    }

    w = 0;
    printf("\nTotal weight of items available :");
    for(int j = 0; j<n; j++){

        w += weight[j];
    }
    printf(" %.3lf", w);

    printf("\nTotal weight of collected item fractions : %.3lf\n", fw);


    printf("\n\nValue of items in order of collection :");
    for(int j = 0; j<i; j++){
        printf(" %.3lf", value[posItens[j]]);
    }

    printf("\nFraction of value collected from items in order of collection (0 to 1) :");

    for(int j = 0; j<i; j++){

        v = value[posItens[j]]*fractItens[j];
        fv += v;
        printf(" %.3lf", v);
    }

    v = 0;
    printf("\n	Total value of items available :");
    for(int j = 0; j<n; j++){
        v += value[posItens[j]];
    }
    printf(" %.3lf", v);

    printf("\n	Total value of collected item fractions : %.3lf\n", fv);

}
