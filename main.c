// Matteo Da Cunha
// Bataille Navale
// 07.03.2022

#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    int choix;
    int nombreBateau;
    char RepCol[] = "A";
    int col, ligne;
    int BNtableau[10][10] = {                               // Tableau du jeu
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


    printf("\nVeuillez choisir le mode ?\n");           // Menu de séléction
    printf("1 : Tutoriel\n");
    printf("2 : Jouer contre l'ordinateur\n");
    scanf("%d", &choix);

    switch (choix) {                                    // Les différents choix
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
                nombreBateau = 0;
                for (int ligne = 0; ligne < 10; ligne++) {
                    for (int col = 0; col < 10; col++) {
                        if ((BNtableau[ligne][col] >= 1) && (BNtableau[ligne][col] <= 5)) {
                            nombreBateau++;
                        }
                    }
                }
                printf("\n\nil vous reste %d case(s)", nombreBateau);
            } while (nombreBateau > 5);
            return 0;
        }
    }
}
