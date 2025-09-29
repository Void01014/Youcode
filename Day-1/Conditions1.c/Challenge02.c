#include <stdio.h>

int main(){

    char let;
    printf("Enter a letter: ");
    scanf("%c", &let);
    if (let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u' || let == 'y') {
        printf("%c is a vowel.\n", let);
    } else {
        printf("%c is a consonant.\n", let);
    }
    return 0;
}