using namespace std;

#include "iostream"

struct node{
    node *next;
    int value;
};

void put(node*&, int);
node* initPila(int);
void print(node*);
node* get(node*&);
void dealloc(node*&);

int main(int argc, char *argv[]){
    node* pila = initPila(14);
    put(pila, 41);
    put(pila, 61);
    put(pila, 72);
    put(pila, 12);

    print(pila);
    dealloc(pila);

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