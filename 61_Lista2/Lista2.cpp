using namespace std;

#include "iostream"

struct node{
    node *next;
    int value;
};

void printLista(node*);
void printRecursive(node*);
node* initLista(int);
void addElement(node*, int);
void addRecursive(node*, int);
node* getNodeAt(node*, int);
node* getRecursive(node*, int);
void removeNode(node*&, int);
void deinit(node*);
void deinitRecursive(node*);

int main(){
    node* n = initLista(15);
    node* nr = initLista(15);
    addElement(n, 51);
    addElement(n, 27);
    addElement(n, 82);
    printLista(n);
    addElement(nr, 51);
    addElement(nr, 27);
    addElement(nr, 82);
    printRecursive(nr);
    cout << getNodeAt(n, 2)->value << endl;
    cout << getRecursive(nr, 2)->value << endl;
    removeNode(n, 3);
    removeNode(nr, 0);
    printLista(n);
    printRecursive(nr);

    deinit(n);
    deinitRecursive(nr);
	return 0;
}

void printLista(node* list){
    while(list != NULL){
        cout << list->value << ",";
        list = list->next;
    }
    cout << endl;
}

void printRecursive(node* list){
    if(list != NULL){
        cout << list->value << ",";
        printRecursive(list->next);
    }
    else
        cout << endl;
}

node* initLista(int startingValue){
    node* n = new node{NULL, startingValue};
    return n;
}

void addElement(node* list, int valueToAdd){
    while(list->next != NULL)
        list = list->next;
    list->next = new node{NULL, valueToAdd};
}

node* getNodeAt(node* list, int position){
    while(position>0){
        list = list->next;
        position--;
    }
    return list;
}

void addRecursive(node* list, int valueToAdd){
    if(list->next == NULL)
        list->next = new node{NULL, valueToAdd};
    else
        addRecursive(list->next, valueToAdd);
}

node* getRecursive(node* list, int position){
    if(position != 0)
        return getRecursive(list->next, --position);
    else
        return list;
}

void removeNode(node* &list, int position){
    node* tmp;
    if(position == 0){
        tmp = list;
        list = list->next;
        delete tmp;
    }
    else{
        node *prev = getNodeAt(list, position-1);
        tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
    }
}

void deinit(node* list){
    node* tmp;
    while(list!=NULL){
        tmp = list;
        list = list->next;
        delete tmp;
    }
}

void deinitRecursive(node* list){
    if(list!=NULL){
        deinitRecursive(list->next);
        delete list;
    }
}