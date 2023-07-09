/*
    Author : iiTONELOC/Anthony Tropeano
    Date   : 7/8/2023
    Purpose: A command line utility to generate secure passwords from lengths of 12 to 128 characters. This is a C implementation of a C#
                program I wrote a while back. I am rewriting it in C to learn more about the language and to get more comfortable with it.

    Notes  : This file contains the type definitions and function prototypes for the utils.c file.
*/

#ifndef UTILS_H
#define UTILS_H

enum password_character_type
{
    ALL,
    LOWERCASE,
    UPPERCASE,
    NUMBERS,
    SPECIAL_CHARACTERS
};

typedef struct
{
    enum password_character_type type;
    const char *characters;
} CharacterMap;

extern int const DEFAULT_PASSWORD_LENGTH;
extern int const MAX_PASSWORD_LENGTH;

/**
 * Safely access a character from a string
 *
 * @param string the string to access a character from
 * @param index the index of the character to access
 *
 * @return the character at the specified index, or '\0' if the index is out of bounds
 */
extern char access_char_from_string(char *string, int index);

/**
 * Generate a random integer between two values
 *
 * @param min the minimum value of the random integer
 * @param max the maximum value of the random integer
 *
 * @return a random integer between the minimum and maximum values -
 * this value is guaranteed to be different from the last one generated
 */
extern int random_int(int min, int max);

/**
 * Generate a random character for a password
 *
 * @param length the length of the password or number of characters to generate
 * @param type the type of character to generate, defaults to all types if not specified
 * (ALL, LOWERCASE, UPPERCASE, NUMBERS, SPECIAL_CHARACTERS)
 *
 * @return a random character of the specified type
 */
extern char *get_random_char_for_password(int length, enum password_character_type type);

/**
 * Randomize the order of characters in a string
 *
 * @param string the string to randomize
 *
 * @return the randomized string
 */
extern char *randomize_string(char *string);

/**
 * Check if a string contains lowercase characters
 *
 * @param string the string to check
 *
 * @return 1 if the string contains lowercase characters, 0 otherwise
 */
extern int has_lowercase(char *string);

/**
 * Check if a string contains uppercase characters
 *
 * @param string the string to check
 *
 * @return 1 if the string contains uppercase characters, 0 otherwise
 */
extern int has_uppercase(char *string);

/**
 * Check if a string contains numbers
 *
 * @param string the string to check
 *
 * @return 1 if the string contains numbers, 0 otherwise
 */
extern int has_numbers(char *string);

/**
 * Check if a string contains whitespace
 *
 * @param string the string to check
 *
 * @return 0 if the string contains whitespace, 1 otherwise
 */
extern int has_no_whitespace(char *string);

/**
 * Check if a string contains special characters
 *
 * @param string the string to check
 *
 * @return 1 if the string contains special characters, 0 otherwise
 */
extern int has_special_characters(char *string);

/**
 * Check if a string contains all character types
 *
 * @param string the string to check
 *
 * @return 1 if the string contains all character types, 0 otherwise
 */
extern int has_all_character_types(char *string);

/**
 * Check if a string contains a special character in the first seven characters
 *
 * @param string the string to check
 *
 * @return 1 if the string contains a special character in the first seven characters, 0 otherwise
 */
extern int has_special_char_in_first_seven_characters(char *string);

/**
 * Checks to see that the first and last characters of a string are not equal
 *
 * @param string the string to check
 *
 * @return 1 if the first and last characters are not equal, 0 otherwise
 */
extern int first_and_last_chars_are_not_equal(char *string);

/**
 * Ensures the first and last characters of a string are alphanumeric
 *
 * @param string the string to check
 *
 * @return 1 if the first and last characters are alphanumeric, 0 otherwise
 */
extern int first_and_last_chars_are_alphanumeric(char *string);

/**
 * Verifies that a password meets the following requirements:
 * - At least one of each type of valid symbol
 * - No spaces
 * - Must contain a special character within the first 7 characters
 * - First and last characters must be different
 * - Fist and last characters must be a letter or number
 *
 * And modifies the password to meet the requirements if it doesn't
 *
 * @param password the password to check
 *
 * @return the password, modified if it didn't meet the requirements
 */
extern char *enforce_password_requirements(char *password);

/**
 * Generates a random password of the specified length
 *
 * @param password_length the length of the password to generate, must be between 12 and 128
 *
 * @return a random password of the specified length
 */
extern char *generate_password(int password_length);

#endif
