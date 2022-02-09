using namespace std;

#include "iostream"

int main(){
    char chars[] = {'A', 'B', 'C', 'D', 'E'};
    int j;
    cin >> j;
    j = j%5;

    char *extraChars = new char[j];

    for(int i=0; i<j; i++)
        extraChars[i] = chars[i];
    for(int i=0; i<5-j; i++)
        chars[i] = chars[i+j];
    for(int i=5-j; i<5; i++)
        chars[i] = extraChars[i-5+j];

    for(int i=0; i<5; i++)
        cout << chars[i] << " ";
    cout << endl;

	return 0;
}
