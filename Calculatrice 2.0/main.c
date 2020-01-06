#include <stdio.h>
#include <stdlib.h>
#include "maths.h"

int main(){
	int state = 1;
	int t;

	double a;
	double b;

	double result = 0;

    int choice;
    char op;

    do{
	    printf("----------Calculatrice----------\n\n");
	    printf("> Addition: +\n");
	    printf("> Soustraction: -\n");
	    printf("> Multiplication: *\n");
	    printf("> Division: /\n\n");

	    printf("> Carre: ^2\n");
	    printf("> Exposant: ^\n\n");

	    printf("> Racine caree: r2\n");
	    printf("> Racine n-ieme: r\n\n");

	    printf("> Factorielle: !.\n\n");

	    printf("> Pi: 0p0\n\n");
	    printf("--------------------------------\n\n\n");

        printf("> Veuillez saisir une operation\n");
        scanf("%lf %c %lf", &a, &op, &b);

        switch (op){
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                if(b==0){
                    printf("Erreur: La division par 0 n'existe pas, veuillez recommencer");
                }else{
                    result = a / b;
                }
                break;

            case'^':
            	if(b==2){
            		result = Pow(a, 2);
            	}else{
            		result = Pow(a, b);
            	}
            	break;

            case 'r':
				result = Sqrt(a, b);
				break;

            case '!':
            	result = Factorielle(a);
            	break;

            case 'p':
           		printf("Avec quelle precision voulez-vous Pi ?\n");
            	scanf("%i", &t);
            	result = Pi_bs(t);
            	break;

            default:
            	system("cls");
                printf("\nIl doit y avoir une erreur.\n\n");
                system("pause");
                system("cls");
                break;
        }

        printf("%f\n\n--------------------------------\n\n\n", result);

        printf("Voullez vous quitter ? (oui -> 1/non -> 0)\n");
        scanf("%i", &choice);

        switch(choice){
            case 0:
                state=1;
                system("cls");
                break;

            case 1:
                state = 0;
                system("cls");
                printf("\nMerci d'avoir utilise la calculatrice !\nA bientot\n\n");
                break;

            default:
            	system("cls");
            	printf("\nIl doit y avoir une erreur.\n\n");
            	system("pause");
            	system("cls");
                break;
        }

    }while(state);

    return 0;
}
