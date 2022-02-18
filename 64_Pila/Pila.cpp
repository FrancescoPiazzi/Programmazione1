using namespace std;

#include "iostream"

struct node{
    node *next;
    int value;
};

void put(node*&, int);
node* initPila(int);
void print(node*);
int get(node*&);
void dealloc(node*&);

int main(int argc, char *argv[]){
    node* pila = initPila(14);
    int i=0, size=1;
    srand(time(NULL));

    while(i<73){
        if(size==0 || rand()%4!=0){
            int n = rand()%100;
            cout << "Aggiungo " << n << endl;
            put(pila, n);
            size++;
        }
        else{
            cout << "Estratto " << get(pila) << endl;
            size--;
        }
        i++;
    }

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

int get(node*& pila){
    node* nodeToReturn = pila;
    pila = pila->next;
    int valueToReturn = nodeToReturn->value;
    delete nodeToReturn;
    return valueToReturn;
}

void dealloc(node*& pila){
    node* tmp;
    while(pila != NULL){
        tmp = pila;
        pila = pila->next;
        delete tmp;
    }
}