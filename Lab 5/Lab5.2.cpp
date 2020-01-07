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
int moj_strcmp(char tab1[],char tab2[]){
	int i = 0;
	while(tab1[i]==tab2[i]){
		i++;
	}
	if((int)tab1[i]>(int)tab2[i]){
		return (int)tab1[i]-(int)tab2[i];
	}else
	if((int)tab1[i]<(int)tab2[i]){
		return (int)tab1[i]-(int)tab2[i];
	}else
	return 0;
}
int main()
{
	printf("TEST FUNCKJI moj_strlen\n");
	char tab1[] = "ala ma kota";
	char tab2[10] = "ala";
	for(int i = 0; i < moj_strlen(tab1); i++) printf("%c",tab1[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab1));
	for(int i = 0; i < moj_strlen(tab2); i++) printf("%c",tab2[i]);
	printf("\nmoj_strlen = %d\n",moj_strlen(tab2));
	printf("\nFUNCKJI moj_strcpy\n");
	char tab3[] = "123hvhvhjvhvhvhvhvh45";
	char tab4[] = "qwertvgvy";
	printf("str1 %s\nstr2 %s\n\n",tab3,tab4);
	moj_strcpy(tab3,tab4);
	printf("str1 %s\nstr2 %s\n",tab3,tab4);
	printf("\nFUNCKJI moj_strcmp\n");
	char tab5[] = "12435bjbjk";
	char tab6[] = "12434hvyvy";
	printf("str1 %s\nstr2 %s\n",tab5,tab6);
	printf("moj_strcmp = %d",moj_strcmp(tab5,tab6));
	
	
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