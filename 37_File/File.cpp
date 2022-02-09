using namespace std;

#include "iostream"
#include "fstream"

int main(){
	char buffer[256];
    int n;

    fstream input;
    fstream output;

    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    do{
        input >> buffer;
    } while(!input.eof());

    n = atof(buffer);
    output << n*2;

    input.close();
    output.close();
    
	return 0;
}
