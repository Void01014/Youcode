#include <stdio.h>

int main() {
    // Challenge 1: Évaluation d'un Prêt
    float revenu;
    int scoreCredit;
    int dureePret;

    printf("Challenge 1: Évaluation d'un Prêt\n");
    printf("Revenu annuel (en euros): ");
    scanf("%f", &revenu);
    printf("Score de crédit (sur 1000): ");
    scanf("%d", &scoreCredit);
    printf("Durée du prêt (en années): ");
    scanf("%d", &dureePret);

    if (revenu >= 30000 && scoreCredit >= 700 && dureePret <= 10) {
        printf("Éligible\n");
    } else if (revenu >= 30000 && scoreCredit >= 650 && dureePret <= 15) {
        printf("Éligible avec conditions\n");
    } else {
        printf("Non éligible\n");
    }

    // Challenge 2: Calcul de Prime d'Assurance Auto
    int ageConducteur;
    int typeVoiture;
    int nbAccidents;
    float primeBase = 1000.0; // Exemple de prime de base
    float prime = primeBase;

    printf("\nChallenge 2: Calcul de Prime d'Assurance Auto\n");
    printf("Âge du conducteur (en années): ");
    scanf("%d", &ageConducteur);
    printf("Type de voiture (1 pour sportive, 2 pour utilitaire, 3 pour familiale): ");
    scanf("%d", &typeVoiture);
    printf("Nombre d'accidents au cours des 5 dernières années: ");
    scanf("%d", &nbAccidents);

    if (ageConducteur < 25) {
        prime *= 1.5;
    } else if (ageConducteur > 65) {
        prime *= 1.2;
    }

    if (typeVoiture == 1) {
        prime *= 2;
    } else if (typeVoiture == 2) {
        prime *= 1.2;
    } else if (typeVoiture == 3) {
        prime *= 1.1;
    }

    if (nbAccidents > 1) {
        prime *= 1.3;
    }

    printf("Prime d'assurance: %.2f euros\n", prime);

    // Challenge 3: Gestion des Congés
    int joursAccordes;
    int joursUtilises;
    int statutEmploye;

    printf("\nChallenge 3: Gestion des Congés\n");
    printf("Nombre total de jours de congés accordés: ");
    scanf("%d", &joursAccordes);
    printf("Nombre de jours de congés utilisés: ");
    scanf("%d", &joursUtilises);
    printf("Statut de l'employé (0 pour temps partiel, 1 pour temps plein): ");
    scanf("%d", &statutEmploye);

    int joursRestants;
    if (statutEmploye == 1) {
        joursRestants = joursAccordes - joursUtilises;
    } else {
        joursRestants = (joursAccordes / 2) - joursUtilises;
    }

    if (joursUtilises > joursAccordes) {
        printf("Alerte: Jours utilisés dépassent les jours accordés!\n");
    } else {
        printf("Jours de congé restants: %d\n", joursRestants);
    }

    // Challenge 4: Évaluation de Performance d'Employé
    int scorePerformance;
    int anciennete;
    int recompenses;

    printf("\nChallenge 4: Évaluation de Performance d'Employé\n");
    printf("Score de performance (de 0 à 100): ");
    scanf("%d", &scorePerformance);
    printf("Ancienneté (en années): ");
    scanf("%d", &anciennete);
    printf("Récompenses reçues (0 pour aucune, 1 pour une, 2 pour deux ou plus): ");
    scanf("%d", &recompenses);

    float bonus = 0.0;
    if (recompenses == 1) {
        bonus = 0.1;
    } else if (recompenses >= 2) {
        bonus = 0.2;
    }

    if (scorePerformance >= 90 && anciennete >= 5) {
        printf("Évaluation: Excellente\n");
    } else if (scorePerformance >= 75 && anciennete >= 3) {
        printf("Évaluation: Bonne\n");
    } else if (scorePerformance >= 50 && anciennete < 3) {
        printf("Évaluation: Satisfaisante\n");
    } else {
        printf("Évaluation: Insuffisante\n");
    }

    if (bonus > 0) {
        printf("Bonus ajouté: %.0f%%\n", bonus * 100);
    }

    // Challenge 5: Planification de Voyage
    float budget;
    int destination;
    int nbPersonnes;

    printf("\nChallenge 5: Planification de Voyage\n");
    printf("Budget (en euros): ");
    scanf("%f", &budget);
    printf("Destination (1 pour plage, 2 pour montagne, 3 pour ville): ");
    scanf("%d", &destination);
    printf("Nombre de personnes: ");
    scanf("%d", &nbPersonnes);

    printf("Recommandation de voyage: ");
    if (budget >= 1000) {
        printf("Voyage haut de gamme, ");
    } else if (budget >= 500) {
        printf("Voyage moyen, ");
    } else {
        printf("Voyage économique, ");
    }

    if (destination == 1 && budget >= 1000 && nbPersonnes > 2) {
        printf("Destination: Plage\n");
    } else if (destination == 2 && budget >= 500 && nbPersonnes <= 2) {
        printf("Destination: Montagne\n");
    } else {
        printf("Destination: Ville\n");
    }
    
    // Challenge 6: Calcul de la Facture d'Électricité
    float consommation;
    int typeUtilisateur;
    int typeContrat;

    printf("\nChallenge 6: Calcul de la Facture d'Électricité\n");
    printf("Consommation d'électricité (en kWh): ");
    scanf("%f", &consommation);
    printf("Type d'utilisateur (1 pour résidentiel, 2 pour commercial): ");
    scanf("%d", &typeUtilisateur);
    printf("Type de contrat (0 pour standard, 1 pour réduit): ");
    scanf("%d", &typeContrat);

    float tarif;
    if (typeUtilisateur == 1) {
        tarif = (typeContrat == 0) ? 0.20 : 0.15;
    } else {
        tarif = (typeContrat == 0) ? 0.30 : 0.25;
    }

    float facture = consommation * tarif;
    if (consommation > 500) {
        facture *= 1.1;
    }

    printf("Facture d'électricité: %.2f euros\n", facture);

    // Challenge 7: Calcul des Impôts
    float revenuAnnuel;
    int statutFiscal;
    float deductions;

    printf("\nChallenge 7: Calcul des Impôts\n");
    printf("Revenu annuel (en euros): ");
    scanf("%f", &revenuAnnuel);
    printf("Statut fiscal (1 pour célibataire, 2 pour marié, 3 pour chef de famille): ");
    scanf("%d", &statutFiscal);
    printf("Déductions (en euros): ");
    scanf("%f", &deductions);

    float revenuImposable = revenuAnnuel - deductions;
    float tauxImposition;

    if (revenuImposable <= 20000) {
        tauxImposition = 0.05;
    } else if (revenuImposable <= 50000) {
        tauxImposition = 0.10;
    } else {
        tauxImposition = 0.20;
    }

    if (statutFiscal == 1) {
        deductions += 1000;
    } else if (statutFiscal == 2) {
        deductions += 2000;
    } else if (statutFiscal == 3) {
        deductions += 3000;
    }

    revenuImposable = revenuAnnuel - deductions;
    float impots = revenuImposable * tauxImposition;

    printf("Impôts à payer: %.2f euros\n", impots);

    // Challenge 8: Plan de Santé
    int age;
    int historiqueMedical;
    int typeCouverture;

    printf("\nChallenge 8: Plan de Santé\n");
    printf("Âge: ");
    scanf("%d", &age);
    printf("Historique médical (0 pour aucun problème, 1 pour problème mineur, 2 pour problème majeur): ");
    scanf("%d", &historiqueMedical);
    printf("Type de couverture (1 pour de base, 2 pour étendue): ");
    scanf("%d", &typeCouverture);

    printf("Plan de santé recommandé: ");
    if (age < 30) {
        printf("Plan de base\n");
    } else if (historiqueMedical == 0) {
        printf("Plan de base\n");
    } else {
        printf("Plan étendu\n");
    }

    if (historiqueMedical == 2) {
        printf("Couverture supplémentaire pour problèmes majeurs recommandée\n");
    }

    // Challenge 9: Calcul du Salaire avec Primes
    float salaireBase;
    int heuresSupplementaires;
    int typePoste;

    printf("\nChallenge 9: Calcul du Salaire avec Primes\n");
    printf("Salaire de base (en euros): ");
    scanf("%f", &salaireBase);
    printf("Nombre d'heures supplémentaires: ");
    scanf("%d", &heuresSupplementaires);
    printf("Type de poste (1 pour junior, 2 pour senior): ");
    scanf("%d", &typePoste);

    float tauxHoraire = salaireBase / 160; // Supposons 160 heures par mois
    float salaireSupplementaire = heuresSupplementaires * (1.5 * tauxHoraire);
    float primePoste = (typePoste == 2) ? 0.2 * salaireBase : 0.1 * salaireBase;
    float salaireTotal = salaireBase + salaireSupplementaire + primePoste;

    printf("Salaire total: %.2f euros\n", salaireTotal);

    // Challenge 10: Plan de Retraite avec Épargne
    int ageRetraite;
    int anneesCotisation;
    float montantEpargne;

    printf("\nChallenge 10: Plan de Retraite avec Épargne\n");
    printf("Âge: ");
    scanf("%d", &ageRetraite);
    printf("Années de cotisation: ");
    scanf("%d", &anneesCotisation);
    printf("Montant total épargné (en euros): ");
    scanf("%f", &montantEpargne);

    printf("Plan de retraite: ");
    if (ageRetraite >= 65 && anneesCotisation >= 30 && montantEpargne >= 100000) {
        printf("Plan complet avec pension élevée\n");
    } else if (ageRetraite >= 65 && anneesCotisation >= 20 && montantEpargne >= 50000) {
        printf("Plan partiel avec pension moyenne\n");
    } else if (ageRetraite < 65) {
        printf("Plan épargne non encore disponible\n");
    }

    if (montantEpargne > 50000) {
        int tranches = (int)((montantEpargne - 50000) / 10000);
        float bonusRetraite = tranches * 0.05;
        printf("Bonus de retraite: %.0f%%\n", bonusRetraite * 100);
    }

    return 0;
}