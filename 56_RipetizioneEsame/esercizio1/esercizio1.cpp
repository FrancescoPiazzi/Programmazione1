using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

long int convertBase(char*);

int main(int argc, char *argv[]){
    fstream input;
    fstream output;
    char n1[10];
    char n2[11];    // deve tenere anche il \n alla fine
    char op;
    long int result;

    if(argc != 3){
        cout << "Usage: esercizio1.out <input> <output>" << endl;
        exit(0);
    }

    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "Errore nell'apertura dell'input" << endl;
        exit(0);
    }
    output.open(argv[2], ios::out);
    if(output.fail()){
        cout << "Errore nell'apertura dell'output" << endl;
        input.close();
        exit(0);
    }

    while(!input.eof()){
        input >> n1;
        input >> op;
        input >> n2;

        switch (op) {
            case '-':
                result = convertBase(n1)-convertBase(n2);
                break;
            case '/':
                result = convertBase(n1)/convertBase(n2);
                break;
            case '%':
                result = convertBase(n1)%convertBase(n2);
                break;
            default:
                break;
        }

        output << result << endl;
    }

    input.close();
    output.close();

	return 0;
}

long int convertBase(char* number){
    long int result = 0;
    int digit;
    int len = strlen(number);

    for(int i=0; i<len; i++){
        if(number[i] >= '0' && number[i] <= '9')
            digit = (int)(number[i]-'0');
        else
            digit = ((int)(number[i]-'A'))+10;
        result += pow(17, (len-i-1))*digit;
    }
    return result;
}