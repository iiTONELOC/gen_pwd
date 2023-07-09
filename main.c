/*
    Author : iiTONELOC/Anthony Tropeano
    Date   : 7/8/2023
    Purpose: A command line utility to generate secure passwords from lengths of 12 to 128 characters. This is a C implementation of a C#
                program I wrote a while back. I am rewriting it in C to learn more about the language and to get more comfortable with it.

    Notes  :
                Password Generator:

                    Valid Symbols:
                        - Lowercase Letters
                        - Uppercase Letters
                        - Numbers
                        - Special Characters

                    Secure Password Requirements:
                        - Minimum of 12 characters
                        - Maximum of 128 characters
                        - At least one of each type of valid symbol
                        - No spaces
                        - Must contain a special character within the first 7 characters
                        - First and last characters must be different
                        - Fist and last characters must be a letter or number


                    CLI Utility, no menu prompts. All options are passed as flags, and the password is printed to stdout.
                    -l <length> - Length of password
                    -h - Show help
                    -i - Show information about the program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void print_info()
{
    printf("This is a password generator.\n");
    printf("It generates passwords.\n");
    printf("It's pretty cool.\n");
}

void print_help()
{
    printf("Usage: pwd [options]\n");
    printf("Options:\n");
    printf("  -l <length> - Length of password\n");
    printf("  -h - Show this help message\n");
    printf("  -i - Show information about the program\n");
}

int main(int argc, char *argv[])
{
    int password_length = 0;

    // handle the command line arguments to see if we need to print help or info
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
        {
            if (i + 1 < argc)
            {
                password_length = atoi(argv[i + 1]);

                // skip the value only if it's a valid integer
                if (password_length > 0)
                {
                    i++;
                }
            }
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            print_help();
            return 0;
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            print_info();
            return 0;
        }
    }

    char *password = generate_password(password_length);
    printf("%s\n", password);

    free(password);

    return 0;
}
