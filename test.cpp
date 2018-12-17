/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hreymond
 *
 * Created on 19 novembre 2018, 14:09
 */

#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"
#include "Catalogue.h"

using namespace std;

void Test(){
	//TEST DU TRAJET
	cout << "########### TEST TRAJET ############" <<endl;
	Trajet a = Trajet("Marseille","Lyon");
	cout << "a: Trajet Marseille-Lyon" << endl;
	Trajet b = Trajet("Lyon","Nantes");
	if(b.SeSuit(a)) //TEST 1
	{
		cout << "Erreur Test 1:" << endl;
		cout << "\tLe trajet a suit le trajet a: incorrect" << endl;
		a.Afficher();
		b.Afficher();
		cout << "#########" << endl;
	}else{

	 	cout << "Test 1: [OK]" << endl;
	}
	if(!a.SeSuit(b)){//Test 2 
		cout << "Test 2: [ERROR]" << endl;
	}
	
	cout << "############### TEST TRAJET SIMPLE ####################" << endl;
	TrajetSimple c = TrajetSimple("Marseille","Lyon","Avion");
        c.Afficher();
        if(b.SeSuit(b)) //TEST 3
	{
            cout<<"Test 3: [ERROR]"<<endl;
        }
        if(!c.SeSuit(b)) //TEST 4
	{
            cout<<"Test 4: [ERROR]"<<endl;
        }
        if(b.SeSuit(c)) //TEST 5
	{
            cout<<"Test 5: [ERROR]"<<endl;
        }
	/////########## Test de classe TrajetComplexe
	cout << "############ TEST TRAJET COMPLEXE #####################" << endl;
	cout << "Création du * * Trajet" << endl;
	Trajet * * trajet = new Trajet * [10];
	trajet[0] = &a;
	trajet[1] = &c;

	trajet[0] -> Afficher();
	trajet[1] -> Afficher();

	cout << "Creation du  trajet complexe" << endl;
	TrajetComplexe tc1 = TrajetComplexe(trajet,2);
	tc1.Afficher();
	delete [] trajet;

	cout << "############# TEST CATALOGUE ############" << endl;
	Catalogue cat = Catalogue();
	cout << "Catalogue vide :" << endl;
	cat.Afficher();
	Trajet t1 = Trajet("Paris","Lyon");
	cat.Ajouter(t1);
	cout << "Ajout d'un trajet:" << endl;
	cat.Afficher();
	TrajetSimple t2 = TrajetSimple("Marseille","Lyon","Avion");
	cat.Ajouter(t2);
	TrajetSimple t8 = TrajetSimple("Lille","Toulon","Avion");
	cat.Ajouter(t8);
	cout << "Ajout d'un trajet Simple:" << endl;
	cat.Afficher();
	TrajetSimple t3 = TrajetSimple("Lille","Paris","Train");
	TrajetSimple t4 = TrajetSimple("Paris","Nice","Avion");
	TrajetSimple t5 = TrajetSimple("Nice","Toulon","Pied");
	Trajet * tab[] = {&t3,&t4,&t5};
	TrajetComplexe t6 = TrajetComplexe(tab,3);
	cat.Ajouter(t6);
	cout << "Ajout d'un trajet Complexe:" << endl;
	cat.Afficher();
	
	cout << "Recherche d'un trajet de Lille à Toulon" << endl;
	cat.RechercheSimple("Lille","Toulon");
	
	cout << "################ FIN DES TESTS ##########" <<endl;

}
/*
 * 
 */
int main(int argc, char** argv) {
    Test();
    
    return 0;
}



