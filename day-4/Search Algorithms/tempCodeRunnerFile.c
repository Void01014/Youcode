#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char lastName[50];
    int age;
} Person;

int youngest(Person p[], int num){
    int youngest_ind = 0;
    for (int i = 0; i<num; i++){
        if(p[i].age < p[youngest_ind].age){
            youngest_ind = i;
        }
    }
    return youngest_ind;
}
int oldest(Person p[], int num){
    int oldest_ind = 0;
    for (int i = 0; i<num; i++){
        if(p[i].age < p[oldest_ind].age){
            oldest_ind = i;
        }
    }
    return oldest_ind;
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
    
    
    printf("La person la plus petite est: %s", youngest(people, 10));
    printf("La person la plus grande est: %s", oldest(people, 10));

    return 0;
}