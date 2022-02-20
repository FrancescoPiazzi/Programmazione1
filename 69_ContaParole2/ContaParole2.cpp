#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct node{
    char* word;
    int n;
    node* next;
};

void addNode(node*, char*);
void increase(node*, int);
int search(node*, char*);
node* getNodeAt(node*, int);
void sort(node*);
void print(node*);

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Usage: " << argv[0] << " <input> <output>" << endl;
        exit(0);
    }

    fstream input, output;
    char buffer[20];
    node* words;

    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "Fallita apertura input" << endl;
        exit(0);
    }
    output.open(argv[2], ios::out);
    if(output.fail()){
        cout << "Fallita apertura output" << endl;
        input.close();
        exit(0);
    }

    input >> buffer;
    char buffer2[20];
    strcpy(buffer2, buffer);
    words = new node{buffer2, 1, NULL};

    while(input >> buffer){
        // cout << "Cerco " << buffer << endl;
        int pos = search(words, buffer);
        if(pos == -1)
            addNode(words, buffer);
        else
            increase(words, pos);
    }
    sort(words);
    print(words);

    input.close();
    output.close();
}

void addNode(node* list, char* word){
    char* wordToAdd = new char;
    strcpy(wordToAdd, word);

    while(list->next!=NULL)
        list=list->next;

    list->next = new node{wordToAdd, 1, NULL};
}

void increase(node* list, int pos){
    while(pos >= 0){
        list=list->next;
        pos--;
    }
    list->n++;
}

int search(node* list, char* word){
    int pos = -1;
    while(list!=NULL && strcmp(list->word, word)){
        list=list->next;
        pos++;
    }
    return list==NULL ? -1 : pos;
}

void print(node* list){
    while(list!=NULL){
        cout << list->word << "\t" << list->n << endl;
        list = list->next;
    }
}

void sort(node* list){
    node *list1=list, *list2=list;
    node *prev1=NULL, *prev2=NULL;
    while(list1!=NULL){
        while(list2!=NULL){
            // cout << list1->word << " " << list2->word << endl;
            if(list1->n > list2->n){
                int tmp1;
                char* tmp2;

                tmp1 = list1->n;
                list1->n = list2->n;
                list2->n = tmp1;

                tmp2 = list1->word;
                list1->word = list2->word;
                list2->word = tmp2;
            }
            prev2 = list2;
            list2 = list2->next;
        }
        prev1=list1;
        list1 = list1->next;
        list2 = list;
        prev2 = NULL;
    }
}

node* getNodeAt(node* list, int position){
    while(position>0){
        list = list->next;
        position--;
    }
    return list;
}