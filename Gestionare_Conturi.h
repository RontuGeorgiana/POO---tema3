#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

template <class T> class Gestionare_Conturi
{
	string nume_banca;
	int id_cont;
	T cont;
	public:
	void operator += (int &a);
	void operator -= (int &a);
	void operator = (Gestionare_Conturi &a);
	void afisare();
	void form_map();
	int get_id();
	float get_suma();
	void depunere();
	void retragere();
	void react();
    void viz_ist();
};

template <class T>
void Gestionare_Conturi<T>::operator += (int &a)
{
	this->nume_banca = "BRD";
	this->id_cont = a;
	citire(this->cont);
	a++;
}

template <class T>
void Gestionare_Conturi<T>::operator -= (int &a)
{
	a--;
}

template <class T>
void Gestionare_Conturi<T>::operator = (Gestionare_Conturi &a)
{
    this->nume_banca = a.nume_banca;
    this->id_cont = a.id_cont;
    this->cont = a.cont;
}

template <class T>
void Gestionare_Conturi<T>::afisare()
{
    cout<<"Numele Bancii : "<<this->nume_banca<<endl;
    cout<<"ID cont : "<<this->id_cont<<endl;
    this->cont.afisare();
}

template <class T>
void Gestionare_Conturi<T>::form_map()
{
    this->foo=&this->cont.afisare;
    this->op.push_back(this->foo);
    this->operatii.insert(pair< int , vector<int> >(this->id_cont,this->op));
    cout<<1<<endl;
}

template <class T>
int Gestionare_Conturi<T>::get_id()
{
    return id_cont;
}

template <class T>
void Gestionare_Conturi<T>::depunere()
{
    this->cont.depunere();
}

template <class T>
void Gestionare_Conturi<T>::retragere()
{
    this->cont.retragere();
}

template <class T>
void Gestionare_Conturi<T>::react()
{
    this->cont.react();
}

template <class T>
void Gestionare_Conturi<T>::viz_ist()
{
    this->cont.viz_ist();
}

template <class T>
float Gestionare_Conturi<T>::get_suma()
{
    return this->cont.get_suma();
}
