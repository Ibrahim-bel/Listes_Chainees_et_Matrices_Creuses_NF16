#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED




// Structures et types
struct Transaction {
    int idEtu;
    float montant;
    char *description;
    struct Transaction *suivant;
};
typedef struct Transaction T_Transaction;

struct Block {
    int idBloc;
    char *dateBloc; // date du bloc sous la forme AAAAMMJJ (ex : 20231009 pour le 09/10/2023)
    T_Transaction *listeTransactions;
    struct Block *suivant;
};
typedef struct Block T_Block;

typedef T_Block *BlockChain;

//Structure date ajoutee
typedef struct Date{
    int annees;
    int mois;
    int jours;
}Date;


// Cr�ation et initialisation des structures
T_Transaction *creerTransaction(int id, float montant, char *descr);
T_Block *creerBloc(int id, char* date);


// 1.	Ajout d'une transaction en t�te d'une liste de transactions :
T_Transaction *ajouterTransaction(int idEtu, float montant, char *descr, T_Transaction *listeTransaction);

// 2.	Ajout d'un bloc en t�te de la BlockChain :
BlockChain ajouterBlock(BlockChain bc);

// 3.	Calcul de la somme des EATCoin cr�dit�s et d�pens�s par un �tudiant sur une journ�e :
float totalTransactionEtudiantBlock(int idEtu, T_Block b);

// 4.	Calcul du solde total d'un �tudiant:
float soldeEtudiant(int idEtu, BlockChain bc);

// 5.	Rechargement du compte d�un �tudiant :
void crediter(int idEtu, float montant, char *descr, BlockChain bc);

// 6.	Paiement d�un repas :
int payer(int idEtu, float montant, char *descr, BlockChain bc);

// 7.	Historique d�un �tudiant :
void consulter(int idEtu, BlockChain bc);

// 8.	Transfert de EATCoins entre deux �tudiants :
int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc);



// UTILS
void viderBuffer() ;

//Afficher la liste des blocs de la BlockChain
void afficherBlockChaine(BlockChain bc);

//Chercher un bloc
T_Block *chercherbloc_ID(int idBloc, BlockChain bc); // Par l'ID du bloc
T_Block *chercherbloc_date(char *date, BlockChain bc); //Par la date du bloc

//Afficher toutes les transactions d'un bloc
void afficherTransactions_bloc(int idBloc, char *dateBloc, BlockChain bc);

//Afficher toutes les transactions du jour pour un etudiant
void afficherTransactions_Jour_Etudiant(int idEtu, int idBloc, char *dateBloc, BlockChain bc);

//Liberer tout l'espace libre
void libererEspace(BlockChain bc);

int saisieEtudiant();
float saisieMontant();

Date conv_char_int(char maDate[9]);
int annee_bissextille(int annee);
int duree_du_mois(int mois, int annee);
char* conv_int_char(Date date);
char* ajouter_jour(char date[9], int nb);

#endif // TP3_H_INCLUDED
