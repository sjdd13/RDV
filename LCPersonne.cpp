#include <iostream>
#include <string>
#include "LCPersonne.h"
#include "personne.h"

LCPersonne::LCPersonne(): d_tete(0)
{}

LCPersonne::LCPersonne(Personne& tete): d_tete(&tete)
{}


LCPersonne::~LCPersonne()
{
    if(this != NULL)
	{
	Personne* crt;
		while(d_tete != 0)
		{
			crt = d_tete;
			d_tete = crt->getSuivant();
			delete crt;
		}
    }
}




void LCPersonne::ajouter(Personne& nouv)
{
	if(d_tete == 0 || d_tete->operator>(nouv))
	{
		nouv.setSuivant(d_tete);
		d_tete = &nouv;
	}
	else 
	{
		Personne* crt = d_tete;   
		while(crt->getSuivant() != 0 && crt->getSuivant()->operator<(nouv))
		{
			crt = crt->getSuivant();
		}
		nouv.setSuivant(crt->getSuivant());
		crt->setSuivant(&nouv);	
	}
}

void LCPersonne::afficher() const
{
	Personne* crt = d_tete;
	while(crt != 0)
	{
		std::cout << *crt << std::endl;
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
			Personne p = *crt;
			return p;
		}	
		crt = crt->getSuivant();
	}
	Personne p;
	return p;
}

void LCPersonne::supprimer(Personne suppr)
{
	if(d_tete != 0)
	{
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
}


Personne LCPersonne::getTete()
{
	return *d_tete;
}





