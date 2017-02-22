#include <iostream>
//#include <string>
#include "LCRDV.h"
//#include "RDV.h"

LCRDV::LCRDV(): d_tete(NULL) {
}

LCRDV::~LCRDV(){
    if(this!=NULL){
        RDV* crt;
        while(d_tete != NULL){
            crt = d_tete;
            d_tete = crt->suivant;
            delete crt;
        }
    }
}

void LCRDV::ajouter(const RDV& nouvRDV){
	RDV* nouv = new RDV(nouvRDV); // on crée une copie pour éviter les bugs liés à des pointeurs sur le RDV qui seraient en dehors de cette classe

	if(d_tete == NULL) {
        d_tete = nouv;
        nouv->suivant = NULL;
    } else {
        RDV* crt = d_tete;
        while(crt->suivant() != NULL && crt->suivant < *nouv) // verification needed
            crt = crt->suivant;

        nouv->suivant = crt->suivant;
        crt->suivant = nouv;
    }
}

void LCRDV::afficher() const {
	RDV *crt = d_tete;
	while(crt != NULL){
		std::cout << *crt << std::endl;
		crt = crt->suivant;
	}
}

bool LCRDV::vide() const{
	return d_tete == NULL;
}

bool LCRDV::existe(const RDV &rendezVous) const {
    RDV *crt=d_tete;

    while(crt!=NULL && *crt!=rendezVous)
        crt=crt.suivant;

    return crt!=NULL;
}

void LCRDV::supprimer(const RDV &suppr){

	if(d_tete != NULL){
        if(*d_tete==suppr){
            RDV *chainon=d_tete;
            d_tete=d_tete->suivant;
            delete chainon;
        } else {
            RDV *crt=tete;
            while(crt->suivant != NULL && *crt->suivant != suppr)
                crt = crt->suivant;

            if(crt->suivant != NULL){
                RDV *chainon = crt->suivant;
                crt->suivant = chainon->suivant;
                delete chainon;
            }
        }
    }

}




