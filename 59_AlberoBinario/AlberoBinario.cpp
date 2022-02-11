#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero creaAlberoDiRicercaBinaria(char * file);
void inserisciNodo(albero radice, nodo* nuovoNodo);
void stampaAlbero(albero radice, int spazio=0);
void invert(albero radice);


int main (int argc, char * argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <file>" << endl;
        exit(1);
    }
    
    albero radice = creaAlberoDiRicercaBinaria(argv[1]);


    
    if (radice == NULL)
        cout << "Errore nella creazione dell'albero" << endl;
    else{
        stampaAlbero(radice);
        cout << endl << "-------" << endl;
        invert(radice);
        stampaAlbero(radice);
    }

    return 0;
}

albero creaAlberoDiRicercaBinaria(char * file) {
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
            inserisciNodo(radice, nuovoNodo);
        }
        input.close();
    }
    return radice;
}


void inserisciNodo(albero radice, nodo* nuovoNodo) {
    if (nuovoNodo->value > radice->value)
        if (radice->right == NULL)
            radice->right = nuovoNodo;
        else
            inserisciNodo(radice->right, nuovoNodo);
    else
        if (radice->left == NULL)
            radice->left = nuovoNodo;
        else 
            inserisciNodo(radice->left, nuovoNodo);
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

void stampaAlbero(albero radice, int spazio) {
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}
