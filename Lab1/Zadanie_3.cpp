#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
	int czy_dalej=1;
	char t;
	do{
	float a,b,c;
	float delta,pierwiastek1,pierwiastek2;
	
	cout<<"Dany jest trojmian kwadratowy w postaci: Ax^2+Bx+C=0. Podaj jego wspolczyniki."<<endl;
	cout<<"Podaj wspolczynnik A: ";
	cin>>a;
	cout<<"Podaj wspolczynnik B: ";
	cin>>b;
	cout<<"Podaj wspolczynnik C: ";
	cin>>c;
	
	delta=(pow(b,2)-(4*a*c));
	cout<<"delta "<<delta;
	
	if(delta>0){
	pierwiastek1=(-b+sqrt(delta))/2*a;
	
	pierwiastek2=(-b-sqrt(delta))/2*a;
	
	cout<<endl<<"Trojmian ma dwa pierwiastki."<<endl<<"Pierwiastek 1: "<<pierwiastek1<<endl<<"Pierwiastek 2: "<<pierwiastek2;
	
	}
	if(delta==0){
		pierwiastek1=(-b)/2*a;
		cout<<endl<<"Trojmian ma jeden pierwiastek: "<<pierwiastek1;
		
	}
	if(delta<0){
		cout<<endl<<"Trojmian nie ma pierwiastkow rzeczywistych";
	}
	cout<<endl<<"---------------------------"<<endl<<"Aby kontunuowac prace programu nacisnij t"<<endl;
	cin>>t;
	if(t=='t') czy_dalej=1; else czy_dalej=0;
	}while(czy_dalej=1);
	
	return 0;
}