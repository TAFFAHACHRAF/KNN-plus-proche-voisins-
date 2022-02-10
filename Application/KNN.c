#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "METHODES.h"

int max=255; // variable global pour les prochaines utilisations
FILE* repertoire = NULL; // Déclaration d'un fichier
FILE* rept = NULL; //Déclaration d'un fichier

static int i,j; // Déclaration de variable statiques
Pays pays; // Déclaration d'un tableau de type pays pour les prochaines utilisations

int getMAX(int x,int y,int z,int k,int l){ //fonction qui permet de retourné le nembre maximal parmie 5 nombres
		int tab[5]={x,y,z,k,l};
		int indice=0,i=0;
		int max=tab[0];
		for(i=0;i<5;i++){
			if(tab[i]>max){
				max=tab[i];
				indice=i;
			}
		}
		return indice;
}
	
void Menu()
{
	choix:
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |   Mini-projet 1 : Programmation en langage C de la Methode des k plus proches voisins            |\n");
	Sleep(100);
	printf("                |                                                                              			   |\n");
	Sleep(100);
	printf("                |                                    Realise par                                  		   |\n");
	Sleep(100);
	printf("                |                                          :                                       		   |\n");
	Sleep(100);
	printf("                |                                   Achraf TAFFAH                                  		   |\n\n");
	Sleep(100);
	printf("                |                                         et                                       		   |\n\n");
	Sleep(100);
	printf("                |                                   Najwa ZRAIDI                                   		   |\n\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("                                    +++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100); 
	printf("                                    |                                       |\n");
	Sleep(100);
	printf("                                    | 1 ==> Affcher la liste des pays       |\n");
	Sleep(100);
	printf("                                    | 2 ==> KNN		                    |\n");
	Sleep(100);
	printf("                                    | 3 ==> Quitter                         |\n");
	Sleep(100);
	printf("                                    ++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	
	printf("                                         Veuillez choisir une action  :" );
	scanf("%d",&i );
	
	int  r=1;
	switch(i){
		case 1:{
			system("cls");
			AffcherLaListeDesPays();
			printf("Cliquer sur '0' pour retourner au Menu :");
			scanf("%d",&r);
			
			if(r==0)
			{
				goto choix;
			}
		}
		case 2:{
			system("cls");
			KNN();
			printf("Cliquer sur '0' pour retourner au Menu :");
			scanf("%d",&r);
			
			if(r==0)
			{
				goto choix;
			}
		}
		case 3:
		system("exit");
	}
}
void AffcherLaListeDesPays(){
	system("cls");
	printf("                +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                      La liste des pays par continent,attitude et longitude                |\n");
	Sleep(100);
	printf("                +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
	Sleep(100);
	
	repertoire = fopen("KNN_Etat.csv","r");
	char line[255];
	
	Pays arr[1000];
	
	while (fgets(line,max,repertoire)!= NULL) {
		  int len = strlen(line);
		  char d[] = ";";
		  char *p = strtok(line,";");
		  int count=0,i=0;
		  while(p=strtok(NULL,";")){
		  	printf("     %s     ",p);
		  }
    }	
}

void KNN(){
	repertoire = fopen("KNN_Etat.csv","r");
	char line[255];
	Pays arr[200];
	while (fgets(line,max,repertoire)!= NULL) { // la lecture des donneés dans le fichier
		  int len = strlen(line);
		  char d[] = ";";
		  char *p = strtok(line,";");
		  while(p=strtok(NULL,";")){
		  	if(i==0){
		  		if(strcmp("Amerique",p)==0)	
		  			arr[j].continent=0;
		  		else if(strcmp(p,"Europe")==0)
		  			arr[j].continent=1;
		  		else if(strcmp(p,"Afrique")==0)
		  			arr[j].continent=2;
		  		else if(strcmp(p,"Asia")==0)
		  			arr[j].continent=3;
		  		else if(strcmp(p,"Oceanie")==0)
		  			arr[j].continent=4;
			  }
		    else if(i==1)
		    	arr[j].latitude = atof(p); 
		    else if(i==2)
		    	arr[j].longitude = atof(p);
		    	
		    i++;
		  }		  
		  j++;
		  i=0;
    }
    int count_fecch=j;
    Pays p;     /*Pays de test*/	
    int n = count_fecch,k; // Number of data points

    printf("                              Entrer svp latitude du pays : ");
    scanf("%f",&p.latitude);
    
    printf("                              Entrer svp longitude du pays : ");
    scanf("%f",&p.longitude);
    
    printf("                              Entrer svp le nombre des enregistrement que vous voulez traiter dans le fichier : ");
    scanf("%d",&k);

     // Remplir les distances de tous les pays de p
     
    for (i = 0; i < n; i++){
        arr[i].distance =
            sqrt((arr[i].latitude - p.latitude) * (arr[i].latitude - p.latitude) +
                 (arr[i].longitude - p.longitude) * (arr[i].longitude - p.longitude));
	}

    // Trier les pays par distance de p  
    int continentTMP; // Le nom temporaire de la continent
    double latitudeTMP,longitudeTMP; // latitude et longtitude temporaire
    double distanceTMP;  // Distance temporaire du Pays de test
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i].distance>arr[j].distance){				
				continentTMP=arr[i].continent;
				arr[i].continent=arr[j].continent;
				arr[j].continent=continentTMP;
				
				latitudeTMP=arr[i].latitude;
				arr[i].latitude=arr[j].latitude;
				arr[j].latitude=latitudeTMP;
				
				longitudeTMP=arr[i].longitude;
				arr[i].longitude=arr[j].longitude;
				arr[j].longitude=longitudeTMP;
				
				distanceTMP=arr[i].distance;
				arr[i].distance=arr[j].distance;
				arr[j].distance=distanceTMP;
			}
		}
	}
	int Amerique=0,Europe=0,Afrique=0,Asia=0,Oceanie=0;
	for(j=0;j<k;j++){
		if(arr[j].continent==0){
			Amerique++;
			printf("%d",Amerique++);
		}
		else if(arr[j].continent==0){
			Europe++;
			printf("%d",Europe++);
		}
		else if(arr[j].continent==0){
			Afrique++;
			printf("%d",Afrique++);
		}
		else if(arr[j].continent==0){
			Asia++;
			printf("%d",Asia++);
		}
		else if(arr[j].continent==0){
			printf("%d",Oceanie++);
		}
	}
	int freq1 = 0;     // Frequency of group 0
    int freq2 = 0;     // Frequency of group 1
    int freq3 = 0;     // Frequency of group 2
    int freq4 = 0;     // Frequency of group 3
    int freq5 = 0;     // Frequency of group 4
    
    for (i = 0; i < k; i++){
        if (arr[i].continent == 0)
            freq1++;
        else if (arr[i].continent == 1)
            freq2++;
        else if (arr[i].continent == 2)
            freq3++;
        else if (arr[i].continent == 3)
            freq4++;
        else if (arr[i].continent == 4)
            freq5++;
    }
    int indice_de_continent=getMAX(freq1,freq2,freq3,freq4,freq5);
	
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                     Le continent de ce pays est : %s 	                       |\n",Cotinent[indice_de_continent]);
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	system("color 2");
	printf("                                               ./oydmNMMMMNmdyo/`\n");
	Sleep(100);
	printf("                                            -smMMMMMMMMMMMMMMMMMMms:\n");
	Sleep(100);
	printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm\n");
	Sleep(100);
	printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
	Sleep(100);
	printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
	Sleep(100);
	printf("                                     .mMMMMMMMMMMMMMMMMMMMMMMMMmdmMMMMMMMm.\n");
	Sleep(100);
	printf("                                     dMMMMMMMMMMMMMMMMMMMMMMMh-   -NMMMMMMd\n");
	Sleep(100);
	printf("                                    +MMMMMMMMMMMMMMMMMMMMMMh-      dMMMMMMM+\n");
	Sleep(100);
	printf("                                    mMMMMMMMMNhshNMMMMMMMh-      :dMMMMMMMMN\n");
	Sleep(100);
	printf("                                    MMMMMMMMm`   `oNMMMh-      :mMMMMMMMMMMM\n");
	Sleep(100);
	printf("                                    MMMMMMMMm.     `oh-      -hMMMMMMMMMMMMM\n");
	Sleep(100);
	printf("                                    NMMMMMMMMNs`           -hMMMMMMMMMMMMMMm\n");
	Sleep(100);
	printf("                                    +MMMMMMMMMMNs`       :hMMMMMMMMMMMMMMMM+\n");
	Sleep(100);
	printf("                                     dMMMMMMMMMMMNs`   /mMMMMMMMMMMMMMMMMMd\n");
	Sleep(100);
	printf("                                     .mMMMMMMMMMMMMMddNMMMMMMMMMMMMMMMMMMm.\n");
	Sleep(100);
	printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
	Sleep(100);
	printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
	Sleep(100);
	printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm+\n");
	Sleep(100);
	printf("                                            -smMMMMMMMMMMMMMMMMMMms-\n");
	Sleep(100);
	printf("                                               `:oydmNMMMMNmdyo:`\n\n");
	
}
