/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 2
Data: 30.10.2019
*/
#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <iomanip>
using namespace std;
void zadanie1(){ //rozwi¹zywanie równania kwadratowego
	double a,b,c,delta,x1,x2;
	system("CLS");
	cout<<"-----------\n|Zadanie 1|\n-----------\n";
	cout<<"Podaj wspolczynniki rownania kwadratowego w postaci Ax^2 + Bx + C = 0\n";
	do{
	cout<<"A = ";
	cin>>a;
		if(a == 0){
			system("CLS");
			cout<<"-----------\n|Zadanie 1|\n-----------\n";
			cout<<"Podaj wspolczynniki rownania kwadratowego w postaci Ax^2 + Bx + C = 0\n";
			cout<<"Wspolczynnik A nie moze byc rowny 0.\n";
		}
	}while(a == 0);
	cout<<"B = ";
	cin>>b;
	cout<<"C = ";
	cin>>c;
	delta = (pow(b,2))-(4*a*c);
	if(delta < 0){
		system("CLS");
		cout<<"-----------\n|Zadanie 1|\n-----------\n";
		cout<<"Rownanie nie ma pierwiastkow rzeczywistych\n";
	}else
	if(delta == 0){
		x1 = ((-b)-sqrt(delta))/(2*a);
		system("CLS");
		cout<<"-----------\n|Zadanie 1|\n-----------\n";
		cout<<"Rownanie ma podwojny pierwiastek rzeczywisty x1 = x2 = "<<x1;
	}else
	if(delta > 0){
		x1 = ((-b)-sqrt(delta))/(2*a);
		x2 = ((-b)+sqrt(delta))/(2*a);
		system("CLS");
		cout<<"-----------\n|Zadanie 1|\n-----------\n";
		cout<<"Rownanie ma dwa pierwiastki rzeczywiste x1 = "<<x1<<" oraz x2 = "<<x2;
	}
	cout<<endl;
	system("pause");
	a = 0;
	b = 0;
	c = 0;
}
void zadanie2(){ //sprawdzanie czy data jest poprawna
	system("CLS");
	int dzien,miesiac,rok;
	cout<<"-----------\n|Zadanie 2|\n-----------\n";
	cout<<"Program sprawdza czy podana data jest poprawna.\n";
	do{
		cout<<"Podaj dzien\n";
		cin>>dzien;
		if(dzien < 1 || dzien > 31){
			cout<<"Podano niepoprawny dzien\n";
		}
	}while(dzien < 1 || dzien > 31);
	do{
		cout<<"Podaj miesiac\n";
		cin>>miesiac;
		if(miesiac < 1 || miesiac > 12){
			cout<<"Podano niepoprawny miesiac\n";
		}
	}while(miesiac < 1 || miesiac > 12);
	do{
		cout<<"Podaj rok\n";
		cin>>rok;
		if(rok < 0){
			cout<<"Program obs³uguje tylko lata naszej ery\n";
		}
	}while(rok < 0);
	//rok nieprzestepny - 28 dni w lutym
	if(miesiac == 2 && (rok%4 != 4 || (rok%100 == 0 && rok%400 != 0)) && dzien >= 28){
		cout<<"Wpisana data jest nieprawidlowa\n";
	}else if(miesiac == 2 && dzien >= 29){ //rok przestepny - 29 dni w lutym
		cout<<"Wpisana data jest nieprawidlowa\n";
	}else if((miesiac == 2 || miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) && dzien > 30){
		//miesiace 30-dniowe
		cout<<"Wpisana data jest nieprawidlowa\n";
	}else{
		cout<<"Wpisana data jest prawidlowa\n";
	}
	system("pause");
	dzien = 0;
	miesiac = 0;
	rok = 0;
}
void zadanie3a(){ //wyliczanie wymiarów kuli w tabeli - wariant pierwszy z bibliotece stdio.h
	system("CLS");
	int min,max,wiersze;
	printf("------------\n|Zadanie 3a|\n------------\n");
	printf("Podaj minimalny promien kuli: ");
	scanf("%d",&min);
	printf("Podaj maksymalny promien kuli: ");
	scanf("%d",&max);
	printf("Podaj ilosc wierszy: ");
	scanf("%d",&wiersze);
	printf("===================================================\n");
	printf("| Lp | Promien | Pole powierzchni | Objetosc kuli |\n");
	printf("===================================================\n");
	float promien[wiersze-1],pole[wiersze-1],objetosc[wiersze-1];
	for (int i = 0; i < wiersze; i++){
		promien[i] = min + (((abs(max - min))*(i))/float(wiersze-1));
		pole[i] = 4*M_PI*pow(promien[i],2);
		objetosc[i] = (4/3)*M_PI*pow(promien[i],3);
		printf("|%3d ",i+1);
		printf("|%8.2f ",promien[i]);
		printf("|%17.2f ",pole[i]);
		printf("|%14.2f |\n",objetosc[i]);
	}
	printf("===================================================\n");
	system("pause");
}
void zadanie3b(){ //wyliczanie wymiarów kuli w tabeli - wariant drugi z bibliotece iostream FUNKCJA NIE JEST W PE£NI SPRAWNA
	system("CLS");
	int min,max,wiersze;
	cout<<"------------\n|Zadanie 3b|\n------------\n";
	cout<<"Podaj minimalny promien kuli: ";
	cin>>min;
	cout<<"Podaj maksymalny promien kuli: ";
	cin>>max;
	cout<<"Podaj ilosc wierszy: ";
	cin>>wiersze;
	cout<<"===================================================\n";
	cout<<"| Lp | Promien | Pole powierzchni | Objetosc kuli |\n";
	cout<<"===================================================\n";
	float promien[wiersze-1],pole[wiersze-1],objetosc[wiersze-1];
	for (int i = 0; i < wiersze; i++){
		promien[i] = min + (((abs(max - min))*(i))/float(wiersze-1));
		pole[i] = 4*M_PI*pow(promien[i],2);
		objetosc[i] = (4/3)*M_PI*pow(promien[i],3);
		
		cout.setf( ios::showpoint );
		
		cout<<"|";
		cout<<setw(3)<<i+1<<" |";
		cout<<setw(8)<<right<<setprecision(3)<<promien[i]<<" |";
		cout<<setw(17)<<right<<setprecision(3)<<pole[i]<<" |";
		cout<<setw(14)<<right<<setprecision(3)<<objetosc[i]<<" |";
		cout<<endl;
	}
	cout<<"===================================================\n";
	system("pause");
}
void zadanie4(){ //algorytm
	system("CLS");
	cout<<"-----------\n|Zadanie 4|\n-----------\n";
	int n,n1,iteracja = 0;
	cout<<"Podaj dodatnia liczbe calkowita: ";
	cin>>n;
	while(n1!=1){
		if(n%2 == 0){
			n1 = n/2;
			cout<<iteracja+1<<", "<<n<<", "<<"parzyste "<<n1<<endl;
		}else if(n%2 != 0){
			n1 = 3*n+1;
			cout<<iteracja+1<<", "<<n<<", "<<"nieparzyste "<<n1<<endl;
		}
		n = n1;
		iteracja++;
	}
	system("pause");	
}
void zadanie5a(){ //losowanie ca³kowite
	system("CLS");
	cout<<"------------\n|Zadanie 5b|\n------------\n";
	int min, max,losMin,losMax,suma = 0,srednia;
	cout<<"Podaj calkowity poczatek przedzialu losowania: ";
	cin>>min;
	cout<<"Podaj calkowity koniec przedzialu losowania: ";
	cin>>max;
	cout<<endl;
	srand(time(NULL));
	losMin = (max-min)/2;
	losMax = (max-min)/2;
	if(min < max){
		for(int i  = 0; i < 20; i++){
			int temp = (rand()%(max-min+1))+min;
			cout<<temp<<endl;
			suma+=temp;
			if(temp < losMin){
				losMin = temp;
			}
			if(temp > losMax){
				losMax = temp;
			}
		}
	}else{
		cout<<"Nieprawidlowo zdefiniowano przedzial\n";
	}
	srednia = suma/20;
	cout<<"\nNajmniejsza z wylosowanych liczb to "<<losMin<<", a najwieksza to "<<losMax<<endl<<"Wartosc srednia to: "<<srednia<<endl;
	min = 0;
	max = 0;
	losMin = 0;
	losMax = 0;
	system("pause");
}
void zadanie5b(){ //losowanie rzeczywiste
	system("CLS");
	cout<<"------------\n|Zadanie 5b|\n------------\n";
	double min, max,losMin,losMax,suma = 0,srednia;
	cout<<"Podaj calkowity poczatek przedzialu losowania: ";
	cin>>min;
	cout<<"Podaj calkowity koniec przedzialu losowania: ";
	cin>>max;
	cout<<endl;
	srand(time(NULL));
	losMin = min+(max-min)/2;
	losMax = min+(max-min)/2;
	if(min < max){
		for(int i  = 0; i < 20; i++){
			double temp = min + (max-min)*rand()/((double)RAND_MAX);
			cout<<temp<<endl;
			suma+=temp;
			if(temp < losMin){
				losMin = temp;
			}
			if(temp > losMax){
				losMax = temp;
			}
		}
	}else{
		cout<<"Nieprawidlowo zdefiniowano przedzial\n";
	}
	srednia = suma/20;
	cout<<"\nNajmniejsza z wylosowanych liczb to "<<losMin<<", a najwieksza to "<<losMax<<endl<<"Wartosc srednia to: "<<srednia<<endl;
	min = 0;
	max = 0;
	losMin = 0;
	losMax = 0;
	system("pause");
}
int main(){
bool dzialaj = true;
	do{
	int nr_zadania;
	system("CLS");
	cout<<"Autor: Tomasz Rzymyszkiewicz \nGrupa: SR/P 15:15 \nTemat: Zadania - Laboratorium 2 \nData: 30.10.2019\n";
	cout<<"\n-----------------\n|Wybierz zadanie|\n-----------------\n";
	cout<<"1. Rozwiazaywanie rownania kwadratowego\n";
	cout<<"2. Sprawdzanie czy wpisana data jest poprawna\n";
	cout<<"3. Wyswietlanie tabeli w wymiarami kul - biblioteka stdio.h\n";
	cout<<"4. Wyswietlanie tabeli w wymiarami kul - biblioteka iostream\n";
	cout<<"5. Algorytm Hofstadtera\n";
	cout<<"6. Losowanie liczb calkowitych w zakresie\n";
	cout<<"7. Losowanie liczb rzeczywistych w zakresie\n";
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
		zadanie3a();
		break;
	case '4':
		zadanie3b();
		break;
	case '5':
		zadanie4();
		break;
	case '6':
		zadanie5a();
		break;
	case '7':
		zadanie5b();
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