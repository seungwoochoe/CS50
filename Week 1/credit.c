#include <cs50.h>
#include <stdio.h>

void check_validity(long number);
int perform_step_1(long number);
int perform_step_2(long number);
int multiply_by_2_and_add_digits(int n);
int get_first_two_digits(long number);
int count_digits(long n);

int main(void) {
    long number = get_long("Number: ");
    check_validity(number);

    return 0;
}

void check_validity(long number) {
    int sum = 0;

    sum += perform_step_1(number);
    sum += perform_step_2(number);
    
    if (sum < 0 || sum % 10 != 0) {
        printf("INVALID\n");
    }
    else {
        int first_two_digits = get_first_two_digits(number);

        if ((first_two_digits == 34 || first_two_digits == 37) && count_digits(number) == 15) {
            printf("AMEX\n");
        }
        else if ((51 <= first_two_digits && first_two_digits <= 55) && count_digits(number) == 16) {
            printf("MASTERCARD\n");
        }
        else if ((40 <= first_two_digits && first_two_digits <= 49) && (count_digits(number) == 13 || count_digits(number) == 16)) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
}

int perform_step_1(long number) {
    int sum = 0;

    number /= 10;
    sum += multiply_by_2_and_add_digits(number % 10);

    while (number > 0) {
        number /= 100;
        sum += multiply_by_2_and_add_digits(number % 10);
    }

    return sum;
}

int perform_step_2(long number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 100;
    }

    return sum;
}

int multiply_by_2_and_add_digits(int n) {
    int sum = 0;
    n *= 2;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int get_first_two_digits(long number) {
    while (number > 99) {
        number /= 10;
    }

    return number;
}

int count_digits(long n) {
    int count = 0;

    while (n > 0) {
        n /= 10;
        ++count;
    }

    return count;
}