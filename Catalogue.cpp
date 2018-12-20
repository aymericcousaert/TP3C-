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
#include <fstream>

using namespace std;


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
    // On réalloue dynamiquement le tableau pour ajouter un trajet
    nbTrajets++;
    Trajet ** nouveautab = new Trajet*[nbTrajets];
    for (int i = 0; i < nbTrajets - 1; nouveautab[i] = trajet[i], i++); // On copie les anciens trajets
    nouveautab[nbTrajets-1]= &untrajet;
    delete [] trajet;
    trajet = nouveautab;
}

void Catalogue::Afficher (){
    cout << "######### Catalogue ##########" << endl;
    for(int i = 0 ; i < nbTrajets; i++){
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
    cout << "Saisir le nom du fichier texte avec l'extension .txt" << endl;
    cin >> nomFichier;
    ifstream fichier(nomFichier, ios::in);
    if (!fichier)
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

    int cas2 = 0; // 1 : On selectionne les trajets simples  2 : On selectionne les trajets complexes
    int cas3 = 0; // 1 : On selectionne les trajets selon le départ 2 : On selectionne les trajets selon l'arrivee
    string cas3ville;
    int cas4inf = 1;
    int cas4sup = nbTrajetACharger;
    
    string premierElement;
    
    string departEtape;
    string arriveeEtape;
    string moyenEtape;
    
    string simpleComplexe;
    string depart;
    string arrivee;
    int nbEtapes;
    
    extern TrajetSimple trajetSimple[1000]; // Le tableau qui stocke les trajets simples créés
    extern int nbTrajetSimple; // Nombre de trajets simples créés
    extern TrajetComplexe trajetComplexe[1000]; // Tableau qui stocke les trajets complexes créés
    extern int nbTrajetComplexe;

    switch (typeSelection) {
        case 1:
            for (int i = 0; i < nbTrajetACharger; i++)
            {
                fichier >> premierElement;
                fichier >> simpleComplexe >> depart >> arrivee >> nbEtapes;
                if (simpleComplexe == "SIMPLE")
                {
                    getline(fichier, ligne);
                    fichier >> departEtape >> arriveeEtape >> moyenEtape;
                    trajetSimple[nbTrajetSimple] = TrajetSimple(depart.c_str(),arrivee.c_str(),moyenEtape.c_str());
                    Ajouter(trajetSimple[nbTrajetSimple]);
                    nbTrajetSimple++;
                    
                }
                else
                {
                    Trajet** trajetCompose = new Trajet*[nbEtapes];
                    for (int a = 0; a < nbEtapes; a++)
                    {
                        getline(fichier, ligne);
                        fichier >> departEtape >> arriveeEtape >> moyenEtape;
                        trajetSimple[nbTrajetSimple] = TrajetSimple(departEtape.c_str(),arriveeEtape.c_str(),moyenEtape.c_str());
                        trajetCompose[a] = &trajetSimple[nbTrajetSimple];
                        nbTrajetSimple++;
                    }
                    trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajetCompose,nbEtapes);
                    Ajouter(trajetComplexe[nbTrajetComplexe]);
                    nbTrajetComplexe++;
                    delete[] trajetCompose;
                }
            }
            break;
        case 2:
            cout << "Saisir le type de trajet (1 - Trajet Simple, 2 - Trajet Complexe)" << endl;
            cin >> cas2;
            for (int i = 0; i < nbTrajetACharger; i++)
            {
                fichier >> premierElement;
                fichier >> simpleComplexe >> depart >> arrivee >> nbEtapes;
                cout << simpleComplexe;
                
                if (simpleComplexe == "SIMPLE" && cas2 == 1)
                {
                    getline(fichier, ligne);
                    fichier >> departEtape >> arriveeEtape >> moyenEtape;
                    trajetSimple[nbTrajetSimple] = TrajetSimple(depart.c_str(),arrivee.c_str(),moyenEtape.c_str());
                    Ajouter(trajetSimple[nbTrajetSimple]);
                    nbTrajetSimple++;
                }
                else if (simpleComplexe == "COMPLEXE" && cas2 == 2)
                {
                    
                    Trajet** trajetCompose = new Trajet*[nbEtapes];
                    for (int a = 0; a < nbEtapes; a++)
                    {
                        getline(fichier, ligne);
                        fichier >> departEtape >> arriveeEtape >> moyenEtape;
                        trajetSimple[nbTrajetSimple] = TrajetSimple(departEtape.c_str(),arriveeEtape.c_str(),moyenEtape.c_str());
                        trajetCompose[a] = &trajetSimple[nbTrajetSimple];
                        nbTrajetSimple++;
                    }
                    trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajetCompose,nbEtapes);
                    Ajouter(trajetComplexe[nbTrajetComplexe]);
                    nbTrajetComplexe++;
                    delete[] trajetCompose;
                }
                else
                    for (int a = 0; a < nbEtapes + 1; a++)
                        getline(fichier, ligne);
            }
            break;
        case 3:
            cout << "Choisir le départ ou l'arrivée (1 - Départ, 2 - Arrivée)" << endl;
            cin >> cas3;
            cout << "Saisir le nom de la ville" << endl;
            cin >> cas3ville;
            for (int i = 0; i < nbTrajetACharger; i++)
            {
                fichier >> premierElement;
                fichier >> simpleComplexe >> depart >> arrivee >> nbEtapes;
                if (cas3ville == depart && cas3 == 1 && simpleComplexe == "SIMPLE")
                {
                    getline(fichier, ligne);
                    fichier >> departEtape >> arriveeEtape >> moyenEtape;
                    trajetSimple[nbTrajetSimple] = TrajetSimple(depart.c_str(),arrivee.c_str(),moyenEtape.c_str());
                    Ajouter(trajetSimple[nbTrajetSimple]);
                    nbTrajetSimple++;
                }
                else if (cas3ville == depart && cas3 == 1 && simpleComplexe == "COMPLEXE")
                {
                    Trajet** trajetCompose = new Trajet*[nbEtapes];
                    for (int a = 0; a < nbEtapes; a++)
                    {
                        getline(fichier, ligne);
                        fichier >> departEtape >> arriveeEtape >> moyenEtape;
                        trajetSimple[nbTrajetSimple] = TrajetSimple(departEtape.c_str(),arriveeEtape.c_str(),moyenEtape.c_str());
                        trajetCompose[a] = &trajetSimple[nbTrajetSimple];
                        nbTrajetSimple++;
                    }
                    trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajetCompose,nbEtapes);
                    Ajouter(trajetComplexe[nbTrajetComplexe]);
                    nbTrajetComplexe++;
                    delete[] trajetCompose;
                }
                else if (cas3ville == arrivee && cas3 == 2 && simpleComplexe == "SIMPLE")
                {
                    getline(fichier, ligne);
                    fichier >> departEtape >> arriveeEtape >> moyenEtape;
                    trajetSimple[nbTrajetSimple] = TrajetSimple(depart.c_str(),arrivee.c_str(),moyenEtape.c_str());
                    Ajouter(trajetSimple[nbTrajetSimple]);
                    nbTrajetSimple++;
                }
                else if (cas3ville == arrivee && cas3 == 2 && simpleComplexe == "COMPLEXE")
                {
                    Trajet** trajetCompose = new Trajet*[nbEtapes];
                    for (int a = 0; a < nbEtapes; a++)
                    {
                        getline(fichier, ligne);
                        fichier >> departEtape >> arriveeEtape >> moyenEtape;
                        trajetSimple[nbTrajetSimple] = TrajetSimple(departEtape.c_str(),arriveeEtape.c_str(),moyenEtape.c_str());
                        trajetCompose[a] = &trajetSimple[nbTrajetSimple];
                        nbTrajetSimple++;
                    }
                    trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajetCompose,nbEtapes);
                    Ajouter(trajetComplexe[nbTrajetComplexe]);
                    nbTrajetComplexe++;
                    delete[] trajetCompose;
                }
                else
                    for (int a = 0; a < nbEtapes + 1; a++)
                        getline(fichier, ligne);
            }
            break;
        case 4:
            do
            {
                cout << "Les bornes de l'intervalle doivent être comprises entre 1 et " << nbTrajetACharger << endl;
                cout << "Saisir la borne inférieure de l'intervalle" << endl;
                cin >> cas4inf;
                cout << "Saisir la borne supérieure de l'intervalle" << endl;
                cin >> cas4sup;
            } while ( !(cas4sup >= cas4inf && cas4sup <= nbTrajetACharger && cas4inf > 0) );
            // On se place en utilisateur et on commence à compter à partir de 1
            
            
            for (int i = 1; i <= nbTrajetACharger; i++)
            {
                fichier >> premierElement;
                fichier >> simpleComplexe >> depart >> arrivee >> nbEtapes;
                if (i >= cas4inf && i <= cas4sup)
                {
                    if (simpleComplexe == "SIMPLE")
                    {
                        getline(fichier, ligne);
                        fichier >> departEtape >> arriveeEtape >> moyenEtape;
                        trajetSimple[nbTrajetSimple] = TrajetSimple(depart.c_str(),arrivee.c_str(),moyenEtape.c_str());
                        Ajouter(trajetSimple[nbTrajetSimple]);
                        nbTrajetSimple++;
                    }
                    else
                    {
                        Trajet** trajetCompose = new Trajet*[nbEtapes];
                        for (int a = 0; a < nbEtapes; a++)
                        {
                            getline(fichier, ligne);
                            fichier >> departEtape >> arriveeEtape >> moyenEtape;
                            trajetSimple[nbTrajetSimple] = TrajetSimple(departEtape.c_str(),arriveeEtape.c_str(),moyenEtape.c_str());
                            trajetCompose[a] = &trajetSimple[nbTrajetSimple];
                            nbTrajetSimple++;
                        }
                        trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajetCompose,nbEtapes);
                        Ajouter(trajetComplexe[nbTrajetComplexe]);
                        nbTrajetComplexe++;
                        delete[] trajetCompose;
                    }
                }
                else
                    for (int a = 0; a < nbEtapes + 1; a++)
                        getline(fichier, ligne);
            }
            break;
    }
    fichier.close();
}

