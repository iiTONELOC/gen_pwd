#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int test_has_lowercase()
{
    char *test_string = "ABC123!@#";
    int result = has_lowercase(test_string);
    if (result != 0)
    {
        printf("\ntest_has_lowercase failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abc123!@#";
    result = has_lowercase(test_string2);
    if (result != 1)
    {
        printf("\ntest_has_lowercase failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_uppercase()
{
    char *test_string = "abc123!@#";
    int result = has_uppercase(test_string);
    if (result != 0)
    {
        printf("\ntest_has_uppercase failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "ABC123!@#";
    result = has_uppercase(test_string2);
    if (result != 1)
    {
        printf("\ntest_has_uppercase failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_numbers()
{
    char *test_string = "abcABC!@#";
    int result = has_numbers(test_string);
    if (result != 0)
    {
        printf("\ntest_has_numbers failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abc123!@#";
    result = has_numbers(test_string2);
    if (result != 1)
    {
        printf("\ntest_has_numbers failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_special_chars()
{
    char *test_string = "abcABC123";
    int result = has_special_characters(test_string);
    if (result != 0)
    {
        printf("\ntest_has_special_chars failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABC123!@#";
    result = has_special_characters(test_string2);
    if (result != 1)
    {
        printf("\ntest_has_special_chars failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_special_char_in_first_seven_characters()
{
    char *test_string = "abcA!C123!@#";
    int result = has_special_char_in_first_seven_characters(test_string);
    if (result != 1)
    {
        printf("\ntest_has_special_char_in_first_seven_characters failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABCt!@#123";
    result = has_special_char_in_first_seven_characters(test_string2);
    if (result != 0)
    {
        printf("\ntest_has_special_char_in_first_seven_characters failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_all_char_types()
{
    char *test_string = "abcABC123!@#";
    int result = has_all_character_types(test_string);
    if (result != 1)
    {
        printf("\ntest_has_all_char_types failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABC123";
    result = has_all_character_types(test_string2);
    if (result != 0)
    {
        printf("\ntest_has_all_char_types failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_first_and_last_not_equal()
{
    char *test_string = "abcABC123!@#";
    int result = first_and_last_chars_are_not_equal(test_string);
    if (result != 1)
    {
        printf("\ntest_first_and_last_not_equal failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABC123!@a";
    result = first_and_last_chars_are_not_equal(test_string2);
    if (result != 0)
    {
        printf("\ntest_first_and_last_not_equal failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_has_no_whitespace()
{
    char *test_string = "abcABC123!@#";
    int result = has_no_whitespace(test_string);
    if (result != 1)
    {
        printf("\ntest_has_no_whitespace failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABC123!@# ";
    result = has_no_whitespace(test_string2);
    if (result != 0)
    {
        printf("\ntest_has_no_whitespace failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_first_last_alphanumeric()
{
    char *test_string = "abcABC123!@#";
    int result = first_and_last_chars_are_alphanumeric(test_string);
    if (result != 1)
    {
        printf("\ntest_first_last_alphanumeric failed\n");
        printf("expected: 1\n");
        printf("actual: %d\n", result);
        return 1;
    }

    char *test_string2 = "abcABC123!@a";
    result = first_and_last_chars_are_alphanumeric(test_string2);
    if (result != 0)
    {
        printf("\ntest_first_last_alphanumeric failed\n");
        printf("expected: 0\n");
        printf("actual: %d\n", result);
        return 1;
    }

    return 0;
}

int test_enforce_password_requirements()
{
    // missing required characters
    char *test_string = "abcABC123dse";
    char *result = enforce_password_requirements(test_string);

    if (strcmp(test_string, result) == 0)
    {
        printf("\ntest_enforce_password_requirements failed - missing required characters check\n");
        printf("expected: test_string != result\n");
        printf("actual: %s == %s\n", test_string, result);
        return 1;
    }

    // correct password requirements
    char *test_string2 = "abcAB$C123!@J";
    result = enforce_password_requirements(test_string2);

    if (strcmp(test_string2, result) != 0)
    {
        printf("\ntest_enforce_password_requirements failed - correct password provided\n");
        printf("expected: test_string2 == result\n");
        printf("actual: %s != %s\n", test_string2, result);
        return 1;
    }

    // first and last characters are equal
    // this should be fixed by the enforce_password_requirements function, and the last character should be changed
    char *test_string3 = "abcA%BC123!@a";
    result = enforce_password_requirements(test_string3);

    if (strcmp(test_string3, result) == 0)
    {
        printf("\ntest_enforce_password_requirements failed - first and last characters match\n");
        printf("expected: test_string3 == result\n");
        printf("actual: %s != %s\n", test_string3, result);
        return 1;
    }
    else
    {
        // ensure that all the characters are equal to their counter part in the test_string3 except for the last character
        // this should be different from the last character in test_string3
        for (int i = 0; i < strlen(test_string3); i++)
        {
            if (i == strlen(test_string3) - 1)
            {
                if (test_string3[i] == result[i])
                {
                    printf("\ntest_enforce_password_requirements failed - first and last characters match\n");
                    printf("expected: test_string3[i] != result[i]\n");
                    printf("actual: %c == %c\n", test_string3[i], result[i]);
                    return 1;
                }
            }
            else
            {
                if (test_string3[i] != result[i])
                {
                    printf("\ntest_enforce_password_requirements failed - first and last characters match\n");
                    printf("expected: test_string3[i] == result[i]\n");
                    printf("actual: %c != %c\n", test_string3[i], result[i]);
                    return 1;
                }
            }
        }
    }

    // contains whitespace
    // this should be fixed by the enforce_password_requirements function, and the whitespace should be removed

    char *test_string4 = "abcA#BC123!@# ";
    result = enforce_password_requirements(test_string4);

    if (strcmp(test_string4, result) == 0)
    {
        printf("\ntest_enforce_password_requirements failed - contains whitespace\n");
        printf("expected: test_string4 != result\n");
        printf("actual: %s == %s\n", test_string4, result);
        return 1;
    }
    else
    {
        // ensure that all the characters are equal to their counter part in the test_string4 except for the last character
        // this should be different from the last character in test_string4
        for (int i = 0; i < strlen(test_string4); i++)
        {
            if (i == strlen(test_string4) - 1)
            {
                if (test_string4[i] == result[i])
                {
                    printf("\ntest_enforce_password_requirements failed - contains whitespace\n");
                    printf("expected: test_string4[i] != result[i]\n");
                    printf("actual: %c == %c\n", test_string4[i], result[i]);
                    return 1;
                }
            }
            else
            {
                if (test_string4[i] != result[i])
                {
                    printf("\ntest_enforce_password_requirements failed - contains whitespace\n");
                    printf("expected: test_string4[i] == result[i]\n");
                    printf("actual: %c != %c\n", test_string4[i], result[i]);
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int r1 = test_has_lowercase();
    int r2 = test_has_uppercase();
    int r3 = test_has_numbers();
    int r4 = test_has_special_chars();
    int r5 = test_has_all_char_types();
    int r6 = test_has_special_char_in_first_seven_characters();
    int r7 = test_first_and_last_not_equal();
    int r8 = test_has_no_whitespace();
    int r9 = test_enforce_password_requirements();

    if (r1 != 0 || r2 != 0 || r3 != 0 || r4 != 0 || r5 != 0 || r6 != 0 || r7 != 0 || r8 != 0 || r9 != 0)
    {
        return 1;
    }

    return 0;
}
