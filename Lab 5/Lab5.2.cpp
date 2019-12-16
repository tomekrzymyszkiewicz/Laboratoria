#include <string.h>
#include <stdio.h>
int moj_strlen(char tablica[]){
	int licznik = 0;
	while(tablica[licznik] != '\0'){
		licznik++;
	}
	return licznik;
}
int main()
{
	//TEST FUNCKJI moj_strlen
	char tab1[] = "ala ma kota";
	char tab2[10] = "ala";
	printf("Test funkcji moj_strlen\n");
	for(int i = 0; i < moj_strlen(tab1); i++) printf("%c",tab1[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab1));
	for(int i = 0; i < moj_strlen(tab2); i++) printf("%c",tab2[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab2));
	return 0;
}