#include<iostream>
using namespace std;
void DodajElement(int **tab, int pion, int poziom)
{
	int pom,i,j;
	pom=1;
	for(i=0;i<pion;i++)
	{
		for(j=0;j<poziom;j++)
		{
			*(*(tab+i)+j)=pom;
			pom++;
		}
	}
}
void CzytajTablice(int **tab, int pion, int poziom)
{
	int i,j;
	for(i=0;i<pion;i++)
	{
		for(j=0;j<poziom;j++)
		{
			cout<<*(*(tab+i)+j)<<" ";
		}
		cout<<endl;
	}
}
void ZwolnijPamiec(int **tab, int pion)
{
	int i;
	for(i=0;i<pion;i++)
	{
		delete tab[i];
	}
	delete *tab;
}
int main(void)
{
	int i,pion,poziom;
	cout<<"Podaj pion";
	cin>>pion;
	cout<<"Podaj poziom";
	cin>>poziom;
	int **tab=new int*[pion];
	for(i=0;i<pion;i++)
	{
		tab[i]=new int[poziom];
	}
	
	
}
