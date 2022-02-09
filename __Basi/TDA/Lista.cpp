#include "iostream"

using namespace std;

// Questa l'ho scritta io, fa un po'schifo ma è quella con più potenziale 😊

struct node{
    int value;
    struct node *next;
};

void addNode(node*, int);
void delNode(node*, int);
node* getNode(node*, int);
void print(node*);

int main(){
    node n = {10, NULL};
    node *pn = &n;

    addNode(pn, 2);
    addNode(pn, 4);
    addNode(pn, 6);
    addNode(pn, 8);

    print(pn);

    delNode(pn, 2);
    delNode(pn, 2);

    print(pn);

    cout << endl;
    return 0;
}

void addNode(node* n, int value){
    node* nodeToAdd = new node{value, NULL};
    while(n->next != NULL){
        n = n->next;
    }
    n->next = nodeToAdd;
}

void delNode(node* head, int n){
    for(int i=0; i<n-1; i++){
        head = head->next;
    }
    node* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    delete nodeToDelete;
}

node* getNode(node * firstNode, int pos){
    node* pointer = firstNode;
    for(int i=0; i<pos; i++){
        pointer = pointer->next;
    }
    return pointer;
}

void print(node* n){
    cout << "-----------------------" << endl;
    while(n != NULL){
        cout << n << "  " << n->value << "  " << n->next << endl;
        n = n->next;
    }
    cout << "-----------------------" << endl << endl;
}
