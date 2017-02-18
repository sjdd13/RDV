#include <iostream>
#include <string>
#include "personne.h"

Personne::Personne(): d_suivant(0)
{}

Personne::Personne(std::string nom, std::string prenom): d_nom(nom), d_prenom(prenom), d_suivant(0)
{}

Personne::Personne(std::string nom, std::string prenom, std::string email):  d_nom(nom), d_prenom(prenom), d_email(email), d_suivant(0)
{}

Personne::Personne(std::string nom, std::string prenom, std::string email, std::string tel):  d_nom(nom), d_prenom(prenom), d_email(email), d_tel(tel), d_suivant(0)
{}

void Personne::setPrenom(std::string prenom)
{
	d_prenom = prenom;
}

std::string Personne::getPrenom() const
{
	return d_prenom;
}

void Personne::setNom(std::string nom)
{
	d_nom = nom;
}

std::string Personne::getNom() const
{
	return d_nom;
}

void Personne::setEmail(std::string email)
{
	d_email = email;
}

std::string Personne::getEmail() const
{
	return d_email;
}

void Personne::setTel(std::string tel)
{
	d_tel = tel;
}

std::string Personne::getTel() const
{
	return d_tel;
}

void Personne::setSuivant(Personne* suivant)
{
	d_suivant = suivant;
}

Personne* Personne::getSuivant() const
{
	return d_suivant;
}

std::ostream& operator<<(std::ostream& os, const Personne& p)
{
	os << p.getPrenom() << " " << p.getNom() << " " << p.getTel() << " " << p.getEmail();
	return os;
}

bool Personne::operator<(const Personne& personne) const
{
	if(d_prenom < personne.getPrenom())
	{
		return true;
	}
	else if(d_prenom > personne.getPrenom())
	{
		return false;
	}
	else
	{
		if(d_nom < personne.getNom())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool Personne::operator>(const Personne& personne) const
{
	if(d_prenom > personne.getPrenom())
	{
		return true;
	}
	else if(d_prenom < personne.getPrenom())
	{
		return false;
	}
	else
	{
		if(d_nom > personne.getNom())
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
}

bool Personne::operator==(const Personne& personne) const
{
	if((d_prenom+d_nom) == (personne.getPrenom()+personne.getNom()))
	{
		return true;
	}
	return false;
}

bool Personne::operator!=(const Personne& personne) const
{
	if((d_prenom+d_nom) != (personne.getPrenom()+personne.getNom()))
	{
		return true;
	}
	return false;
}
