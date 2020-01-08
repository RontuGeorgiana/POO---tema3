#include <list>
#include "istoric.h"

class Cont_Economii : public Cont
{
	float rata_dob, perioada_dob;
	list <istoric> ist;
	float suma;

    public:
    Cont_Economii();
    Cont_Economii(const Cont_Economii&);
    ~Cont_Economii();
    void operator = (Cont_Economii &a);
    friend void citire (Cont_Economii &a);
    void afisare ();
    friend std::istream & operator >> (std::istream &, Cont &);
    void react();
    void viz_ist();
    float get_suma();
};
