#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
string szyfrowanie(string wyraz, char tab[][6])
{
	string zaszyfrowana="";
	for(int k=0;k<wyraz.length();k++)
	{
		if(wyraz[k]=='J')
		{
			wyraz[k]='I';
		}
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				if(wyraz[k]==tab[i][j])
				{
					zaszyfrowana+=i+'0';
					zaszyfrowana+=j+'0';
					zaszyfrowana+=" ";
				}
			}	
		}
	}
	return zaszyfrowana;
}
string deszyfrowanie(string zaszyfrowana, char tab[][6])
{
	int znak,znak2;
	string odszyfrowana="";
	for(int i=0;i<zaszyfrowana.length();i+=3)
	{
		znak=(int)zaszyfrowana[i]-48;
		znak2=(int)zaszyfrowana[i+1]-48;
		odszyfrowana+=tab[znak][znak2];
	}
	return odszyfrowana;
}
int main(int argc, char *argv[])
{
	if(argc!=4)
	{
		return 0;
	}
	int i,j;
	char tab[6][6],linia[200],x,znak;
	string wyraz , zaszyfr, odszyfr,napis;
	ifstream odczyt ("tabelka.txt");
	ifstream polibiusz (argv[1]);
	ofstream zapis (argv[2]);
	znak=argv[3][0];
	if(!odczyt)
	{
		cout<<"Nie otwarto pliku "<<endl;
		return 0;
	}
	while(!odczyt.eof())
	{
		for(i=0;i<6;i++)
		{
				odczyt.getline(linia,200);
				for(j=0;j<6;j++)
				{
					x=linia[j];
					tab[i][j]=x;
				}
		}
	}
	if(!polibiusz)
	{
		cout<<"Nie otwarto pliku"<<endl;
		return 0;
	}
	while(!polibiusz.eof())
	{
		polibiusz>>wyraz;
		napis+=wyraz;
		napis+=" ";
	}
	switch(znak)
		{
			case '0': zapis<<szyfrowanie(napis,tab);
			case '1': zapis<<deszyfrowanie(napis,tab); 
		}
		return 0;
}
