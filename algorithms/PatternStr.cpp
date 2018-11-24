
#include<stdio.h>
#include<string>

using namespace std;

void searchPattern(string text, string pattern){

    int j = 0, i = 0, sizeP = pattern.size(), k = sizeP-1, sizeT = text.size();

    while(i<(sizeT-k)){

        if(k==0){
            printf("\nPattern found from the index: %d\n", (i-sizeP+1));
            return;
        }
        if(pattern[j]==text[i]){
            k--;
            j++;
        } else{
            k = sizeP-1;
            j = 0;
        }
        i++;
    }
    printf("\nPattern not found.\n");
}

int main(){

string text;
text.append("kvjlixapejrbxeenpbzphkhthbkwyrwamnugzhppfxiyjyanhapfwbzubghxmshrlyujfjhrsovk");
text.append("vveylnbxnawavggfdfggrzizyvmfohigeabgkszfnbkmffbzbzxjffqbualeytqrphyrbjqdjqavctg");
text.append("xjifqgfgydhoiwhrvwqbxgrixydzbpzjnhopvlazbzumzhhfavoctdfytvvggikngkwzibzbzbzuxgj");
text.append("tlxkojlefilbrboignbzsudssvqynbzuapbpqvlubdoyxkkwhcoudvtkmikbzbzansgsutdjythzl");
string pattern = "bzbzbzu";
string pattern2 = "lbzbzbzu";


printf("Pattern 1 (bzbzbzu):"); searchPattern(text, pattern);
printf("\n\nPattern 2 (lbzbzbzu):"); searchPattern(text, pattern2);

}
