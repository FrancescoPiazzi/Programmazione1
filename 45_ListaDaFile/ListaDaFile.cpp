using namespace std;

#include "iostream"
#include "fstream"

struct node{
    int value;
    node* next;
};

void inversePrint(node*);

int main(){
    fstream input;
    char buffer[256];
    node *head = new node;
    node *prevNode = head;

    input.open("input.txt", ios::in);

    input >> buffer;
    head->value = atoi(buffer);

    while(!input.eof()){
        node *newNode = new node;
        input >> buffer;
        newNode->value = atoi(buffer);
        prevNode->next = newNode;
        prevNode = newNode;
    }
    node *head2 = head;
    while(head2 != NULL){
        cout << head2 << "  " << head2->value << "  " << head2->next << endl;
        head2 = head2->next;
    }

    head2 = head;
    cout << endl;
    inversePrint(head2);
    cout << endl;

    while(head != NULL){
        node *tmp = head;
        head = head->next;
        delete tmp;
    }

	return 0;
}

void inversePrint(node *n){
    if(n->next != NULL)
        inversePrint(n->next);
    cout << n->value << "  ";
}