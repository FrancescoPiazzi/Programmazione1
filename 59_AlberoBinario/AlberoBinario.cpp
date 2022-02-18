#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;

albero creaAlbero(char * file);
void put(albero radice, nodo* nuovoNodo);
void print(albero radice, int spazio=0);
void invert(albero radice);
void deinit(albero radice);

int main (int argc, char * argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <file>" << endl;
        exit(1);
    }
    
    albero radice = creaAlbero(argv[1]);
    
    if (radice == NULL)
        cout << "Errore nella creazione dell'albero" << endl;
    else{
        print(radice);
        cout << endl << "-------" << endl;
        invert(radice);
        print(radice);
    }

    deinit(radice);
    return 0;
}

albero creaAlbero(char * file) {
    albero radice = NULL;
    fstream input;
    
    input.open(file, ios::in);
    if (input.fail()) {
        cout << "Errore in lettura" << endl;
    }
    else {
        int numero;
        input >> numero;
        radice = new nodo{numero, NULL , NULL};    
        
        while(input >> numero) {
            nodo* nuovoNodo = new nodo{numero, NULL, NULL};
            put(radice, nuovoNodo);
        }
        input.close();
    }
    return radice;
}


void put(albero radice, nodo* nuovoNodo) {
    if (nuovoNodo->value > radice->value)
        if (radice->right == NULL)
            radice->right = nuovoNodo;
        else
            put(radice->right, nuovoNodo);
    else
        if (radice->left == NULL)
            radice->left = nuovoNodo;
        else 
            put(radice->left, nuovoNodo);
}

void invert(albero node){
    albero tmp;
    tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    if(node->left!=NULL)
        invert(node->left);
    if(node->right!=NULL)
        invert(node->right);
}

void print(albero radice, int spazio) {
   if (radice != NULL) {
    spazio ++;
    
    print(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    print(radice->left, spazio);
   }
}

void deinit(albero radice){
    if(radice->left != NULL)
        deinit(radice->left);
    if(radice->right != NULL)
        deinit(radice->right);
    delete radice;
}