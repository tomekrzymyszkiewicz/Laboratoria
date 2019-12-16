/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 4
Data: 11.12.2019
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#define ROZMIAR 20
using namespace std;
float tablica[ROZMIAR]={0}; //TABLICA G£ÓWNA
float t[ROZMIAR]={0};//TABLICA POMOCNICZA DO DZIA£ANIA MERGE SORT
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
	printf("]\n");
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
	int j = 0;
	for(int i = 0; i < ROZMIAR-1; i++){
		if(tablica[i] == tablica[i+1]){
			j++;
		}
		if(j == ROZMIAR-1){
			printf("Elementy tablicy sa rowne\n");
			system("pause");
			return;
		}
	}
	j = 0;
	for(int i = 0; i < ROZMIAR-1; i++){
		if(tablica[i] < tablica[i+1]){
			j++;
		}
		if(j == ROZMIAR-1){
			printf("Elementy tablicy ustawione sa rosnaco\n");
			system("pause");
			return;
		}
	}
	j = 0;
	for(int i = ROZMIAR-1; i > 0; i--){
		if(tablica[i] < tablica[i-1]){
			j++;
		}
		if(j == ROZMIAR-1){
			printf("Elementy tablicy ustawione sa malejaco\n");
			system("pause");
			return;
		}
	}
	j = 0;
	for(int i = 0; i < ROZMIAR-1; i++){
		if(tablica[i] <= tablica[i+1]){
			j++;
		}
		if(j == ROZMIAR-1){
			printf("Elementy tablicy ustawione sa niemalejaco\n");
			system("pause");
			return;
		}
	}
	j = 0;
	for(int i = ROZMIAR-1; i > 0; i--){
		if(tablica[i] <= tablica[i-1]){
			j++;
		}
		if(j == ROZMIAR-1){
			printf("Elementy tablicy ustawione sa nierosnaco\n");
			system("pause");
			return;
		}
	}
	printf("Elementy tablicy sa ustawione niemonotonicznie\n");
	system("pause");
}
void zadanie2(){//WSTAWIANIE LOSOWYCH WARTOŒCI Z PODANEGO ZAKRESU
	system("CLS");
	printf("Podaj zakres losowania w postaci [a;b]\n");
	float a = 0, b = 0;
	printf("a = ");
	scanf("%f",&a);
	printf("b = ");
	scanf("%f",&b);
	srand(time(NULL));
	for(int i = 0; i < ROZMIAR; i++){
		tablica[i] = a + (b - a)*rand()/((double)RAND_MAX);
	}
	system("pause");	
}
void sortowanieBubbleSort(){//SORTOWANIE BUBBLESORT
	float temp;
	for(int i = 0; i < ROZMIAR; i++){
		for(int j = 0; j < ROZMIAR-1; j++){
			if(tablica[j]>tablica[j+1]){
				temp = tablica[j];
				tablica[j] = tablica[j+1];
				tablica[j+1] = temp;
			}
		}	
	}
	system("CLS");
	printf("Tablica zostala posortowana\n");
	system("pause");
}
void quick_sort(float *tab, int lewy, int prawy){//SORTOWANIE QUICK SORT
	if(prawy <= lewy) return;
	int i = lewy - 1, j = prawy + 1;
	float pivot = tab[(lewy+prawy)/2]; 
	while(1)
	{
		while(pivot>tab[++i]);
		while(pivot<tab[--j]);
		if( i <= j){
			float tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
		else
			break;
	}
	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);
}
void merge(int pocz, int sr, int kon){
int i,j,q;
for (i=pocz; i<=kon; i++) t[i]=tablica[i];  
i=pocz; j=sr+1; q=pocz;                
while (i<=sr && j<=kon) {       
if (t[i]<t[j])
tablica[q++]=t[i++];
else
tablica[q++]=t[j++];
}
while (i<=sr) tablica[q++]=t[i++];
}
void mergesort(int pocz, int kon){//SORTOWANIE MERGESORT
int sr;
if (pocz<kon) {
sr=(pocz+kon)/2;
mergesort(pocz, sr);    
mergesort(sr+1, kon);   
merge(pocz, sr, kon);   
}
}
int main()
{
	bool dzialaj = true;
	while(dzialaj){
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 4 \nData: 11.12.2019";
	cout<<"\n-----------------\n|Wybierz operacje|\n-----------------\n";
	cout<<"1. Wczytaj dane do tablicy\n";
	cout<<"2. Wyswietla zawartosc tablicy\n";
	cout<<"3. Sprawdz tablice\n";
	cout<<"4. Wypelnij zablice liczbami losowymi z zakresu\n";
	cout<<"5. Posortuj tablice algorytmem BubbleSort\n";
	cout<<"6. Posortuj tablice algorytmem QuickSort\n";
	cout<<"7. Posortuj tablice algorytmem MergeSort\n";
	cout<<"ESC. Wyjscie\n";
	nr_zadania=getch();
	cout<<endl;
	switch(nr_zadania)
	{
	case '1':
		wczytaj();
		break;
	case '2':
		wypisz();
		break;
	case '3':
		zadanie1();
		break;	
	case '4':
		zadanie2();
		break;
	case '5':
		sortowanieBubbleSort();
		break;
	case '6':
		quick_sort(tablica,0,ROZMIAR-1);
		system("CLS");
		printf("Tablica zostala posortowana\n");
		system("pause");
		break;
	case '7':
		mergesort(0,ROZMIAR-1);
		system("CLS");
		printf("Tablica zostala posortowana\n");
		system("pause");
		break;
	case 27: 
		dzialaj = false;
		break;
	default:
		break;
	}
	}
	return 0;
}