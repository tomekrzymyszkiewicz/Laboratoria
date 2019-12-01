/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 4
Data: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define ROZMIAR 5
using namespace std;
float tablica[ROZMIAR];
void wczytaj(){ //WCZYTANIE DANYCH
	system("CLS");
	printf("Wczytywanie danych do tablicy %d-elementowej\n",ROZMIAR);
	for(int i = 0; i < ROZMIAR; i++){
	printf("Tab[%d] = ",i+1);
	scanf("%f",&tablica[i]);			
	}
	printf("Wczytano wszystkie wartosci do tablicy\n");
	system("pause");
}
void wypisz(){ //WYPISANIE DANYCH
	system("CLS");
	printf("Tab = [");
	for(int i = 0; i < ROZMIAR; i++){
		printf("  %.1f",tablica[i]);
	}
	printf("]");
	system("pause");
}
void zadanie1(){ //LISTA SPRAWDZEÑ Z ZADANIA 1
	system("CLS");
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
	float sredniaDodatnich = sumaDodatnich/ileDodatnich;
	float sredniaUjemnych = sumaUjemnych/ileUjemnych;
	printf("W tablicy jest:\n");
	printf("-> %d liczb dodatnich\n",ileDodatnich);
	printf("-> %d liczb ujemnych\n",ileUjemnych);
	printf("-> suma liczb dodatnich wynosi %.2f\n",sumaDodatnich);
	printf("-> suma liczb ujemnych wynosi %.2f\n",sumaUjemnych);
	if(ileDodatnich > 0){
		printf("-> srednia liczb dodatnich wynosi %.2f\n",sredniaDodatnich);
	}
	if(ileUjemnych > 0){
		printf("-> srednia liczb ujemnych wynosi %.2f\n",sredniaUjemnych);
	}
	for(int i = 0; i < ROZMIAR; i++){
		if(tablica[i]>tablica[i+1]){
			break;
		}
		if(i = ROZMIAR-1){
			printf("Elementy tablicy ustawione sa rosnaco\n");
		}
	}
	for(int i = ROZMIAR-1; i > 0; i--){
		if(tablica[i] > tablica[i-1]){
			break;
		}
		if(i = 1){
			printf("Elementy tablicy ustawione sa malejaco\n");
		}
	}
	system("pause");
}
int main()
{
	bool dzialaj = true;
	while(dzialaj){
	wczytaj();
	wypisz();
	zadanie1();
	}
	return 0;
}