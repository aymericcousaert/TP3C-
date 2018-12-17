/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// La classe Catalogue s'occupe du stockage des références et de l'affichage
// des trajets
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    /**Ajoute un trajet au catalogue
    *@param trajet la référence du trajet à ajouter (Simple ou Complexe)
    */
    void Ajouter (Trajet & trajet);
    /**Affiche le contenu du catalogue
    *
    */
    void Afficher ();
    /**Recherche les trajets qui correspondent aux critères suivants:
    * Ville de départ = undepart et Ville d'arrivée = unearrivee
    */
    void RechercheSimple(const char * undepart,const char * unearrivee);




//-------------------------------------------- Constructeurs - destructeur

    /**Constructeur de catalogue
    * Le catalogue est vide à la conception
    */
    Catalogue ( );

    /** Destructeur du Catalogue
    *
    */
    virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    /** Les trajets enregistrés dans le Catalogue
    */
    Trajet ** trajet;
    /** Le nombre de trajets enregistrés
    */
    int nbTrajets =0;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
