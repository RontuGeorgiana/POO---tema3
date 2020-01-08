#include <string.h>

using namespace std;

class Cont
{
	protected:
	string detinator,data_deschidere,CNP;
	float sold;

	public:
	Cont();
	Cont(const Cont&);
	~Cont();
	void operator = (Cont &a);
	friend std::istream & operator >> (std::istream &, Cont &);
	friend void citire (Cont &a);
	virtual void afisare ();
};
