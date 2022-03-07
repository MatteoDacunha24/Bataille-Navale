// Matteo Da Cunha
// Bataille Navale
// 03.03.2022

#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    int choix;
    int col, ligne;
    int BNtableau[10][10] = {                               // Tableau du jeu
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 10, 0, 0, 0, 4, 0, 0, 0, 0},
            {0, 0, 2, 0, 0, 4, 0, 0, 10, 0},
            {0, 0, 2, 0, 0, 4, 0, 0, 0, 0},
            {0, 0, 2, 0, 0, 4, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 11, 11, 11, 11, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 3, 13, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 5, 5, 5},


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

                break;
            }
        }





    return 0;
}
