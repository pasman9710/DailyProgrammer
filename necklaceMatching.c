#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
Imagine a necklace with lettered beads that can slide along the string.
In this example, you could take the N off NICOLE and slide it around to the
other end to make ICOLEN. Do it again to get COLENI, and so on. For the purpose
of today's challenge, we'll say that the strings "nicole", "icolen", and "coleni"
describe the same necklace.

Generally, two strings describe the same necklace if you can remove some number
of letters from the beginning of one, attach them to the end in their original
ordering, and get the other string. Reordering the letters in some other way
does not, in general, produce a string that describes the same necklace.

Write a function that returns whether two strings describe the same necklace.
*/

int sameNecklace(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // strings are not the same length
    if (len1 != len2) {
        return 0;
    }
    char* copy = malloc(len2 + 1);
    assert(copy != NULL);
    strcpy(copy, str2);
    for (int i = 0; i < len1; i++) {
        // strings are the same so they are the same necklace
        if (!strcmp(str1, copy)) {
            free(copy);
            return 1;
        }
        // rotate the last letter of str2 to the front
        char c = copy[len2 - 1];
        for (int j = len2 - 1; j > 0; j--) {
            copy[j] = copy[j - 1];
        }
        copy[0] = c;
    }
    free(copy);
    return 0;
}

/*
If you have a string of N letters and you move each letter one at a time from
the start to the end, you'll eventually get back to the string you started with,
after N steps. Sometimes, you'll see the same string you started with before N
steps. For instance, if you start with "abcabcabc", you'll see the same string
("abcabcabc") 3 times over the course of moving a letter 9 times.

Write a function that returns the number of times you encounter the same
starting string if you move each letter in the string from the start to the end,
one at a time.
*/

int repeats(char* str) {
    int len = strlen(str);
    int cnt = 1;
    char* copy = malloc(len + 1);
    assert(copy != NULL);
    strcpy(copy, str);
    for (int i = 0; i < len - 1; i++) {
        char c = copy[len - 1];
        for (int j = len - 1; j > 0; j--) {
            copy[j] = copy[j - 1];
        }
        copy[0] = c;
        if (!strcmp(copy, str)) {
            cnt++;
        }
    }
    free(copy);
    return cnt;
}

int main(int argc, char const *argv[]) {
    // NECKLACE
    // char str1[256];
    // char str2[256];
    // do {
    //     printf("\nEnter two strings to see if they are the same necklace!\n '!' to exit.\n");
    //     scanf("%s", str1);
    //     if (str1[0] == '!') {
    //         break;
    //     }
    //     scanf("%s", str2);
    //     int x = sameNecklace(str1, str2);
    //     if (x) {
    //         printf("The two necklaces are identical!\n");
    //     } else {
    //         printf("These are two different necklaces!\n");
    //     }
    // } while(str1[0] != '!');
    // printf("Good Bye\n");

    // REPEATS
    char str[256];
    do {
        printf("\nEnter a string to see how often it repeats when rotated!\n '!' to exit.\n");
        scanf("%s", str);
        if (str[0] == '!') {
            break;
        }
        printf("It repeats %d times!\n", repeats(str));
    } while(str[0] != '!');
    printf("Good Bye\n");

    return 0;
}
