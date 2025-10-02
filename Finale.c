#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct Animal
{
    int ID;
    char nom[40];
    char espece[40];
    int age;
    char habitat[40];
    float poids;
    int pop;
};

struct Animal animal[200]= {{0, "Rex", "Lion", 5, "Savane", 190.85, 20},
                            {1, "Nala", "Tigre" , 4, "Jungle", 220.20, 19},
                            {2, "Tony", "Lion", 6, "Savane", 180.27, 15},
                            {3, "Flocon", "Serpent", 3, "Jungle", 61.40, 1},
                            {4, "Nemo", "Poisson Clown", 1, "Aquatique", 0.25, 8},
                            {5, "Donkey", "singe", 2, "Jungle", 33.00, 0},
                            {6, "Bob", "Ours Polaire", 8, "Arctique", 449.99, 0},
                            {7, "Geoffrey", "Girafe", 7, "Savane",803.50, 0},
                            {8, "Melman", "Girafe", 7, "Savane", 764.10, 4},
                            {9, "Ping", "Pingouin", 2, "Aquatique",32.50, 4},
                            {10, "Nola", "Renard", 4, "Jungle", 15.30, 21},
                            {11, "koko", "Gorille", 7, "Jungle", 150.70, 0},
                            {12, "Speedy", "Tortue", 70, "Aquatique", 100.25, 0},
                            {13, "Dumbo", "Elephant", 23, "Savane", 5400.10, 7},
                            {14, "Sunny", "Lezard", 1, "Desert", 0.70, 0},
                            {15, "Rocky", "Chameau", 13, "Desert", 557.30, 5},
                            {16, "Bongo", "Zebre", 5, "Savane", 350.30, 0},
                            {17, "Splash", "Dauphin", 9, "Aquatique", 15.30, 5},
                            {18, "Blizzard", "Loop Arctique", 7, "Arctique", 75.00, 19},
                            {19, "Sonic", "Herisson", 3, "Jungle", 35.30, 21},
                           };


void eliminer_n_ligne(char x[]){
    x[strcspn(x, "\n")] = 0;
}

void verifier_et_remplire_str(char y[]){         //Cette loop se répète jusqu'à l'utilisateur saisie un list de caractère (alphabet), et sauvgarde ce string dans une varaible nommée verf_str
    int check = 0;              //
    eliminer_n_ligne(y);
    while (check == 0){
        check = 1;
        for (int i = 0; i < strlen(y); i++){
            if (!isalpha(y[i]))
            {
                check = 0;
                break;
            }
        }
        if (check == 0){
            printf("Votre derniere saisie est incorrecte. Veuillez taper une chaine de caracteres: ");
            fgets(y, 40, stdin);
            eliminer_n_ligne(y);
        }
    }
}

float verifier_et_remplire_digit(){             //Cette loop se répète jusqu'à l'utilisateur saisie un digit, et retourn ce nombre
    int check = 0;
    float z;

    while (check == 0){
        check = 1;
        if (scanf("%f", &z) != 1 || z <= 0){
            check = 0;
            printf("Votre derniere saisie est incorrecte. Veuillez taper un nombre entier: ");   
            while (getchar() != '\n');          //Pour vider le "Buffer"
        }
    }
    return z;
}

void afficher_animal(struct Animal a){
    printf("ID : %d\n", a.ID);
    printf("Nom : %s\n", a.nom);
    printf("Espece : %s\n", a.espece);
    printf("Age : %d\n", a.age);
    printf("Habitat : %s\n", a.habitat);
    printf("Poids : %.2f\n", a.poids);
    printf("Popularite : %d\n", a.pop);
}

void rechercher_nom(int num_anim, char nom_ch[]){          //recherche linéaire
    int trouve = 0;

    for (int i = 0; i < num_anim; i++){
        if (stricmp(animal[i].nom, nom_ch) == 0)        
        {
            trouve = 1;
            printf("\n-------------------------\n");
            afficher_animal(animal[i]);
            printf("\n-------------------------\n");
            animal[i].pop++; 
            break;
        }
    }
    if (!trouve){
        printf("\nDesole, cet animal n'existent pas dans notre zoo.\n");
    }
}

