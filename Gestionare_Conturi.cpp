#include <iostream>
#include <string.h>
#include "Cont.h"
#include "Cont_Curent.h"
#include "Cont_Economii.h"
#include "Gestionare_Conturi.h"

using namespace std;

template <class T>
void Gestionare_Conturi<T>::operator += (int &a)
{
	this->nume_banca = "BRD";
	this->id_cont = a + 1;
	citire(this->cont);
	a++;
}

template <class T>
void Gestionare_Conturi<T>::operator -= (int &a)
{
	a--;
}

template <class T>
void Gestionare_Conturi<T>::afisare()
{
    cout<<"Numele Bancii : "<<this->nume_banca<<endl;
    cout<<"ID cont : "<<this->id_cont<<endl;
    this->cont.afisare();
}
