#include <iostream>
#include <string>

class Personne 
{
	public:
		Personne();
		Personne(std::string nom, std::string prenom);
		Personne(std::string nom, std::string prenom, std::string email);
		Personne(std::string nom, std::string prenom, std::string email, std::string tel);
		void setPrenom(std::string prenom);
		std::string getPrenom() const;
		void setNom(std::string nom);
		std::string getNom() const;
		void setEmail(std::string email);
		std::string getEmail() const;
		void setTel(std::string tel);
		std::string getTel() const;
		void setSuivant(Personne* suivant);
		Personne* getSuivant() const;
		bool operator<(const Personne& personne) const;
		bool operator>(const Personne& personne) const;
		bool operator==(const Personne& personne) const;
		bool operator!=(const Personne& personne) const;


	private:
		std::string d_prenom;
		std::string d_nom;
		std::string d_email;
		std::string d_tel;
		Personne* d_suivant;
		friend class LCPersonne;
};

std::ostream& operator<<(std::ostream& os, const Personne& p);
