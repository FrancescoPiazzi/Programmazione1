using namespace std;

#include "iostream"

int calcolaIt(int, int, int);

int main(){
    int x=10, y=2;
	cout << calcolaIt(x, y, 0) << endl;
	return 0;
}

int calcolaIt(int x, int y, int res){
    if(x>=y)
        calcolaIt(x-y, y, ++res);
    else
        return res;
}