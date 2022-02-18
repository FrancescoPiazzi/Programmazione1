using namespace std;

#include "iostream"

int* put(int*, int, int);
int* initPila();
void print(int*, int);
int* get(int*, int&, int);
void dealloc(int*, int);

int main(int argc, char *argv[]){
    int* pila = initPila();
    int i=0, size=0;
    srand(time(NULL));

    while(i<73){
        if(size==0 || rand()%4!=0){
            int n = rand()%100;
            cout << "Aggiungo " << n << endl;
            pila = put(pila, n, size);
            size++;
        }
        else{
            int n;
            pila = get(pila, n, size);
            cout << "Estratto " << n << endl;
            size--;
        }
        i++;
    }

    print(pila, size);
    delete[] pila;
	return 0;
}

int* get(int* pila, int& value, int size){
    if(pila!=NULL){
        int* newPila = new int[size-1];
        for(int i=0; i<size-1; i++)
            newPila[i] = pila[i];
        value = pila[size-1];
        delete[] pila;
        return newPila;
    }
    return NULL;
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
    cout << "[";
    for(int i=0; i<size; i++)
        cout << pila[i] << ",";
    cout << "]" << endl;
}