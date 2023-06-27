#include <cs50.h>
#include <stdio.h>

int main(void) {
    int start, target;

    do {
        start = get_int("Start size: ");
    } while (start < 9);

    do {
        target = get_int("End size: ");
    } while (target < start);

    int years = 0;
    while (start < target) {
        ++years;
        start += (start / 3) - (start / 4);
    }

    printf("Years: %d\n", years);

    return 0;
}