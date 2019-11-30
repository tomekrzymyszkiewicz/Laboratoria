/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 3
Data: 27.11.2019
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
void zadanie1(){ //prawdopodobieñstwo pojawienia siê bombki
	system("CLS");
	cout<<"-----------\n|Zadanie 1|\n-----------\n";
	cout<<"Program drukujacy choinke\nPodaj wysokosc choinki: ";
	int wysokosc = 0;
	cin>>wysokosc;
	float prawd = 0;
	cout<<"Podaj prawdopodobienstwo pojawienia sie bombki: ";
	cin>>prawd;
	srand(time(NULL));
	for(int i = 1; i <= wysokosc; i++ ){
		for(int j = wysokosc - i; j > 0; j--){
			cout<<" ";
		}
		for(int k = (2*(i-1))+1; k > 0; k--){
			if((rand()%100) < prawd*100){
				cout<<"o";
			}else
			cout<<"*";
		}
		for(int l = wysokosc - i; l > 0; l--){
			cout<<" ";
		}
		cout<<endl;
	}
	for(int j = wysokosc - 1; j > 0; j--){
			cout<<" ";
		}
		cout<<"#";
		for(int l = wysokosc - 1; l > 0; l--){
			cout<<" ";
		}
		cout<<endl;
	system("pause");
}
void zadanie2(){
	system("CLS");
	cout<<"-----------\n|Zadanie 2|\n-----------\n";
	cout<<"Program drukujacy tabliczke mnozenia\nPodaj liczbe wierszy: ";
	int wiersze = 0, kolumny = 0;
	cin>>wiersze;
	cout<<"Podaj liczbe kolumn: ";
	cin>>kolumny;
	printf("    | ");
	for(int i = 1; i <= kolumny; i++){
		printf(" %3d",i);
	}
	cout<<endl;
	for(int i = 1; i <= 6+kolumny*4; i++){
		printf("-");
	}
	cout<<endl;
	for(int i = 1; i <= wiersze; i++){
		printf("%3d | ", i);
		for(int j = 1; j <= kolumny; j++){
			printf(" %3d",i*j);
		}	
		cout<<endl;
	}
	system("pause");
}
int nwd(int a, int b){
	int temp = 0;
	while(b!=0)
    {
		temp = b;
		b = a%b;
		a = temp;	
	}
    return a;	
}
int nww(int a, int b){
	return (a*b)/nwd(a,b);
}
void zadanie3(){
	system("CLS");
	cout<<"-----------\n|Zadanie 3|\n-----------\n";
	cout<<"Program wyliczajacy NWD i NWW dla podanych licz calkowitych a i b\n";
	cout<<"Podaj a: ";
	int a,b;
	cin>>a;
	cout<<"Podaj b: ";
	cin>>b;
	cout<<"NWD = "<<nwd(a,b)<<", a NWW = "<<nww(a,b)<<endl;
	system("pause");
}
void zadanie4(){
	system("CLS");
	cout<<"-----------\n|Zadanie 4|\n-----------\n";
	cout<<"Program sumujacy cyfry podanej liczby\n";
	cout<<"Podaj liczbe: ";
	unsigned long liczba = 0, suma = 0;
	cin>>liczba;
	while(liczba){
		suma+=liczba%10;
		liczba/=10;
	}
	cout<<"Suma cyfr podanej liczby to "<<suma<<endl;
	
	system("pause");
}
void zadanie5(){//wersja dla ambitnych - zrobiæ to dla wszystkich liter na tablicy
	int wczytanyZnak, liczbaZnakow = 0;
	int znak[26] = {0};
	do{
			system("CLS");
			cout<<"-----------\n|Zadanie 5|\n-----------\n";
			cout<<"Podaj znak\n";
			wczytanyZnak = getch();
			liczbaZnakow++;
			if(wczytanyZnak >= 97 || wczytanyZnak <= 122){
				znak[wczytanyZnak - 97]++;
			}
			if(wczytanyZnak >= 65 || wczytanyZnak <= 90){
				znak[wczytanyZnak - 65]++;
			}
	}while(wczytanyZnak != 'k' && wczytanyZnak != 'K');
	system("CLS");
	cout<<"Wpisano ogolem "<<liczbaZnakow<<" znakow w tym:\n";
	for(int i = 0; i < 26; i++){
		printf("Litera %c %3d ",(char)i+65, znak[i]);
		for(int j = 0; j<znak[i]; j++){
			printf("#");
		}
		printf("\n");
	}
	system("pause");
}
int main(){
bool dzialaj = true;
	do{
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 3 \nData: 27.11.2019\n";
	cout<<"\n-----------------\n|Wybierz zadanie|\n-----------------\n";
	cout<<"1. Rysowanie choinki\n";
	cout<<"2. Tabliczka mnozenia\n";
	cout<<"3. NWD i NWW\n";
	cout<<"4. Suma cyfr\n";
	cout<<"5. Zliczanie klawiszy\n";
	cout<<"ESC. Wyjscie\n";
	nr_zadania=getch();
	cout<<endl;
	switch(nr_zadania)
	{
	case '1':
		zadanie1();
		break;
	case '2':
		zadanie2();
		break;
	case '3':
		zadanie3();
		break;	
	case '4':
		zadanie4();
		break;
	case '5':
		zadanie5();
		break;
	case 27: 
		dzialaj = false;
		break;
	default:
		break;
	}
	}while(dzialaj);
	return 0;
}
