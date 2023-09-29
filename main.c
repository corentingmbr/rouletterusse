#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rouletteRusse() {
    srand(time(NULL));

    int barillet, balles, positionBalle, joueurActuel = 1;

    printf("Entrez la taille du barillet du colt : ");
    scanf("%d", &barillet);

    printf("Entrez le nombre de balles dans le barillet : ");
    scanf("%d", &balles);

    if (balles <= 0 || balles > barillet) {
        printf("Nombre de balles invalide.\n");
        return;
    }

    positionBalle = rand() % barillet + 1;

    printf("\nLa partie commence !\n");

    while (1) {
        printf("\nJoueur %d, appuyez sur 't' pour tirer ou 'q' pour quitter : ", joueurActuel);
        char choix;
        scanf(" %c", &choix);

        if (choix == 'q') {
            printf("Joueur %d a quitté la partie. Joueur %d remporte la partie.\n", joueurActuel, 3 - joueurActuel);
            return;
        } else if (choix == 't') {

            printf("BOOM!\n");

            if (positionBalle == 1) {
                printf("Joueur %d est tombé sur une balle ! Joueur %d a perdu.\n", joueurActuel, 3 - joueurActuel);
                return;
            } else {
                printf("Le barillet tourne...\n");
            }

            positionBalle = (positionBalle % barillet) + 1;

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
