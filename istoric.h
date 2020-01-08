#include <string.h>

using namespace std;

class istoric
{
	string data;
	string tip;
	float suma;

	public:
	istoric();
	istoric(const istoric&);
	~istoric();
	void operator = (istoric &a);
	string get_data();
	float get_suma();
	string get_tip();
	void set_data(string &a);
	void set_suma(float &a);
	void set_tip(string &a);
	friend std::ostream & operator << (std::ostream &, istoric&);
};
