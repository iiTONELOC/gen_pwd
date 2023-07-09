/*
    Author : iiTONELOC/Anthony Tropeano
    Date   : 7/8/2023

    Purpose: Utility functions for the password generator program.

    Notes:
            This file uses RAND_bytes from the OpenSSL library (https://www.openssl.org/)
            distributed under the Apache License 2.0 (https://www.openssl.org/source/apache-license-2.0.txt)
 */

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/rand.h>
#include <stdio.h>
#include "utils.h"

static int last_random_int = -1;
static pthread_mutex_t random_int_mutex = PTHREAD_MUTEX_INITIALIZER; // ensures that random_int is thread-safe

CharacterMap character_maps[] = {
    {ALL, ""},
    {LOWERCASE, "abcdefghijklmnopqrstuvwxyz"},
    {UPPERCASE, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {NUMBERS, "0123456789"},
    {SPECIAL_CHARACTERS, "!@#$%^&*()-_=+[]{}<>?/\\|~`:\"',.;"}};

int const DEFAULT_PASSWORD_LENGTH = 12;
int const MAX_PASSWORD_LENGTH = 128;

char access_char_from_string(char *string, int index)
{
    if (index < 0 || index > strlen(string))
    {
        return '\0';
    }
    return string[index];
}

int random_int(int min, int max)
{
    if (min > max)
    {
        // Invalid range
        return -1;
    }

    unsigned int range = max - min + 1;
    unsigned int random_value = 0;
    RAND_bytes((unsigned char *)&random_value, sizeof(random_value));

    return min + (random_value % range);
}

char *get_random_char_for_password(int length, enum password_character_type type)
{
    char *characters = malloc((length + 1) * sizeof(char));
    if (characters == NULL)
    {
        // Handle memory allocation failure
        return " \0";
    }

    int character_map_index = 0;

    for (int i = 0; i < length; i++)
    {
        if (type == ALL)
        {
            character_map_index = random_int(1, 4); // Generate a random index between 1 and 4 (excluding 0)
        }
        else
        {
            character_map_index = type;
        }

        int random_index = random_int(0, strlen(character_maps[character_map_index].characters) - 1);
        characters[i] = character_maps[character_map_index].characters[random_index];
    }

    characters[length] = '\0'; // Add null-terminating character

    return characters;
}

char *randomize_string(char *string)
{
    int length = strlen(string);
    char *random_string = malloc((length + 1) * sizeof(char)); // Add 1 for null terminator

    for (int i = 0; i < length; i++)
    {
        int random_index = random_int(0, strlen(string) - 1);
        random_string[i] = string[random_index];
    }

    random_string[length] = '\0'; // Add null terminator at the end

    return random_string;
}

int has_lowercase(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            return 1;
        }
    }

    return 0;
}

int has_uppercase(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            return 1;
        }
    }

    return 0;
}

int has_numbers(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}

int has_no_whitespace(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            return 0;
        }
    }

    return 1;
}

int has_special_characters(char *string)
{
    CharacterMap special_characters_map = character_maps[SPECIAL_CHARACTERS];
    const char *special_characters = special_characters_map.characters;

    for (int i = 0; i < strlen(string); i++)
    {
        char current_char = string[i];
        for (int j = 0; j < strlen(special_characters); j++)
        {
            if (current_char == special_characters[j])
            {
                return 1;
            }
        }
    }

    return 0;
}

int has_all_character_types(char *string)
{
    return has_lowercase(string) && has_uppercase(string) && has_numbers(string) && has_special_characters(string);
}

int has_special_char_in_first_seven_characters(char *string)
{
    CharacterMap special_characters_map = character_maps[SPECIAL_CHARACTERS];
    const char *special_characters = special_characters_map.characters;

    for (int i = 0; i < strlen(string) && i < 7; i++)
    {
        char current_char = string[i];
        for (int j = 0; j < strlen(special_characters); j++)
        {
            if (current_char == special_characters[j])
            {
                return 1;
            }
        }
    }

    return 0;
}

int first_and_last_chars_are_not_equal(char *string)
{
    return string[0] != string[strlen(string) - 1];
}

int first_and_last_chars_are_alphanumeric(char *string)
{
    return (string[0] >= 'a' && string[0] <= 'z' || string[0] >= 'A' && string[0] <= 'Z' || string[0] >= '0' && string[0] <= '9') &&
           (string[strlen(string) - 1] >= 'a' && string[strlen(string) - 1] <= 'z' || string[strlen(string) - 1] >= 'A' && string[strlen(string) - 1] <= 'Z' || string[strlen(string) - 1] >= '0' && string[strlen(string) - 1] <= '9');
}

