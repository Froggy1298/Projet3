// DevoirNo3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "treeHelper.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

static bool CheckIfNumber(string s)
{
	//Le titre dit tout, no need to comment
	for (char const& ch : s) {
		if (isdigit(ch) == 0)
			return false;
	}
	return true;

}

static int IntUserInput(string question)
{
	string userInput;
	do
	{
		cout << question << endl;
		cin >> userInput;

	} while (!CheckIfNumber(userInput));

	return stoi(userInput);
}


int main()
{
	vector<string> commande = { "I","D","N","H", "C","P", "B" };

	noeud racine = noeud{ to_string(IntUserInput("Enter the value of the root.")), nullptr, nullptr };

	treeHelper arbre = treeHelper(&racine);

	string userCommand;
	while (1 != 2)
	{
		system("CLS");

		cout <<
			"I->" << "Insert an element into the tree" << endl <<
			"D->" << "Delete a chosen element inside the tree" << endl <<
			"N->" << "Display all element at the chosen level" << endl <<
			"H->" << "Display the height of the tree" << endl <<
			"C->" << "Display the child(s) of the chosen element" << endl <<
			"P->" << "Display the parent(s) of the chosen element" << endl <<
			"B->" << "Check if tree is balance of not" << endl <<
			"A->" << "Display all the tree" << endl <<
			"E->" << "Exit the program" << endl;

		cin >> userCommand;

		if (userCommand == "I")
		{
			arbre.insert(IntUserInput("Enter the value to insert."));
			cout << "Insertion done!" << endl;
		}
		else if (userCommand == "D")
		{
			arbre.effacerNoeud(IntUserInput("Enter the value you want to delete."));
			cout << "Deletion done!" << endl;
		}
		else if (userCommand == "N")
		{
			arbre.AfficheNiveau(IntUserInput("Enter the level of the tree that you'd like to display."));
		}
		else if (userCommand == "H")
		{
			cout << "The height of the tree is: " << arbre.hauteurArbre() << endl;
		}
		else if (userCommand == "C")
		{
			arbre.displayChild(IntUserInput("Enter the node you want the child(s) to be displayed."));
		}
		else if (userCommand == "P")
		{
			arbre.displayParent(IntUserInput("Enter the node you want the parent(s) to be displayed."));
		}
		else if (userCommand == "B")
		{
			if (arbre.IsEquilibre())
				cout << "The tree is balanced." << endl;
			else
				cout << "The tree is not balanced." << endl;
		}
		else if (userCommand == "A")
		{
			arbre.displayChild();
		}
		else if (userCommand == "E")
		{
			break;
		}
		else
		{
			cout << "Command not found" << endl;
		}

		system("pause");
	}



	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
