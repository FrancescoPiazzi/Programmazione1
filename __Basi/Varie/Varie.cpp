bool isNum(char a){
	return a>='0' && a<='9';
}
bool isLowerCase(char a){
	return a>='a' && a<='z';
}
bool isUpperCase(char a){
	return a>='A' && a<='Z';
}
char toUpper(char a){
	return a+='A'-'a';
}
char toLower(char a){
	return a-='A'-'a';
}
