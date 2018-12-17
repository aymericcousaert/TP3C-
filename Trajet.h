/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// La classe trajet décrit un trajet par son point d'arrivée et son départ.
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /** Affiche le trajet dans la console
    */
    virtual const void Afficher();

//-------------------------------------------- Constructeurs - destructeur
    /**Constructeur de copie de Trajet
    *
    */
    Trajet ( const Trajet & unTrajet );

    /**Constructeur de Trajet, prend en paramètre la ville de départ et la ville d'arrivée
    *
    *@param depart Le nom de la ville de départ
    *@param arrivee Le nom de la ville d'arrivee
    */
    Trajet(const char * depart, const char * arrivee);

    /**Constructeur de trajet
    */
    Trajet();

    /**Destructeur de Trajet
    */
    virtual ~ Trajet( );

    /**Renvoie le nom de la ville de départ
    */
    const char * getDepart();

    /**Renvoie le nom de la ville d'arrivée
    */
    const char * getArrivee();

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    /**Le nom de la ville de départ
    */
    char * depart;

    /** Le nom de la ville d'arrivée
    */
    char * arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
