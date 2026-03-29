/*
Activity2: Modify the program of activity 1 and calculate the 
        ◦ average waiting time, 
        ◦  minimum wait time, 
        ◦ maximum wait time, 
        ◦ average number of customer in the system
Algorithm
1. Create one structure Customer with following 
    • int arrivalTime;
    • int serviceTime;
    • int startTime;
    • int endTime;'
2. Generate Customer, Arrival Time Service Time and stored them in a structure 
3. Calculate the  Service Begin, Service End Times of each customer 
4. Generate the the statisctics in tabular form with following heading 
    • Customer No
    • Inter Arrival
    • Arrival Time 
    • Ser. Time: 
    • Ser. Begin: 
    • Service end 
    • T.spent 
    • Idle time
5. Print the following  Performance parameters of the queue 
    • Average Wait Time
    • Average Time Spent in System
    • Average Service time
    • Server Utilization
    • Total Idle Time and percentage 
*/
#include <stdio.h>

#define MAX_CUSTOMERS 20

typedef struct {
    int iat, at, st, start, ct, wt, tat, idle;
} Customer;

int main() {
    int n;
    Customer c[MAX_CUSTOMERS];

    int prev_arrival = 0, prev_completion = 0;
    double total_wait = 0, total_tat = 0, total_service = 0;
    int total_idle = 0;

    int min_wt, max_wt;
    printf("\nEnter number of customers (1-%d): ", MAX_CUSTOMERS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_CUSTOMERS) {
        printf("Invalid number of customers.\n");
        return 1;
    }

    printf("\nEnter Inter Arrival Time and Service Time:\n");

    for (int i = 0; i < n; i++) {
        printf("\nCustomer %d\n", i + 1);

        printf("Inter Arrival Time: ");
        scanf("%d", &c[i].iat);

        printf("Service Time: ");
        scanf("%d", &c[i].st);

        c[i].at = prev_arrival + c[i].iat;
        c[i].start = (c[i].at > prev_completion) ? c[i].at : prev_completion;
        c[i].idle = c[i].start - prev_completion;
        c[i].ct = c[i].start + c[i].st;
        c[i].wt = c[i].start - c[i].at;
        c[i].tat = c[i].ct - c[i].at;

        total_wait += c[i].wt;
        total_tat += c[i].tat;
        total_service += c[i].st;
        total_idle += c[i].idle;

        if (i == 0) {
            min_wt = max_wt = c[i].wt;
        } else {
            if (c[i].wt < min_wt) min_wt = c[i].wt;
            if (c[i].wt > max_wt) max_wt = c[i].wt;
        }

        prev_arrival = c[i].at;
        prev_completion = c[i].ct;
    }

    int total_time = prev_completion;

    double avg_wait = total_wait / n;
    double avg_tat = total_tat / n;
    double avg_service = total_service / n;
    double utilization = (total_service / total_time) * 100.0;
    double idle_percent = ((double)total_idle / total_time) * 100.0;
    double avg_num_system = total_tat / total_time;

    printf("\nSingle Server Queue Simulation (%d Customers)\n\n", n);

    printf("%-5s %-15s %-15s %-15s %-15s %-15s %-12s %-15s %-12s\n",
           "Cust", "InterArrival", "ArrivalTime", "ServiceTime",
           "StartTime", "EndTime", "WaitTime", "TimeInSystem", "IdleTime");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-15d %-15d %-15d %-15d %-15d %-12d %-15d %-12d\n",
               i + 1,
               c[i].iat,
               c[i].at,
               c[i].st,
               c[i].start,
               c[i].ct,
               c[i].wt,
               c[i].tat,
               c[i].idle);
    }

    printf("\n--- Results ---\n");
    printf("Average Waiting Time        = %.2lf\n", avg_wait);
    printf("Minimum Waiting Time        = %d\n", min_wt);
    printf("Maximum Waiting Time        = %d\n", max_wt);
    printf("Average Time in System      = %.2lf\n", avg_tat);
    printf("Average Service Time        = %.2lf\n", avg_service);
    printf("Server Utilization          = %.2lf%%\n", utilization);
    printf("Total Idle Time             = %d\n", total_idle);
    printf("Idle Time Percentage        = %.2lf%%\n", idle_percent);
    printf("Average Number in System    = %.2lf\n", avg_num_system);

    return 0;
}