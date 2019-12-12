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
float tablica[ROZMIAR]={0};
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
void zadanie2(){
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

void sortowanieBubbleSort(){
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
/*
int partition(float tablica[], int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
int x = tablica[p]; // obieramy x
int i = p, j = r, w; // i, j - indeksy w tabeli
while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
{
while (tablica[j] > x) // dopoki elementy sa wieksze od x
j--;
while (tablica[i] < x) // dopoki elementy sa mniejsze od x
i++;
if (i < j) // zamieniamy miejscami gdy i < j
{
w = tablica[i];
tablica[i] = tablica[j];
tablica[j] = w;
i++;
j--;
}
else // gdy i >= j zwracamy j jako punkt podzialu tablicy
return j;
}
}
 
void quicksort(float tablica[], int p, int r) // sortowanie szybkie
{
int q;
if (p < r)
{  
q = partition(tablica,p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
quicksort(tablica, q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
}
}
*/
void sortowanieMergeSort(){
	
}
int main()
{
	bool dzialaj = true;
	while(dzialaj){
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 4 \nData: 11.12.2019\n";
	cout<<"\n-----------------\n|Wybierz operacje|\n-----------------\n";
	cout<<"1. Wczytaj dane do tablicy\n";
	cout<<"2. Wyswietla zawartosc tablicy\n";
	cout<<"3. Sprawdz tablice\n";
	cout<<"4. Wypelnij zablice liczbami losowymi z zakresu\n";
	cout<<"5. Posortuj tablice algorytmem BubbleSort\n";
	cout<<"6. Posortuj tablice algorytmem QuickSort\n";
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
		sortowanieBubbleSort();//KILKA ALGORYTMÓW SORTOWANIA
		break;
	case '6':
		//quicksort(tablica,0,ROZMIAR-1);
	case 27: 
		dzialaj = false;
		break;
	default:
		break;
	}
	}
	return 0;
}