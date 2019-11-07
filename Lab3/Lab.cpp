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

int main(){
bool dzialaj = true;
	do{
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 3 \nData: 30.10.2019\n";
	cout<<"\n-----------------\n|Wybierz zadanie|\n-----------------\n";
	cout<<"1. Rysowanie choinki\n";
	cout<<"2. Tabliczka mnozenia\n";
	cout<<"3. \n";
	cout<<"4. \n";
	cout<<"5. \n";
	cout<<"6. \n";
	cout<<"7. \n";
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
	
	case 27: 
		dzialaj = false;
		break;
	default:
		break;
	}
	}while(dzialaj);
	return 0;
}
