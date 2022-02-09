using namespace std;

#include "iostream"
#include "fstream"

struct node{
    int value;
    struct node *left;
    struct node *right;
};

void insert(int, node*);
void stampaAlbero(node*, int spazio=0);
void stampaSequenza(node*);
void ricerca(node*, int, char*, int &depth);
void free(node*);

int main(int argc, char *argv[]){
    fstream input;
    char buffer[256];
    int n;

    input.open("input", ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }

    input >> buffer;
    n = atoi(buffer);

    node *root = new node{n, NULL, NULL};

    while(!input.eof()){
        input >> buffer;
        n=atoi(buffer);
        insert(n, root);
    }
    input.close();

    stampaAlbero(root);
    stampaSequenza(root);
    cout << endl;

    char* path = new char[10];
    int depth;

    ricerca(root, 9, path, depth);

    for(int i=0; i<depth; i++){
        cout << path[i] << " ";
    }
    cout << endl;

    free(root);

	return 0;
}

void insert(int n, node* root){
    if(n < root->value){
        if(root->left == NULL){
            node *newNode = new node{n, NULL, NULL};
            root->left = newNode;
        }
        else{
            insert(n, root->left);
        }
    }
    else{
        if(root->right == NULL){
            node *newNode = new node{n, NULL, NULL};
            root->right = newNode;
        }
        else{
            insert(n, root->right);
        }
    }
}

void stampaSequenza(node *root){
    if(root != NULL){
        stampaSequenza(root->right);
        cout << root->value << " ";
        stampaSequenza(root->left);
    }
}

void ricerca(node* root, int n, char* path, int &depth){
    if(n != root->value){
        if(n<root->value){
            path[depth] = 'L';
            ricerca(root->left, n, path, ++depth);
        }
        else{
            path[depth] = 'R';
            ricerca(root->right, n, path, ++depth);
        }
    }
}

void free(node* root){
    if(root->right != NULL)
        free(root->right);
    if(root->left != NULL)
        free(root->left);
    delete root;
}

void stampaAlbero(node* radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
    //  TODO: deallocare la memoria
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}
