/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 3
Data: 
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void zadanie1(){
	system("CLS");
	cout<<"-----------\n|Zadanie 1|\n-----------\n";
	cout<<"Program drukujacy choinke\nPodaj wysokosc choinki: ";
	int wysokosc;
	cin>>wysokosc;
	for(int i = 1; i <= wysokosc; i++ ){
		for(int j = wysokosc - i; j > 0; j--){
			cout<<" ";
		}
		for(int k = (2*(i-1))+1; k > 0; k--){
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
	cout<<"-----------\n|Zadanie 3|\n-----------\n";
	cout<<"Program drukujacy tabliczke mnozenia\nPodaj liczbe wierszy: ";
	int wiersze, kolumny;
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
	int temp;
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
	unsigned long liczba, suma = 0;
	cin>>liczba;
	while(liczba){
		suma+=liczba%10;
		liczba/=10;
	}
	cout<<"Suma cyfr podanej liczby to "<<suma<<endl;
	
	system("pause");
}
void zadanie5(){
	int wczytanyZnak, liczbaZnakow = 0, a = 0, e = 0, i = 0, o = 0, u = 0, y = 0;;
	do{
		system("CLS");
		cout<<"-----------\n|Zadanie 5|\n-----------\n";
		cout<<"Podaj znak\n";
		wczytanyZnak = getch();
		liczbaZnakow++;
		if(wczytanyZnak == 'a' || wczytanyZnak == 'A') a++;
		if(wczytanyZnak == 'e' || wczytanyZnak == 'E') e++;
		if(wczytanyZnak == 'i' || wczytanyZnak == 'I') i++;
		if(wczytanyZnak == 'o' || wczytanyZnak == 'O') o++;
		if(wczytanyZnak == 'u' || wczytanyZnak == 'U') u++;
		if(wczytanyZnak == 'y' || wczytanyZnak == 'Y') y++;
	}while(wczytanyZnak != 'k' && wczytanyZnak != 'K');
	cout<<"Wpisano ogolem "<<liczbaZnakow<<" znakow w tym:";
	printf("\nlitera A %3d ",a);
	for(int j = 0; j <= a; j++) cout<<"#";
	printf("\nlitera E %3d ",e);
	for(int j = 0; j <= e; j++) cout<<"#";
	printf("\nlitera I %3d ",i);
	for(int j = 0; j <= i; j++) cout<<"#";
	printf("\nlitera O %3d ",o);
	for(int j = 0; j <= o; j++) cout<<"#";
	printf("\nlitera U %3d ",u);
	for(int j = 0; j <= u; j++) cout<<"#";
	printf("\nlitera Y %3d ",y);
	for(int j = 0; j <= y; j++) cout<<"#";
	cout<<endl;
	system("pause");
}
int main(){
bool dzialaj = true;
	do{
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 3 \nData: 30.10.2019\n";
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
