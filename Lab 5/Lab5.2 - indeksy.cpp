/*
Autor: Tomasz Rzymyszkiewicz
Grupa: ŒR/P 15:15
Temat: Zadania - Laboratorium 5
Data: XXXXXXXXXXXXXXXXXXXXXXXX
*/
#include <string.h>
#include <stdio.h>
int moje_strlen(char * tablica){
	int licznik = 0;
	while(tablica[licznik] != '\0'){
		licznik++;
	}
	return licznik;
}
char * moje_strcpy(char * tab1,char * tab2){
	int i = 0;
	do{
		tab1[i] = tab2[i];
	}
	while(tab2[i++] != '\0');
	return tab1;
}
int moje_strcmp(char * tab1,char * tab2){
	int i = 0;
	while(tab1[i]==tab2[i]){
		i++;
	}
	if((int)tab1[i]>(int)tab2[i]){
		return (int)tab1[i]-(int)tab2[i];
	}else
	if((int)tab1[i]<(int)tab2[i]){
		return (int)tab1[i]-(int)tab2[i];
	}else
	return 0;
}
char * moje_strchr (char * tab, int znak){
	
	while( *tab != (char)znak){
		if(*tab == '\0'){
			return NULL;
		}else
		tab++;
	}
	return tab;
	
}
char * moje_strupr(char * tab){
	for(int i = 0; tab[i] != '\0'; i++){
		if((int)tab[i] >= 'a' && (int)tab[i] <= 'z')
		tab[i] -= 32;
	}
	return tab;
}
char * moje_strlwr(char * tab){
	for(int i = 0; tab[i] != '\0'; i++){
		if((int)tab[i] >= 'A' && (int)tab[i] <= 'Z')
		tab[i] += 32;
	}
	return tab;
}
int main()
{
	printf("TEST FUNCKJI moje_strlen\n");
	char tab1[] = "ala ma kota";
	char tab2[10] = "ala";
	for(int i = 0; i < moje_strlen(tab1); i++) printf("%c",tab1[i]);
	printf("\nmoje_strlen = %d\n",moje_strlen(tab1));
	for(int i = 0; i < moje_strlen(tab2); i++) printf("%c",tab2[i]);
	printf("\nmoje_strlen = %d\n",moje_strlen(tab2));

	printf("\nFUNCKJI moje_strcpy\n");
	char tab3[] = "123hvhvhjvhvhvhvhvh45";
	char tab4[] = "qwertvgvy";
	printf("str1 %s\nstr2 %s\n\n",tab3,tab4);
	moje_strcpy(tab3,tab4);
	printf("str1 %s\nstr2 %s\n",tab3,tab4);
	
	printf("\nFUNCKJI moje_strcmp\n");
	char tab5[] = "12435bjbjk";
	char tab6[] = "12434hvyvy";
	printf("str1 %s\nstr2 %s\n",tab5,tab6);
	printf("moje_strcmp = %d\n",moje_strcmp(tab5,tab6));
	
	printf("\nFUNCKJI moje_strchr\n");
	char str[] = "This is a sample string";
	char * pch;
	printf ("Looking for the 's' character in \"%s\"...\n",str);
	pch = moje_strchr(str,'s');
	while (pch!=NULL)
	{
    	printf ("found at %d\n",pch-str+1);
    	pch=moje_strchr(pch+1,'s');
	}
  
    printf("\nFUNCKJI moje_strupr\n");
    char tab7[] = "tekst z malych i WIELKCH liter";
    printf("%s\n",tab7);
    moje_strupr(tab7);
    printf("moje_strupr = %s\n",tab7);
    
    printf("\nFUNCKJI moje_strupr\n");
    char tab8[] = "tekst z malych i WIELKICH liter";
    printf("%s\n",tab8);
    moje_strlwr(tab8);
    printf("moje_strlwr = %s",tab8);
    
	return 0;
}