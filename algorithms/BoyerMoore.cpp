
#include<stdio.h>
#include<string>

using namespace std;

void BoyerMoore(string text, string pattern){

    int i = 0, j = 0, w = 256, sizeP = pattern.size(), sizeT = text.size();
    int L[w-1];

    for(int k = 0; k < w; k++){
        L[k] = -1;
    }
    for(int k = 0; k < sizeP; k++){
        L[pattern[k]] = k;
    }
    i = sizeP - 1;
    j = sizeP - 1;

    do{
        if(text[i] == pattern[j]){
            if(j == 0){
                    printf("\npadrão encontrado a partir do indice: %d\n", i);
                    return;
            }else {
                i--;
                j--;
            }
        }else {
            i = i + sizeP - min(j, 1 + L[text[i]]);
            j = sizeP - 1;
        }
    }while(i < (sizeT));
    printf("\npadrão não encontrado.\n");
}


int main(){

string text;
text.append("kvjlixapejrbxeenpbzphkhthbkwyrwamnugzhppfxiyjyanhapfwbzubghxmshrlyujfjhrsovk");
text.append("vveylnbxnawavggfdfggrzizyvmfohigeabgkszfnbkmffbzbzxjffqbualeytqrphyrbjqdjqavctg");
text.append("xjifqgfgydhoiwhrvwqbxgrixydzbpzjnhopvlazbzumzhhfavoctdfytvvggikngkwzibzbzbzuxgj");
text.append("tlxkojlefilbrboignbzsudssvqynbzuapbpqvlubdoyxkkwhcoudvtkmikbzbzansgsutdjythzl");
string pattern = "bzbzbzu";
string pattern2 = "lbzbzbzu";


printf("Padrão 1 (bzbzbzu):"); BoyerMoore(text, pattern);
printf("\n\nPadrão 2 (lbzbzbzu):"); BoyerMoore(text, pattern2);

}
