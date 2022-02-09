using namespace std;

#include "iostream"
#include "fstream"

bool checkSeq(char*);

int main(int argc, char *argv[]){
    fstream input, output;
    char buffer[256];
    int nSeq=0;

    input.open("input1", ios::in);
    if(input.fail()){
        cout << "fallita apertura input" << endl;
        exit(0);
    }
    int i=0;
    while(!input.eof()){
        input >> buffer;
        i=0;
        while(i<4 && checkSeq(buffer) && !input.eof()){
            input >> buffer;
            i++;
        }
        if(i==4 && !checkSeq(buffer)) nSeq++;
    }
    if(i==3 && checkSeq(buffer))
        nSeq++;
    cout << nSeq << endl;

    input.close();
	return 0;
}

bool checkSeq(char* s){
    return s[0] >= '0' && s[0] <= '9' && 
            s[1] >= '0' && s[1] <= '9' && 
            s[2] >= '0' && s[2] <= '9' && 
            s[3] >= '0' && s[3] <= '9' && 
            s[4] == '\0';
}