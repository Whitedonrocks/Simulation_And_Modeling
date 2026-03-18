// Find the period of the generator for a=13, m=64 and X0=1,2,3,4 using the multiplicative congruent method.
// Print the minimum and maximum cycle length detected and for which value of seeds.

#include <stdio.h>

int main() {
    int a, m, n;
    int seeds[100], seq[100][1000], period[100];
    int i, s, x;

    printf("\nEnter value of a: ");
    scanf("%d", &a);
    printf("Enter value of m: ");
    scanf("%d", &m);
    printf("Enter number of seeds: ");
    scanf("%d", &n);
    for (s = 0; s < n; s++) {
        printf("Enter seed X0[%d]: ", s + 1);
        scanf("%d", &seeds[s]);
    }

    for (s = 0; s < n; s++) {
        x = seeds[s];
        period[s] = 0;
        do {
            seq[s][period[s]++] = x;
            x = (a * x) % m;
        } while (x != seeds[s] && period[s] < 1000);
    }

    int maxP = 0;
    for (s = 0; s < n; s++)
        if (period[s] > maxP) maxP = period[s];

    char hdr[20];
    printf("\n%-6s", "i");
    for (s = 0; s < n; s++) {
        sprintf(hdr, "X0=%d", seeds[s]);
        printf("%-10s", hdr);
    }
    printf("\n");

    for (i = 0; i < maxP; i++) {
        printf("%-6d", i + 1);
        for (s = 0; s < n; s++) {
            if (i < period[s])
                printf("%-10d", seq[s][i]);
            else
                printf("%-10s", "-");
        }
        printf("\n");
    }

    printf("%-6s", "P");
    for (s = 0; s < n; s++)
        printf("%-10d", period[s]);
    printf("\n\n");

    int minP = period[0], maxPeriod = period[0];
    int minSeed = seeds[0], maxSeed = seeds[0];
    for (s = 1; s < n; s++) {
        if (period[s] < minP)      { minP = period[s];      minSeed = seeds[s]; }
        if (period[s] > maxPeriod) { maxPeriod = period[s]; maxSeed = seeds[s]; }
    }

    printf("Minimum cycle length: %d  (X0 = %d)\n", minP, minSeed);
    printf("Maximum cycle length: %d  (X0 = %d)\n", maxPeriod, maxSeed);

    return 0;
}