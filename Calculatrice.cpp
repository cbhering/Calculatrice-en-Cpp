// Calculatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <locale>
using namespace std;
int etat;
const int E0 = 0, E1 = 1, E2 = 2, E3 = 3, E4 = 4, E5 = 5;
char reponse;
char car = ' ';
//Menu principal où l'utilisateur va choisir parmi la première version, le sous-menu de définition des paramètres, le sous-menu aide e quitter le logiciel.
void menu() {
	system("cls");
	cout << "\n--------------------------------------------" << endl;
	cout << "PROJET 1 - MINI CALCULATRICE";
	cout << "\n--------------------------------------------" << endl;
	cout << "MENU GENERAL" << endl;
	cout << "\n1) Nouvelle operation";
	cout << "\n2) Definir les parametres";
	cout << "\n3) Aide";
	cout << "\nQ) Quitter le logiciel" << endl;
	cout << "\n Choix: "; reponse = _getch(); //L'utilisateur est demandé de choisir l'option.
	switch (reponse)
	{
	case '1': etat = E1; break; //Première verision de la calculatrice.
	case '2': etat = E2; break; //Definition des paramètres dans un nouveau menu pour que l'utilisateur puisse choisir entre la première et la deuxième version. 
	case '3': etat = E3; break; //Menu aide. Ça sert à expliquer à l'utilisateur les fonctions basiques de la calculatrice.
	case 'Q': etat = E4; break; //Quitter.
	case 'q': etat = E4; break; //Quitter.
	default:
		etat = E0;
	}
}
//Fonction pour quitter le logiciel.
void quitter() {
	system("cls");
	cout << "\nPROJET 1 - MINI CALCULATRICE" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "FIN DU PROGRAMME";
	cout << "\nMerci davoir utilise la MiniCalculatrice" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Appuyez sur une touche pour finir" << endl;
	system("pause");
	system("cls");
	etat = E5; //L'état 5 sort du logiciel.
}
//Cette fonction vérifie si le caractère est un chiffre. 
bool estChiffre(char car) {
	if (car >= '0' && car <= '9') {
		return true;
	}
	else {
		return false;
	}
}
//Cette fonction vérifie si le caractère est un opérateur.
bool estOperateur(char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/') {
		return true;
	}
	else return false;
}


//Premiere version de la calculatrice.
void nouvelleOperation() {
	system("cls");
	float chiffre[50];
	char operateur[25];
	int cptC, cptOp;
	string nombre = " ";
	float resultat2 = 0;
	bool mauvaiseExpression = false;
	cout << endl;
	cout << "PROJET 1 - MINI CALCULATRICE - VERSION (1)" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "SAISIE D'UNE OPERATION: " << endl;

	cptC = 0;
	cptOp = 0;
	do {
		nombre = " ";
		cin >> car;
		if (!estChiffre(car)) {
			mauvaiseExpression = true;
			break;
		}
		while (estChiffre(car)) {
			nombre = nombre + car;
			cin >> car;
		}

		if ((!estOperateur(car)) && (car != '=')) {
			mauvaiseExpression = true;
			break;
		}
		chiffre[cptC] = stoi(nombre); //La fonction stoi fait la conversion des nombres tapés par l'utilisateur sous forme de caractères et les transforme en chiffres vers le tableau chiffre.
		cptC++;
		if (estOperateur(car)) {
			operateur[cptOp] = car; //Les operateurs sont enregistrés dans le tableau operateur.
			cptOp++;
		}
	} while (car != '='); //Pendant que l'utilisateur ne tape pas '=', le logiciel reçoit les valeurs de l'expression.
	
	while (getchar() != '\n'); //Vider le buffer.
	
	if (mauvaiseExpression) {
		cout << "PAS VALIDE" << endl;
		system("pause");
		nouvelleOperation();
	}


	/*Parcourir le tableau operateur pour calculer les resultats avec le tableau chiffre. Le resultat de l'opération des deux premiers chiffres du tableau chiffre sont enregistrés dans la variable resultat2 et ensuite avance une position dans les deux tableaux.*/
	
	for (int i = 0; i < cptOp; i++) {
		if (i == 0) {
			switch (operateur[i])
			{
			case '+': resultat2 = chiffre[i] + chiffre[i + 1]; break;
			case '-': resultat2 = chiffre[i] - chiffre[i + 1]; break;
			case '/': resultat2 = chiffre[i] / chiffre[i + 1]; break;
			case '*': resultat2 = chiffre[i] * chiffre[i + 1]; break;
			default:
				break;
			}
		}
		else if (i > 0)
		{
			cout << "PAS VALIDE" << endl;
			system("pause");
			nouvelleOperation();
		}

	}
	cout << endl;
	cout << resultat2 << endl;
	cout << endl;
	system("pause");
}

