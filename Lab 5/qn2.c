// Activity 2: Election Process 
//     • A population of vector are distributed between the Democratic (D), Republican (R) , and Independent (I) parties. 
//     • Each election the voting  population  P=[ D, R, I]  obeys the distribution like 

// Fig: vote shift between two election 
//     • In 2004 election, the voters were distributed according to the distribution vector 
//     • P0= [0.48, 0.51, 0.01] 
// Q. The next expected population outcome of the 2008 election??
//              Ans:  P0* T2 = 0.70*0.48 +0.10*0.51+0.30*0.10=0.417

#include <stdio.h>

int main() {
    int electionYear;
    const int baseYear = 2004;

    printf("\nEnter election year (e.g., 2004, 2008, 2012): ");
    if (scanf("%d", &electionYear) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (electionYear < baseYear || (electionYear - baseYear) % 4 != 0) {
        printf("Please enter a valid election year from %d onward in 4-year intervals.\n", baseYear);
        return 1;
    }

    int steps = (electionYear - baseYear) / 4;

    double current[3] = {0.48, 0.51, 0.01};
    double next[3];

    double T[3][3] = {
        {0.70, 0.20, 0.10},
        {0.10, 0.80, 0.10},
        {0.30, 0.30, 0.40}
    };

    for (int step = 0; step < steps; step++) {
        for (int j = 0; j < 3; j++) {
            next[j] = 0.0;
            for (int i = 0; i < 3; i++) {
                next[j] += current[i] * T[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            current[i] = next[i];
        }
    }

    printf("Election Year %d Result:\n", electionYear);
    printf("Democratic: %.3f\n", current[0]);
    printf("Republican: %.3f\n", current[1]);
    printf("Independent: %.3f\n", current[2]);

    return 0;
}