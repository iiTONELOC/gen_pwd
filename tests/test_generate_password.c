#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int test_generates_password_of_correct_length()
{
    int length = 50;
    char *password = generate_password(length);
    int password_length = strlen(password);
    if (password_length != length)
    {
        printf("Generated Password %s", password);
        printf("Password length is %d, expected %d\n", password_length, length);
        return 1;
    }
    return 0;
}

int test_generates_password_with_correct_requirements()
{
    int length = 12;
    char *password = generate_password(length);

    int _has_no_whitespace = has_no_whitespace(password);
    int _has_correct_length = strlen(password) == length;
    int _has_all_character_types = has_all_character_types(password);
    int _first_last_not_equal = first_and_last_chars_are_not_equal(password);
    int _first_last_alphanumeric = first_and_last_chars_are_alphanumeric(password);
    int _has_special_char_in_first_seven_characters = has_special_char_in_first_seven_characters(password);

    if (!_has_no_whitespace)
    {
        printf("Generated Password %s\n", password);
        printf("Password contains whitespace\n");
        return 1;
    }
    if (!_has_correct_length)
    {
        printf("Generated Password %s\n", password);
        printf("Password length is %d, expected %d\n", strlen(password), length);
        return 1;
    }
    if (!_has_all_character_types)
    {
        printf("Generated Password %s\n", password);
        printf("Password does not contain all character types\n");
        return 1;
    }
    if (!_first_last_not_equal)
    {
        printf("Generated Password %s\n", password);
        printf("Password first and last characters are equal\n");
        return 1;
    }
    if (!_first_last_alphanumeric)
    {
        printf("Generated Password %s\n", password);
        printf("Password first and last characters are not alphanumeric\n");
        return 1;
    }
    if (!_has_special_char_in_first_seven_characters)
    {
        printf("Generated Password %s\n", password);
        printf("Password does not contain a special character in the first seven characters\n");
        return 1;
    }

    return 0;
}

int main()
{
    int correct_length = test_generates_password_of_correct_length();
    int correct_requirements = test_generates_password_with_correct_requirements();

    return (correct_length == 0 && correct_requirements == 0) ? 0 : 1;
}