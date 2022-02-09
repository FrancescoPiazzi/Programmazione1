using namespace std;

#include "iostream"

int pascal(int, int);

int main(int argc, char *argv[]){
    cout << pascal(atoi(argv[1]), atoi(argv[2])) << endl;;
	return 0;
}

int pascal(int r, int c){
    if(c==0 || r==c)
        return 1;
    else
        return pascal(r-1, c-1)+pascal(r-1, c);
}