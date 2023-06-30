// Check that a password has at least one lowercase letter, uppercase letter,
// number and symbol Practice iterating through a string Practice using the
// ctype library

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

bool valid(string password);

int main(void) {
    string password = get_string("Enter your password: ");

    if (valid(password)) {
        printf("Your password is valid!\n");
    } else {
        printf(
            "Your password needs at least one uppercase letter, lowercase "
            "letter, number and symbol!\n");
    }
}

bool valid(string password) { 
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    while (*password != '\0') {
        if (isupper(*password)) {
            upper = true;
        }
        else if (islower(*password)) {
            lower = true;
        }
        else if (isnumber(*password)) {
            number = true;
        }
        else {
            symbol = true;
        }

        ++password;
    }    

    return (upper && lower && number && symbol);
}
