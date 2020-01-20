/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 5
Data: XXXXXXXXXXXXXXXXXXXXXXXX
*///WEERSJA Z PRZEKAZYWANIEM PRZEZ REFERENCJE
#include <stdio.h>
#include <windows.h>
using namespace std;
void czytajRownanie(float &a, float &b, float &c){
	system("CLS");
	printf("Wczytywanie rownania w postaci:\n\n");
	printf("Ax + By = C\n\n");
	printf("Podaj A: ");
	scanf("%f",&a);
	printf("Podaj B: ");
	scanf("%f",&b);
	printf("Podaj C: ");
	scanf("%f",&c);
	printf("Wczytano wspolczynniki\n\n");
	printf("Rowanie jest w postaci:\n\n\t%.1f X + %.1f Y = %.1f\n\n",a,b,c);
	system("pause");
}
float obliczWyznacznik(float p1, float p2, float p3, float p4){
	return p1*p4-p2*p3;
}
int obliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y){
	float W,Wx,Wy; //wyznaczniki
	W = obliczWyznacznik(a1,b1,a2,b2);
	Wx = obliczWyznacznik(c1,b1,c2,b2);
	Wy = obliczWyznacznik(a1,c1,a2,c2);
	if(W == 0 && Wx == 0 && Wy == 0){
		return 2;
	}else
	if(W == 0 && Wx != 0 && Wy != 0){
		return 0;
	}else
	if(W != 0){
		x = Wx/W;
		y = Wy/W;
		return 1;
	}else{
		printf("Blad funkcji obliczRozwiazanie");	
	}
}
void wypiszUkladRownan(float a1, float b1, float c1, float a2, float b2, float c2){
	printf("Uklad rownan:\n");
	printf("%.1f X + %.1f Y = %.1f\n",a1,b1,c1);
	printf("%.1f X + %.1f Y = %.1f\n",a2,b2,c2);
}
void wypiszRozwiazanie(int n, float &x, float &y){
	switch(n){
		case 0:
			printf("Uklad rownan jest sprzeczny\n");
			break;
		case 1:
			
			printf("Uklad rownan jest oznaczony\n");
			printf("Rozwiazanie ukladu rownan:\n");
			printf("X = %.2f\n",x);
			printf("Y = %.2f\n",y);
			break;
		case 2:
			printf("Uklad rownan jest nieoznaczony\n");
			break;
		default:
			printf("Blad funkcji wypiszRozwiazanie");
			break;
	}
}
int main(){
	float a1=0, b1=0, c1=0; //wspó³czynniki pierwszego równania
	float a2=0, b2=0, c2=0; //wspó³czynniki drugiego rówania
	float x = 0, y = 0; // rozwi¹zania uk³adu równañ
	int n; //liczba rozwi¹zañ uk³adu
	//0 - sprzeczny; 1 - oznaczony; 2 - nieoznaczony
	czytajRownanie(a1,b1,c1);
	czytajRownanie(a2,b2,c2);
	system("cls");
	wypiszUkladRownan(a1,b1,c1,a2,b2,c2);
	n = obliczRozwiazanie(a1,b1,c1,a2,b2,c2,x,y);
	wypiszRozwiazanie(n,x,y);
	system("pause");
	return 0;
}