#include <iostream>
#include <list>
#include "Cont.h"
#include "Cont_Economii.h"

using namespace std;

Cont_Economii::Cont_Economii()
{
	list <istoric> ist;
}

Cont_Economii::~Cont_Economii()
{

}

Cont_Economii::Cont_Economii(const Cont_Economii &a)
{
	detinator = a.detinator;
	CNP = a.CNP;
	data_deschidere = a.data_deschidere;
	sold = a.sold;
	rata_dob = a.rata_dob;
	perioada_dob = a.perioada_dob;
	list<istoric> ist (a.ist);
}

void Cont_Economii::operator = (Cont_Economii &a)
{
	this->detinator = a.detinator;
	this->CNP = a.CNP;
	this->data_deschidere = a.data_deschidere;
	this->sold = a.sold;
	this->rata_dob = a.rata_dob;
	this->perioada_dob = a.perioada_dob;
	list<istoric>::iterator p;
	list<istoric>::iterator r;
	for(r = ist.end(); r != ist.begin(); r--)
        ist.erase(r);
    for(p = a.ist.begin(); p != a.ist.end(); p++)
            ist.push_back(*p);
}

void citire (Cont_Economii &a)
{
	cin>>a;
	cout<<"Rata dobanda: ";
	cin>>a.rata_dob;
	cout<<"Perioada dobanda: ";
	cin>>a.perioada_dob;
}

void Cont_Economii::afisare ()
{
	cout<<"Nume si prenume: "<<this->detinator<<endl;
	cout<<"CNP: "<<this->CNP<<endl;
	cout<<"Data deschiderii: "<<this->data_deschidere<<endl;
	cout<<"Sold: "<<this->sold<<endl;
	cout<<"Rata dobanda: "<<this->rata_dob<<endl;
	cout<<"Perioada dobanda: "<<this->perioada_dob<<endl;
}

void Cont_Economii::react()
{
	istoric x;
	float val;
	string a,t="reactualizare";
	cout<<"Data curenta: ";
	cin>>a;
	x.set_data(a);
	x.set_tip(t);
	val = this->sold * this->rata_dob * (12 / this->perioada_dob);
	x.set_suma(val);
	this->suma = val;
	this->sold += x.get_suma();
	this->ist.push_back(x);
}

void Cont_Economii::viz_ist()
{
	list<istoric>::iterator p;
	for(p = this->ist.begin(); p != this->ist.end(); p++)
        cout<<*p<<endl;
}

float Cont_Economii::get_suma()
{
    return this->suma;
}
