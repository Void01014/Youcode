#include<stdio.h>
#include<string.h>

struct contact
{
    char nom[50];
    char email[50];
    char numero[50];
};

//variables globale:
struct contact cont[50];
char a_rechercher[50];     //Permet de chercher un nom entrer par l'utilisateur
int trouve;                //Indique si le contact a ete trouvé ou pas 
int index_de_nom;          //Nous donne l'indice du contact trouvé pour modifier ses données

int rechercher(int num_contact, char nom_ch[]){
    trouve = 0;

    for (int i = 0; i < num_contact; i++){
        if (strcmp(cont[i].nom, nom_ch) == 0)
        {
            trouve = 1;
            index_de_nom = i;
            break;
        }
    }
    if (!trouve){
        printf("Ce contact est inexistant.\n");
    }
    return index_de_nom;
}

int main()
{
    int num_contact = 0;
    int choix;

    while(1)
    {

        printf("1.Ajouter un contact.\n");
        printf("2.Modifier un Contact.\n");
        printf("3.Supprimer un Contact.\n");
        printf("4.Afficher Tous les Contacts.\n");
        printf("5.Rechercher un Contact.\n");
        printf("6.Quitter\n");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
            case 1:
            {
                printf("Entrez le nom du contact: ");
                fgets(cont[num_contact].nom, sizeof(cont[num_contact]), stdin);
                cont[num_contact].nom[strcspn(cont[num_contact].nom, "\n")] = 0;         //Eliminer '\n'
                printf("Entrez l'email du contact: ");
                fgets(cont[num_contact].email, sizeof(cont[num_contact].email), stdin);
                cont[num_contact].email[strcspn(cont[num_contact].email, "\n")] = 0;     //Eliminer '\n'
                printf("Entrez le numero de telephone du contact: ");
                fgets(cont[num_contact].numero, sizeof(cont[num_contact].numero), stdin);
                cont[num_contact].numero[strcspn(cont[num_contact].numero, "\n")] = 0;   //Eliminer '\n'
                printf("Le conatct a ete ajoute avec succes\n");
                num_contact++;
                break;
            }
            case 2:
            {
                int choix_2 = 0;
                do{
                    printf("Entrez le nom du contact que vous souhaiter chercher: \n");
                    scanf("%s", a_rechercher);
                    rechercher(num_contact, a_rechercher);
                }while(!trouve);

                printf("Si vous voulez changer l'email, entrez '1'\n");
                printf("Si vous voulez changer le numero de telephone, entrez '2'\n");
                printf("Si vous voulez changer l'email et le numero de telephone, entrez '3'\n");
                scanf("%d", &choix_2);
                switch (choix_2)
                {
                case 1:
                    printf("\nEntrez le nouveau email: ");
                    scanf("%s", cont[index_de_nom].email);
                    printf("Les données ont été modifiées avec succès");
                    break;
                
                case 2:
                    printf("\nEntrez le nouveau numero de telephone: ");
                    scanf("%s", cont[index_de_nom].numero);
                    printf("Les données ont été modifiées avec succès");
                    break;
                
                case 3:
                    printf("\nEntrez le nouveau email:");
                    scanf("%s", cont[index_de_nom].email);
                    printf("\nEntrez le nouveau numero de telephone: ");
                    scanf("%s", cont[index_de_nom].numero);
                    printf("Les données ont été modifiées avec succès");
                    break;
                default:
                    printf("Entrez un nombre enter 1-3");
                    break;
                }
                break;
            }
            case 3:
            {
                printf("Entrez le nom du contact que vous souhaitez supprimer");
                fgets(a_rechercher, sizeof(a_rechercher), stdin);
                a_rechercher[strcspn(a_rechercher, "\n")] = 0;
                rechercher(num_contact, a_rechercher);
                for (int i = index_de_nom; i <num_contact - 1; i++){
                    cont[i] = cont[i + 1];
                }
                num_contact --;
                break;
            }
            case 4:
            {
                for (int i = 0; i < num_contact; i++) {
                    printf(" %s\n", cont[i].nom);
                    printf(" %s\n", cont[i].numero);
                    printf(" %s\n", cont[i].email);
                }

                break;
            }
            case 5:
            {
                printf("Entrez le nom du contact: ");
                fgets(a_rechercher, sizeof(a_rechercher), stdin);
                a_rechercher[strcspn(a_rechercher, "\n")] = 0;
                rechercher(num_contact, a_rechercher);
                printf("Nom : %s\n", cont[index_de_nom].nom);
                printf("numero: %s\n", cont[index_de_nom].numero);
                printf("email: %s\n", cont[index_de_nom].email);
                break;
            }
            case 6:
                printf("le programme a ete ferme avec succes");
                return 0;
            }
    }
                
}