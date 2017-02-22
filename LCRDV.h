#include <iostream>
//#include <string>

class RDV; // **********


class LCRDV{ // Liste chainée rendez-vous
	public:
		LCRDV();
		~LCRDV();
		void ajouter(const RDV& nouv);
		void supprimer(const RDV &suppr);
		void afficher() const;
		bool vide() const;
		bool existe(const RDV &rendezVous) const;
	private:
		RDV* d_tete;
};
