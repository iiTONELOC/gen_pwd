#include "utils.h"
#include <stdio.h>

// it should generate a random integer between 0 and 10
int generates_random_int()
{
    int random = random_int(0, 10);

    if (random < 0 || random > 10)
    {
        printf("\ngenerates_random_int failed\n");
        printf("expected: 0 <= random <= 10\n");
        printf("actual: %d\n", random);
        return 1;
    }

    return 0;
}

// a number generated by random_int should be different each time
int generates_different_random_ints()
{
    int random1 = random_int(0, 10);
    int random2 = random_int(0, 10);

    if (random1 == random2)
    {
        printf("\ngenerates_different_random_ints failed\n");
        printf("expected: random1 != random2\n");

        return 1;
    }

    return 0;
}

int main()
{
    int r1 = generates_random_int();
    int r2 = generates_different_random_ints();

    if (r1 != 0 || r2 != 0)
    {
        return 1;
    }

    return 0;
}