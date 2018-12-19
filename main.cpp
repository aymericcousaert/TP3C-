/***Point d'entrée du programme
*
*/

#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"
#include "Catalogue.h"

using namespace std;

TrajetSimple trajetSimple[1000]; // Le tableau qui stocke les trajets simples créés
int nbTrajetSimple = 0; // Nombre de trajets simples créés
TrajetComplexe trajetComplexe[1000]; // Tableau qui stocke les trajets complexes créés
int nbTrajetComplexe = 0; // Nombre de trajets complexes créés
Catalogue cat = Catalogue(); // Le catalogue qui référence les trajets

/***Affiche les actions possibles à l'écran
*/
void Consignes(){
    cout << '\n' << endl;;
    cout << "Saisir une commande : " << endl;
    cout << "0 - Quitter le programme" << endl;
    cout << "1 - Ajouter un trajet simple" << endl;
    cout << "2 - Ajouter un trajet complexe" << endl;
    cout << "3 - Trouver trajet" << endl;
    cout << "4 - Afficher tous les trajets" << endl;
    cout << "5 - Charger un fichier de trajets dans le catalogue" << endl;
    cout << "6 - Sauvegarder le catalogue dans un fichier" << endl;
}
/***Permet la saisie de Trajets simples,
* prend en paramètre si la fonction est utilisée dans le cadre d'un trajet complexe ou non
*
*@param complexe: -1 si le trajet est simple
*@param depart: Dans le cadre d'un trajet complexe, la ville de départ du trajet simple à créer
*
*/
void AjoutSimple(int complexe, char* depart){
    if (complexe == -1){
        cout << "Nous procédons à l'ajout d'un trajet simple" << endl;
    }

    // On demande à l'utilisateur de rentrer toutes les informations
    char* arrivee= new char[30];
    char* moyen= new char[30];
    if (complexe <= 0){
        cout << "Quelle est la ville de départ?" << endl;
        cin >> depart;
    }
    cout << "Quelle est la ville d'arrivée?" << endl;
    cin >> arrivee;
    cout << "Quel est le moyen de transport?" << endl;
    cin >> moyen;

    // On crée un trajet Simple, que l'on stocke dans le tableau des trajets simples
    trajetSimple[nbTrajetSimple]= TrajetSimple(depart,arrivee,moyen);

    // Si nous ne sommes pas dans un processus de trajet complexe, on ajoute ce trajet au catalogue
    if (complexe == -1){
        cat.Ajouter(trajetSimple[nbTrajetSimple]);
        cout << "Trajet simple ajouté au catalogue !" << endl;
    }
    nbTrajetSimple++;

    delete [] arrivee;
    delete [] moyen;


}
/***Permet la saisie d'un Trajet complexe et l'ajout de celui ci dans le catalogue
*
*/
void AjoutComplexe(){
    cout << "Nous procédons à l'ajout d'un trajet complexe : " << endl;
    int nbTrajet = 0;
    while (nbTrajet == 0){
        cout << "Votre trajet complexe est composé de combien de trajets simple (au moins 1) ?" << endl;
        cin >> nbTrajet;
    }
    Trajet** trajet = new Trajet*[nbTrajet];
    cout << "Construction trajet par trajet : " << endl;
    char* villenoeud = new char[30];
    strcpy(villenoeud, "");

    //Construction des différents trajets simples
    for (int i = 0; i < nbTrajet; i++){
        cout << "Pour le trajet numéro " << i+1 << " : "  << endl;
        if (i != 0){
            cout << "Votre départ est : " << villenoeud << "." << endl;
        }
        AjoutSimple(i,villenoeud); // On crée un trajet simple
        trajet[i] = &(trajetSimple[nbTrajetSimple-1]); // On récupère le trajet simple créé
        strcpy(villenoeud,trajetSimple[nbTrajetSimple-1].getArrivee());
    }
    trajetComplexe[nbTrajetComplexe] = TrajetComplexe(trajet,nbTrajet); // On stocke le trajet complexe
    cat.Ajouter(trajetComplexe[nbTrajetComplexe]); // On met sa référence dans le catalogue
    cout << "Trajet complexe ajouté au catalogue!" << endl;
    nbTrajetComplexe++;
    delete [] villenoeud;
    delete [] trajet;

}

/***Permet la recherche de trajets (D'une ville de départ à une ville d'arrivée)
*/
void Recherche(){
    cout << "Nous procédons à une recherche de trajets : " << endl;
    char* depart = new char[30];
    char* arrivee = new char[30];
    cout << "Quelle est la ville de départ?" << endl;
    cin >> depart;
    cout << "Quelle est la ville d'arrivée?" << endl;
    cin >> arrivee;
    cat.RechercheSimple(depart, arrivee);
    delete [] depart;
    delete [] arrivee;

}

/**Affiche le catalogue
*
*/
void Afficher(){
    cout << "Voici l'exhaustivité du catalogue : " << endl;
    cat.Afficher();

}

void Charger(){
    cat.Charger();
}


void Sauvegarder(){
    cat.Sauvegarder();
}
/***Fonction principale, point d'entrée du programme
*
*/
int main(void)
{
  char lecture;
  Consignes(); //Affichage du menu
  cin >> lecture;

  while(lecture != '0') {
    if (lecture == '1') {
        char* depart = new char[30];
        strcpy(depart, "");
        AjoutSimple(-1,depart);
        delete [] depart;
        cat.Afficher();
    }
    else if (lecture == '2') {
        AjoutComplexe();
    }
    else if (lecture == '3') {
        Recherche();
    }
    else if (lecture == '4') {
        Afficher();
    }
    else if (lecture == '5')
    {
        Charger();
    }
    else if (lecture == '6')
    {
        Sauvegarder();
    }
    Consignes();
    cin >> lecture;
  }
  return 0;
}
