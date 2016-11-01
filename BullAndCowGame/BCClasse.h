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
	//donn�es membres
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
	//le mot cach�
	string GetHiddenWord()const;
	void SetHiddenWord(string nv);
	//victoire
	bool GetIsWon()const;
	void SetIsWon(bool nv);
	//nbbull
	int GetNbBull()const;
	void SetNbBull(int nv);
	//remise des bulls � z�ro � chaque tour de jeu
	void Bull();
	//nbcow
	int GetNbCow()const;
	void SetNbCow(int nv);
	//remise des cows � z�ro � chaque tour de jeu
	void Cow();

	//enum
	//Verif contient toutes les verifications de l'�tat du jeu
	void Verif(string nv);
	//isogramme
	void VerifIso(string nv);
	//minuscules
	void VerifLower(string nv);
	//longueur
	void VerifLength(string nv);
	
	//v�rif victoire
	void CheckVictoire();
	void SetScore(string nv);


	
	~BCClasse();
};

