using namespace std;

#include "iostream"
#include "fstream"

int main(int argc, char *argv[]){
    fstream input, output;
    char parole[10000][256];

    if(argc != 3){
        cout << "input errati." 
            << "Uso: ./CopiaPariInversi <input> <output>" 
            << endl;
    }

    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }
    output.open(argv[2], ios::out);
    if(output.fail()){
        cout << "fallita apertura output" << endl;
        input.close();
        exit(0);
    }

    int i=0;
    while(!input.eof()){
        input >> parole[i];
        i++;
    }
    input.close();

    for(int j=i-1; j>=0; j--){
        int len=0;
        while(parole[j][len] != '\0'){
            len++;
        }
        if(len%2==0){
            output << parole[j] << " ";
        }
    }

    output.close();
	return 0;
}
