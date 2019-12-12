/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 5
Data: XXXXXXXXXXXXXXXXXXXXXXXX
*///WERSJA Z PRZEKAZYWANIEM PRZEZ ADRES
#include <stdio.h> 
#include <windows.h>
using namespace std;
void czytajRownanie(float *a, float *b, float *c){
	system("CLS");
	printf("Wczytywanie rownania w postaci:\n\n");
	printf("Ax + By = C\n\n");
	printf("Podaj A: ");
	scanf("%f",a);
	printf("Podaj B: ");
	scanf("%f",b);
	printf("Podaj C: ");
	scanf("%f",c);
	printf("Wczytano wspolczynniki\n\n");
	printf("Rowanie jest w postaci:\n\n\t%.1f X + %.1f Y = %.1f\n\n",*a,*b,*c);
	system("pause");
}
float obliczWyznacznik(float p1, float p2, float p3, float p4){
	return p1*p4-p2*p3;
}
int obliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y){
	float W,Wx,Wy; //wyznaczniki	
	W = obliczWyznacznik(a1,b1,a2,b2);
	Wx = obliczWyznacznik(c1,b1,c2,b2);
	Wy = obliczWyznacznik(a1,c1,a2,c2);
	//printf("W = %.2f Wx = %.2f Wy = %.2f \n",W,Wx,Wy);
	//system("pause");
	if(W == 0 && Wx == 0 && Wy == 0){
		return 2;
	}else
	if(W == 0 && Wx != 0 && Wy != 0){
		return 0;
	}else
	if(W != 0){
		*x = Wx/W;
		*y = Wy/W;
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
void wypiszRozwiazanie(int n, float *x, float *y){
	switch(n){
		case 0:
			printf("Uklad rownan jest sprzeczny\n");
			break;
		case 1:
			printf("Uklad rownan jest oznaczony\n");
			printf("Rozwiazanie ukladu rownan:\n");
			printf("X = %.2f\n",*x);
			printf("Y = %.2f\n",*y);
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
	float *wsk_a1 = &a1;
	float *wsk_b1 = &b1;
   	float *wsk_c1 = &c1;
	float *wsk_a2 = &a2;
	float *wsk_b2 = &b2;
	float *wsk_c2 = &c2;
	float *wsk_x = &x;
	float *wsk_y = &y;
	int n; //liczba rozwi¹zañ uk³adu
	//0 - sprzeczny; 1 - oznaczony; 2 - nieoznaczony
	czytajRownanie(wsk_a1,wsk_b1,wsk_c1);
	czytajRownanie(wsk_a2,wsk_b2,wsk_c2);
	system("cls");
	wypiszUkladRownan(a1,b1,c1,a2,b2,c2);
	n = obliczRozwiazanie(a1,b1,c1,a2,b2,c2,wsk_x,wsk_y);
	wypiszRozwiazanie(n,wsk_x,wsk_y);
	system("pause");
	return 0;
}