#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
	int wzrost;
	cout<<"Podaj wzrost w cm: ";
	cin>>wzrost;
	if(wzrost<150) cout<<"niski";
	if(wzrost>=150&&wzrost<180) cout<<"sredni";
	if(wzrost>=180) cout<<"wysoki";
	
	return 0;
}