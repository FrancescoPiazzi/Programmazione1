using namespace std;

#include "iostream"

struct node{
    node *next;
    int value;
};

struct coda{
    node *head;
    node *tail;
};

void put(coda*&, int);
coda* initCoda(int);
void print(coda*);
int get(coda*&);
void dealloc(coda*&);

int main(int argc, char *argv[]){
    coda* c = initCoda(14);
    int i=0, size=1;
    srand(time(NULL));

    while(i<73){
        if(size==0 || rand()%4!=0){
            int n = rand()%100;
            cout << "Aggiungo " << n << endl;
            put(c, n);
            size++;
        }
        else{
            cout << "Estratto " << get(c) << endl;
            size--;
        }
        i++;
    }

    print(c);
    dealloc(c);
	return 0;
}

void put(coda*& c, int value){
    node* newNode = new node{NULL, value};
    if(c->tail != NULL)
        c->tail->next = newNode;
    else
        c->head->next = newNode;
    c->tail = newNode;
}

coda* initCoda(int value){
    node* head = new node{NULL, value};
    node* tail = NULL;
    coda* c = new coda{head, tail};
    return c;
}

void print(coda* c){
    node* n = c->head;
    while(n != NULL){
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

int get(coda*& c){
    node* nodeToReturn = c->head;
    c->head = c->head->next;
    int valueToReturn = nodeToReturn->value;
    delete nodeToReturn;
    return valueToReturn;
}

void dealloc(coda*& c){
    while(c->head != NULL){
        node* tmp = c->head;
        c->head = c->head->next;
        delete tmp;
    }
    delete c;
}
