using namespace std;

#include "iostream"
#include "fstream"

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

    while(!input.eof()){
        input >> buffer;
        output << buffer;
    }

    input.close();
    output.close();
	return 0;
}
