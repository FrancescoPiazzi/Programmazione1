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
void scambia(node*&, int, int);
void deinit(node*);
void deinitRecursive(node*);

int main(){
    node* n = initLista(15);
    node* nr = initLista(15);
    addElement(n, 51);
    addElement(n, 27);
    addElement(n, 82);
    addElement(n, 62);
    addElement(n, 73);
    printLista(n);
    addElement(nr, 51);
    addElement(nr, 27);
    addElement(nr, 82);
    printRecursive(nr);
    cout << getNodeAt(n, 2)->value << endl;
    cout << getRecursive(nr, 2)->value << endl;
    removeNode(n, 3);
    removeNode(nr, 0);
    scambia(n, 0, 3);
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

void scambia(node*&list, int pos1, int pos2){ 
    node *prev1=NULL, *prev2=NULL, *list1=list, *list2=list;
    while(list1!=NULL && pos1>0){
        prev1 = list1;
        list1 = list1->next;
        pos1--;
    }
    while(list2!=NULL && pos2>0){
        prev2 = list2;
        list2 = list2->next;
        pos2--;
    }

    if(prev1 != NULL)
        prev1->next = list2;
    else
        list = list2;

    if(prev2 != NULL)
        prev2->next = list1;
    else
        list = list1;
 
    node* tmp = list2->next;
    list2->next = list1->next;
    list1->next = tmp;
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