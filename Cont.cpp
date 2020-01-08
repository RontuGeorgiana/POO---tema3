#include <iostream>
#include <string.h>
#include "Cont.h"

using namespace std;

Cont::Cont()
{

}

Cont::~Cont()
{

}

Cont::Cont(const Cont &a)
{
	detinator = a.detinator;
	CNP = a.CNP;
	data_deschidere = a.data_deschidere;
	sold = a.sold;
}

istream & operator >> (istream & in, Cont &a)
{
    string nume,prenume;
	cout<<"Nume : ";
    cin>>nume;
    cout<<"Prenume : ";
    cin>>prenume;
    a.detinator = nume + " " + prenume;
	cout<<"CNP : ";
	cin>>a.CNP;
	cout<<"data curenta: ";
	cin>>a.data_deschidere;
	cout<<"suma depusa: ";
	cin>>a.sold;
}

void citire (Cont &a)
{
	cin>>a;
}

void Cont::operator = (Cont &a)
{
	this->detinator = a.detinator;
	this->CNP = a.CNP;
	this->data_deschidere = a.data_deschidere;
	this->sold = a.sold;
}

void Cont::afisare ()
{
	cout<<"Nume si prenume: "<<this->detinator<<endl;
	cout<<"CNP: "<<this->CNP<<endl;
	cout<<"Data deschiderii: "<<this->data_deschidere<<endl;
	cout<<"Sold: "<<this->sold<<endl;
}