int rechercher_nom_cache(int num_anim, char nom_ch[]){          //recherche linéaire
    int trouve = 0;

    for (int i = 0; i < num_anim; i++){
        if (stricmp(animal[i].nom, nom_ch) == 0)        
        {
            trouve = 1;
            animal[i].pop++; 
            return i;
        }
    }
    if (!trouve){
        printf("\nDesole, cet animal n'existent pas dans notre zoo.\n");
        return -1;
    }
}

void  rechercher_espece(int num_anim, char esp_ch[]){   //recherche linéaire
    int trouve = 0;
    for (int i = 0; i < num_anim; i++){
        if (stricmp(animal[i].espece, esp_ch) == 0){
            trouve = 1;
            printf("\n-------------------------\n");
            afficher_animal(animal[i]);
            printf("\n-------------------------\n");
            animal[i].pop++;       
        }
    }
    if (!trouve)
    {
        printf("\nDesole, cet espece n'existent pas dans notre zoo.\n");
    }   
}

int jeune(struct Animal animal[], int num){                        //Retourne l'index de l'animal le plu petit
    int youngest_ind = 0;
    for (int i = 0; i<num; i++){
        if(animal[i].age < animal[youngest_ind].age){
            youngest_ind = i;
        }
    }
    return youngest_ind;
}

int vielle(struct Animal animal[], int num){                       //Retourne l'index de l'animal le plu grand
    int oldest_ind = 0;
    for (int i = 0; i<num; i++){
        if(animal[i].age > animal[oldest_ind].age){
            oldest_ind = i;
        }
    }
    return oldest_ind;
}

