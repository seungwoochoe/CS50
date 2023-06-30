#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

#define INSIDE_WORD 0
#define OUTSIDE_WORD 1

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_index(int letters_count, int words_count, int sentences_count);

int main(void) {
    string text = get_string("Text: ");
    
    int index = compute_index(count_letters(text), count_words(text), count_sentences(text));

    if (index >= 16) {
        printf("Grade 16+\n");
    }
    else if (index < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %d\n", index);
    }

    return 0;
}

int count_letters(string text) {
    int count = 0;

    while (*text != '\0') {
        if (isalpha(*text)) {
            ++count;
        }
        ++text;
    }

    return count;
}

int count_words(string text) {
    int count = 0;
    int state = OUTSIDE_WORD;

    while (*text != '\0') {
        if (state == OUTSIDE_WORD && isalpha(*text)) {
            state = INSIDE_WORD;
            ++count;
        }
        else if (state == INSIDE_WORD && *text == ' ') {
            state = OUTSIDE_WORD;
        }

        ++text;
    }

    return count;
}

int count_sentences(string text) {
    int count = 0;

    while (*text != '\0') {
        if (*text == '.' || *text == '?' || *text == '!') {
            ++count;
        }
        
        ++text;
    }

    return count;
}

int compute_index(int letters_count, int words_count, int sentences_count) {
    return round(0.0588 * ((double)letters_count * 100 / words_count) - 0.296 * ((double)sentences_count * 100 / words_count) - 15.8);
}