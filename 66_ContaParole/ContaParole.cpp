using namespace std;

#include "iostream"
#include "fstream"
#include "cstring"

struct node{
    node *next;
    int occurences;
    char* word;
};

void printLista(node*);
node* initLista();
void addElement(node*&, char*);
node* getNodeAt(node*, int);
void deinit(node*);

int search(node*, char*);
int strCmp(char*, char*);

int main(int argc, char *argv[]){
    fstream input, output;
    char buffer[256];

    input.open("input", ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }
    output.open("output", ios::out);
    if(output.fail()){
        cout << "fallita apertura output" << endl;
        input.close();
        exit(0);
    }

    node* words = NULL;

    while(input >> buffer){
        // cout << "Cerco " << buffer << endl;
        int n = search(words, buffer);
        if(n == -1){
            // cout << "non l'ho trovato, lo aggiungo" << endl;
            addElement(words, buffer);
        }
        else{
            // cout << "Trovato!: " << n << endl;
            getNodeAt(words, n)->occurences++;
        }
    }

    printLista(words);

    input.close();
    output.close();
	return 0;
}

int search(node* words, char* word){
    int n=-1, i=0;
    // cout << words->word;
    while(words!=NULL && n==-1){
        // cout << "   " << words->word << " " << word << endl;
        if(!strCmp(words->word, word)){
            n = i;
        }
        words = words->next;
        i++;
    }
    return n;
}

void printLista(node* list){
    while(list != NULL){
        cout << list->word << "\t\t " << list->occurences << endl;
        list = list->next;
    }
    cout << endl;
}

void addElement(node*& list, char* wordToAdd){
    char* wordToAdd2 = new char;
    strcpy(wordToAdd2, wordToAdd);
    if(list == NULL){  // eseguito solo la prima volta
        // cout << "aggiungo il primo nodo" << endl;
        list = new node{NULL, 1, wordToAdd2};
        // cout << "Aggiunto primo nodo: " << wordToAdd2 << endl;
    }
    else{
        node* tmp = list;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new node{NULL, 1, wordToAdd2};
        // cout << "Aggiunto n-esimo nodo" << endl;
    }
}

node* getNodeAt(node* list, int position){
    while(position>0){
        list = list->next;
        position--;
    }
    return list;
}

void deinit(node* list){
    while(list!=NULL){
        node* tmp = list;
        list = list->next;
        delete tmp;
    }
}

int strCmp(char* s1, char* s2){
	int i=0;
	int res=2;	// a fine funzione questo valore non deve MAI essere 2

	while(s1[i]!='\0' && s2[i]!='\0' && res==2){
		if((int)s1[i] > (int)s2[i])
			res=1;
		if((int)s1[i] < (int)s2[i])
			res=-1;
		i++;
	}
	if(res==2){	// almeno una delle due è a \0
		if(s1[i] != '\0')	// è la seconda, la prima è più lunga
			res=1;
		else if(s2[i] != '\0')	// è la prima, la seconda è più lunga
			res=-1;
		else		// sono uguali
			res=0;
	}
	return res;
}