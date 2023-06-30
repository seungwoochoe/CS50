#include <stdio.h>
#include <string.h>
#include <cs50.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void) {
    string message = get_string("Message: ");
    
    while (*message != '\0') {
        int array[BITS_IN_BYTE] = { 0 };

        int value = *message;
        int index = BITS_IN_BYTE - 1;
        while (value > 0) {
            if (value % 2 == 1) {
                array[index] = 1;
            }
            value /= 2;
            --index;
        }

        for (int i = 0; i < BITS_IN_BYTE; i++) {
            print_bulb(array[i]);
        }
        printf("\n");

        ++message;
    }

    return 0;
}

void print_bulb(int bit) {
    if (bit == 0) {
        // Dark emoji
        printf("\U000026AB");
    } else if (bit == 1) {
        // Light emoji
        printf("\U0001F7E1");
    }
}
