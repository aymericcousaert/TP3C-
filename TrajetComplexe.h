/*************************************************************************
 TrajetComplexe  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetComplexe> (fichier TrajetComplexe.h) ----------------
#if ! defined ( TRAJETCOMPLEXE_H )
#define TRAJETCOMPLEXE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComplexe>
//
// La classe TrajetComplexe gère la création, l'affichage, etc de trajets complexes
//------------------------------------------------------------------------

class TrajetComplexe : public Trajet
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  /** Affiche le trajet
  */
  virtual const void Afficher();

  /**Renvoie si le trajet complexe est correctement constitué, c'est à dire arrivée_i = depart_i+1
  */
  bool EstValide();



  //------------------------------------------------- Surcharge d'opérateurs
  /** Surchage de l'opérateur d'affectation
  *
  *
  */
  void operator = (const TrajetComplexe & trajet);

  //-------------------------------------------- Constructeurs - destructeur

  /** Constructeur vide
  */
  TrajetComplexe ();

  /** Constructeur de Trajet Complexe, prend en paramètre les pointeurs des trajets qui composent ce trajet, et le nombre de trajets
  *
  *Attention, il n'y a pas de deepcopy, donc les trajets doivent être stockés jusqu'à la fin du programme.
  *
  *@param trajets Tableau des pointeurs des trajets qui composent ce trajet
  *@param nbTrajets le nombre de trajets qui composent le trajet complexe
  */
  TrajetComplexe (Trajet** trajets,int nbTrajets);

  /***Destructeur de TrajetComplexe, détruit le tableau de trajets, mais pas les trajets !
  *
  */
  virtual ~TrajetComplexe ( );



  //------------------------------------------------------------------ PRIVE
protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  /** Un tableau de pointeurs vers les trajets qui composent ce trajet complexe
  */
  Trajet** trajets;

  /** Le nombre de trajets qui composent le trajet complexe
  */
  int nbTrajet;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H
