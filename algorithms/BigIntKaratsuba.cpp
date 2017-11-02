//Implemente um programa (em qualquer linguagem) que dado dois números grandes A
//e B (da ordem de 100 dígitos decimais), seja capaz de calcular o produto de A e B.
//
//
//
//b) Utilize a estratégia de divisão e conquista do algoritmo de Karatsuba.


#include <stdio.h>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <algorithm>


using namespace std;

void matchSize(string *s1, string *s2){

    int str1Size, str2Size, diffSize, i = 0;
    string str1 = *s1, str2 = *s2;

    str1Size = str1.size();
    str2Size = str2.size();

    if(str1Size < str2Size){

        diffSize = str2Size - str1Size;

        while(i<diffSize){
            str1.insert(str1.begin(), '0');
            i++;
        }
    }else if(str2Size < str1Size){

        diffSize = str1Size - str2Size;

        while(i<diffSize){
            str2.insert(str2.begin(), '0');
            i++;
        }
    }
    *s1 = str1;
    *s2 = str2;
}

string removeZeros(string s){ // remove zeros digitados no inicio de numeros 

    int i = 0;
    if(s[0]==45){ //verifica se o primeiro digito é um sinal de menos
        i = 1;
    }
    while((s[i]==48)&&(s.size()>1)){ //remove zeros e caracteres indesejados inicio de um numero digitado
        s.erase(s.begin());
    }
    return s;
}


int stringToNum(string s){

    int i = 0, l = 0, n = 0;
    char c;

    l = s.size();

    while(i<l){
        n = n*10 + s[i]-48;
        i++;
    }
    return n;
}


string numToString(int n){

    int m = 0, i = 0, countN = 0;
    string s;

    if(n>0){
        while (n>0) {
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


string sumString(string str1, string str2){

    string result;
    int strSize, carry = 0, sum, n1, n2, i = 0, j = 0;

    str1 = removeZeros(str1);
    str2 = removeZeros(str2);

    if(str1.size()<=str2.size()){
        i = str1.size()-1;
        j = str2.size()-1;
    }else{
        swap(str1, str2);
        i = str1.size()-1;
        j = str2.size()-1;
    }

    while(i >= 0){
        n1 = str1[i]-48;
        n2 = str2[j]-48;

        sum = n1 + n2 + carry;
        result.push_back(sum%10+48);

        if(sum>=10){
            carry = sum/10;
        }else{
            carry = 0;
        }
        i--;
        j--;
    }

    while(j >= 0){
        n1 = str2[j]-48;
        sum = n1 + carry;
        result.push_back(sum%10+48);

        if(sum>=10){
            carry = sum/10;
        }else{
            carry = 0;
        }
        j--;
    }

    if(carry>0){
        result.push_back(carry+48);
    }

    reverse(result.begin(), result.end());
    return result;
}


string subtractString(string str1, string str2){

    string result;
    int strSize, substract, n1, n2, nAux, i = 0, j = 0, k = 0;

    i = str1.size()-1;
    j = str2.size()-1;

    while(j >= 0){
        n1 = str1[i]-48;
        n2 = str2[j]-48;

        if(n1<n2){
            n1 += 10;
            k = i-1;
            while(str1[k]=='0'){
                str1.erase(str1.begin()+k);
                str1.insert(str1.begin()+k,'9');
                k--;
            }
            nAux = str1[k]-48;
            nAux--;
            str1.erase(str1.begin()+k);
            str1.insert(str1.begin()+k, nAux+48);
        }

        substract = n1 - n2;
        result.push_back(substract%10+48);

        i--;
        j--;
    }

    while(i >= 0){
        result.push_back(str1[i]);
        i--;
    }

    reverse(result.begin(), result.end());
    result = removeZeros(result);

    return result;
}

string karatsuba(string str1, string str2, int sizeStr){

    matchSize(&str1,&str2);

    if(sizeStr < 5){
        return removeZeros(numToString(stringToNum(str1)*stringToNum(str2)));
    }else   {
        int m;

        m = sizeStr/2 + sizeStr%2;

        string strA = str1.substr(0, str1.size()-m); // u / 10^m
        string strB = str1.substr(str1.size()-m, m); // u mod 10^m
        string strC = str2.substr(0, str2.size()-m); // v / 10^m
        string strD = str2.substr(str2.size()-m, m); // v mod 10^m
        string strAC;
        string strBD;
        string strX;
        string strY;
        string strAux;

        matchSize(&strA,&strB);
        matchSize(&strC,&strD);

        strAC = karatsuba(strA,strC,m);
        strBD = karatsuba(strB,strD,m);

        strY = karatsuba(sumString(strA,strB),sumString(strC,strD),m+1);

        strAux = subtractString(strY,sumString(strAC,strBD));
        strAC.append(2*m, '0');
        strAux.append(m, '0');

        strX = sumString(sumString(strAC,strAux),strBD);

        return strX;
    }
}

int main () {

    string str1, str2, result;
    int sizeStr;
    bool negative = false;

    printf("\nMultiplicacao de inteiros grandes - Karatsuba\n");
    printf("\nDigite o inteiro A: ");
    cin >> str1;
    printf("\nDigite o inteiro B: ");
    cin >> str2;

    str1 = removeZeros(str1);
    str2 = removeZeros(str2);

    if((str1[0]==45)||(str2[0]==45)){ //verifica se um dos digitos é negativo
        if((str1[0]==45)&&(str2[0]==45)){ //remove o sinal caso ambos sejam negativos
            str1.erase(str1.begin());
            str2.erase(str2.begin());
        }else if(str1[0]==45){ // guarda o sinal caso um dos digitos seja negativo
            negative = true;
            str1.erase(str1.begin());
        }else if(str2[0]==45){
            negative = true;
            str2.erase(str2.begin());
        }
    }

    matchSize(&str1,&str2);
    sizeStr = str1.size();
    result = karatsuba(str1, str2, sizeStr);

    if(negative){
        result.insert(result.begin(),'-');
    }
    cout << "\n\nKaratsuba: " << result << "\n\n";

}
