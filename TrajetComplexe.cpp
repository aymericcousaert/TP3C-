/*************************************************************************
 TrajetComplexe  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetComplexe> (fichier TrajetComplexe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void TrajetComplexe::operator = (TrajetComplexe const & trajet){
	delete depart;
	depart = new char[strlen(trajet.depart)+1];
	strcpy(depart,trajet.depart);
	delete arrivee;
	arrivee = new char[strlen(trajet.arrivee)+1];
	strcpy(arrivee,trajet.arrivee);
	nbTrajet = trajet.nbTrajet;
	delete [] trajets;
	trajets = new Trajet * [nbTrajet];
	for(int i=0;i<nbTrajet;i++){
        trajets[i] = trajet.trajets[i];
	}
}
//----------------------------------------------------- Méthodes publiques
// type TrajetComplexe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void const TrajetComplexe::Afficher(){
  cout << "Trajet complexe de "<< depart << " vers " << arrivee << endl;
  for(int i=0;i<nbTrajet;i++){
    cout << "\t";
    trajets[i]->Afficher();
  }
  //cout << "Fin du trajet complexe" << endl;
}


//-------------------------------------------- Constructeurs - destructeur

TrajetComplexe::TrajetComplexe(Trajet ** desTrajets,int nbTrajet):
	Trajet(desTrajets[0]->getDepart(),desTrajets[nbTrajet-1]->getArrivee())
{
  this->nbTrajet = nbTrajet;
  this->trajets = new Trajet * [nbTrajet];
  for(int i=0;i<nbTrajet;i++){
    this->trajets[i] = desTrajets[i];
  }
#ifdef MAP
  cout << "Appel au constructeur de <TrajetComplexe>" << endl;
#endif
} //----- Fin de TrajetComplexe

TrajetComplexe::TrajetComplexe():Trajet(){
    #ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
}

TrajetComplexe::~TrajetComplexe ( )
  // Algorithme :
  //
{
delete [] trajets;
#ifdef MAP
  cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
} //----- Fin de ~TrajetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

