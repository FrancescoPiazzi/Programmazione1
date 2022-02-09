/* Utilizzando le funzioni scritte precedentemente, scrivere un programma
che, dato in input un file contenente i dati di alcuni studenti e il numero di
righe del file, generi un array dinamico che contenga tutti questi studenti. E’
consigliato raggruppare questa logica all’interno di una funzione separata.
Utilizzare la libreria fstream. */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int DIM = 50;

struct Studente{
    char nome[DIM];
    char cognome[DIM];
    int matricola;
    float media;
};

Studente genera_studente(char*, char*, int, float);
void stampa_studente(const Studente&);
void inserisci_studenti(Studente*, int, fstream&);

int main(int argc, char * argv[]){
    if(argc != 3){
        cerr << "Usage: ./a.out <studenti> <N>\n";
        exit(0);
    }

    int N = atoi(argv[2]);

    fstream file;
    file.open(argv[1], ios::in);
    if(file.fail()){
        cerr << "Errore apertura file\n";
        exit(1);
    }

    Studente * database = new Studente[N];

    inserisci_studenti(database, N, file);

    for(int i=0; i<N; i++){
        stampa_studente(database[i]);
        cout << endl;
    }
    
    file.close();
    return 0;
}

void stampa_studente(const Studente& s){ //passare struct per riferimento con const se possibile
    cout << "Nome: " << s.nome << endl;
    cout << "Cognome: " << s.cognome << endl;
    cout << "Matricola: " << s.matricola << endl;
    cout << "Media ponderata: " << s.media << endl;
}

void inserisci_studenti(Studente* database, int N, fstream& file){
    char buffer[DIM];
    for(int i=0; i<N; i++){
        file >> database[i].nome;
        file >> database[i].cognome;

        file >> buffer;
        database[i].matricola = atoi(buffer);

        file >> buffer;
        database[i].media = atof(buffer);
    }
}