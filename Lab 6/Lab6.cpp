#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
struct Towar
{
	char nazwa[20];
	float cena;
	int ilosc;
};

Towar* Tab = NULL;
int Rozmiar = 0;

void nowaTablica(){
	system("CLS");
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&Rozmiar);
	if(Tab == NULL){
		delete Tab;
	}else{
	Tab = new Towar[Rozmiar];
	}
	for(int i = 0; i < Rozmiar; i++){
		system("CLS");
		printf("Rekord %d\nPodaj nazwe towaru: ", i+1);
		scanf("%s",Tab[i].nazwa);
		printf("Podaj cene jednostkowa towaru: ");
		scanf("%f",&Tab[i].cena);
		printf("Podaj ilosc twoaru: ");
		scanf("%d",&Tab[i].ilosc);
		printf("Poprawnie wczytano towar %d z %d\n",i+1,Rozmiar);
		system("PAUSE");
	}
}



void wypiszTablice(){
	if(Tab == NULL){
		printf("Brak tablicy\n");
	}else{
	printf(" lp ||     Nazwa towaru     || Cena jednostkowa || Ilosc ||\n");
	printf("===========================================================\n");
	for(int i = 0; i < Rozmiar; i++){
		printf(" %2d || %20s || %16.2f || %5d ||\n",i+1,Tab[i].nazwa,Tab[i].cena,Tab[i].ilosc);
	}
	}
}

void dopiszRekord(){
	
	Rozmiar++;
	realloc(Tab,(Rozmiar)*sizeof(Towar));
	system("CLS");
		printf("Dopisanie dodatkowego rekordu nr %d\nPodaj nazwe towaru: ", Rozmiar);
		scanf("%s",Tab[Rozmiar-1].nazwa);
		printf("Podaj cene jednostkowa towaru: ");
		scanf("%f",&Tab[Rozmiar-1].cena);
		printf("Podaj ilosc twoaru: ");
		scanf("%d",&Tab[Rozmiar-1].ilosc);
		printf("Poprawnie wczytano towar\n");
		system("PAUSE");
}

void usunRekord(){
	system("CLS");
	wypiszTablice();
	int rekord = 0;
	printf("Podaj nr rekordu do usuniecia: ");
	scanf("%d",&rekord);
	memcpy(Tab+(rekord*sizeof(Towar)),Tab+((rekord-1)*sizeof(Towar)),(Rozmiar-rekord)*sizeof(Towar));
	Rozmiar--;
	realloc(Tab,(Rozmiar)*sizeof(Towar));
	
}

void daneTestowe(){
	Tab = new Towar[5];
	Tab[1] = {"Mleko",1.5,20};
	Tab[2].nazwa = "Pomidory";
	Tab[2].cena = 4.25;
	Tab[2].ilosc = 30;
	Tab[3].nazwa = "Ziemniaki";
	Tab[3].cena = 1;
	Tab[3].ilosc = 200;
	Tab[4].nazwa = "Sok pomaranczowy";
	Tab[4].cena = 3.75;
	Tab[4].ilosc = 5;
	Tab[5].nazwa = "Ser";
	Tab[5].cena = 25;
	Tab[5].ilosc = 3.7;
	printf("Poprawnie wczytano dane testowe\n");
	system("pause");
}

int main()
{
	bool dzialaj = true;
	do{
	int akcja = 0;
	system("CLS");
	printf("Baza danych zawierajaca informacje o towarach\n");
	printf("Wybierz akcje: \n");
	printf("1. Ustal rozmiar + wczytaj dane do tablicy\n");
	printf("2. Wyswietl zawartosc tablicy\n");
	printf("3. Dopisz nowy rekord do tablicy\n");
	printf("ESC. Wyjdz z programu\n");
	akcja = getch();
	switch(akcja){
		case '1':
			nowaTablica();
			break;
		case '2':
			system("CLS");
			wypiszTablice();
			system("PAUSE");
			break;
		case '3':
			dopiszRekord();
			break;
		case 27:
			dzialaj = false;
		break;
		
	}
	}while(dzialaj);
	
	
	return 0;
}