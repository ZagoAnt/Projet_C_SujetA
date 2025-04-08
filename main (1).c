// Bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
// Constantes
#define max_nom 50

/* Appel fonction ------------------------------------------------------------------------------------*/
// Exercices
int addition();
int soustraction();
int multiplication();
int table_multiplication();
int table_multiplication_exo();
int division();
int conversion_minutes();
int conversion_secondes();
int conversion_minutes_secondes();
int mesure_de_masses();
int mesure_de_longueur();
int aire();
int conversion();
int ordre_grandeur();
// Menu
void affiche_menu(void);
void choix_menu();
// Gestion du score
void nouvel_utilisateur(int score, char nom[max_nom],char tempsformate[sizeof "JJ/MM/AAAA HH:MM:SS"]);
int recup_score(char nom[max_nom]);
void sauvegarde(int score, char nom[max_nom]);
/*-------------------------------------------------------------------------------------*/

// Programme principal
int main(void) {
  srand(time(NULL));
  choix_menu();
  return 0;
}

void affiche_menu(void) {
  printf("+------------------------------------+\n");
  printf("|1: Addition                         |\n");
  printf("|2: Soustraction                     |\n");
  printf("|3: Multiplication                   |\n");
  printf("|4: Tables des multiplication        |\n");
  printf("|5: Divisions                        |\n");
  printf("|6: Conversions                      |\n");
  printf("|7: Conversion en minutes-secondes   |\n");
  printf("|8: Ordre de grandeur                |\n");
  printf("|0: Sortir du jeu                    |\n");
  printf("+------------------------------------+\n");
  printf("Quel est votre choix ? ");
}

void choix_menu() {
  // Variables
  int choix = -1;
  // Gestion du score
  printf("nom : ");
  char nom[max_nom];
  scanf("%s", nom);
  int score = recup_score(nom);
  while (choix != 0) {
    affiche_menu();
    scanf("%d", &choix);
    printf("\n");
    switch (choix){
      case 1:
        printf("Addition\n\n");
        score = score + addition();
        break;
      case 2:
        printf("Soustraction\n\n");
        score = score + soustraction(score);
        break;
      case 3:
        printf("Multiplication\n\n");
        score = score + multiplication();
        break;
      case 4: 
        printf("Tables des multiplication\n\n");
        score = score + table_multiplication_exo();
        break;
      case 5:
        printf("Divisions\n\n");
        score = score + division();
        break;
      case 6:
        printf("Conversion\n\n");
        score = score + conversion(); 
        break;
      case 7: 
        printf("Conversion en minutes-secondes\n\n");
        score = score + conversion_minutes_secondes();
        break;
      case 8:
        printf("Ordre de grandeur\n\n");
        score = score + ordre_grandeur();
        break;
      case 0:
        printf("Merci de votre visite\n\n");
        break;   
      default:
        printf("Erreur de saisie\n\n");
        break;
    }
    printf("Votre score est de %d\n\n", score);
    sauvegarde(score, nom);
  }
}


