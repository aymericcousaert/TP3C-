/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Ajouter (Trajet & untrajet)
{
  //On réalloue dynamiquement le tableau pour ajouter un trajet
  nbTrajets++;
  Trajet ** nouveautab = new Trajet*[nbTrajets];
	for(int i=0;i<nbTrajets-1;nouveautab[i]=trajet[i],i++); //On copie les anciens trajet
	nouveautab[nbTrajets-1]= & untrajet;
	delete [] trajet;
  trajet = nouveautab;
}

void Catalogue::Afficher (){
    cout << "######### Catalogue ##########" << endl;
    for(int i=0;i<nbTrajets;i++){
	     cout << i << ") ";
      trajet[i]->Afficher();
    }
    cout << "#########    Fin    ##########" << endl;
}

void Catalogue::RechercheSimple (const char * undepart, const char * unearrivee ){
    cout << "Les trajets qui correspondent à votre voyage sont: " << endl;
    for (int i =0; i<nbTrajets; i++){
        if (!strcmp(trajet[i]->getDepart(),undepart) && !strcmp(trajet[i]->getArrivee(),unearrivee)){
	          cout << i << ")";
            trajet[i]->Afficher();
        }
    }
}





Catalogue::Catalogue ( )
// Algorithme :
//
{
trajet = new  Trajet*[1];
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
delete [] trajet;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
