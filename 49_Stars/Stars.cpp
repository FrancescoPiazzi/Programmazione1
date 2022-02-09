using namespace std;

#include "iostream"
#include "fstream"

int starsToN(char[11]);

int main(int argc, char *argv[]){
    fstream input, output;
    char buffer[11];
    int avg = 0;
    int n = 0;

    if(argc != 2){
        cout << "parametri sbagliati" << endl;
        exit(0);
    }

    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }

    while(!input.eof()){
        input >> buffer;
        avg += starsToN(buffer);
        n++;
    }
    avg = avg/n;
    input.close();

    output.open(argv[1], ios::app);
    if(output.fail()){
        cout << "fallita apertura output" << endl;
        exit(0);
    }

    output << " ";
    for(int i=0; i<avg; i++){
        output << '*';
    }
    output.close();

    cout << "La media è: " << avg << endl;
	return 0;
}

int starsToN(char stars[11]){
    int len=0;
    while(stars[len] == '*'){
        len++;
    }
    return len;
}