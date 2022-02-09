int size(char* str){
    int size=0;
    while(str[size]!='\0')
        size++;
    return size;
}

char* substringFromTo(char* str, int start, int stop){
    char* substring = new char[stop-start+1];
    for(int i=0; i<stop-start; i++){
        substring[i] = str[start+i];
    }
    substring[stop-start] = '\0';
    return substring;
}

char* substringFrom(char* str, int start){
    char* substring = new char[size(str)-start+1];
    for(int i=0; i<size(str)-start; i++){
        substring[i] = str[start+i];
    }
    substring[size(str)-start] = '\0';
    return substring;
}

char* substringTo(char* str, int stop){
    char* substring = new char[stop+1];
    for(int i=0; i<stop; i++){
        substring[i] = str[i];
    }
    substring[stop] = '\0';
    return substring;
}

int strCmp(char* s1, char* s2){
	int i=0;
	int res=2;	// a fine funzione questo valore non deve MAI essere 2

	while(s1[i]!='\0' && s2[i]!='\0' && res==2){
		if((int)s1[i] > (int)s2[i])
			res=1;
		if((int)s1[i] < (int)s2[i])
			res=-1;
		i++;
	}
	if(res==2){	// almeno una delle due è a \0
		if(s1[i] != '\0')	// è la seconda, la prima è più lunga
			res=1;
		else if(s2[i] != '\0')	// è la prima, la seconda è più lunga
			res=-1;
		else		// sono uguali
			res=0;
	}
	return res;
}

char** split(char* str, char separator, int &sizeParameter){
    int nElements=0;
    int size=0;
    // Calcolo la dimensione dell'array di stringhe risultato
    for(int i=0; str[i]!='\0'; i++){
        size++;
        if(str[i]==separator)
            nElements++;
    }
    nElements++;    // n separatori => n+1 elementi
    sizeParameter = nElements;

    int k=0;
    // Calcolo la lunghezza delle stringhe
    int* sizes = new int[nElements];
    for(int i=0; i<nElements; i++){
        sizes[i]=0;
        int j;
        for(j=k; str[j]!=separator && str[j]!='\0'; j++){
            sizes[i]++;
            k++;
        }
        k++;
    }

    // Costruisco l'array risultato
    char** result = new char*[nElements];
    k=0;
    for(int i=0; i<nElements; i++){
        result[i] = new char[sizes[i]+1];
        for(int j=0; j<sizes[i]; j++){
            result[i][j] = str[k];
            k++;
        }
        result[i][sizes[i]] = '\0';
        k++;
    }

    delete[] sizes;
    return result;
}