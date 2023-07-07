// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct {
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void bubble_sort(void);
void selection_sort(void);
void insertion_sort(void);

int main(void) {
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    bubble_sort();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }

    return 0;
}

void bubble_sort(void) {
    for (int i = 0; i < NUM_CITIES - 1; ++i) {
        for (int j = 0; j < NUM_CITIES - i - 1; ++j) {
            if (temps[j].temp < temps[j + 1].temp) {
                avg_temp t = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = t;
            }
        }
    }
}

void selection_sort(void) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        int max_index = i;

        for (int j = i; j < NUM_CITIES; ++j) {
            if (temps[j].temp > temps[max_index].temp) {
                max_index = j;
            }
        }

        avg_temp t = temps[i];
        temps[i] = temps[max_index];
        temps[max_index] = t;
    }
}

void insertion_sort(void) {
    for (int i = 1; i < NUM_CITIES; ++i) {
        for (int j = i; j > 0; --j) {
            if (temps[j].temp > temps[j - 1].temp) {
                avg_temp t = temps[j - 1];
                temps[j - 1] = temps[j];
                temps[j] = t;
            }
        }
    }
}
