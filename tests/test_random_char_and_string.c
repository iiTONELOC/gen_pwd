#include <stdio.h>
#include <string.h>
#include "utils.h"

// it should be able to get random characters for a string of a specified length and type
int get_random_char_for_password_test()
{
    int length = 12;
    enum password_character_type type = ALL;
    char *actual = get_random_char_for_password(length, type);
    int actual_length = strlen(actual);

    if (actual_length != length)
    {
        printf("\nget_random_char_for_password_test failed\n");
        printf("expected length: %d\n", length);
        printf("actual length: %d\n", actual_length);

        printf("expected: %s\n", actual);
        return 1;
    }

    return 0;
}

int main()
{
    int status = 0;

    status += get_random_char_for_password_test();

    return status;
}
