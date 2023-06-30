#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

#define THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET 26

int length(string s);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (length(argv[1]) != THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];

    string a = key;
    for (int i = 0; i < THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET; i++) {
        if (!isalpha(a[i])) {
            printf("Found an invalid character.\n");
            return 1;
        }
        if (isupper(a[i])) {
            a[i] = tolower(a[i]);
        }
    }

    string b = a;

    for (int i = 0; i < THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET; i++) {
        for (int j = i + 1; j < THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET; j++) {
            if (a[i] == b[j]) {
                printf("Characters should be unique.\n");
                return 1;
            }
        }
    }
    
    for (string a = key; *a != '\0'; ++a) {
        if (isupper(*a)) {
            *a = tolower(*a);
        }
        for (string b = key; *b != '\0'; ++b) {

        }
    }


    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    while (*plaintext != '\0') {
        if (isupper(*plaintext)) {
            printf("%c", toupper(key[*plaintext - 'A']));
        }
        else if (islower(*plaintext)) {
            printf("%c", tolower(key[*plaintext - 'a']));
        }
        else {
            printf("%c", *plaintext);
        }

        ++plaintext;
    }
    printf("\n");

    return 0;
}

int length(string s) {
    int length = 0;

    while (*s != '\0') {
        ++length;
        ++s;
    }

    return length;
}