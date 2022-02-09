using namespace std;

#include "iostream"
#include "fstream"
#include "cstring"

int main(int argc, char *argv[]){
    // Preparativi vari
    fstream input1;
    fstream input2;
    fstream output;

    char buffer[101];

    char parole1[1000][100];
    char parole2[1000][100];
    char intersezione[1000][100];
    bool duplicato[1000];
    int size1, size2, size3=0;

    for(int i=0; i<1000; i++)
        duplicato[i] = false;

    input1.open(argv[1], ios::in);
    input2.open(argv[2], ios::in);
    output.open(argv[3], ios::out);

    // Leggo i file in modo da poter lavorare con degli array, più comodi
    int i;
    for(i=0; input1 >> buffer ; i++)
        strcpy(parole1[i], buffer);
    size1=i;
    for(i=0; input2 >> buffer; i++)
        strcpy(parole2[i], buffer);
    size2=i;
    input1.close();
    input2.close();

    // Creo l'array delle parole comuni
    for(int i=0; i<size1; i++)
        for(int j=0; j<size2; j++)
            if(!strcmp(parole1[i], parole2[j]))
                strcpy(intersezione[size3++], parole1[i]);

    // Elimino i duplicati
    for(int i=0; i<size3-1; i++)
        for(int j=i+1; j<size3; j++)
            if(!strcmp(intersezione[i], intersezione[j]))
                duplicato[j] = true;

    // Scrivo il risultato
    for(int i=0; i<size3; i++)
        if(!duplicato[i])
            output << intersezione[i] << endl;

    output.close();
	return 0;
}
