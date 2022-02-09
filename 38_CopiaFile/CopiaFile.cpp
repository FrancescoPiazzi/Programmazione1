using namespace std;

#include "iostream"
#include "fstream"

int main(int argc, char *argv[]){
    fstream input;
    fstream output;
    char buffer[256];

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    do{
        input >> buffer;
        output << buffer;
    } while(!input.eof());
    
    input.close();
    output.close();

	return 0;
}
