#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct uni
{char nume[30], stat[30], zona[30];
float rata;
int nr;
};

FILE *f;

void meniu ()
{cout<<"1. sortati univeristatile dupa nume"<< endl;
cout<<"2. sortati universitatile dupa statul de provenienta"<<endl;
cout<<"3. sortati universitatile dupa tipul de zona universitara"<<endl;
cout<<"4. sortati universitatile dupa rata de admitere"<<endl;
cout<<"5. sortati universitatile dupa numarul de studenti undegrad admisi anual"<<endl;
}

void nume (uni u[], int n)
{int i, ok; uni aux;
for (i=0; i<=n-2; i++)
 if (strcmp(u[i].nume, u[i+1].nume)>0)
 {aux=u[i];
 u[i]=u[i+1];
 u[i+1]=aux;
 }
for (i=0; i<=n-1; i++)
cout<<i+1<<". "<<u[i].nume<<" "<<u[i].stat<<" "<<u[i].zona<<" "<<u[i].rata<<" "<<u[i].nr<<endl;
}

void stat (uni u[], int n)
{int i, ok; uni aux;
for (i=0; i<=n-2; i++)
 if (strcmp(u[i].stat, u[i+1].stat)>0)
 {aux=u[i];
 u[i]=u[i+1];
 u[i+1]=aux;
 }
for (i=0; i<=n-1; i++)
cout<<i+1<<". "<<u[i].nume<<" "<<u[i].stat<<" "<<u[i].zona<<" "<<u[i].rata<<" "<<u[i].nr<<endl;
}

void zona (uni u[], int n)
{int i, ok; uni aux;
for (i=0; i<=n-2; i++)
 if (strcmp(u[i].zona, u[i+1].zona)>0)
 {aux=u[i];
 u[i]=u[i+1];
 u[i+1]=aux;
 }
for (i=0; i<=n-1; i++)
cout<<i+1<<". "<<u[i].nume<<" "<<u[i].stat<<" "<<u[i].zona<<" "<<u[i].rata<<" "<<u[i].nr<<endl;
}


void rata (uni u[], int n)
{int i, ok; uni aux;
do
{ok=0;
for (i=0; i<=n-2; i++)
 if (u[i].rata>u[i+1].rata)
 {aux=u[i];
 u[i]=u[i+1];
 u[i+1]=aux;
 }
} while (ok==1);
for (i=0; i<=n-1; i++)
cout<<i+1<<". "<<u[i].nume<<" "<<u[i].stat<<" "<<u[i].zona<<" "<<u[i].rata<<" "<<u[i].nr<<endl;
}


void nr (uni u[], int n)
{int i, ok; uni aux;
do
{ok=0;
for (i=0; i<=n-2; i++)
 if (u[i].nr> u[i+1].nr)
 {aux=u[i];
 u[i]=u[i+1];
 u[i+1]=aux;
 }
} while (ok==1);
for (i=0; i<=n-1; i++)
cout<<i+1<<". "<<u[i].nume<<" "<<u[i].stat<<" "<<u[i].zona<<" "<<u[i].rata<<" "<<u[i].nr<<endl;
}

void index (uni u[], int &n)
{int tasta; char r;
do
{
 meniu ();
 cout<<"tastati cifra corespunzatoare optiunii"<<endl;
 cin>>tasta;
 switch(tasta)
 {case 1: {nume (u, n); break;}
 case 2: {stat (u, n); break;}
 case 3: {zona (u, n); break;}
 case 4: {rata (u, n); break;}
 case 5: {nr (u, n); break;}
 default: cout<<"nu ati introdus cifra corecta"<<endl;
 }
cout<<"daca doriti sa reveniti la meniul principal apasati r"<<endl;
cin>>r;
} while (r=='r');
}


int main()
{
int n, i, ok;
uni u[30]; uni aux;
f=fopen ("uni.in", "r");
fscanf (f, "%d", &n);
for (i=0; i<=n-1; i++)
 fscanf (f, "%s %s %s %f %d", u[i].nume, u[i].stat, u[i].zona, &u[i].rata, &u[i].nr);

meniu();
index (u, n);

getch();
return 0 ;
}
