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
#include <string.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"


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

void Catalogue::Charger() {
    string nomFichier;
    cout << "Saisir le nom du fichier texte avec l'extention .txt" << endl;
    cin >> nomFichier;
    ifstream fichier;
    fichier.open(nomFichier);
    if ((fichier.rdstate() & ifstream::failbit) != 0)
    {
        cout << "Nom de fichier inconnu" << endl;
        return;
    }
    string ligne;
    getline(fichier, ligne);
    int nbTrajetACharger;
    int typeSelection;
    nbTrajetACharger = stoi(ligne);
    cout << "Choisir type de selection" << endl;
    cout << "1 - Selection totale" << endl;
    cout << "2 - Selection selon le type de trajet" << endl;
    cout << "3 - Selection selon le départ ou l'arrivée" << endl;
    cout << "4 - Selection selon un intervalle" << endl;
    cin >> typeSelection;



    int cas2 = 0; // 0 : on prend tout  1 : on prend simple  2 : on prend complexe
    int cas3 = 0;
    string cas3ville; //
    int cas4inf = 1;
    int cas4sup = nbTrajetACharger;

    switch (typeSelection) {
        case 1:
            break;
        case 2:
            cout << "Saisir le type de trajet (1 - Trajet Simple, 2 - Trajet Composé)" << endl;
            cin >> cas2;
            break;
        case 3:
            cout << "Choisir le départ ou l'arrivée (1 - Départ, 2 - Arrivée)" << endl;
            cin >> cas3;
            cout << "Saisir le nom de la ville" << endl;
            cin >> cas3ville;
            break;
        case 4:
            do
            {
                cout << "Saisir la borne inférieure de l'intervalle" << endl;
                cin >> cas4inf;
                cout << "Saisir la borne supérieure de l'intervalle" << endl;
                cin >> cas4sup;
            } while ( !(cas4sup > cas4inf && cas4sup <= nbTrajetACharger && cas4inf > 0) ); // On se place en utilisateur et on commence à compter à partir de 1
            break;

    }


    for (int i = 0; i < cas4sup; i++) // Arreter de parcourir une fois borne max atteint
    {
        getline(fichier, ligne);
        char* tabString[];
        string tabEtape[3];
        char * lignedup = strdup(ligne.c_str());
        tabString = strtok(lignedup, ", ");
        if (i<cas4inf - 1) // On ne considère pas les trajets qui sont en dessous de la borne min
        {
            for (int a = 0; a < stoi(tabString[4]); a++)
                getline(fichier, ligne);
        }
        else
        {
            if ( (cas2 == 2 && strcmp(tabString[1],"SIMPLE") == 0) || (cas2 == 1 && strcmp(tabString[1],"COMPOSE") == 0)) // Cas 2 si on ne veut pas un certain type de trajet
            {
                for (int a = 0; a < stoi(tabString[4]); a++)
                    getline(fichier, ligne);
            }
            else
            {
                if ((cas3 == 1 && strcmp(cas3ville,tabString[2]) !=0 )||(cas3 == 2 && strcmp(cas3ville,tabString[3]) !=0 ))
                {
                    for (int a = 0; a < stoi(tabString[4]); a++)
                        getline(fichier, ligne);
                }
                else
                {
                    if(strcmp(tabString[1],"SIMPLE")==0){
                        getline(fichier,ligne);
                        tabEtape = strtok(ligne, ", ");
                        TrajetSimple* trajetAAjouter = new TrajetSimple(tabEtape[0],tabEtape[1],tabEtape[2]);
                        this->Ajouter(trajetAAjouter);
                    }
                    else{
                        Trajet** tabTrajetAAjouter = new Trajet*[tabString[4]];
                        for (int j = 0; j < tabString[4]; j++)
                        {
                            getline(fichier,ligne);
                            tabEtape = strtok(ligne, ", ");
                            tabTrajetAAjouter[j] = new TrajetSimple(tabEtape[0],tabEtape[1],tabEtape[2]);

                        }
                        Trajet trajetAAjouter = TrajetComplexe(tabTrajetAAjouter, stoi(tabString[4]));
                        this->Ajouter(trajetAAjouter);

                    }
                }
            }
        }
    }


}

void Catalogue::Sauvegarder() {

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
