using namespace std;

#include "iostream"
#include "fstream"

struct node{
    node *next;
    int value;
};

void put(node*&, int);
node* initPila(int);
void print(node*);
node* get(node*&);
void dealloc(node*&);

int main(){
    fstream input, output;
    node* pila;
    char buffer[256];
    int numero;

    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    if(!input.eof()){
        input >> buffer;
        pila = initPila(atoi(buffer));
    }

    while(!input.eof()){
        input >> buffer;
        put(pila, atoi(buffer));
    }

    while(pila != NULL){
        numero = get(pila)->value;
        output << numero << endl;
    }

    dealloc(pila);

    input.close();
    output.close();

	return 0;
}

void put(node*& pila, int value){
    node* newPila = new node{NULL, value};
    newPila->next = pila;
    pila = newPila;
}

node* initPila(int value){
    node* pila = new node{NULL, value};
    return pila;
}

void print(node* pila){
    while(pila != NULL){
        cout << pila->value << " ";
        pila = pila->next;
    }
    cout << endl;
}

node* get(node*& pila){
    node* nodeToReturn = pila;
    pila = pila->next;
    return nodeToReturn;
}

void dealloc(node*& pila){
    node* tmp;
    while(pila != NULL){
        tmp = pila;
        pila = pila->next;
        delete tmp;
    }
}