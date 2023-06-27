#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void) {
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);

    return 0;
}

int get_cents(void) {
    int cents;

    do {
        cents = get_int("Change owedd: ");
    } while (cents < 0);

    return cents;
}

int calculate_quarters(int cents) { return cents / 25; }

int calculate_dimes(int cents) { return cents / 10; }

int calculate_nickels(int cents) { return cents / 5; }

int calculate_pennies(int cents) { return cents; }