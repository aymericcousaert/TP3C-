/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    /*** Affiche le trajet en console
    *
    */
    virtual const void  Afficher();

//-------------------------------------------------- Surcharge d'opérateurs
    /**Surcharge de l'opérateur =, pour gérer la deepcopy des chaines de caractères
    *
    */
   void operator =(TrajetSimple const & trajet);

//-------------------------------------------- Constructeurs - destructeur

    /**Constructeur de TrajetSimple: Construit un trajet d'un Ville A à un Ville B en utilisant un moyen de transport
    *
    *@param depart Nom de la ville de départ
    *@param arrivee Nom de la ville d'arrivée
    *@param moyen Nom du moyen de transport
    */
    TrajetSimple (const char * depart,const char * arrivee, const char * moyen);

    /**Constructeur vide
    *
    */
    TrajetSimple ();

    /**Constructeur de copie
    *
    */
    TrajetSimple(const TrajetSimple & unTrajetSimple);

    /**Destructeur
    *
    */
    virtual ~TrajetSimple ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  /** Le moyen de transport
  */
    char * moyen; 
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
