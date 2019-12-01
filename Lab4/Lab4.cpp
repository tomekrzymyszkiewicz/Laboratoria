/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 4
Data: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#define ROZMIAR 5
using namespace std;
float tablica[ROZMIAR];
void wczytaj(){
	system("CLS");
	printf("Wczytywanie danych do tablicy %d-elementowej\n",ROZMIAR);
	for(int i = 0; i < ROZMIAR; i++){
	printf("Tab[%d] = ",i+1);
	scanf("%f",&tablica[i]);			
	}
	printf("Wczytano wszystkie wartosci do tablicy\n");
	system("pause");
}
void wypisz(){
	system("CLS");
	printf("Tab = [");
	for(int i = 0; i < ROZMIAR; i++){
		printf("  %.1f",tablica[i]);
	}
	printf("]");
	system("pause");
}
void zadanie1(){
	int ileDodatnich = 0, ileUjemnych = 0;
	float sumaDodatnich = 0, sumaUjemnych = 0;
	for(int i = 0; i < ROZMIAR; i++){
		if(tablica[i] > 0){
			ileDodatnich++;
			sumaDodatnich += tablica[i];
		}
		if(tablica[i] < 0){
			ileUjemnych++;
			sumaUjemnych += tablica[i];
		}
	}
	
}
int main()
{
	wczytaj();
	wypisz();
	return 0;
}