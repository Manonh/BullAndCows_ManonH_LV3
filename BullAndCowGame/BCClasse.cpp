#include "BCClasse.h"



//constructeurs
BCClasse::BCClasse()
{
	this->myHiddenWord = "zelda";
	this->maxTry = this->GetMaxTries();
	this->myCurrentTry = 0;
	this->gameIsWon = false;
	this->GameStatut = Statut::ok;
	this->compteur.nbBulls = 0;
	this->compteur.nbCows = 0; 
}


BCClasse::~BCClasse()
{
}

//début du jeu
void BCClasse::BeginGame() const
{
	
	cout << "Bonjour, vous allez jouer au Bull and Cow !" << endl;
	cout << "Pour commencer appuyez sur O, pour quitter appuyer sur N:" << endl;
}

//donne le nombre de tours par rapport à la longueur du mot donné
int BCClasse::GetMaxTries()const
{
	std::map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[myHiddenWord.length()];

}

//mutateurs
int BCClasse::GetCurrentTry() const
{
	return myCurrentTry;
}

void BCClasse::SetCurrentTry(int nv)
{
	this->myCurrentTry = nv; 
}

int BCClasse::GetMax() const
{
	return maxTry;
}

string BCClasse::GetHiddenWord() const
{
	return myHiddenWord;
}

void BCClasse::SetHiddenWord(string nv)
{
	this->myHiddenWord = nv;
}

bool BCClasse::GetIsWon() const
{
	return gameIsWon;
}

void BCClasse::SetIsWon(bool nv)
{
	this->gameIsWon = nv;
}

int BCClasse::GetNbBull() const
{
	return compteur.nbBulls;
}

void BCClasse::SetNbBull(int nv)
{
	this->compteur.nbBulls = nv;
}

void BCClasse::Bull()
{
	this->compteur.nbBulls = 0; 
}

int BCClasse::GetNbCow() const
{
	return compteur.nbCows;
}

void BCClasse::SetNbCow(int nv)
{
	this->compteur.nbCows;
}

void BCClasse::Cow()
{
	this->compteur.nbCows = 0; 
}


//Verif regroupe toutes les méthodes enum, et avec un switch renvoie à l'utilisateur si la saisie est correcte
void BCClasse::Verif(string nv)
{
	VerifIso(nv);
	VerifLength(nv);
	VerifLower(nv);
	switch (GameStatut)
	{
	case 0:
		break;
	case 1: SetScore(nv);
		break;
	case 2: cout << "prière de ne pas rentrer d'isogramme"<< endl;
		break;
	case 3: cout << "rentrez un mot en minuscule" << endl;
		break;
	case 4: cout << "rentrez un mot de 5 lettres" << endl;
		break;
	default: cout << "erreur de saisie" << endl;
		break;
	}
}

//verifie si le mot saisie est un isogramme
void BCClasse::VerifIso(string nv)
{

	for (size_t i = 0; i < nv.length(); i++)
	{
		for (size_t j = 0; j < nv.length(); j++)
		{
			if ((nv[i] == nv[j]) && (i != j))
			{
				this->GameStatut = Statut::notIsogram;
			}
		}
	}
}

//vérifie si le mot saisi par l'utilisateur comporte des majuscules
void BCClasse::VerifLower(string nv)
{
	for (size_t i = 0; i < nv.length(); i++)//size_t est un type de variable > i. ne pourra pas avoir de val neg.
	{
		if (isupper(nv[i]))
		{
			this->GameStatut = Statut::notLowerCase;
		}
	}
}

//vérifie si le mot saisi par l'utilisateur a la même longueur que le mot caché
void BCClasse::VerifLength(string nv)
{
	if (nv.length() != myHiddenWord.length())
	{
		this->GameStatut = Statut::wrongLength;
	}
}

void BCClasse::SetScore(string nv)
{
	for (size_t i = 0; i < myHiddenWord.length(); i++)
	{
		for (size_t j = 0; j < myHiddenWord.length(); j++)
		{
			if (myHiddenWord[i] == nv[j]) 
			{
				if (i == j)
				{
					SetNbBull(GetNbBull() + 1);
				}
				else
				{
					SetNbCow(GetNbCow() + 1); 
				}
				
			}
		}

	}
	CheckVictoire();
}

//vérifie la victoire ou la défaite
void BCClasse::CheckVictoire()
{
	if (GetNbBull() == myHiddenWord.length())
	{
		SetIsWon(true);
	}
}

