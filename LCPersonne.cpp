#include <iostream>
#include <string>
#include "LCPersonne.h"
#include "personne.h"

LCPersonne::LCPersonne()
{}

LCPersonne::LCPersonne(Personne& tete): d_tete(&tete)
{}

void LCPersonne::ajouter(Personne& nouv)
{
	if(d_tete == NULL)
	{
		d_tete = &nouv;
		return;
	}
	Personne* crt = d_tete;   
	while(crt->getSuivant() != NULL && crt->getSuivant()->operator<(nouv))
	{
		crt = crt->getSuivant();
	}
	nouv.setSuivant(crt->getSuivant());
	crt->setSuivant(&nouv);
}

void LCPersonne::afficher() const
{
	Personne* crt = d_tete;
	while(crt != NULL)
	{
		std::cout << crt << std::endl;
		crt = crt->getSuivant();
	}
}

bool LCPersonne::vide() const
{
	return d_tete == 0;
}

Personne LCPersonne::rechercher(std::string nom) const
{
	if(d_tete == 0)
	{
		Personne p;
		return p;
	}
	Personne* crt = d_tete;
	while(crt->getSuivant() != 0)
	{
		if(crt->getPrenom() == nom)
		{
			return *crt;
		}	
		crt = crt->getSuivant();
	}
	Personne p;
	return p;
}

void LCPersonne::supprimer(Personne suppr)
{
	if(d_tete == 0)
	{
		return;
	}
	Personne* crt = d_tete;
	if(*crt == suppr)
	{
		d_tete = crt->getSuivant();
		return;
	}
	while(crt->getSuivant()->getSuivant() != 0 && *crt->getSuivant() != suppr)
	{
		crt = crt->getSuivant();
	}   
	if(*crt->getSuivant() == suppr)
	{
		crt->setSuivant(crt->getSuivant()->getSuivant());
	}	
}


Personne LCPersonne::getTete()
{
	return *d_tete;
}