void Catalogue::Sauvegarder() {
    string nomFichier;
    int typeSelection;
    cout << "Saisir le nom du fichier texte avec l'extension .txt" << endl;
    cin >> nomFichier;
    ofstream fichier(nomFichier, ios::trunc);
    cout << "Choisir type de selection" << endl;
    cout << "1 - Selection totale" << endl;
    cout << "2 - Selection selon le type de trajet" << endl;
    cout << "3 - Selection selon le départ ou l'arrivée" << endl;
    cout << "4 - Selection selon un intervalle" << endl;
    cin >> typeSelection;
    
    int cas2 = 0; // 1 : On selectionne les trajets simples  2 : On selectionne les trajets complexes
    int cas3 = 0; // 1 : On selectionne les trajets selon le départ 2 : On selectionne les trajets selon l'arrivee
    string cas3ville;
    int cas4inf = 1;
    int cas4sup = nbTrajets;
    fichier << nbTrajets << endl;
    switch (typeSelection) {
        case 1:
            for (int i = 0; i < nbTrajets; i++)
            {
                if (!trajet[i]->estComplexe())
                {
                    fichier << "TRAJET " << "SIMPLE " << trajet[i]->getDepart() << " " << trajet[i]->getArrivee() << " 1" << endl;
                    fichier << trajet[i]->getDepart() << " " << trajet[i]->getArrivee() << " " << trajet[i]->getMoyen() << endl;
                }
                else
                {
                    fichier << "TRAJET " << "COMPLEXE " << trajet[i]->getDepart() << " " << trajet[i]->getArrivee() << " " << trajet[i]->getNbEtapes() << endl;
                    
                    
                    
                    
                }
            }
            
            
            break;
        case 2:
            cout << "Saisir le type de trajet (1 - Trajet Simple, 2 - Trajet Complexe)" << endl;
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
                cout << "Les bornes de l'intervalle doivent être comprises entre 1 et " << nbTrajets << endl;
                cout << "Saisir la borne inférieure de l'intervalle" << endl;
                cin >> cas4inf;
                cout << "Saisir la borne supérieure de l'intervalle" << endl;
                cin >> cas4sup;
            } while ( !(cas4sup >= cas4inf && cas4sup <= nbTrajets && cas4inf > 0) );
            
            break;
        default:
            cout << "Indice de Selection incorrect" << endl;
    }
    fichier.close();
    if (typeSelection == 1 || typeSelection == 2 || typeSelection == 3 || typeSelection == 4)
        cout << "Le catalogue a été sauvegardé dans le fichier " << nomFichier << endl;
    
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
