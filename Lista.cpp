#include<iostream>
using namespace std;
struct element
{
        int liczba;
        struct element *next;
};

void dodajNaKoniec(struct element **head)
 {
 	
        element* n = new element;
        cout<<"Podaj liczbe"<<endl;
        int podana;
        cin>>podana;
        n->liczba=podana;
        n->next = NULL;
        if(*head==NULL)
		{
            *head=n;
        }
        else 
		{
            element* tmp;
            tmp = *head;
            while(tmp->next) 
			{
                tmp=tmp->next;
            }
            tmp->next=n;
        }
}
void dodajNaPocz(struct element **head)
{
        element* n = new element;
    	cout<<"Podaj liczbe"<<endl;
        int podana;
        cin>>podana;
        n->liczba=podana;
        if(*head==NULL) 
		{
            *head=n;
            n->next = NULL;
        }
        else 
		{
            n->next = *head;
            *head = n;
        }
}
void wypisz(struct element *head) 
{
    if(head!=NULL) 
	{
		cout<<"Wypisana lista"<<endl;
        do 
		{
            cout<<head->liczba<<endl;
            head=head->next;
        }
		while(head);
    }
}

int main(void) 
{
    struct element *head = NULL;
    int co;
    int koniec=1;
    while(koniec==1) 
	{
        cout<<"co chcesz zrobic\n1. na koniec\n2. na pocz\n3. wypisz\n4. wyjdz "<<endl;
        scanf("%d",&co);
        switch(co)
		{
            case 1:
                dodajNaKoniec(&head);
                break;
            case 2:
                dodajNaPocz(&head);
                break;
            case 3:
                wypisz(head);
                break;
            case 4:
                koniec=0; cout<<"Koniec dzialania";
                break;
            default:
                break;
        }
    }
}
