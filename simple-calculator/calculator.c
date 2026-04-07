#include <stdio.h>

// Fonction pour afficher le menu
void afficherMenu() {
    printf("\n===== CALCULATRICE =====\n");
    printf("1. Addition\n");
    printf("2. Soustraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    double a, b, resultat;

    do {
        afficherMenu();
        scanf("%d", &choix);

        if (choix >= 1 && choix <= 4) {
            printf("Entrez le premier nombre : ");
            scanf("%lf", &a);

            printf("Entrez le deuxième nombre : ");
            scanf("%lf", &b);

            switch (choix) {
                case 1:
                    resultat = a + b;
                    printf("Résultat : %.2lf\n", resultat);
                    break;

                case 2:
                    resultat = a - b;
                    printf("Résultat : %.2lf\n", resultat);
                    break;

                case 3:
                    resultat = a * b;
                    printf("Résultat : %.2lf\n", resultat);
                    break;

                case 4:
                    if (b != 0) {
                        resultat = a / b;
                        printf("Résat : %.2lf\n", resultat);
                    } else {
                        printf("Erreur : division par zéro !\n");
                    }
                    break;
            }

        } else if (choix != 5) {
            printf("Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 5);

    printf("Merci d'avoir utilisé la calculatrice !\n");

    return 0;
}
