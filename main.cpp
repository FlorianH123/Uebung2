#include <iostream>

int countWords(const char *string) {
    int count = 0;

    do {
        if (*string != ' ' && *string != '\t' && *string != '\n' && *string != '\0') {
            count++;

            while (*string != ' ' && *string != '\t' && *string != '\n' && *string != '\0') {
                *string++;
            }
        }
    } while (*string++);

    return count;
}

int strcmp_ign_wsp(const char *s1, const char *s2) {
    while (*s1 == *s2) {
        while (*s1 == ' ') {
            *s1++;
        }

        while (*s2 == ' ') {
            *s2++;
        }

        if (*s1 < *s2) {
            return 1;
        }

        if (*s1 > *s2) {
            return -1;
        }

        *s1++;
        *s2++;
    }

    return 0;
}

int main() {
    char string[] = " Halldfsffff";

    //std::cout << countWords(" H a l \tl o ");
    std::cout << strcmp_ign_wsp("   aa ab","a  aa");

    return 0;
}