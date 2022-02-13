using namespace std;

#include <iostream>
#include <fstream>

struct node{
    node *next;
    int value;
    char op;
};

void printLista(node*);
node* initLista(int);
void addElement(node*, int, char, bool);
node* getNodeAt(node*, int);

int evaluate(node*);

int main(int argc, char *argv[]){
    fstream input;
    char buffer[10];

    input.open(argv[1], ios::in);

    input >> buffer;
    node* lista = initLista(atoi(buffer));

    while(input >> buffer){
        if(buffer[0] == '+' || buffer[0] == '*' || buffer[0] == '-')
            addElement(lista, 0, buffer[0], false);
        else
            addElement(lista, atoi(buffer), '.', true);
    }

    cout << evaluate(lista) << endl;

	return 0;
}

int evaluate(node* lista){
    node* ptr = getNodeAt(lista, 1);
    node* prevptr = getNodeAt(lista, 0);
    while(ptr != NULL){
        if(ptr->op == '*'){
            prevptr->value = (prevptr->value)*(ptr->next->value);
            node* tmp1 = ptr;
            node* tmp2 = ptr->next;
            ptr = ptr->next->next;
            prevptr->next = ptr;
            delete tmp1, tmp2;
        }
        else{
            prevptr = ptr;
            ptr = ptr->next;
        }
    }

    ptr = getNodeAt(lista, 1);
    prevptr = getNodeAt(lista, 0);
    while(ptr != NULL){
        if(ptr->op == '+' || ptr->op == '-'){
            if(ptr->op == '+')
                prevptr->value = (prevptr->value)+(ptr->next->value);
            else
                prevptr->value = (prevptr->value)-(ptr->next->value);
            node* tmp1 = ptr;
            node* tmp2 = ptr->next;
            ptr = ptr->next->next;
            prevptr->next = ptr;
            delete tmp1, tmp2;
        }
        else{
            prevptr = ptr;
            ptr = ptr->next;
        }
    }

    return getNodeAt(lista, 0)->value;
}

void printLista(node* list){
    while(list != NULL){
        if(list->op == '.')
            cout << list->value;
        else
            cout << list->op;
        list = list->next;
    }
    cout << endl;
}

node* initLista(int startingValue){
    node* n = new node{NULL, startingValue, '.'};
    return n;
}

void addElement(node* list, int valueToAdd, char opToAdd, bool addValue){
    while(list->next != NULL)
        list = list->next;

    list->next = addValue ? new node{NULL, valueToAdd, '.'} : new node{NULL, 0, opToAdd};
}

node* getNodeAt(node* list, int position){
    while(position>0){
        list = list->next;
        position--;
    }
    return list;
}
