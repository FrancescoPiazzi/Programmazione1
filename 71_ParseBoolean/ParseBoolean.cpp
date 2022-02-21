using namespace std;

#include "iostream"
#include "fstream"

struct node{
    node *next;
    int value;
};

void put(node*&, int);
node* initPila(int);
void print(node*);
int get(node*&);
void dealloc(node*&);

bool eval(char*);
int toNumber(char);

// &!FT non funziona ma vabbè

int main(int argc, char *argv[]){
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()){
        cout << "Fallita apertura input" << endl;
        exit(0);
    }
    if(input.fail()){
        cout << "Fallita apertura output" << endl;
        input.close();
        exit(0);
    }

    char s[100];
    while(input >> s){
        bool res = eval(s);
        output << res << endl;
    }

    input.close();
    output.close();
	return 0;
}

bool eval(char* s){
    bool result = true;
    node* values = NULL;
    node* operations = NULL;
    int i=0;

    while(s[i]!='\0'){
        if(s[i]=='T' || s[i]=='F'){
            if(values==NULL)
                values = initPila(toNumber(s[i]));
            else
                put(values, toNumber(s[i]));
        }
        else{
            if(operations==NULL)
                operations = initPila(toNumber(s[i]));
            else
                put(operations, toNumber(s[i]));
        }
        i++;
    }

    while(operations!=NULL){  // esco se ho solo un valore e 0 operazioni
        // print(values);
        // print(operations);
        // cout << endl;
        char op = get(operations);
        if(op==1)
            put(values, !(bool)get(values));
        else
            put(values, (bool)get(values)&&(bool)get(values));
    }

    /*cout << "----" << endl;
    print(values);
    print(operations);
    cout << "----" << endl;*/

    result = (bool)values->value;

    dealloc(values);
    dealloc(operations);
    return result;
}

int toNumber(char c){
    return (c=='T' || c=='!') ? 1 : 0;
}

void put(node*& pila, int value){
    node* newPila = new node{pila, value};
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