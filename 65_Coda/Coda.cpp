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
node* get(coda*&);
void dealloc(coda*&);

int main(int argc, char *argv[]){
    coda* c = initCoda(14);
    put(c, 41);
    put(c, 61);
    put(c, 72);
    put(c, 12);

    print(c);
    dealloc(c);

    if(c == NULL)
        cout << "yeeee";
    else
        cout << "impossibile, è ancora viva: " << c;
    cout << endl;

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

node* get(coda*& c){
    node* nodeToReturn = c->head;
    c->head = c->head->next;
    return nodeToReturn;
}

void dealloc(coda*& c){
    while(c->head != NULL){
        node* tmp = c->head;
        c->head = c->head->next;
        cout << "elimino " << tmp << endl;
        delete tmp;
    }
    cout << "elimino la coda: " << c << endl;
    delete c;
}
