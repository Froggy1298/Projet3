#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct noeud
{
	string valeur;
	noeud* droit;
	noeud* gauche;
};


class treeHelper
{
private:
	noeud* racine;
public:
	treeHelper(noeud* valeur);
	~treeHelper();

	void insert(int number);							
	void insert(noeud* racine, int number);					

	noeud* effacerNoeud(int number);			
	noeud* effacerNoeud(noeud* racine, int number);

	noeud* rechercheParent(noeud* racine, int number);
	noeud* rechercheActuelle(noeud* racine, int number);

	void AfficheNiveau(int hauteur);						

	int hauteurArbre();										
	int hauteurArbre(noeud* actualNoeud);					


	bool IsEquilibre();										
	bool IsEquilibre(noeud* racine);						

	void simpleDisplayChild(noeud* actualNoeud);			

	void displayChild();									
	void displayChild(int valeur);							

	void displayParent(int valeur);							





};

