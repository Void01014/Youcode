#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char lastName[50];
    int age;
} Person;

int start, finish; 
int get(Person people[]){

}

int main() {
    Person people[50] = {
        {"Alice", "Smith", 25},
        {"Bob", "Johnson", 30},
        {"Charlie", "Williams", 22},
        {"David", "Brown", 28},
        {"Eve", "Jones", 24},
        {"Frank", "Garcia", 27},
        {"Grace", "Martinez", 45},
        {"Alice", "Martinez", 18},    // same first name as Alice Smith
        {"Bob", "Smith", 67},         // same first name as Bob Johnson
        {"Hannah", "Smith", 23},      // shares last name "Smith"
        {"Ian", "Johnson", 29},       // shares last name "Johnson"
        {"Julia", "Martinez", 21} 
        };
    
        int start;
        int finish;
        printf("\nEntrez le point de depart: ");
        scanf("%d", &start);
        printf("\nEntrez le point finale: ");
        scanf("%d", &finish);


        
    return 0;
}