int main() {
    
    int num_anim = 20;
    int choix, choix_2, choix_3;
    int tri[200];

    while (1){
        printf("======================================================\n");
        printf("||              ZZZZZZ   OOOOO    OOOOO             ||\n");
        printf("||                 Z    O     O  O     O            ||\n");
        printf("||                Z     O     O  O     O            ||\n");
        printf("||               Z      O     O  O     O            ||\n");
        printf("||              ZZZZZZ   OOOOO    OOOOO             ||\n");
        printf("||                                                  ||\n");
        printf("||                                                  ||\n");
        printf("||                  ZOO MANAGER APP                 ||\n");
        printf("||                                                  ||\n");
        printf("||                   1.[Ajouter]                    ||\n");
        printf("||                   2.[Afficher]                   ||\n");
        printf("||                   3.[Modifier]                   ||\n");
        printf("||                   4.[Supprimer]                  ||\n");
        printf("||                   5.[Rechercher]                 ||\n");
        printf("||                   6.[Statistiques]               ||\n");
        printf("||                   7.[Quitter]                    ||\n");
        printf("||                                                  ||\n");
        printf("======================================================\n");
        scanf("%d", &choix);
        getchar();


        switch (choix)
        {
            case 1:
            {
                int num_ajout;

                printf("combien d'animaux souhaitez-vous ajouter? : ");
                num_ajout = verifier_et_remplire_digit();
                getchar();              //Eliminer \n
                while (num_ajout > 0)
                {
                    char verf_str[40];    //Permet de sauvegarder seulement la saisie "correct" de l'utilisateur, et j'ai utilisé cette variable temporelle parce que les fonctions ne peuvent pas retourner des "strings" (NB: il est possible mais plus avancé)
                    //Ajouter nom
                    printf("Entrez le nom de l'animal que vous souhaitez ajouter: ");
                    fgets(verf_str, sizeof(verf_str), stdin);           
                    verifier_et_remplire_str(verf_str);
                    strcpy(animal[num_anim].nom, verf_str);
                    eliminer_n_ligne(animal[num_anim].nom);  
                    //Ajouter espece 
                    printf("Entrez l'espece de l'animal que vous souhaitez ajouter: ");
                    fgets(verf_str, sizeof(verf_str), stdin);           
                    verifier_et_remplire_str(verf_str);  
                    strcpy(animal[num_anim].espece, verf_str);     
                    eliminer_n_ligne(animal[num_anim].espece);   
                    //Ajouter age
                    printf("Entrez l'age de l'animal que vous souhaitez ajouter: ");
                    animal[num_anim].age = (int)verifier_et_remplire_digit();
                    getchar();
                    //Ajouter habitat
                    printf("Entrez l'Habitat de l'animal que vous souhaitez ajouter: ");
                    printf("\n1.Savane \n2.Jungle \n3.Aquatique \n4.Arctique \n5.Desert\n");
                    
                    //cette loop a pour but assurer que l'utilisateur saisira correctement une valeur entre 1-5
                    while (1)
                    {
                        int choix_2 = (int)verifier_et_remplire_digit();
                        getchar();
                        if (choix_2< 1 || choix_2 > 5){
                            printf("Votre dernier saisie est incorrect. Veuillez taper un nombre entier entre 1-5: ");
                            continue;
                        }
                        break;
                    }
                    switch (choix_2)
                    {
                    case 1:
                        strcpy(animal[num_anim].habitat, "Savane");
                        break;
                    case 2:
                        strcpy(animal[num_anim].habitat, "Jungle");
                        break;
                    case 3:
                        strcpy(animal[num_anim].habitat, "Aquatique");
                        break;
                    case 4:
                        strcpy(animal[num_anim].habitat, "Arctique");
                        break;
                    case 5:
                        strcpy(animal[num_anim].habitat, "Desert");
                        break;
                    }   
                    //Ajouter poids
                    printf("Entrez le poids de l'animal que vous souhaitez ajouter: ");
                    animal[num_anim].poids = verifier_et_remplire_digit();  
                    getchar();

                    printf("%s a ete ajoute avec succes\n", animal[num_anim].nom);      
                    num_anim++;
                    num_ajout--;
                }
                break;
            }
            case 2:
            {
                printf("Vouillez choisir l'un de ces choix: ");
                printf("\n1.Afficher la liste complete");
                printf("\n2.Trier par nom");
                printf("\n3.Trier par age");
                printf("\n4.Afficher uniquement les animaux d'un habitat specifique\n");
                //cette loop a pour but assurer que l'utilisateur saisira correctement une valeur entre 1-4
                while (1)
                {
                    choix_2 = (int)verifier_et_remplire_digit();
                    getchar();
                    if (choix_2< 1 || choix_2 > 4){
                        printf("Votre derniere saisie est incorrect. Veuillez taper un nombre entier entre 1-4: ");
                        continue;
                    }
                    break;
                }
                switch (choix_2)
                {
                    case 1:
                        for (int i = 0; i < num_anim; i++)
                        {
                            printf("\n-------------------------\n");
                            afficher_animal(animal[i]);
                            printf("\n-------------------------\n");
                        }
                        
                        break;
                    case 2:
                        
                        break;
                    case 3:
                        
                        break;
                    case 4:
                        
                        break;
                }
                break;
            }
            case 3:
            {
                int temp_index;
                char verf_str[40];
                int n_age = 0;

                printf("Vouillez entrez le nom de l'animal que vous shouhaitez modifier: ");
                fgets(verf_str, sizeof(verf_str), stdin);
                verifier_et_remplire_str(verf_str);
                eliminer_n_ligne(verf_str);
                temp_index = rechercher_nom_cache(num_anim, verf_str);
                if (temp_index >= 0){
                    printf("Vouillez Choisir le type de modification: ");
                    printf("\n1.Modifier l'habitat");
                    printf("\n2.Modifier l'age\n");
                    //cette loop a pour but assurer que l'utilisateur saisira correctement une valeur entre 1-2
                    while (1)
                    {
                        choix_2 = verifier_et_remplire_digit();
                        getchar();
                        if (choix_2< 1 || choix_2 > 2){
                            printf("Votre dernier saisie est incorrect. Veuillez taper un nombre entier entre 1-2: ");
                            continue;
                        }
                        break;
                    }
                    switch (choix_2)
                    {
                        case 1:{       
                            printf("\nL'habitat actualle de %s est: %s\n", animal[temp_index].nom, animal[temp_index].habitat);
                            printf("Choisissez la nouvelle habitat: ");
                            printf("\n1.Savane \n2.Jungle \n3.Aquatique \n4.Arctique \n5.Desert\n");
                            
                            //cette loop a pour but assurer que l'utilisateur saisira correctement une valeur entre 1-5
                            while (1)
                            {
                                choix_3 = (int)verifier_et_remplire_digit();
                                getchar();
                                if (choix_3< 1 || choix_3 > 5){
                                    printf("Votre dernier saisie est incorrect. Veuillez taper un nombre entier entre 1-5: ");
                                    continue;
                                }
                                break;
                            }
                            switch (choix_3)
                            {
                            case 1:
                                strcpy(animal[temp_index].habitat, "Savane");
                                printf("modification a ete effectue avec succes, la nouvelle habitat de %s est 'Savane'\n", animal[temp_index].nom);
                                break;
                            case 2:
                                strcpy(animal[temp_index].habitat, "Jungle");
                                printf("modification a ete effectue avec succes, la nouvelle habitat de %s est 'Jungle'\n", animal[temp_index].nom);
                                break;
                            case 3:
                                strcpy(animal[temp_index].habitat, "Aquatique");
                                printf("modification a ete effectue avec succes, la nouvelle habitat de %s est 'Aquatique'\n", animal[temp_index].nom);
                                break;
                            case 4:
                                strcpy(animal[temp_index].habitat, "Arctique");
                                printf("modification a ete effectue avec succes, la nouvelle habitat de %s est 'Arctique'\n", animal[temp_index].nom);
                                break;
                            case 5:
                                strcpy(animal[temp_index].habitat, "Desert");
                                printf("modification a ete effectue avec succes, la nouvelle habitat de %s est 'Desert'\n", animal[temp_index].nom);
                                break;
                            }   
                            break;
                        }
                        case 2:{
                            printf("\nL'age actualle de %s est: %d\n", animal[temp_index].nom, animal[temp_index].age);
                            printf("Entrez le nouveau age: \n");
                            n_age = (int)verifier_et_remplire_digit();
                            getchar();
                            animal[temp_index].age = n_age;
                            printf("modification a ete effectue avec succes, le nouveau age de %s est %d\n", animal[temp_index].nom, animal[temp_index].age);
                            break;
                        }
                    }
                }
                break;   
            }
            case 4:
            {
                int temp_index;
                int error = 0;

                printf("\nVouillez entrez l'ID de l'animal que vous shouhaitez supprimer: \n");
                printf("Voici Les ID des animeaux:\n");
                for (int j = 0; j < num_anim; j++){
                    printf("\n%s : %d\n", animal[j].nom, animal[j].ID);
                }
                temp_index = verifier_et_remplire_digit();
                getchar();
                for (int i = temp_index; i < num_anim; i++){
                    animal[i] = animal[i+1];
                    
                }

                //Verifions si l'operation a ete effectué avec succès
                for (int f = 0; f < num_anim - 1; f++)
                {
                    if (animal[f].ID == temp_index)
                    {
                        printf("Operation echouee");
                        error = 1;
                    }
                    
                }
                if (error == 0)
                {
                    printf("\nmodification a ete effectue avec succes\n");
                }
                
                
                num_anim --;
                break;
            }
            case 5:
            {
                printf("Vouillez choisir l'un de ces choix: ");
                printf("\n1.Rechercher par ID");
                printf("\n2.Rechercher par nom");
                printf("\n3.Rechercher par espece\n");
                //cette loop a pour but assurer que l'utilisateur saisira correctement une valeur entre 1-3
                while (1)
                {
                    choix_2 = (int)verifier_et_remplire_digit();
                    getchar();
                    if (choix_2< 1 || choix_2 > 3){
                        printf("Votre derniere saisie est incorrect. Veuillez taper un nombre entier entre 1-3: ");
                        continue;
                    }
                    break;
                }
                switch (choix_2)
                {
                    case 1:
                        int temp;           //"temp" permet de resutiliser la valeur retourner par la fonction (dans la ligne '292') 
                        printf("Vouillez entrer l'ID de l'animal que vous souhaitez chercher: ");
                        temp = verifier_et_remplire_digit();
                        getchar();
                        if (temp >= num_anim){
                            printf("\nDesole, cet animal n'existent pas dans notre zoo.\n");
                        }else{
                            printf("\n-------------------------\n");
                            afficher_animal(animal[temp]);
                            printf("\n-------------------------\n");
                            animal[temp].pop++;               //Augemente la popularitée 
                        }
                        break;
                    case 2:
                        char verf_str[40];      //nous permet de sauvegarder seulemet la saisie "correct" de l'utilisateur, et j'ai utilisé cette variable temporelle parce que les fonctions ne peuvent pas retourner des "strings" (NB: il est possible mais plus avancé)

                        printf("Vouiller entrer le nom de l'animal que vous shouhaitez chercher: ");
                        fgets(verf_str, sizeof(verf_str), stdin);
                        verifier_et_remplire_str(verf_str); 
                        eliminer_n_ligne(verf_str);
                        rechercher_nom(num_anim, verf_str);
                        break;
                    case 3:
                        printf("Entrez l'espece des animeaux que vous souhaitez chercher: ");
                        fgets(verf_str, sizeof(verf_str), stdin);
                        verifier_et_remplire_str(verf_str);
                        eliminer_n_ligne(verf_str);
                        rechercher_espece(num_anim, verf_str);
                        break;
                } 
                break;
            }  
            case 6:
            {
                int choix_2;
                printf("Vouillez choisir l'un de ces choix: ");
                printf("\n1.Afficher le nombre total d'animaux dans le zoo");
                printf("\n2.Calculer et afficher l'age moyen des animaux");
                printf("\n3.Afficher le plus vieux et le plus jeune animal");
                printf("\n4.Afficher les especes les plus representees\n");
                choix_2 = verifier_et_remplire_digit();
                getchar();
                switch (choix_2)
                {
                case 1:
                    printf("\nLe nombre totale des animeaux dans notre Zoo est : %d\n", num_anim);
                    break;                
                case 2:
                    float temp = 0;
                    for (int  i = 0; i < num_anim; i++)
                    {
                        temp += animal[i].age;
                    }                    
                    temp /= num_anim;
                    printf("%f", temp);
                    break;
                case 3:
                    printf("La person la plus petite est: \n");
                    printf("\n-------------------------\n");
                    afficher_animal(animal[jeune(animal,20)]);
                    printf("\n-------------------------\n");
                    printf("La person la plus grande est: \n");
                    printf("\n-------------------------\n");
                    afficher_animal(animal[vielle(animal,20)]);
                    printf("\n-------------------------\n");
                    break;
                case 4:
                    int p_grand = animal[0].pop;
                    for (int i = 0; i < num_anim; i++){                 //Cette boucle trouve la valeur la plus grande de popularité
                        if (animal[i].pop > p_grand){
                            p_grand = animal[i].pop;
                        } 
                    }
                    printf("\nle plus grand %d\n", p_grand);

                    printf("Les especes les plus présentées sont: \n"); 

                    for (int j = 0; j < num_anim; j++){                 //Cette boucle mais en concideration que plusieurs espèce peut avoir la même popularité
                        if (p_grand == animal[j].pop)
                            printf("\n%s",animal[j].espece);
                    }
                    break;
                }
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                printf("L'option que vous avez choisis est incorrect, s'il vous plait, entrez une valeur entre 1-6\n");
            }
        }
    }
}
