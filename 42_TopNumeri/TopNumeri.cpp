using namespace std;

#include "iostream"
#include "fstream"

void selectionSort(float[], int);
void swap(float &, float &);

int main(int argc, char *argv[]){
	fstream input;
    char buffer[10];
    int N = atoi(argv[2]);
    float *numeri = new float[N];

    input.open(argv[1], ios::in);

    input >> buffer;
    int i=0;
    while(i<N){
        numeri[i] = atof(buffer);
        i++;
        input >> buffer;
    }
    selectionSort(numeri, N);

    for(int i=0; i<N; i++)
        cout << numeri[i] << "  ";

    input.close();
    delete[] numeri;

    cout << endl;
	return 0;
}

void selectionSort(float a[], int n){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i] < a[j])
                swap(a[i], a[j]);
}

void swap(float &a, float &b){
    a = a+b;
    b = a-b;
    a = a-b;
}
