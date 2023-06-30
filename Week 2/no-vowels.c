// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <cs50.h>

string replace(string s);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string converted_word = replace(argv[1]);

    printf("%s\n", converted_word);
}

string replace(string s) {
    string head = s;

    while (*s != '\0') {
        switch (*s) {
            case 'a':
                *s = '6';
                break;
            case 'e':
                *s = '3';
                break;
            case 'i':
                *s = '1';
                break;
            case 'o':
                *s = '0';
                break;
        }

        ++s;
    }

    return head;
}