char *enforce_password_requirements(char *generated_password)
{
    char *new_password = strdup(generated_password);

    // Check that the password has lowercase, uppercase, numbers, and special characters
    if (has_lowercase(new_password) == 0)
    {
        new_password[random_int(0, strlen(new_password) - 1)] = get_random_char_for_password(1, LOWERCASE)[0];
    }
    if (has_uppercase(new_password) == 0)
    {
        new_password[random_int(0, strlen(new_password) - 1)] = get_random_char_for_password(1, UPPERCASE)[0];
    }
    if (has_numbers(new_password) == 0)
    {
        new_password[random_int(0, strlen(new_password) - 1)] = get_random_char_for_password(1, NUMBERS)[0];
    }
    if (has_special_characters(new_password) == 0)
    {
        new_password[random_int(0, strlen(new_password) - 1)] = get_random_char_for_password(1, SPECIAL_CHARACTERS)[0];
    }

    // Check if the password has a special character in the first seven characters
    if (has_special_char_in_first_seven_characters(new_password) == 0)
    {
        int random_insert_index = random_int(0, 6);
        int random_special_char_index = random_int(0, strlen(character_maps[SPECIAL_CHARACTERS].characters) - 1);
        char random_special_char = character_maps[SPECIAL_CHARACTERS].characters[random_special_char_index];

        new_password[random_insert_index] = random_special_char;
    }

    // Check that the first and last characters are not equal
    if (first_and_last_chars_are_not_equal(new_password) == 0)
    {
        int last_index = strlen(new_password) - 1;
        char random_char = get_random_char_for_password(1, ALL)[0];
        new_password[last_index] = random_char;
    }

    // Check that the first and last characters are alphanumeric
    if (first_and_last_chars_are_alphanumeric(new_password) == 0)
    {
        // check the first character, if it's not alphanumeric, replace it with a random alphanumeric character
        char *first_char = malloc(2 * sizeof(char));
        first_char[0] = new_password[0];
        first_char[1] = '\0';

        int is_first_char_alphanumeric = first_and_last_chars_are_alphanumeric(first_char);

        if (is_first_char_alphanumeric == 0)
        {
            char random_alphanumeric_char = get_random_char_for_password(1, LOWERCASE | UPPERCASE | NUMBERS)[0];
            new_password[0] = random_alphanumeric_char;
        }

        // check the last character, if it's not alphanumeric, replace it with a random alphanumeric character
        char *last_char = malloc(2 * sizeof(char));
        last_char[0] = new_password[strlen(new_password) - 1];
        last_char[1] = '\0';

        int is_last_char_alphanumeric = first_and_last_chars_are_alphanumeric(last_char);

        if (is_last_char_alphanumeric == 0)
        {
            char random_alphanumeric_char = get_random_char_for_password(1, LOWERCASE | UPPERCASE | NUMBERS)[0];
            new_password[strlen(new_password) - 1] = random_alphanumeric_char;
        }

        free(first_char);
        free(last_char);
    }

    // Check that the first and last characters are not equal - there is a slight random chance they could be equal after the previous check
    if (first_and_last_chars_are_not_equal(new_password) == 0)
    {
        int last_index = strlen(new_password) - 1;
        char random_char = get_random_char_for_password(1, ALL)[0];
        new_password[last_index] = random_char;
    }

    // Check for any whitespace characters and replace them with a random character
    if (has_no_whitespace(new_password) == 0)
    {
        char random_char = get_random_char_for_password(1, ALL)[0];
        for (int i = 0; i < strlen(new_password); i++)
        {
            if (new_password[i] == ' ')
            {
                new_password[i] = random_char;
            }
        }
    }

    return new_password;
}

char *generate_password(int password_length)
{
    // Validate the password length - if over 128 we set it to 128, if under 12 we set it to 12, otherwise we set it to the value passed in
    if (password_length > 128)
    {
        password_length = MAX_PASSWORD_LENGTH;
    }
    else if (password_length < 12)
    {
        password_length = DEFAULT_PASSWORD_LENGTH;
    }

    // Generate a fresh password each time by calling get_random_char_for_password
    char *password = get_random_char_for_password(password_length, ALL);

    // Enforce password requirements on the generated password
    char *enforced_password = enforce_password_requirements(password);

    // Free the memory allocated for the original password
    free(password);

    return enforced_password;
}
