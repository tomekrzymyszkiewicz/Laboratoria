#include <string.h>
#include <stdio.h>
int moj_strlen(char tablica[]){
	int licznik = 0;
	while(tablica[licznik] != '\0'){
		licznik++;
	}
	return licznik;
}
void moj_strcpy(char tab1[],char tab2[]){
	int tab2_length = 0;
	while(tab2[tab2_length] != '\0'){
		tab2_length++;
	}
	int i = 0;
	for(i = 0; i < tab2_length; i ++){
		tab1[i] = tab2[i];
	}
	tab1[i] = '\0';
}
int main()
{
	/*
	//TEST FUNCKJI moj_strlen
	char tab1[] = "ala ma kota";
	char tab2[10] = "ala";
	printf("Test funkcji moj_strlen\n");
	for(int i = 0; i < moj_strlen(tab1); i++) printf("%c",tab1[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab1));
	for(int i = 0; i < moj_strlen(tab2); i++) printf("%c",tab2[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab2));
	//-----------------------
	*/
	/*
	//TEST FUNCKJI moj_strlen
	char tab3[] = "123hvhvhjvhvhvhvhvh45";
	char tab4[] = "qwertvgvy";
	printf("%s\n%s\n\n",tab3,tab4);
	moj_strcpy(tab3,tab4);
	printf("%s\n%s\n",tab3,tab4);
	*/
	
	
	
	return 0;
}

/*
argument domnieany funckji 
dynamiczne tworzenie tablcy dwuwymoarowej
switch
porównanie sta³a tekstowa
przeboriony for zakresy widodcznoœci
przeysniecie bitowe
rzutowanie liczb i znaków
zwracanie wartosci i intkrementacja
*/