#include <iostream>
#include <string.h>
#include "Cont.h"
#include "Cont_Curent.h"

using namespace std;

Cont_Curent::Cont_Curent()
{

}

Cont_Curent::~Cont_Curent()
{

}

Cont_Curent::Cont_Curent(const Cont_Curent &a)
{
	detinator = a.detinator;
	CNP = a.CNP;
	data_deschidere = a.data_deschidere;
	sold = a.sold;
	nr_tranz = a.nr_tranz;
	dob_tranz = a.dob_tranz;
}

void Cont_Curent::operator = (Cont_Curent &a)
{
	this->detinator = a.detinator;
	this->CNP = a.CNP;
	this->data_deschidere = a.data_deschidere;
	this->sold = a.sold;
	this->nr_tranz = a.nr_tranz;
	this->dob_tranz = a.dob_tranz;
}

void citire (Cont_Curent &a)
{
	cin>>a;
	cout<<"Numar de tranzactii gratuite : ";
	cin>>a.nr_tranz;
	cout<<"Dobanda aplicta tranzactiilor : ";
	cin>>a.dob_tranz;
}

void Cont_Curent::afisare ()
{
	cout<<"Nume si prenume: "<<this->detinator<<endl;
	cout<<"CNP: "<<this->CNP<<endl;
	cout<<"Data deschiderii: "<<this->data_deschidere<<endl;
	cout<<"Sold: "<<this->sold<<endl;
	cout<<"Numar de tranzactii gratuite : "<<this->nr_tranz<<endl;
	cout<<"Dobanda aplicta tranzactiilor : "<<this->dob_tranz<<endl;
}

void Cont_Curent::retragere ()
{
	string rasp;
	cout<<"Cardul si bancomatul apartin aceleasi banci?(da/nu)\n";
	cin>>rasp;
	cout<<"Introduceti valoarea dorita : ";
	cin>>suma;
	if (rasp == "da" && this->nr_tranz>0)
	{
		this->nr_tranz--;
		this->sold -= suma;
	}
	else
		this->sold -= (suma + (suma * this->dob_tranz));
}

void Cont_Curent::depunere()
{
	string rasp;
	cout<<"Cardul si bancomatul apartin aceleasi banci?(da/nu)\n";
	cin>>rasp;
	cout<<"Introduceti valoarea dorita : ";
	cin>>this->suma;
	if (rasp == "da")
		this->sold += suma;
	else
		this->sold += (suma - (suma * dob_tranz));
}

float Cont_Curent::get_suma()
{
    return this->suma;
}
