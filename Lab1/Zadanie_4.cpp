#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char** argv)
{
	while(1){
	cout<<"Wcisniety klawisz to: "<<endl;
	int znak=getch();
	if((int)znak>=97&&(int)znak<=122) cout<<"Mala litera"; else
	if((int)znak>=48&&(int)znak<=57) cout<<"Cyfra"; else
	if((int)znak==13) cout<<"Enter"; else
	if((int)znak>=65&&(int)znak<=90) cout<<"Wielka litera"; else
	//if((int)znak==27) cout<<"Escape"; else
	//if((int)znak==13) cout<<"Strzalka w lewo"; else
	//if((int)znak==13) cout<<"Strzalka w prawo"; else
	//if((int)znak==13) cout<<"Klawisz F1"; else
	cout<<"Inny klawisz";
	cout<<endl;
	}
	
	
	return 0;
}