//Deuxième version de la calculatrice.
void version2() {
	system("cls");
	float chiffre[50];
	char operateur[25];
	int cptC, cptOp;
	string nombre = " ";
	float resultat2 = 0;
	bool mauvaiseExpression = false;
	cout << endl;
	cout << "PROJET 1 - MINI CALCULATRICE - VERSION (2)" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "SAISIE D'UNE OPERATION: ";

	cptC = 0;
	cptOp = 0;
	do {
		nombre = " ";
		cin >> car; //L'utilisateur tape l'expression mathématique sous forme de caractères. Ensuite, les vérifications commencent.
		if (!estChiffre(car)) {
			mauvaiseExpression = true;
			break;
		}
		while (estChiffre(car)) {
			nombre = nombre + car;
			cin >> car;
		}
		if (!estOperateur(car) && (car != '=')) {
			mauvaiseExpression = true;
			break;
		}
		chiffre[cptC] = stoi(nombre); //La fonction stoi fait la conversion des nombres tapés par l'utilisateur sous forme de caractères et les transforme en chiffres vers le tableau chiffre.
		cptC++;
		if (estOperateur(car)) {
			operateur[cptOp] = car; //Les operateurs sont enregistrés dans le tableau operateur.
			cptOp++;
		}

	} while (car != '='); //Pendant que l'utilisateur ne tape pas '=', le logiciel reçoit les valeurs de l'expression.
	while (getchar() != '\n'); //Vider le buffer.
	if (mauvaiseExpression) {
		cout << "PAS VALIDE" << endl;
		system("pause");
	}
	//Parcourir le tableau operateur pour calculer les resultats avec le tableau chiffre. Le resultat de l'opération des deux premiers chiffres du tableau chiffre sont enregistrés dans la variable resultat2 et ensuite avance une position dans les deux tableaux.
	if (!mauvaiseExpression) {
		for (int i = 0; i < cptOp; i++) {
			if (i == 0) {
				switch (operateur[i])
				{
				case '+': resultat2 = chiffre[i] + chiffre[i + 1]; break;
				case '-': resultat2 = chiffre[i] - chiffre[i + 1]; break;
				case '/': resultat2 = chiffre[i] / chiffre[i + 1]; break;
				case '*': resultat2 = chiffre[i] * chiffre[i + 1]; break;
				default:
					break;
				}
			}
			else
			{
				switch (operateur[i])
				{
				case '+': resultat2 = resultat2 + chiffre[i + 1]; break;
				case '-': resultat2 = resultat2 - chiffre[i + 1]; break;
				case '/': resultat2 = resultat2 / chiffre[i + 1]; break;
				case '*': resultat2 = resultat2 * chiffre[i + 1]; break;
				default:
					break;
				}
			}

		}
		cout << endl;
		cout << resultat2 << endl;
	}
	cout << endl;
	system("pause");
}
//Pas encore disponible. 
void version3() {
	system("cls");
	char choix;
	cout << endl;
	cout << "PROJET 1 - MINI CALCULATRICE - VERSION (3)" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Bien vouloir attendre la version du logiciel en 2020." << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "\nRevenir au menu general? (O/N)"; choix = _getch();
	if (choix == 'O' || choix == 'o') {
		menu();
	}
	if (choix == 'N' || choix == 'n') {
		quitter();
	}
}
//Definition des paramètres. Choix de la version de la calculatrice, revenir au menu général ou quitter.	
void parametres() {
	system("cls");
	char choix;
	cout << endl;
	cout << "PROJET 1 - MINI CALCULATRICE" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "PROPRIETES";
	cout << "\nNom du Programmeur: Conrado Bhering";
	cout << "\nDate de Creation: 22/10/2019";
	cout << "\nLieu de developpement: Institut Grasset";
	cout << "\nVersion en cours: 1.0" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "CHOISISSEZ LA VERSION DU LOGICIEL";
	cout << "   \n1- Additionneuse a 1 seule operation";
	cout << "   \n2- Additionneuse priorite par Rang de l`operation";
	cout << "   \n3- Additionneuse Priorite * et /";
	cout << "   \n4- Revenir au menu general";
	cout << "   \nQ- Quitter" << endl;
	cout << "   \n Choix: "; choix = _getch();
	switch (choix)
	{
	case '1':
		nouvelleOperation(); break;
	case '2':
		version2(); break;
	case '3':
		version3(); break;
	case '4':
		menu(); break;
	case 'Q':
		quitter(); break;
	case 'q':
		quitter(); break;
	default:
		cout << "\nPas un choix valide" << endl;
		system("pause");
	}
}

//Cette fonction affiche les instructions du logiciel et demande si l'utilisateur veut revenir au menu principal ou quitter.
void aide() {
	char choix = ' ';
	system("cls");
	cout << endl;
	cout << "PROJET 1 - MINI CALCULATRICE" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "AIDE" << endl;
	cout << "Ce logiciel offre les fonctions de base d'une calculatrice (Addition, Soustraction, Multiplication et Division)";
	cout << endl;
	cout << "\n1- Le menu 1 vous amene a la saisie de l'operation";
	cout << "\n2- Le menu 2 permet de definir les parametres du logiciel";
	cout << "\n3- Le menu 3 vous propose l'aide que vous lisez actuellement";
	cout << "\n4- La touche Q permet de quitter le programme" << endl;
	cout << "\nRevenir au menu general? (O/N)"; choix = _getch();
	if (choix == 'O' || choix == 'o') {
		menu();
	}
	if (choix == 'N' || choix == 'n') {
		quitter();
	}
}
//Il s'agit de la fonction principale.
int main() {
	system("CLS");
	etat = E0;
	do {
		switch (etat) {
		case E0: menu(); break; //Le programme commence dans le menu principal.
		case E1: nouvelleOperation(); break;
		case E2: parametres(); break;
		case E3: aide(); break;
		case E4: quitter(); break;
		}
	} while (etat != E5);
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