int addition() {
  // Variables
  int nb1 = rand() % 101, nb2 = rand() % 101, reponse, resultat = nb1 + nb2;
  int score = 0;
  // Programme
  for (int essai = 1; essai < 4; essai++) {
    printf("%d + %d = ?\n", nb1, nb2);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    printf("\n");
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int soustraction() {
  // Variables
  int nb1 = rand() % 101, nb2 = rand() % 101, reponse, resultat;
  int score = 0;
  // Programme
  for (int essai = 1; essai < 4; essai++) {
    if (nb1 < nb2) {
      reponse = nb1;
      nb1 = nb2;
      nb2 = reponse;
    }
    resultat = nb1 - nb2;
    printf("%d - %d = ?\n", nb1, nb2);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int multiplication() {
  // Variables
  int nb1 = rand() % 10 + 1, nb2 = rand() % 10 + 1, reponse,
      resultat = nb1 * nb2;
  int score = 0;
  // Programme
  for (int essai = 1; essai < 4; essai++) {
    printf("%d * %d = ?\n", nb1, nb2);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int table_multiplication() {
  // Variables
  int choix;
  printf("Entrez votre choix : ");
  scanf("%d", &choix);
  for (int i = 0; i <= 10; i++) {
    printf("%d * %d = %d \n\n", choix, i, choix * i);
  }
  printf("\n");
  return choix;
}

int table_multiplication_exo() {
  // On affiche la tables de multiplication du choix de l'utilisateur
  int choix = table_multiplication();
  // Variable
  int nb2 = rand() % 10 + 1, reponse, resultat = choix * nb2, score = 0;
  // Exercice
  for (int essai = 1; essai < 4; essai++) {
    printf("%d * %d = ?\n", choix, nb2);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    // Attribution du score
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int division() {
  // Variables
  int nb2 = rand() % 10 + 1, nb1 = rand() % 100 + 1, reponse,
      resultat = nb1 / nb2, score = 0;
  // on transforme nb1 en multiple de nb2
  nb1 = nb1 - nb1 % nb2;
  // Exercice
  for (int essai = 1; essai < 4; essai++) {
    printf("%d / %d = ?\n", nb1, nb2);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    // Attribution du score
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

/* Exercice Conversion -----------------------------------------------------------------*/
int mesure_de_longueur(){
  // Création de la conversion
  const char *unitesl[] = {"km", "hm", "dam", "m", "dm", "cm", "mm"};
  const double facteursl[] = {1e3, 1e2, 1e1, 1, 1e-1, 1e-2, 1e-3};
  int alea = rand() % 7, alea2 = rand() % 7;
  while (alea == alea2){
    alea2 = rand() % 7;
  }
  int reponsegauche = rand() % 10 + 1;
  double reponsedroite = reponsegauche * facteursl[alea] / facteursl[alea2];
  // Exercice
  double reponse;
  int score = 0;
    for (int i = 1; i < 4; i++) {
      printf("%d %s = ? %s", reponsegauche, unitesl[alea], unitesl[alea2]);
      printf("\nEntrez le résultat : ");
      scanf("%lf", &reponse);
      if (i == 1 && reponsedroite == reponse) {
        score = 10;
        break;
      } else if (i == 2 && reponsedroite == reponse) {
        score = 5;
        break;
      } else if (i == 3 && reponsedroite == reponse) {
        score = 1;
        break;
      } else {
        printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - i);
      }
    }
  printf("Le résultat est %f\n\n", reponsedroite);
  return score;
}

int mesure_de_masses(){
  // Création de la conversion
  const char *unitesl[] = {"kg", "hg", "dag", "g", "dg", "cg", "mg"};
  const double facteursl[] = {1e3, 1e2, 1e1, 1, 1e-1, 1e-2, 1e-3};
  int alea = rand() % 7, alea2 = rand() % 7;
  while (alea == alea2){
    alea2 = rand() % 7;
  }
  int reponsegauche = rand() % 10 + 1;
  double reponsedroite = reponsegauche * facteursl[alea] / facteursl[alea2];
  // Exercice
  double reponse;
  int score = 0;
    for (int i = 1; i < 4; i++) {
      printf("%d %s = ? %s", reponsegauche, unitesl[alea], unitesl[alea2]);
      printf("\nEntrez le résultat : ");
      scanf("%lf", &reponse);
      if (i == 1 && reponsedroite == reponse) {
        score = 10;
        break;
      } else if (i == 2 && reponsedroite == reponse) {
        score = 5;
        break;
      } else if (i == 3 && reponsedroite == reponse) {
        score = 1;
        break;
      } else {
        printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - i);
      }
    }
  printf("Le résultat est %f\n\n", reponsedroite);
  return score;
}

int aire() {
  int score = 0;
  // Dictionnaire de conversion
  const char *unites[] = {"km²", "hm²", "dam²", "m²", "dm²", "cm²", "mm²"};
  const double facteurs[] = {1e6, 1e4, 1e2, 1, 1e-2, 1e-4, 1e-6};
  // Alea1-2 = Index du dictionnaire
  int alea = rand() % 7, alea2 = rand() % 7;
  // On cherche des conversions pas trop grandes et on évite la meme unité de
  // conversion
  while (alea == alea2 || alea2 - 3 > alea || alea2 < alea - 3) {
    alea2 = rand() % 7;
  }
  int reponsegauche = rand() % 10 + 1;
  double reponsedroite = reponsegauche * facteurs[alea] / facteurs[alea2];
  double reponse;
  for (int i = 1; i < 4; i++) {
    printf("%d %s = ? %s", reponsegauche, unites[alea], unites[alea2]);
    printf("\nEntrez le résultat : ");
    scanf("%lf", &reponse);
    if (i == 1 && reponsedroite == reponse) {
      score = 10;
      break;
    } else if (i == 2 && reponsedroite == reponse) {
      score = 5;
      break;
    } else if (i == 3 && reponsedroite == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - i);
    }
  }
  printf("Le résultat est %f\n\n", reponsedroite);
  return score;
}

int conversion(){
  //Variables
  int score = 0;
  int exo = rand() % 3 +1;
  if (exo == 1){score = aire();}
  else if (exo == 2){score = mesure_de_longueur();}
  else{score = mesure_de_masses();}
  return score;
}
/*----------------------------------------------------------------------------------------------*/

/* Exercice Conversion minutes -----------------------------------------------------------------*/
int conversion_minutes() {
  // Variables
  int heure = rand() % 11 + 1, minutes = rand() % 60, reponse, resultat;
  int score = 0;
  // Programme
  resultat = (heure * 60) + minutes;
  for (int essai = 1; essai < 4; essai++) {
    printf("%dh : %dmin= ? min\n", heure, minutes);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int conversion_secondes() {
  // Variables
  int minutes = rand() % 11 + 1, secondes = rand() % 60, reponse, resultat;
  int score = 0;
  // Programme
  resultat = minutes * 60 + secondes;
  for (int essai = 1; essai < 4; essai++) {
    printf("%dmin : %ds= ? s\n", minutes, secondes);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    if (essai == 1 && resultat == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultat == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultat == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultat);
  return score;
}

int conversion_minutes_secondes() {
  // Variables
  int valeur = rand() % 2 + 1;
  int score = 0;
  // Programme
  if (valeur == 1) {
    score = conversion_minutes();
  } else {
    score = conversion_secondes();
  }
  return score;
}
/*-----------------------------------------------------------------------------------------*/

/* Exercice ordre de grandeur -------------------------------------------------------------*/
int ordre_grandeur(){
  // Variables
  int alea = rand() % 10000 +1 , alea2 = rand() % 10 - 5;
  double resultat = alea * pow(10, alea2);
  int resultatordre = log10(resultat);
  int reponse;
  int score = 0;
  for (int essai = 1; essai < 4; essai++) {
    printf("%f donnez son ordre de grandeur (10**?)\n", resultat);
    printf("Entrez le résultat : ");
    scanf("%d", &reponse);
    if (essai == 1 && resultatordre == reponse) {
      score = 10;
      break;
    } else if (essai == 2 && resultatordre == reponse) {
      score = 5;
      break;
    } else if (essai == 3 && resultatordre == reponse) {
      score = 1;
      break;
    } else {
      printf("Mauvaise réponse, il vous reste %d essai(s)\n\n", 3 - essai);
    }
  }
  printf("Le résultat est %d\n\n", resultatordre);
  return score;
}
/*-----------------------------------------------------------------------------------------*/

/*Gestion du score ------------------------------------------------------------------------*/
void sauvegarde(int score, char nom[20]) {
  // Création d'une chaine de caractère du temps actuels
  // lire l'heure courante
  time_t temps = time(NULL);
  // la convertir en heure locale
  struct tm Heure_actuelle = *localtime(&temps);
  // Creer une chaine JJ/MM/AAAA HH:MM:SS
  char tempsformate[sizeof "JJ/MM/AAAA HH:MM:SS"];
  strftime(tempsformate, sizeof tempsformate, "%d/%m/%Y %H:%M:%S",
           &Heure_actuelle);

  // Variables
  char nomf[max_nom]; // Chaine pour comparer avec le nom saisie
  int ecrire = 0; // Variable pour savoir si l'utilisateur est nouveau ou non

  // On ouvre le fichier pour savoir si l'utilisateur est nouveau ou non
  FILE *f = fopen("score.txt", "r+");
  if (f == NULL) {
    printf("Impossible d'ouvrir le fichier.\n");
    exit(1);
  }
  // Tant que le fichier n'est pas fini
  while (fscanf(f, "%s", nomf) != EOF) {
    // On compare les deux chaines de caractère
    if (strcmp(nomf, nom) == 0) {
      // On actualise le score si l'utilisateur est déjà enregistré
      fprintf(f, "\t\t\t\t%d\t\t\t\t%s\n", score, tempsformate);
      ecrire = 1;
      break;
    }
  }
  fclose(f);
  // Si l'utilisateur n'est pas déjà enregistré
  if (ecrire == 0) {
    nouvel_utilisateur(score, nom, tempsformate);
  }
}

// La fonction ajoute un nouvel utilisateur et ajoute la première ligne de
// description
void nouvel_utilisateur(int score, char nom[20],
                        char tempsformate[sizeof "JJ/MM/AAAA HH:MM:SS"]) {
  // Variables
  char nomf[max_nom];
  // On écrie à la fin du fichier
  FILE *f = fopen("score.txt", "a");
  if (f == NULL) {
    printf("Impossible d'ouvrir le fichier.\n");
    exit(1);
  }
  // On vérifie que le fichier n'est pas vide
  fseek(f, 0, SEEK_END);  // Se place à la fin du fichier
  long taille = ftell(f); // Récupère la position (taille du fichier)
  if (taille == 0) {
    // Si le fichier est vide, on ajoute la première ligne de description
    fprintf(f, "Nom\t\t\t\t\tScore\t\t\t\t\tHeure\n");
  }
  // On ajoute le nouvel utilisateur
  fprintf(f, "%s\t\t\t\t%d\t\t\t\t%s\n", nom, score, tempsformate);
  fclose(f);
}

// La fonction récupère le score de l'utilisateur
int recup_score(char nom[max_nom]) {
  // On crée un fichier si il n'existe pas pour éviter d'ouvrir un fichier inexistant en mode read
  FILE *f1 = fopen("score.txt", "a");
  fclose(f1);
  // Variables
  int scoref, score = 0;
  char nomf[max_nom];

  // On ouvre le fichier
  FILE *f = fopen("score.txt", "r");
  // On verifie que le fichier existe
  if (f == NULL) {
    fclose(f);
  }
  // Tant que le fichier n'est pas fini
  while (fscanf(f, "%s\t\t\t\t\t\t%d", nomf, &scoref) != EOF) {
    // On vérifie que les noms sont identiques
    if (strcmp(nomf, nom) == 0) {
      score = scoref;
      break;
    }
  }
  fclose(f);
  printf("Votre score est de %d\n\n", score);
  return score;
}
/*-----------------------------------------------------------------------------------------*/