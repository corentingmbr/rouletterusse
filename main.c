#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rouletteRusse() {
    srand(time(NULL));

    int barillet, balles, positionBalle1, positionBalle2, joueurActuel = 1;

    printf("Entrez la taille du barillet du colt : ");
    scanf("%d", &barillet);

    printf("Entrez le nombre de balles dans le barillet : ");
    scanf("%d", &balles);

    if (balles <= 0 || balles > barillet) {
        printf("Nombre de balles invalide.\n");
        return;
    }

    positionBalle1 = rand() % barillet + 1;
    positionBalle2 = rand() % barillet + 1;

    printf("\nLa partie commence !\n");

    while (1) {
        printf("\nJoueur %d, appuyez sur 't' pour tirer ou 'q' pour quitter : ", joueurActuel);
        char choix;
        scanf(" %c", &choix);

        if (choix == 'q') {
            printf("Joueur %d a quitte la partie. Joueur %d remporte la partie.\n", joueurActuel, 3 - joueurActuel);
            return;
        } else if (choix == 't') {
            printf("BOOM!\n");

            if ((joueurActuel == 1 && positionBalle1 == 1) || (joueurActuel == 2 && positionBalle2 == 1)) {
                printf("Joueur %d a tiré une balle ! Joueur %d a perdu.\n", joueurActuel, 3 - joueurActuel);
                return;
            } else {
                printf("Le barillet tourne...\n");
            }

            if (joueurActuel == 1) {
                positionBalle1 = (positionBalle1 % barillet) + 1;
            } else {
                positionBalle2 = (positionBalle2 % barillet) + 1;
            }

            joueurActuel = 3 - joueurActuel;
        } else {
            printf("Commande non reconnue. Veuillez entrer 't' pour tirer ou 'q' pour quitter.\n");
        }
    }
}

int main() {
    rouletteRusse();

    return 0;
}
