#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

bool only_digits(string s);

int main(int argc, string argv[]) {
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    while (*plaintext != '\0') {
        if (isupper(*plaintext)) {
            printf("%c", (*plaintext - 'A' + key) % 26 + 'A');
        }
        else if (islower(*plaintext)) {
            printf("%c", (*plaintext - 'a' + key) % 26 + 'a');
        }
        else {
            printf("%c", *plaintext);
        }
        
        ++plaintext;
    }
    printf("\n");

    return 0;
}

bool only_digits(string s) {
    while (*s != '\0') {
        if (!isdigit(*s)) {
            return false;
        }

        ++s;
    }
    return true;
}
