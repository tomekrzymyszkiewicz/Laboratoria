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
void wypiszTablice(int &Rozmiar,Towar **Tab);
void dopiszRekord(int &Rozmiar,Towar **Tab);
void usunRekord(int &Rozmiar,Towar **Tab);
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
	printf("4. Usun rekord z tablicy\n");
	printf("ESC. Wyjdz z programu\n");
	akcja = getch();
	switch(akcja){
		case '1':
			nowaTablica(Rozmiar, &Tab);
			break;
		case '2':
			system("CLS");
			wypiszTablice(Rozmiar, &Tab);
			system("PAUSE");
			break;
		case '3':
			dopiszRekord(Rozmiar, &Tab);
			break;
		case '4':
			usunRekord(Rozmiar, &Tab);
			break;
		case 27:
			dzialaj = false;
		break;
		
	}
	}while(dzialaj);
	
	return 0;
}
void nowaTablica(int &Rozmiar, Towar** Tab){
	if (*Tab != NULL)
        free(*Tab);
	system("CLS");
    printf("Wprowadz rozmiar tablicy: ");
    cin >> Rozmiar;
    *Tab = (Towar*) malloc(Rozmiar*sizeof(Towar));
    cin.get();
    for (int i = 0; i < Rozmiar; ++i)
    {
    	system("CLS");
        printf("Towar %d\n",i+1);
        printf("Nazwa: ");
        cin.getline((*Tab)[i].nazwa, 20);
        printf("Cena: ");
        cin >> (*Tab)[i].ilosc;
        printf("Ilosc: ");
        cin >> (*Tab)[i].cena;
		printf("Poprawnie wczytano rekord %d z %d\n",i+1,Rozmiar);
		system("pause");
    }
}

void wypiszTablice(int &Rozmiar,Towar **Tab){
	if (*Tab == NULL)
        printf("Brak tablicy\n");

    else
    {
        printf(" lp ||     Nazwa towaru     || Cena jednostkowa || Ilosc ||\n");
	printf("===========================================================\n");
	for(int i = 0; i < Rozmiar; i++){
		printf(" %2d || %20s || %16.2f || %5d ||\n",i+1,(*Tab)[i].nazwa,(*Tab)[i].cena,(*Tab)[i].ilosc);
	}
    }
}


void dopiszRekord(int &Rozmiar,Towar **Tab){
	
	Rozmiar++;
    *Tab = (Towar*) realloc(*Tab, (Rozmiar)*sizeof(Towar));

    cout << "Podaj dane dodawanego towaru" << endl << endl;

    cout << "Nazwa: ";
    cin.getline((*Tab)[Rozmiar-1].nazwa, 20);

    cout << "Cena: ";
    cin >> (*Tab)[Rozmiar-1].ilosc;

    cout << "Ilosc: ";
    cin >> (*Tab)[Rozmiar-1].cena;
    cin.get();
}

void usunRekord(int &Rozmiar,Towar **Tab){
	
	if (*Tab == NULL)
        cout << "Brak tablicy!";

    else
    {
        int n;

        cout << "Podaj nr rekordu, ktory chcesz usunac: ";
        cin >> n;
        if (n == Rozmiar)
        {
            Rozmiar--;
            *Tab = (Towar*)realloc(*Tab, (Rozmiar)*sizeof(Towar));
        }
        else if (Rozmiar == 1 && n == 1)
        {
            free(*Tab);
            *Tab = NULL;
            Rozmiar = 0;

        }
        else
        {

            for (int i = n-1; i < Rozmiar-1; ++i)
            {
                strcpy((*Tab)[i].nazwa, (*Tab)[i+1].nazwa );
                (*Tab)[i].cena = (*Tab)[i+1].cena;
                (*Tab)[i].ilosc = (*Tab)[i+1].ilosc;

            }
            Rozmiar--;
            *Tab = (Towar*) realloc(*Tab, Rozmiar*sizeof(Towar));
        }

    }

	
}