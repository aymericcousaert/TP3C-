/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
const void TrajetSimple::Afficher ()
{
    cout<<"Trajet de " << depart << " à " << arrivee<<" en "<<moyen<<endl;
    
}


//------------------------------------------------- Surcharge d'opérateurs
void TrajetSimple::operator = (TrajetSimple const & trajet){
	delete depart;
	depart = new char[strlen(trajet.depart)+1];
	strcpy(depart,trajet.depart);
	delete arrivee;
	arrivee = new char[strlen(trajet.arrivee)+1];
	strcpy(arrivee,trajet.arrivee);
	delete moyen;
	moyen = new char[strlen(trajet.moyen)+1];
	strcpy(moyen,trajet.moyen);
}
//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char * undepart,const char * unearrivee, const char * unmoyen):Trajet(undepart,unearrivee)
// Algorithme :
//
{
    moyen = new char[strlen(unmoyen)+1];
    strcpy(moyen,unmoyen);
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple():Trajet(){
    #ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
}

TrajetSimple::TrajetSimple(const TrajetSimple & unTrajet):Trajet(unTrajet.depart,unTrajet.arrivee){
    moyen = new char[strlen(unTrajet.moyen)+1];
    strcpy(moyen,unTrajet.moyen);

    #ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif
}
TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
    delete [] moyen;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
