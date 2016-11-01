#include <iostream>
#include <string>
#include "BCClasse.h"
using namespace std;

int main()
{
	// var de la classe BBClasse
	BCClasse m_mot;
	string mot_j;
	// var de la classe compteurBC
	compteurBC compteur;

	cout << "bonjour, vous jouer au Bull and Cow, veuillez entrez un mot de 5 lettres." << endl;
	cout << "les bulls vous indqueront le nombre de lettres bien placees." << endl; 
	cout << "les cows vous indiqueront le nombre de lettres qui existent dans le mot mais mal placees." << endl;

	//boucle while pour le déroulement du jeu
	do
	{	

	m_mot.SetCurrentTry(m_mot.GetCurrentTry() + 1); 
	m_mot.Bull();
	cout << "Bull and cow, entrez un mot: " << endl;
	cin >> mot_j; 
	m_mot.Verif(mot_j);
	cout << "Bulls: " << m_mot.GetNbBull() << endl;
	cout << "Cows: " << m_mot.GetNbCow() << endl;



	} while ((m_mot.GetIsWon() == false) && (m_mot.GetMax()>m_mot.GetCurrentTry()));
	if (m_mot.GetIsWon() == true)
	{
		cout << "C'est gagné !" << endl;
	}
	else
	{
		cout << "Perdu !" << endl;
	}
	system("pause");
	return 0;
}