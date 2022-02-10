#ifndef METHODES
	#define METHODES
	#define MAX_LENGTH 100
	#define NUM_STRINGS 5
	
	typedef struct  // La structure pays
	{
	    int continent;     // L'indice de nom de la continent
	    float latitude,longitude;     // latitude et longtitude
	    double distance; // Distance du Pays de test
	}Pays;
	
	void AffcherLaListeDesPays(); // La methode qui permet d'afficher la liste des pays
	void Menu(); // Le menue principale
	void KNN(); // La methode qui permer d'appliqué l'lgorithm KNN
	
	char Cotinent[NUM_STRINGS][MAX_LENGTH] = {  //Les noms des continent qui existent dans le monde
		{"Amerique"}, 
    	{"Europe"},
        {"Afrique"},
        {"Asia"},
        {"Oceanie"} 
	};
	int getMAX(int,int,int,int,int);
#endif
