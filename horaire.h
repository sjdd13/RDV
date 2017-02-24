#ifndef HORAIRE_H
#define HORAIRE_H

class Horaire
{
	public:
		Horaire();
		Horaire(int h, int min);
		int getH() const;
		int getMin() const;
		void setH(int h);
		void setMin(int min);
		void addHeures(int v);
		void addMinutes(int v);
		bool operator<(const Horaire& horaire) const;
		bool operator>(const Horaire& horaire) const;
		bool operator==(const Horaire& horaire) const;
		bool operator!=(const Horaire& horaire) const; 
	private:
		int d_h, d_min;
		friend class RDV;
};

std::ostream& operator<<(std::ostream& os, const Horaire& h);

#endif
