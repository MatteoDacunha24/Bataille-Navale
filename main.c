// Matteo Da Cunha
// Bataille Navale
// 07.03.2022

#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    int nombreEssai;
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


    };
    //**************************************MENU************************************
    printf("        Bataille Navale\n");
    printf("   Réalisé par Matteo Da Cunha\n");
    printf("=================================\n\n");

    printf("[Authentification] | Veuillez entrer votre pseudonyme :\n");
    scanf("%s",&pseudo);


    printf("\n\nBienvenue %s !",pseudo);
    do {
        printf("\n\nVeuillez choisir le mode ?\n");
        printf("0 : Quitter\n");                              // Si l'on marque 0 cela va arrêter le jeu
        printf("1 : Tutoriel\n");                            // Si l'on marque 1 cela va lancer le tutoriel
        printf("2 : Jouer contre l'ordinateur\n");          // Si l'on marque 2 cela va lancer le jeu
        scanf("%d", &choix);


    //**************************************Jeux************************************



        switch (choix) {            // Les différents choix
            case 0: {
                printf("Vous avez quitté le jeu, bonne continuation !");
            }
            case 1: {
                printf("Vous avez choisi le tutoriel le voici :\n");
                printf("Il faut selectioner une case sur la grille pour savoir si nous avons touché un bateau, exemple : B 3");
                break;
            }
            case 2: {
                printf("\nVous avez choisi : Jouer contre l'ordinateur\n");

                do {
                    printf("\nColonne ?(A-J)");
                    scanf("%s", &RepCol);
                    RepCol[0] = RepCol[0] & (0xFF - 0x20);
                    col = RepCol[0] - 65;
                    printf("\nLigne ?(1-10)");
                    scanf("%d", &ligne);
                    ligne -= 1;
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
                            if (BNtableau[ligne][col] == 10) {
                                printf(" [O]");
                            }
                            if (BNtableau[ligne][col] > 10) {
                                printf(" [X]");
                            }
                            if (BNtableau[ligne][col] > 20) {
                                printf(" [/]");
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
                } while (nombreCase > 0);
                printf("\n\nBravo %s vous avez touché toutes les cases et fini la partie!", pseudo);
                return 0;
            }
        }
    } while (choix > 0);
}
