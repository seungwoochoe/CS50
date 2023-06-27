#include <stdio.h>
#include <cs50.h>

float half(float bill, float tax, int tip);

int main(void) {
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));

    return 0;
}

float half(float bill, float tax, int tip)
{
    float sum = bill * (1 + tax / 100) * (1 + (float)tip / 100);
    return sum / 2;
}