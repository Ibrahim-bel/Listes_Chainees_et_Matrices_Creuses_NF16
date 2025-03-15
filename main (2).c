#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main(){

    BlockChain ma_chaine_de_blocs = NULL;

    int option;
    int idEtu, idSource, idDestination;
    float montant;
    int idBloc;
    char descr[100];
    char dateBloc[9];
    int nb_ajout;//case8
    char* nouvelle_date;

    char dateref[9] = "20231107";
    ma_chaine_de_blocs = creerBloc(0, dateref);

    // ============= MENU UTILISATEUR ============= 
    char choix = '0';
    while (choix != '9') {
        printf("\n======================================");
        printf("\n1. Afficher la liste des blocs de la BlockChain");
        printf("\n2. Afficher toutes les transactions d'un bloc");
        printf("\n3. Afficher toutes les transactions du jour pour un etudiant");
        printf("\n4. Afficher l'historique pour un etudiant");
        printf("\n5. Crediter un compte");
        printf("\n6. Payer un repas");
        printf("\n7. Transferer des EATCoins entre deux etudiants");
        printf("\n8. Changer de date");
        printf("\n9. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");

        choix = getchar();

        switch (choix) {
            case '1' :
                if (ma_chaine_de_blocs == NULL){
                    printf("La Blockchaine est vide !\n");
                }
                else {afficherBlockChaine(ma_chaine_de_blocs);}
                break;

            case '2' :
                printf("1.Rechercher par l'ID du bloc\n");
                printf("2.Rechercher par la date du bloc (sous la forme AAAAMMJJ)\n");
                printf("Quelle option choisissez-vous ? : ");
                scanf("%d", &option);

                if (option == 1){
                     printf("ID du bloc : ");
                    scanf("%d", &idBloc);
                    afficherTransactions_bloc(idBloc, NULL, ma_chaine_de_blocs);
                }
                else if (option == 2){
                    printf("Date du bloc : ");
                    scanf("%9s", dateBloc);
                    afficherTransactions_bloc(-1, dateBloc, ma_chaine_de_blocs);
                }
                else {printf("\nERREUR : votre choix n'est pas valide ! ");}
                break;
                        
            case '3' :
                idEtu = saisieEtudiant();
                printf("1.Rechercher par l'ID du bloc\n");
                printf("2.Rechercher par la date du bloc (sous la forme AAAAMMJJ)\n");
                printf("Quelle option choisissez-vous ? : ");
                scanf("%d", &option);
                if (option == 1){
                        printf("ID du bloc: ");
                        scanf("%d", &idBloc);
                        afficherTransactions_Jour_Etudiant(idEtu, idBloc, NULL, ma_chaine_de_blocs);
                }
                else if (option == 2){
                        printf("Date du bloc: ");
                        scanf("%9s", dateBloc);
                        afficherTransactions_Jour_Etudiant(idEtu, -1, dateBloc, ma_chaine_de_blocs);
                }
                else {printf("\nERREUR : votre choix n'est pas valide ! ");}
                break;

            case '4' :
                idEtu = saisieEtudiant();
                consulter(idEtu, ma_chaine_de_blocs);
                printf("\nAppuyer sur entrer pour continuer");
                break;

            case '5' :
                idEtu = saisieEtudiant();
                do{ montant = saisieMontant(); } while(montant <= 0);
                crediter(idEtu, montant, "Rechargement", ma_chaine_de_blocs);
                printf("\nAppuyer sur entrer pour continuer");
                break;

            case '6' :
                idEtu = saisieEtudiant();
                printf("\nEntrez la description (Pas de caracteres speciaux) :  ");
                fgets(descr, sizeof(descr), stdin);
                do{ montant = saisieMontant(); } while(montant <= 0);
                if(payer(idEtu, montant, descr, ma_chaine_de_blocs)){
                    printf("\nPaiement accepté !\n");
                }
                else{
                    printf("\nPayement refusé ! Vous n'avez pas assez de EATCoin.\n");
                }
                printf("\nAppuyer sur entrer pour continuer");
                break;

            case '7' :
                printf("Entrez les ID des étudiants.\n");
                printf("ID de l'étudiant donneur ");
                idSource = saisieEtudiant();
                printf("ID de l'étudiant receveur ");
                idDestination = saisieEtudiant();
                do{ montant = saisieMontant(); } while(montant <= 0);
                if(transfert(idSource, idDestination, montant, "Transfert", ma_chaine_de_blocs)){
                    printf("Transfert réussi !\n"); }
                else {printf("L'étudiant source n'a pas assez de EATCoin sur son compte !\n");}
               break;

            case '8' : //Changer la date
                printf("la dernière date enregistrée est  %s \n",ma_chaine_de_blocs->dateBloc);
                printf("Saisir le nombre de jour a ajouter pour la nouvelle date : ");
                scanf("%d",&nb_ajout);
                nouvelle_date=ajouter_jour(ma_chaine_de_blocs->dateBloc,nb_ajout);
                printf("La nouvelle date : ");
                printf("%s",nouvelle_date);
                ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
                strcpy(ma_chaine_de_blocs->dateBloc, nouvelle_date);
                break;

            case '9' :
                libererEspace(ma_chaine_de_blocs);
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer(); // supprimer de l'entr�e standard le retour charriot et les �ventuels caract�res suppl�mentaires tap�s par l'utilisateur
    }

    return 0;
}
