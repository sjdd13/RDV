#ifndef DATE_H
#define DATE_H

class Dates
{
	public:
		Dates();
		Dates(int j, int m, int a);
		int getJ() const;
		int getM() const;
		int getA() const;
		void setJ(int j);
		void setM(int m);
		void setA(int a);
		bool operator<(const Dates& date) const;
		bool operator>(const Dates& date) const;
		bool operator==(const Dates& date) const;
		bool operator!=(const Dates& date) const; 
	private:
		int d_j, d_m, d_a;
		friend class RDV;
};

std::ostream& operator<<(std::ostream& os, const Dates& d);

#endif
