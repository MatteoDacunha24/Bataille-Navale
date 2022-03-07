// Matteo Da Cunha
// Bataille Navale
// 03.03.2022

#include <stdio.h>
#include <time.h>
#include <windows.h>


int main() {
    SetConsoleOutputCP(65001);
    int choix;
    int BNtableau[10][10] = {
            {0, 0, 1, 1, 11, 11, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 10, 0, 0, 0, 10, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 4, 14, 14, 4, 0, 0, 0, 105},
            {12, 0, 0, 0, 0, 0, 0, 0, 0, 105},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {2, 0, 0, 0, 0, 0, 0, 0, 10, 0},
            {12, 0, 0, 10, 0, 0, 0, 0, 0, 0},
            {12, 0, 0, 0, 0, 0, 13, 13, 3, 0},


    };

        printf("      A     B     C     D     E     F     G     H     I     J \n");
        for (int ligne = 0; ligne < 10; ++ligne) {
            printf("%2d", ligne + 1);
            for (int colonnes = 0; colonnes < 10; ++colonnes) {
                if (BNtableau[ligne][colonnes] == 0) { printf("   [ ]"); }
                if ((BNtableau[ligne][colonnes] >= 1) && (BNtableau[ligne][colonnes] <= 5)) { printf("   [ ]"); }
                if (BNtableau[ligne][colonnes] == 10) { printf("   [X]"); }
                if ((BNtableau[ligne][colonnes] >= 11) && (BNtableau[ligne][colonnes] <= 15)) { printf("   [O]"); }
                if ((BNtableau[ligne][colonnes] >= 101) && (BNtableau[ligne][colonnes] <= 105)) { printf("   [¦]"); }
            }
            printf("\n");
        }

    return 0;
}
