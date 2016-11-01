#pragma once
#include <string>
#include <iostream>
#include <map>
#include <ctype.h>

using namespace std;

//type structure
typedef struct compteurBC
{
	int nbBulls;
	int nbCows;
}compteurBC;

enum Statut
{
	invalidStatut,
	ok,
	notIsogram,
	notLowerCase,
	wrongLength
};

class BCClasse
{
	//données membres
	int myCurrentTry;
	string myHiddenWord;
	bool gameIsWon;
	int maxTry;
	Statut GameStatut;
	compteurBC compteur;

public:
	BCClasse();

	void BeginGame() const;
	//mutateurs
	//concernant les essais
	int GetMaxTries()const;
	int GetCurrentTry()const;
	void SetCurrentTry(int nv);
	int GetMax() const;
	//le mot caché
	string GetHiddenWord()const;
	void SetHiddenWord(string nv);
	//victoire
	bool GetIsWon()const;
	void SetIsWon(bool nv);
	//nbbull
	int GetNbBull()const;
	void SetNbBull(int nv);
	//remise des bulls à zéro à chaque tour de jeu
	void Bull();
	//nbcow
	int GetNbCow()const;
	void SetNbCow(int nv);
	//remise des cows à zéro à chaque tour de jeu
	void Cow();

	//enum
	//Verif contient toutes les verifications de l'état du jeu
	void Verif(string nv);
	//isogramme
	void VerifIso(string nv);
	//minuscules
	void VerifLower(string nv);
	//longueur
	void VerifLength(string nv);
	
	//vérif victoire
	void CheckVictoire();
	void SetScore(string nv);


	
	~BCClasse();
};

