/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 1
Data: 16.10.2019
*/

#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

void zadanie1a(){
	cout<<"----------\nZadanie 1a\n----------\n";
	//z uzyciem biblioteki iostream
	cout<<"Moja wizytowka"<<endl<<endl;
	cout<<"Tomasz Rzymyszkiewicz"<<endl;
	cout<<"Grunwaldzka 67 Wroclaw"<<endl;
	cout<<"tel. 604 453 413"<<endl;
	cout<<"mail: tomaszrzymyszkiewicz@wp.pl"<<endl;	
}
void zadanie1b(){
	printf("----------\nZadanie 1b\n----------\n");
	//z uzyciem biblioteki stdio.h
	printf("wizytowka 2\n\n");
	printf("Adam Nowakowski\n");
	printf("Kuznicza 56 Wroclaw\n");
	printf("tel. 792 478 921\n");
	printf("mail: adamnowakowski@onet.pl\n");
}
void zadanie1c(){
	printf("----------\nZadanie 1c\n----------\n");
	//generator wizytowki
	char imie[100],nazwisko[100],adres[200],telefon[10],mail[100];
	printf("Generator wizytowki\n");
	printf("Podaj imie\n");
	scanf("%s",imie);
	printf("Podaj nazwisko\n");
	scanf("%s",nazwisko);
	printf("Podaj adres\n");
	scanf("%s",adres);
	printf("Podaj numer telefonu\n");
	scanf("%s",telefon);
	printf("Podaj adres e-mail\n");
	scanf("%s",mail);
	printf("\nOto wygenerowana wizytowka\n\n");
	printf("%s %s\n",imie,nazwisko);
	printf("%s\n",adres);
	printf("tel. %s\n",telefon);
	printf("mail: %s\n",mail);
}
void zadanie2a(){
	cout<<"----------\nZadanie 2a\n----------\n";
	//z biblioteka iostream
	int a,b,c,suma,iloczyn;
	float srednia;
	float liczba_zmiennych=3;
	cout<<"Podaj 3 liczby calkowite"<<endl;
	cin>>a>>b>>c;
	suma=a+b+c;
	iloczyn=a*b*c;
	srednia=suma/liczba_zmiennych;
	cout<<"Suma="<<suma<<endl;
	cout<<"Iloczyn="<<iloczyn<<endl;
	cout<<"Srednia="<<srednia<<endl;
}
void zadanie2b(){
	cout<<"---------\nZadanie 2b\n---------\n";
	//z bibloteka stdio.h
	int a,b,c,suma,iloczyn;
	float srednia;
	float liczba_zmiennych=3;
	printf("Podaj 3 liczby calkowite\n");
	scanf("%d %d %d",&a ,&b ,&c);
	suma=a+b+c;
	iloczyn=a*b*c;
	srednia=suma/liczba_zmiennych;
	printf("Suma = %d\n",suma);
	printf("Iloczyn = %d\n",iloczyn);
	printf("Srednia = %f\n",srednia);
}
void zadanie3a(){
	printf("----------\nZadanie 3a\n----------\n");
	//z uzyciem biblioteki stdio.h
	float promien, obwod, pole, objetosc;
	printf("Podaj promien kuli: ");
	scanf("%f",&promien);
	printf("Dla podanego promienia = %f\n",promien);
	obwod=2*M_PI*promien;
	pole=4*M_PI*pow(promien,2);
	objetosc=(4/3)*M_PI*pow(promien,3);
	printf("Obwod = %f\n",obwod);
	printf("Pole = %f\n",pole);
	printf("Objetosc = %f\n",objetosc);
}
void zadanie3b(){
	cout<<"----------\nZadanie 3b\n----------\n";
	//z uzyciem biblioteki iostream
	float promien, obwod, pole, objetosc;
	cout<<"Podaj promien kuli: ";
	cin>>promien;
	obwod=2*M_PI*promien;
	pole=4*M_PI*pow(promien,2);
	objetosc=(4/3)*M_PI*pow(promien,3);
	cout<<"Dla podanego promienia = "<<promien<<endl;
	cout<<"Obwod = "<<obwod<<endl;
	cout<<"Pole = "<<pole<<endl;
	cout<<"Objetosc = "<<objetosc<<endl;
}
int main(int argc, char** argv)
{
	int czy_dalej;
	do{
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 1 \nData: 16.10.2019\n";
	cout<<"\nDostepne zadania:\n";
	cout<<"1. Zadanie 1a - wizytowka z wykorzystaniem biblioteki iostream\n";
	cout<<"2. Zadanie 1b - wizytowka z wykorzystaniem biblioteki stdio.h\n";
	cout<<"3. Zadanie 1c - generator wizytowki z wykorzystaniem biblioteki stdio.h\n";
	cout<<"4. Zadanie 2a - operacje matematyczne z wykorzystaniem biblioteki iostream\n";
	cout<<"5. Zadanie 2b - operacje matematyczne z wykorzystaniem biblioteki stdio.h\n";
	cout<<"6. Zadanie 3a - obliczanie wymiarow kuli z wykorzystaniem biblioteki iostream\n";
	cout<<"7. Zadanie 3b - obliczanie wymiarow kuli z wykorzystaniem biblioteki stdio.h\n";
	cout<<"8. Wyjscie\n";
	cout<<"Podaj numer zadania: ";
	nr_zadania=getch();
	cout<<endl;
	
	switch(nr_zadania)
	{
	case '1':zadanie1a();
		break;
	case '2':zadanie1b();
		break;
	case '3':zadanie1c();
		break;
	case '4':zadanie2a();
		break;
	case '5':zadanie2b();
		break;
	case '6':zadanie3a();
		break;
	case '7':zadanie3b();
		break;
	case '8': return 0;
		break;
	default:
		break;
	}
	cout<<"\nAby kontunuowac nacisnij BACKSPACE\nAby zakonczyc nacisnik ENTER\n";
	czy_dalej=getch();
	}while(czy_dalej==8);
	
	return 0;
}