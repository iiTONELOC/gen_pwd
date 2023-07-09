#include "utils.h"
#include <stdio.h>
#include <string.h>

char *string = "Hello, World!";

// tries to access the first character of the string
int safely_access_char_from_string_test()
{
    char *expected = "H";
    char actual = access_char_from_string(string, 0);

    if (*expected != actual)
    {
        printf("safely_access_char_from_string_test failed\n");
        printf("expected: %c\n", *expected);
        printf("actual: %c\n", actual);
        return 1;
    }

    return 0;
}

// tries to access a character at a negative index
int safely_access_char_from_string_with_negative_index()
{
    char *expected = "\0";
    char actual = access_char_from_string(string, -1);

    if (*expected != actual)
    {
        printf("safely_access_char_from_string_with_negative_index failed\n");
        printf("expected: %c\n", *expected);
        printf("actual: %c\n", actual);
        return 1;
    }

    return 0;
}

// tries to access a character at an index greater than the length of the string
int safely_access_char_from_string_with_index_greater_than_string_length()
{
    char *expected = "\0";
    char actual = access_char_from_string(string, 14);

    if (*expected != actual)
    {
        printf("\nsafely_access_char_from_string_with_index_greater_than_string_length failed\n");
        printf("expected: %c\n", *expected);
        printf("actual: %c\n", actual);
        return 1;
    }

    return 0;
}

// tries to access a character at an index equal to the length of the string
int safely_access_char_from_string_with_index_equal_to_string_length()
{
    char *expected = "\0";
    char actual = access_char_from_string(string, 13);

    if (*expected != actual)
    {
        printf("\nsafely_access_char_from_string_with_index_equal_to_string_length failed\n");
        printf("expected: %c\n", *expected);
        printf("actual: %c\n", actual);
        return 1;
    }

    return 0;
}

// tries to access a character at an index equal to zero
int safely_access_char_from_string_with_index_equal_to_zero()
{
    char *expected = "H";
    char actual = access_char_from_string(string, 0);

    if (*expected != actual)
    {
        printf("\nsafely_access_char_from_string_with_index_equal_to_zero failed\n");
        printf("expected: %c\n", *expected);
        printf("actual: %c\n", actual);
        return 1;
    }

    return 0;
}

int main()
{
    int r1 = safely_access_char_from_string_test();
    int r2 = safely_access_char_from_string_with_negative_index();
    int r3 = safely_access_char_from_string_with_index_greater_than_string_length();
    int r4 = safely_access_char_from_string_with_index_equal_to_string_length();
    int r5 = safely_access_char_from_string_with_index_equal_to_zero();

    // if any test failed, return 1
    if (r1 != 0 || r2 != 0 || r3 != 0 || r4 != 0 || r5 != 0)
    {
        return 1;
    }

    return 0;
}
