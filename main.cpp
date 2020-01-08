#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include "Cont.h"
#include "Cont_Economii.h"
#include "Cont_Curent.h"
#include "Gestionare_Conturi.h"
//#include "istoric.h"

using namespace std;

int main()
{

    int opt, id=100;
    bool b=1;
    vector<Gestionare_Conturi<Cont_Curent> > cont_c;
    vector<Gestionare_Conturi<Cont_Economii> > cont_e;
    vector<istoric> op;
    map<int,vector<istoric> > operatii;
    Gestionare_Conturi<Cont_Curent> c_c;
    Gestionare_Conturi<Cont_Economii>c_e;
    do
    {
        cout<<"Alegeti optiunea dorita:\n1-Crearea conturilor\n2-Afisarea conturilor curente\n3-Afisarea conturilor de economii\n4-Afisarea unui cont\n5-Depunere in cont curent\n6-Retragere din cont curent\n";
        cout<<"7-Reactualizarea unui cont de economii\n8-Vizualizarea istoricului de reactualizare a unui cont de economii\n9-Vizualizarea istoricului unui cont\n10-Inchiderea programului\n";
        cin>>opt;
        while(1)
        {
            try
            {
                if (!cin)
                    throw b;
                else throw opt;
            }
            catch (bool)
            {
                cout<<"Valoarea nu este buna\n";
                cin.clear();
                cin.ignore(1);
                break;
            }
            catch (int x)
            {
                switch (opt)
                {
                    case 1:
                        {
                            int opt_2;
                            cout<<"Ce tip de cont doriti?\n1-Cont curent\n2-Cont de economii\n";
                            cin>>opt_2;
                            if (opt_2==1)
                            {
                                c_c += id;
                                cont_c.push_back(c_c);
                            }
                            else if (opt_2==2)
                            {
                                c_e += id;
                                cont_e.push_back(c_e);
                            }
                            break;
                        }
                    case 2:
                        {
                            int i;
                            for(i=0; i<cont_c.size(); i++)
                                cont_c[i].afisare();
                            break;
                        }
                    case 3:
                        {
                            int i;
                            for(i=0; i<cont_e.size(); i++)
                                cont_e[i].afisare();
                            break;
                        }
                    case 4:
                        {
                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            int i;
                            for(i=0; i<cont_c.size(); i++)
                                if (cont_c[i].get_id()==id_s)
                                {
                                    cont_c[i].afisare();
                                    break;
                                }
                            for(i=0; i<cont_e.size(); i++)
                                if (cont_e[i].get_id()==id_s)
                                {
                                    cont_e[i].afisare();
                                    break;
                                }
                            break;
                        }
                    case 5:
                        {
                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            int i;
                            for(i=0; i<cont_c.size(); i++)
                                if (cont_c[i].get_id()==id_s)
                                {
                                    string data;
                                    float suma;
                                    cout<<"Introduceti data curenta : ";
                                    cin>>data;
                                    cont_c[i].depunere();
                                    istoric ist;
                                    ist.set_data(data);
                                    string st = "depunere";
                                    ist.set_tip(st);
                                    suma = cont_c[i].get_suma();
                                    ist.set_suma(suma);
                                    if(operatii.find(id_s) == operatii.end())
                                    {
                                        op.push_back(ist);
                                        operatii.insert(pair<int, vector<istoric> >(id_s, op));
                                    }
                                    else
                                        operatii[id_s].push_back(ist);
                                    break;
                                }
                            break;
                        }
                    case 6:
                        {
                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            int i;
                            for(i=0; i<cont_c.size(); i++)
                                if (cont_c[i].get_id()==id_s)
                                {
                                    string data;
                                    float suma;
                                    cout<<"Introduceti data curenta : ";
                                    cin>>data;
                                    cont_c[i].retragere();
                                    istoric ist;
                                    ist.set_data(data);
                                    string st = "retragere";
                                    ist.set_tip(st);
                                    suma = cont_c[i].get_suma();
                                    ist.set_suma(suma);
                                    if(operatii.find(id_s) == operatii.end())
                                    {
                                        op.push_back(ist);
                                        operatii.insert(pair<int, vector<istoric> >(id_s, op));
                                    }
                                    else
                                        operatii[id_s].push_back(ist);
                                    break;;
                                }
                            break;
                        }
                    case 7:
                        {

                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            int i;
                            for(i=0; i<cont_e.size(); i++)
                                if (cont_e[i].get_id()==id_s)
                                {
                                    string data;
                                    float suma;
                                    cout<<"Introduceti data curenta : ";
                                    cin>>data;
                                    cont_e[i].react();
                                    istoric ist;
                                    ist.set_data(data);
                                    string st = "reactualizare";
                                    ist.set_tip(st);
                                    suma = cont_e[i].get_suma();
                                    ist.set_suma(suma);
                                    if(operatii.find(id_s) == operatii.end())
                                    {
                                        op.push_back(ist);
                                        operatii.insert(pair<int, vector<istoric> >(id_s, op));
                                    }
                                    else
                                        operatii[id_s].push_back(ist);
                                    break;
                                }
                            break;
                        }
                    case 8:
                        {
                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            int i;
                            for(i=0; i<cont_e.size(); i++)
                                if (cont_e[i].get_id()==id_s)
                                {
                                    cont_e[i].viz_ist();
                                    break;
                                }
                            break;
                        }
                    case 9:
                        {
                            int id_s;
                            cout<<"Introduceti id-ul contului:";
                            cin>>id_s;
                            vector<istoric>::iterator p;
                            for(p=operatii[id_s].begin(); p!=operatii[id_s].end(); p++)
                                cout<<*p<<endl;
                            break;
                        }

                }
                if (x==10)
                    b=0;
                break;
            }
        }

    }while (b);
    return 0;

}
