/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 6
Data: 20.01.2020
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct Towar
{
	char nazwa[20];
	float cena;
	int ilosc;
};

void nowaTablica(int &Rozmiar, Towar **Tab);
//void wypiszTablice(int &Rozmiar, Towar **Tab);
//void dopiszRekord(int &Rozmiar, Towar **Tab);

int main()
{
	
	Towar* Tab = NULL;
	int Rozmiar = 0;
	
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
			nowaTablica(Rozmiar, &Tab);
			break;
		case '2':
			system("CLS");
			//wypiszTablice(Rozmiar, &Tab);
			system("PAUSE");
			break;
		case '3':
			//dopiszRekord(Rozmiar, &Tab);
			break;
		case 27:
			dzialaj = false;
		break;
		
	}
	}while(dzialaj);
	
	
	return 0;
}



/*

void nowaTablica(int &Rozmiar, Towar **Tab){
	system("CLS");
	
	if(*Tab != NULL){
		free(*Tab);
	}
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&Rozmiar);
	*Tab = (Towar*) malloc(Rozmiar*sizeof(Towar));
	
	for(int i = 0; i < Rozmiar; i++){
		system("CLS");
		printf("Rekord %d\nPodaj nazwe towaru: ", i+1);
		cin.getline((*Tab)[i].nazwa, 20);
		//scanf("%s",Tab[i].nazwa);
		printf("Podaj cene jednostkowa towaru: ");
		cin >> (*Tab)[i].ilosc;
		//scanf("%f",(*Tab)[i].cena);
		printf("Podaj ilosc twoaru: ");
		cin >> (*Tab)[i].ilosc;
		//scanf("%d",(*Tab)[i].ilosc);
		printf("Poprawnie wczytano towar %d z %d\n",i+1,Rozmiar);
		system("PAUSE");
	}
}
*/
void nowaTablica(int &Rozmiar, Towar **Tab)
{
    if (*Tab != NULL)
        free(*Tab);

    cout << "Wprowadz rozmiar tablicy: ";
    cin >> Rozmiar;
    cout << endl;

    *Tab = (Towar*) malloc(Rozmiar*sizeof(Towar));
    cin.get();

    for (int i = 0; i < Rozmiar; ++i)
    {
        cout << "Towar nr" << i+1 << endl << endl;

        cout << "Nazwa: ";
        cin.getline((*Tab)[i].nazwa, 20);

        cout << "Cena: ";
        cin >> (*Tab)[i].ilosc;

        cout << "Ilosc: ";
        cin >> (*Tab)[i].cena;
        cin.get();

        cout << endl << endl;

    }


}

/*
void wypiszTablice(int &Rozmiar, Towar **Tab){
	if(*Tab == NULL){
		printf("Brak tablicy\n");
	}else{
	printf(" lp ||     Nazwa towaru     || Cena jednostkowa || Ilosc ||\n");
	printf("===========================================================\n");
	for(int i = 0; i < Rozmiar; i++){
		printf(" %2d || %20s || %16.2f || %5d ||\n",i+1,(*Tab)[i].nazwa,(*Tab)[i].cena,(*Tab)[i].ilosc);
	}
	}
}
*/
/*
void dopiszRekord(int &Rozmiar, Towar **Tab){
	Rozmiar++;
	realloc(Tab,(Rozmiar)*sizeof(Towar));
	system("CLS");
		printf("Dopisanie dodatkowego rekordu nr %d\nPodaj nazwe towaru: ", Rozmiar);
		scanf("%s",(*Tab)[Rozmiar-1].nazwa);
		printf("Podaj cene jednostkowa towaru: ");
		scanf("%f",(*Tab)[Rozmiar-1].cena);
		printf("Podaj ilosc twoaru: ");
		scanf("%d",(*Tab)[Rozmiar-1].ilosc);
		printf("Poprawnie wczytano towar\n");
		system("PAUSE");
}
*/
/*
void usunRekord(int &Rozmiar, Towar **Tab){
	system("CLS");
	wypiszTablice(Rozmiar, Tab);
	int rekord = 0;
	printf("Podaj nr rekordu do usuniecia: ");
	scanf("%d",&rekord);
	memcpy(Tab+(rekord*sizeof(Towar)),Tab+((rekord-1)*sizeof(Towar)),(Rozmiar-rekord)*sizeof(Towar));
	Rozmiar--;
	realloc(Tab,(Rozmiar)*sizeof(Towar));
	
}
*/
/*
void daneTestowe(){
	if(Tab != NULL){
		delete Tab;
	}
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
*/