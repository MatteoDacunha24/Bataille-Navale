// Matteo Da Cunha
// Bataille Navale
// 21.03.2022

#include <stdio.h>
#include <windows.h>


//**************************************Lecture de Fichier************************************

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

int main() {
    SetConsoleOutputCP(65001);
    int coup=0;
    char pseudo[20];
    int choix;
    int nombreCase;
    char RepCol[] = "A";
    int col, ligne;
        //**************************************Tableau************************************
        int BNtableau[10][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {5, 0, 1, 0, 3, 3, 3, 0, 0, 0},
                {5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},


        };
        //**************************************MENU************************************
        printf("        Bataille Navale\n");
        printf("   Réalisé par Matteo Da Cunha\n");
        printf("=================================\n\n");

        printf("[Authentification] | Veuillez entrer votre pseudonyme :\n");
        scanf("%s", &pseudo);


        printf("\n\nBienvenue %s !", pseudo);
        do {
            printf("\n\nVeuillez choisir le mode ?\n");
            printf("1 : Quitter\n");                              // Si l'on marque 1 cela va arrêter le jeu
            printf("2 : Tutoriel\n");                            // Si l'on marque 2 cela va lancer le tutoriel
            printf("3 : Jouer \n");                             // Si l'on marque 3 cela va lancer le jeu
            scanf("%d", &choix);


            //**************************************Jeux************************************



            switch (choix) {            // Les différents choix
                case 1: {
                    printf("Vous avez quitté le jeu, bonne continuation !");
                    break;
                }
                case 2: {
                    afficheFichier("../tutorial.txt");
                    break;
                }
                case 3: {
                    printf("\nVous avez choisi : Jouer contre l'ordinateur\n");

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
                    printf("\n\nBravo %s vous avez touché toutes les cases et fini la partie en %d coups!", pseudo, coup);
                    return 0;
                }
            }
        } while (choix > 0);
    }