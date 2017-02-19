#include <iostream>
#include <string>

class Personne;
class LCPersonne {
	public:
		LCPersonne();
		~LCPersonne();
		LCPersonne(Personne& tete);
		void ajouter(Personne& nouv);
		void afficher() const;
		bool vide() const;
		Personne rechercher(std::string nom) const;
		void supprimer(Personne suppr);
		void setTete(Personne tete);
		Personne getTete();
	private:
		Personne* d_tete;
};
