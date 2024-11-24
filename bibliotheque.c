#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char titre[50];
    char auteur[50];
    char description[50];
    char utilisateur[50];
    float prix;
    char categorie[50];
    int disponible;
} Livre;

void ajouterLivre(Livre livres[], int *numLivres, char utilisateur[])
{
    if (*numLivres < 10)
    {
        Livre nouveauLivre;
        printf("Entrez le titre du livre : ");
        scanf(" %[^\n]s", nouveauLivre.titre);
        printf("Entrez l'auteur du livre : ");
        scanf(" %[^\n]s", nouveauLivre.auteur);
        printf("Entrez la description du livre : ");
        scanf(" %[^\n]s", nouveauLivre.description);
        printf("Entrez le nom d'utilisateur : ");
        scanf(" %[^\n]s", nouveauLivre.utilisateur);
        printf("Entrez le prix du livre : ");
        scanf("%f", &nouveauLivre.prix);
        printf("Entrez la catégorie du livre : ");
        scanf(" %[^\n]s", nouveauLivre.categorie);
        nouveauLivre.disponible = 1;
        nouveauLivre.id = *numLivres + 1;

        livres[*numLivres] = nouveauLivre;
        (*numLivres)++;
        printf("Livre ajouté avec succès.\n");
    }
    else
    {
        printf("La bibliothèque est pleine, impossible d'ajouter plus de livres.\n");
    }
}

void afficherLivres(Livre livres[], int numLivres)
{
    printf("Liste des livres :\n");
    printf("ID | Titre | Auteur | Description | Utilisateur | Prix | Catégorie | Disponibilité\n");
    for (int i = 0; i < numLivres; i++)
    {
        printf("%d | %s | %s | %s | %s | %.2f | %s | %s\n", livres[i].id, livres[i].titre, livres[i].auteur,
               livres[i].description, livres[i].utilisateur, livres[i].prix, livres[i].categorie,
               livres[i].disponible ? "Disponible" : "Non disponible");
    }
}

void rechercherLivre(Livre livres[], int numLivres)
{
    char recherche[10];
    printf("Entrez le titre ou l'auteur du livre à rechercher : ");
    scanf(" %[^\n]s", recherche);

    printf("Résultats de la recherche :\n");
    printf("ID | Titre | Auteur | Description | Utilisateur | Prix | Catégorie | Disponibilité\n");
    for (int i = 0; i < numLivres; i++)
    {
        if (strstr(livres[i].titre, recherche) != NULL || strstr(livres[i].auteur, recherche) != NULL)
        {
            printf("%d | %s | %s | %s | %s | %.2f | %s | %s\n", livres[i].id, livres[i].titre, livres[i].auteur,
                   livres[i].description, livres[i].utilisateur, livres[i].prix, livres[i].categorie,
                   livres[i].disponible ? "Disponible" : "Non disponible");
        }
    }
}

void trierParTitre(Livre livres[], int numLivres)
{
    for (int i = 0; i < numLivres - 1; i++)
    {
        for (int j = 0; j < numLivres - i - 1; j++)
        {
            if (strcmp(livres[j].titre, livres[j + 1].titre) > 0)
            {
                Livre temp = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temp;
            }
        }
    }
}

void trierParCategorie(Livre livres[], int numLivres)
{
    for (int i = 0; i < numLivres - 1; i++)
    {
        for (int j = 0; j < numLivres - i - 1; j++)
        {
            if (strcmp(livres[j].categorie, livres[j + 1].categorie) > 0)
            {
                Livre temp = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temp;
            }
        }
    }
}

void supprimerLivre(Livre livres[], int *numLivres, int id)
{
    int trouve = 0;
    for (int i = 0; i < *numLivres; i++)
    {
        if (livres[i].id == id)
        {
            trouve = 1;
            for (int j = i; j < *numLivres - 1; j++)
            {
                livres[j] = livres[j + 1];
            }
            (*numLivres)--;
            printf("Livre supprimé avec succès.\n");
            break;
        }
    }
    if (!trouve)
    {
        printf("Livre non trouvé avec cet ID.\n");
    }
}

void modifierLivre(Livre livres[], int numLivres, int id)
{
    int trouve = 0;
    for (int i = 0; i < numLivres; i++)
    {
        if (livres[i].id == id)
        {
            trouve = 1;
            printf("Entrez le nouveau titre du livre : ");
            scanf(" %[^\n]s", livres[i].titre);
            printf("Entrez le nouvel auteur du livre : ");
            scanf(" %[^\n]s", livres[i].auteur);
            printf("Entrez la nouvelle description du livre : ");
            scanf(" %[^\n]s", livres[i].description);
            printf("Entrez le nouveau prix du livre : ");
            scanf("%f", &livres[i].prix);
            printf("Entrez la nouvelle catégorie du livre : ");
            scanf(" %[^\n]s", livres[i].categorie);

            printf("Livre modifié avec succès.\n");
            break;
        }
    }
    if (!trouve)
    {
        printf("Livre non trouvé avec cet ID.\n");
    }
}

int main()
{
    Livre livres[10];
    int numLivres = 0;
    int choix;
    char nomUtilisateur[50];

    printf("Entrez votre nom : ");
    scanf(" %[^\n]s", nomUtilisateur);

    do
    {
        printf("\nMenu :\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher la liste des livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Trier les livres par titre\n");
        printf("5. Trier les livres par catégorie\n");
        printf("6. Modifier un livre\n");
        printf("7. Supprimer un livre\n");
        printf("8. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterLivre(livres, &numLivres, nomUtilisateur);
            break;
        case 2:
            afficherLivres(livres, numLivres);
            break;
        case 3:
            rechercherLivre(livres, numLivres);
            break;
        case 4:
            trierParTitre(livres, numLivres);
            printf("Livres triés par titre.\n");
            break;
        case 5:
            trierParCategorie(livres, numLivres);
            printf("Livres triés par catégorie.\n");
            break;
        case 6:
            printf("Entrez l'ID du livre à modifier : ");
            int idModification;
            scanf("%d", &idModification);

            modifierLivre(livres, numLivres, idModification);
            break;
        case 7:
            printf("Entrez l'ID du livre à supprimer : ");
            int idSuppression;
            scanf("%d", &idSuppression);

            supprimerLivre(livres, &numLivres, idSuppression);
            break;
        case 8:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}