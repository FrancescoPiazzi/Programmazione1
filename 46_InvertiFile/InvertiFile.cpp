using namespace std;

#include "iostream"
#include "fstream"
#include "pila.hpp"

int main(){
    fstream input, output;
    char buffer[256];
    int numero;

    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    init();

    while(!input.eof()){
        input >> buffer;
        push(atoi(buffer));
    }

    while(top(numero)){
        output << numero << endl;
        pop();
    }

    deinit();

    input.close();
    output.close();

	return 0;
}
