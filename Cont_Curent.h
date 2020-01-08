class Cont_Curent : public Cont
{
	int nr_tranz;
	float dob_tranz;
	float suma;

	public:
	Cont_Curent();
	Cont_Curent(const Cont_Curent&);
	~Cont_Curent();
	void operator = (Cont_Curent &a);
    friend void citire (Cont_Curent &a);
    void afisare ();
    friend std::istream & operator >> (std::istream &, Cont &);
	void retragere ();
	void depunere ();
	float get_suma();
};
