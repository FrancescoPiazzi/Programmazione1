using namespace std;

#include "iostream"

int* put(int*, int, int);
int* initPila();
void print(int*, int);
int* get(int*, int);
void dealloc(int*, int);

int main(int argc, char *argv[]){
    int* pila = initPila();

    pila = put(pila, 623, 0);
    pila = put(pila, 132, 1);
    pila = put(pila, 13, 2);

    print(pila, 3);

	return 0;
}

int* put(int* pila, int value, int size){
    int* newPila = new int[size+1];
    for(int i=0; i<size; i++)
        newPila[i] = pila[i];
    newPila[size] = value;
    delete[] pila;
    return newPila;
}

int* initPila(){
    int* pila = new int[1];
    return pila;
}

void print(int* pila, int size){
    for(int i=0; i<size; i++)
        cout << pila[i] << " ";
    cout << endl;
}