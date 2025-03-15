# TP3 - Listes Chaînées et Matrices Creuses

## 📌 **Description**
Ce TP a pour objectif de se familiariser avec les **listes chaînées** et leur utilisation pour représenter des **matrices creuses**. Une matrice creuse est une matrice contenant une majorité d'éléments nuls, ce qui permet d'optimiser son stockage en ne conservant que les éléments non nuls.

## 📚 **Structures de Données**
Nous implémenterons les structures suivantes :

- **`element`** : Structure représentant un élément non nul d'une matrice.
  - `colonne` : Indice de la colonne.
  - `valeur` : Valeur de l'élément.
  - `suivant` : Pointeur vers l'élément suivant.

- **`liste_ligne`** : Liste chaînée contenant les éléments non nuls d'une ligne.

- **`matrice_creuse`** : Structure représentant une matrice creuse.
  - `N` : Nombre de lignes.
  - `M` : Nombre de colonnes.
  - `lignes` : Tableau de `N` listes chaînées contenant les éléments non nuls.

## ⚙️ **Fonctions à Implémenter**
Le TP demande l'implémentation des fonctions suivantes :

1️⃣ **`void remplirMat(matrice_creuse *m, int N, int M);`**
   - Permet de remplir une matrice creuse à partir d'une saisie utilisateur.

2️⃣ **`void afficherMat(matrice_creuse m);`**
   - Affiche la matrice creuse sous forme tabulaire.

3️⃣ **`int getValue(matrice_creuse m, int i, int j);`**
   - Retourne la valeur d'un élément à la ligne `i` et la colonne `j`.

4️⃣ **`void putValue(matrice_creuse m, int i, int j, int val);`**
   - Affecte une valeur donnée à un élément de la matrice.

5️⃣ **`void addMat(matrice_creuse m1, matrice_creuse m2);`**
   - Additionne deux matrices creuses de même taille et stocke le résultat dans `m1`.

6️⃣ **`int nombreOctetsGagnes(matrice_creuse m1);`**
   - Calcule l'espace mémoire économisé grâce à la représentation creuse.

## 🖥 **Interface Utilisateur**
Un programme interactif sera développé avec un **menu** permettant d’exécuter les opérations suivantes :

1. Remplir une matrice creuse.
2. Afficher une matrice creuse.
3. Obtenir la valeur d'un élément.
4. Modifier la valeur d'un élément.
5. Additionner deux matrices creuses.
6. Calculer le gain en mémoire.
7. Quitter le programme.

Le programme devra gérer **plusieurs matrices** en mémoire.

## 📂 **Organisation du Code**
Le projet sera structuré en **trois fichiers** :

- **`tp3.h`** : Contient les déclarations des structures et des fonctions.
- **`tp3.c`** : Implémente les fonctions du TP.
- **`main.c`** : Contient le programme principal et l’interface utilisateur.

## 📜 **Consignes Générales**
✅ La mémoire allouée dynamiquement doit être libérée à la fin du programme.
✅ Un rapport (4 pages max) doit expliquer les choix d'implémentation et analyser la complexité des fonctions.
✅ Le projet devra être remis sur **Moodle**.

## 🚀 **Améliorations Possibles**
- Optimisation de l'affichage pour un rendu plus lisible.
- Ajout d'une interface graphique simple.
- Tests unitaires pour valider les opérations sur les matrices.

🎯 **Objectif final : maîtriser la manipulation des listes chaînées en C à travers un cas d'utilisation concret !**

