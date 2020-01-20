/*
Autor: Tomasz Bortniak, sroda parzysta 13:15
Data: 20 stycznia 2020
Tytul: program na laboratorium 6
*/


#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>


using namespace std;



struct Towar
{
    char nazwa[20];
    float cena;
    int ilosc;
};


void UtworzTablice(int &Rozmiar, Towar **Tab);
void WyswietlTablice(int &Rozmiar, Towar **Tab);
void DodajStrukture(int &Rozmiar, Towar **Tab);
void UsunStrukture(int &Rozmiar, Towar **Tab);
void Menu(int &pozycja);

int main()
{


    int Rozmiar = 0;
    Towar *Tab = NULL;

    int pozycja, n;
    for (;;)
    {
        pozycja = 0;

        Menu(pozycja);
        system("cls");


        switch (pozycja)
        {
        case 0:
            UtworzTablice(Rozmiar, &Tab);
            break;
        case 1:
            WyswietlTablice(Rozmiar, &Tab);
            break;
        case 2:
            DodajStrukture(Rozmiar, &Tab);
            break;
        case 3:
            UsunStrukture(Rozmiar, &Tab);
            break;
        case 4:
            break;
        }

        if (pozycja == 4)
            break;

        cout << endl << endl;
        cout << "Wcisnij ENTER, aby kontynuowac...";
        cin.get();
        system("cls");

    }

    free(Tab);
    return 0;
}

void Menu(int &pozycja)
{
    bool koniec = false;
    char wybor;

    char *arr[5]
    {
        "UTWORZ LISTE TOWAROW",
        "WYSWIETL LISTE TOWAROW",
        "DODAJ TOWAR",
        "USUN TOWAR",
        "WYJSCIE"
    };

    cout << "Autor: Tomasz Bortniak, sroda parzysta 13:15" << endl;
    cout << "Data: 20 stycznia 2020" << endl;
    cout << "Tytul: program na laboratorium 6" << endl << endl;
    cout << "\tM E N U" << endl << endl;

    for (int i = 0; i < 5; ++i)
    {
        if (i == 0)
            cout << "*  " << arr[i] << endl << endl;

        else
            cout << "   " << arr[i] << endl << endl;;
    }



    do
    {

        wybor = getch();

        switch(wybor)
        {
        case 72:
            pozycja--;

            if (pozycja == -1)
                pozycja = 4;
            break;
        case 80:
            pozycja++;

            if (pozycja == 5)
                pozycja = 0;
            break;

        case 13:
            koniec = true;
            break;

        }

        if (koniec == true)
            break;

        system("cls");

        cout << "Autor: Tomasz Bortniak, sroda parzysta 13:15" << endl;
        cout << "Data: 20 stycznia 2020" << endl;
        cout << "Tytul: program na laboratorium 6" << endl << endl;

        cout << "\tM E N U" << endl << endl;

        for (int i = 0; i < 5; ++i)
        {
            if (i == pozycja)
                cout << "*  " << arr[i] << endl << endl;

            else
                cout << "   " << arr[i] << endl << endl;;

        }


    }
    while(true);

}


void UtworzTablice(int &Rozmiar, Towar **Tab)
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

void WyswietlTablice(int &Rozmiar, Towar **Tab)
{
    if (*Tab == NULL)
        cout << "Brak tablicy!";

    else
    {
        cout << "  NR TOWARU\t|\tNAZWA\t\t|\tCENA\t\t|\tILOSC\t\t |" << endl;

        for (int i = 0; i < 10; ++i)
            cout << "---------";

        cout << endl;

        for (int i = 0; i < Rozmiar; ++i)
        {
            cout << "  " << i+1 << "\t\t|\t" <<(*Tab)[i].nazwa << "\t\t|\t" << (*Tab)[i].cena;
            cout << "\t\t|\t" << (*Tab)[i].ilosc << "\t\t |\t\t" << endl;

            for (int i = 0; i < 10; ++i)
                cout << "---------";

            cout << endl;
        }
    }
}

void DodajStrukture(int &Rozmiar, Towar **Tab)
{
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

void UsunStrukture(int &Rozmiar, Towar **Tab)
{
    if (*Tab == NULL)
        cout << "Brak tablicy!";

    else
    {
        int n;

        cout << "Podaj nr towaru, który chcesz usunac: ";
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
