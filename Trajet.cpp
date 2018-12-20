/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const void Trajet::Afficher ()
{
    cout<<"Trajet de " << depart << " à " << arrivee<<endl;
}

const char * Trajet::getDepart(){
    return depart;
}

const char * Trajet::getArrivee(){
    return arrivee;
}

const char* Trajet::getMoyen() const {
    string temp = "NONDEFINI";
    return temp.c_str();
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
{
    depart = new char[strlen(unTrajet.depart)+1];
    arrivee = new char[strlen(unTrajet.arrivee)+1];
    strcpy(depart,unTrajet.depart);
    strcpy(arrivee,unTrajet.arrivee);
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)

Trajet::Trajet(){
    depart = new char[1];
    arrivee = new char[1];
    strcpy(depart,"");
    strcpy(arrivee,"");
}


Trajet::Trajet (const char * undepart, const char * unearrivee )
{
    depart = new char[strlen(undepart)+1];
    arrivee = new char[strlen(unearrivee)+1];
    strcpy(depart,undepart);
    strcpy(arrivee,unearrivee);
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
}

Trajet::~Trajet( )
{
delete [] arrivee;
delete [] depart;
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
