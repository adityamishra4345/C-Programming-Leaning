//code to find longest substring without repeating any alphabate.
#include <stdio.h>
#include <string.h>

int main() {
    char org[] = "abswcabcqbcasdfghjklbb";
    int n = strlen(org);
    int lastseen[256];
    
    for (int i = 0; i < 256; i++) {
        lastseen[i] = -1;
    }

    int maxlen = 0;
    int start = 0;
    int beststart = 0;

    for (int end = 0; end < n; end++) {
        if (lastseen[(int)org[end]] >= start) {
            start = lastseen[(int)org[end]] + 1;
        }

        lastseen[(int)org[end]] = end;

        if (end - start + 1 > maxlen) {
            maxlen = end - start + 1;
            beststart = start;
        }
    }

    printf("%d\n", maxlen);
    for (int i = beststart; i < beststart + maxlen; i++) {
        putchar(org[i]);
    }
    printf("\n");

    return 0;
}