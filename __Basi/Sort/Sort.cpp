void isort(int* a, int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void fsort(float* a, int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(a[i] > a[j]){
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void csort(char* a, int size){
   for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if((int)a[i] > (int)a[j]){
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	} 
}

void bubbleSortWrapper(int a[], int size){
    bubbleSort(a, 0, size, 0);
}

void bubbleSort(int a[], int index, int size, int iterations){
    if(a[index] > a[index+1]){
        int t;
        t = a[index];
        a[index] = a[index+1];
        a[index+1] = t;
    }
    if(index<size-2){
        bubbleSort(a, index+1, size, iterations);
    }
    if(iterations < size){
        bubbleSort(a, 0, size-1, iterations+1);
    }
}