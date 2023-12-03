#include "treeHelper.h"

treeHelper::treeHelper(noeud* temp)
{
	racine = new noeud;
	racine = temp;
}

treeHelper::~treeHelper()
{
	//The logic here is good
	//The problem is about deleting struct pointer
	//Maybe I'll change to object later when I have more time

	/*queue<noeud*> theQueue;
	noeud separator;
	separator.valeur = "*";

	theQueue.push(racine);
	theQueue.push(&separator);

	while (!theQueue.empty())
	{
		while (theQueue.front()->valeur != "*")
		{
			if (theQueue.front()->gauche != nullptr)
				theQueue.push(theQueue.front()->gauche);

			if (theQueue.front()->droit != nullptr)
				theQueue.push(theQueue.front()->droit);

			noeud* temp = theQueue.front();
			theQueue.pop();
			delete(temp);
		}
		theQueue.pop();
		theQueue.push(&separator);
	}*/
}

void treeHelper::insert(int number)
{
	insert(racine, number);
}

void treeHelper::insert(noeud* racine, int number)
{
	if (stoi(racine->valeur) > number)
	{
		if (racine->gauche == nullptr)
		{
			noeud* tempNoeud = new noeud{ to_string(number), nullptr, nullptr };
			racine->gauche = tempNoeud;
		}
		else
			insert(racine->gauche, number);
	}

	if (stoi(racine->valeur) < number)
	{
		if (racine->droit == nullptr)
		{
			noeud* tempNoeud = new noeud{ to_string(number), nullptr, nullptr };
			racine->droit = tempNoeud;
		}
		else
			insert(racine->droit, number);
	}


}

noeud* treeHelper::effacerNoeud(int number)
{
	return effacerNoeud(racine, number);
}

noeud* treeHelper::effacerNoeud(noeud* racine, int number)
{
	if (racine == nullptr)
		return racine;

	if (stoi(racine->valeur) > number)
		racine->gauche = effacerNoeud(racine->gauche, number);
	else if (stoi(racine->valeur) < number)
		racine->droit = effacerNoeud(racine->droit, number);
	else {
		if (racine->gauche == nullptr)
		{
			noeud* temp = racine->droit;
			free(racine);
			return temp;
		}
		else if (racine->droit == nullptr)
		{
			noeud* temp = racine->gauche;
			free(racine);
			return temp;
		}

		noeud* now = racine->droit;

		while (now && now->gauche != nullptr)
			now = now->gauche;

		racine->valeur = now->valeur;

		racine->droit = effacerNoeud(racine->droit, stoi(now->valeur));
	}
	return racine;
}

noeud* treeHelper::rechercheParent(noeud* racine, int number)
{
	if (stoi(racine->valeur) == number)
		return racine;

	if (stoi(racine->valeur) > number)
	{
		if (racine->gauche == nullptr)
			return nullptr;
		else if (stoi(racine->gauche->valeur) == number)
			return racine;
		else
			return rechercheParent(racine->gauche, number);
	}

	if (stoi(racine->valeur) < number)
	{
		if (racine->droit == nullptr)
			return nullptr;
		else if (stoi(racine->droit->valeur) == number)
			return racine;
		else
			return rechercheParent(racine->droit, number);
	}
}

noeud* treeHelper::rechercheActuelle(noeud* racine, int number)
{
	if (stoi(racine->valeur) == number)
		return racine;

	if (stoi(racine->valeur) > number)
	{
		if (racine->gauche == nullptr)
			return nullptr;
		else if (stoi(racine->gauche->valeur) == number)
			return racine->gauche;
		else
			return rechercheActuelle(racine->gauche, number);
	}

	if (stoi(racine->valeur) < number)
	{
		if (racine->droit == nullptr)
			return nullptr;
		else if (stoi(racine->droit->valeur) == number)
			return racine->droit;
		else
			return rechercheActuelle(racine->droit, number);

	}
}

void treeHelper::AfficheNiveau(int hauteur)
{
	int hauteurAct = 1;
	queue<noeud*> theQueue;
	noeud separator;
	separator.valeur = "*";

	theQueue.push(racine);
	theQueue.push(&separator);

	while (hauteurAct != hauteur && !theQueue.empty())
	{
		while (theQueue.front()->valeur != "*")
		{
			if (theQueue.front()->gauche != nullptr)
				theQueue.push(theQueue.front()->gauche);

			if (theQueue.front()->droit != nullptr)
				theQueue.push(theQueue.front()->droit);

			theQueue.pop();
		}
		theQueue.pop();
		theQueue.push(&separator);
		hauteurAct++;
	}

	while (theQueue.front()->valeur != "*")
	{
		cout << theQueue.front()->valeur << "|";
		theQueue.pop();
	}
	cout << endl;
}

int treeHelper::hauteurArbre()
{
	return hauteurArbre(racine);
}

int treeHelper::hauteurArbre(noeud* actualNoeud)
{
	if (actualNoeud == nullptr)
		return 0;
	else
		return (1 + max(hauteurArbre(actualNoeud->gauche),
			hauteurArbre(actualNoeud->droit)));
}


bool treeHelper::IsEquilibre()
{
	return IsEquilibre(racine);
}

bool treeHelper::IsEquilibre(noeud* racine)
{
	int lh;

	int rh;

	if (racine == nullptr)
		return 1;

	lh = hauteurArbre(racine->gauche);
	rh = hauteurArbre(racine->droit);

	if (abs(lh - rh) <= 1 && IsEquilibre(racine->gauche)
		&& IsEquilibre(racine->droit))
		return 1;

	return 0;
}

void treeHelper::simpleDisplayChild(noeud* actualNoeud)
{
	cout << actualNoeud->valeur << "|";

	if (actualNoeud->gauche != nullptr)
		simpleDisplayChild(actualNoeud->gauche);

	if (actualNoeud->droit != nullptr)
		simpleDisplayChild(actualNoeud->droit);
	
}

void treeHelper::displayChild()
{
	displayChild(stoi(racine->valeur));
}

void treeHelper::displayChild(int valeur)
{
	cout << endl;
	queue<noeud*> theQueue;
	noeud* separator = new noeud{"*", nullptr, nullptr};

	noeud* theNoeud = rechercheActuelle(racine, valeur);

	theQueue.push(theNoeud);
	theQueue.push(separator);

	while (!theQueue.empty() && theQueue.front()->valeur != "*")
	{
		while (theQueue.front()->valeur != "*")
		{
			if (theQueue.front()->gauche != nullptr)
				theQueue.push(theQueue.front()->gauche);

			if (theQueue.front()->droit != nullptr)
				theQueue.push(theQueue.front()->droit);

			cout << "|" << theQueue.front()->valeur << "|";
			theQueue.pop();
		}
		theQueue.pop();
		theQueue.push(separator);
		cout << endl;
	}

}

void treeHelper::displayParent(int valeur)
{
	cout << endl;
	stack<noeud*> theStack;

	noeud* parent;
	noeud* child = rechercheActuelle(racine, valeur);
	theStack.push(child);

	while (this->racine->valeur != child->valeur)
	{
		parent = rechercheParent(racine, stoi(child->valeur));
		theStack.push(parent);
		child = parent;
	}

	while (!theStack.empty())
	{
		cout << theStack.top()->valeur << endl;
		theStack.pop();
	}
}


