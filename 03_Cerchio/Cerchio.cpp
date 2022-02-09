using namespace std;

#include "iostream"

int main(){
  const float PI = 3.1415926;
  float r;

  //do{
  //  cin.clear();
    cout << "Raggio del cerchio: ";
    cin >> r;
  //}while(cin.fail());

  cout << "Area: " << r*r*PI << endl;
  cout << "Circonferenza: " << r*2*PI << endl;
}
