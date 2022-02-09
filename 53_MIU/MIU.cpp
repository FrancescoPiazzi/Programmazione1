using namespace std;

#include "iostream"
#include "fstream"

bool checkMIU(char*);

int main(int argc, char *argv[]){
    fstream input, output;
    char buffer[256];

    if(argc!=3){
        cout << "parametri sbagliati" << endl;
        exit(0);
    }

    input.open(argv[0], ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }
    output.open(argv[1], ios::out);
    if(output.fail()){
        cout << "fallita apertura output" << endl;
        input.close();
        exit(0);
    }

    while(!input.eof()){
        input >> buffer;
        if(checkMIU(buffer))
            output << buffer;
    }

    input.close();
    output.close();
	return 0;
}

bool checkMIU(char* buffer){
    int len=0;
    int nI=0;

    while(buffer[len]!='\0')
        len++;
    if(buffer[0]=='M' && buffer[len-1]!='U')
        return false;
    for(int i=0; i<len; i++){
        if(buffer[i] == 'I')
            nI++;
    }
    if(nI%2==0)
        return false;

    return true;
}