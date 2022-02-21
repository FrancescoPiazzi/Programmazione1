using namespace std;

#include <iostream>
#include <cmath>
#include <cstring>

char* convertiAN(int, int);
int convertiDaN(char*, int);
char* convertiDaNaM(char*, int, int);
int size(char*);

int main(int argc, char *argv[]){
    char input[100];
    cin >> input;
    char *result = convertiDaNaM(input, 16, 2);
    cout << result << endl;
	return 0;
}

char* convertiDaNaM(char* n, int baseFrom, int baseTo){
    return convertiAN(convertiDaN(n, baseFrom), baseTo);
}

char* convertiAN(int n, int base){
    char *result = new char[100];
    int digit, i=0;
    char convertedDigit;
    while (n != 0){
        digit = n % base;

        if (digit < 10)
            convertedDigit = '0' + digit;
        else
            convertedDigit = digit - 10 + 'A';

        result[i] = convertedDigit;
        n /= base;
        i++;             
    }
    result[i] = '\0';

    int len = size(result)-1;
    for(int i=0; i<len/2; i++){
        char tmp = result[i];
        result[i] = result[len-i];
        result[len-i] = tmp;
    }

    return result;
}

int convertiDaN(char* number, int base){
    long int result = 0;
    int digit;
    int len = size(number);

    for(int i=0; i<len; i++){
        if(number[i] >= '0' && number[i] <= '9')
            digit = (int)(number[i]-'0');
        else
            digit = ((int)(number[i]-'A'))+10;
        result += pow(base, (len-i-1))*digit;
    }
    return result;
}

int size(char* str){
    int size=0;
    while(str[size]!='\0')
        size++;
    return size;
}