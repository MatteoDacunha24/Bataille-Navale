// Auteur : Matteo Da Cunha
// Projet : Bataille Navale - MA-20
// Date début : 07.03.2022
// Date fin : 28.02.2022

#include <stdio.h>
#include <windows.h>
#include <time.h>



//**************************************Affiche de Fichier************************************

void afficheFichier(char nomFichier[]){
    //Cette fonction affiche le fichier texte
    //dont le nom est passé par la variable "nomFichier"
    char chaine[50]="";//pour lire une ligne, longueur max 50
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        //lecture de la ligne suivante
        while (fgets(chaine,50,fichier) ){
            printf("%s",chaine);//affichage ligne (y compris fin de ligne)
        }
        fclose(fichier); // fermeture du fichier
    }
}
//**************************************Tableau************************************


int BNtableau[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},


};

//**************************************Lecture Fichier Vers Tableau************************************

int lectureFichierVersTableau(char nomFichier[]) {
    //Cette procédure lit le fichier nomFichier (ex: ../BN1.txt dans le répertoire du main.c)
    //on s'attend à un fichier du genre:
    // 0011111000
    // 0000033000... etc
    //et le transforme en fichier BN[10][10]
    char chaine[20];
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        int ligne=0;
        //lecture de la ligne suivante (de 0 à 9 max)
        while (fgets(chaine,20,fichier) && ligne<10){
            int co=0;
            //la boucle s'arrête soit quand on est à 9, soit quand ce n'est pas un chiffre
            while (co<10 && chaine[co]>=48 && chaine[co]<=57){
                BNtableau[ligne][co]=chaine[co]-48;
                co++;
            }
            ligne++;
        }
        fclose(fichier); // fermeture du fichier
    }
}

//**************************************Fonctions************************************

int main() {
    SetConsoleOutputCP(65001);
    int coup=0;
    char pseudo[20];
    int choix;
    int nombreCase;
    char RepCol[] = "A";
    int col, ligne;
    int variablealeatoire;

        //**************************************MENU************************************


        printf("        Bataille Navale\n");
        printf("   Réalisé par Matteo Da Cunha\n");
        printf("=================================\n\n");

        printf("[Authentification] | Veuillez entrer votre pseudonyme :\n");
        scanf("%s", &pseudo);


        printf("\n\nBienvenue %s !", pseudo);
        do {
            printf("\n\nVeuillez choisir le mode \n");
            printf("1 : Quitter\n");                              // Si l'on marque 1 cela va arrêter le jeu
            printf("2 : Tutoriel\n");                            // Si l'on marque 2 cela va lancer le tutoriel
            printf("3 : Jouer \n");                             // Si l'on marque 3 cela va lancer le jeu
            scanf("%d", &choix);


            //**************************************Jeux************************************

            switch (choix) {            // Les différents choix
                case 1: {                                                           //Quitter
                    printf("Vous avez quitté le jeu, bonne continuation !");
                    return 0;
                }
                case 2: {                                                           //Tutoriel
                    afficheFichier("../Fichier/tutorial.txt");
                    break;
                }
                case 3: {


                    //Choisi Aléatoirement un tableau
                    srand(time(NULL));
                    variablealeatoire = rand() % 5+1;
                    char nomfichier[15];
                    sprintf(nomfichier,"../Fichier/BNtableau%d.txt",variablealeatoire);
                    lectureFichierVersTableau(nomfichier);
                    printf(" %s",nomfichier);


                    printf("\nVous avez choisi : Jouer contre l'ordinateur\n\n");  //Jeux
                    printf("    A   B   C   D   E   F   G   H   I   J \n"
                           "1  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "2  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "3  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "4  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "5  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "6  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "7  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "8  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "9  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                           "10 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n");

                    do {

                        printf("\nColonne ?(A-J)");
                        scanf("%s", &RepCol);
                        RepCol[0] = RepCol[0] & (0xFF - 0x20);
                        col = RepCol[0] - 65;
                        printf("\nLigne ?(1-10)");
                        scanf("%d", &ligne);
                        ligne -= 1;
                        coup++;
                        //Mise à jour tableau
                        if (BNtableau[ligne][col] < 10)
                            BNtableau[ligne][col] += 10;

                        //Affichage du tableau
                        printf("\n    A   B   C   D   E   F   G   H   I   J ");
                        for (int ligne = 0; ligne < 10; ligne++) {
                            printf("\n");
                            printf("%2d", ligne + 1);
                            for (int col = 0; col < 10; col++) {
                                if (BNtableau[ligne][col] < 10) {
                                    printf(" [ ]");
                                }
                                if (BNtableau[ligne][col] == 10) {          //Raté
                                    printf(" [O]");
                                }
                                if (BNtableau[ligne][col] > 10) {           //Touché
                                    printf(" [X]");
                                }
                            }
                        }
                        //Quand c'est fini la bataille s'arrête
                        nombreCase = 0;
                        for (int ligne = 0; ligne < 10; ligne++) {
                            for (int col = 0; col < 10; col++) {
                                if ((BNtableau[ligne][col] >= 1) && (BNtableau[ligne][col] <= 5)) {
                                    nombreCase++;
                                }
                            }
                        }
                        printf("\n\nIl vous reste %d case(s) à toucher", nombreCase);
                        printf("\nVous avez fait %d coups",coup);
                    } while (nombreCase > 0);
                    printf("\n\nBravo %s vous avez touché toutes les cases contenant un bateau et fini la partie en %d coups!", pseudo, coup);
                    return 0;
                }
            }
        } while (choix > 0);
    }