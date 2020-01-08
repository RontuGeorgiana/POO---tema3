#include <iostream>
#include <string.h>
#include "istoric.h"

using namespace std;

istoric::istoric()
{

}

istoric::~istoric()
{

}

istoric::istoric(const istoric &a)
{
	data = a.data;
	suma = a.suma;
	tip = a.tip;
}

void istoric::operator = (istoric &a)
{
    this->data = a.data;
    this->suma = a.suma;
    this->tip = a.tip;
}

string istoric::get_data()
{
	return this->data;
}

float istoric::get_suma()
{
	return this->suma;
}

string istoric::get_tip()
{
    return this->tip;
}

void istoric::set_data(string &a)
{
    this->data = a;
}

void istoric::set_suma(float &a)
{
    this->suma = a;
}

void istoric::set_tip(string &a)
{
    this->tip = a;
}

ostream & operator << (ostream &out, istoric &a)
{
    cout<<"Data :"<<a.data<<endl;
    cout<<"Tip operatiune : "<<a.tip<<endl;
    cout<<"Suma :"<<a.suma<<endl;
}
