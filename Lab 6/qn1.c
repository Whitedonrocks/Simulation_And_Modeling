// Lab 6:  Implementation of Single Server Queuing System.
// Scenario:  
//     • Grocery shop with Single Checkout counter   
//     • Customer arrival in 1 to 8 min Gap with equal probability
//     • Each customer takes 1 to 6 min of service time with equal probability 
//  Activity1: Create a simulation table for given scenario for 20 customers. Also Calculate the 
//         ◦ Average Wait Time
//         ◦ Average Time Spent in System by customer 
//         ◦ Average Service time
//         ◦ Server Utilization
//         ◦ Total Idle Time and percentage
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define NUM_CUSTOMERS 20
 
typedef struct {
    int interArrival; /* gap between this and previous customer */
    int arrivalTime;  /* cumulative arrival time                */
    int serviceTime;  /* time needed for service                */
    int startTime;    /* when service actually begins           */
    int endTime;      /* when service ends                      */
    int waitTime;     /* time spent waiting in queue            */
    int timeInSystem; /* total time from arrival to departure   */
    int idleTime;     /* server idle time before this customer  */
} Customer;
 
/* Returns a random integer in [lo, hi] */
int randRange(int lo, int hi) {
    return lo + rand() % (hi - lo + 1);
}
 
int main(void) {
    srand((unsigned int)time(NULL));
 
    Customer c[NUM_CUSTOMERS];
    int totalWait = 0, totalInSystem = 0, totalService = 0;
    int totalIdle = 0;
    int prevEnd = 0; /* end time of the previous customer's service */
 
    /* ── Generate and compute all customer data ── */
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        c[i].interArrival = randRange(1, 8);
        c[i].serviceTime  = randRange(1, 6);
 
        c[i].arrivalTime = (i == 0) ? c[i].interArrival
                                    : c[i - 1].arrivalTime + c[i].interArrival;
 
        /* Service begins when server is free or customer arrives, whichever is later */
        c[i].startTime = (c[i].arrivalTime > prevEnd) ? c[i].arrivalTime : prevEnd;
        c[i].endTime   = c[i].startTime + c[i].serviceTime;
 
        c[i].idleTime     = (c[i].startTime > prevEnd) ? (c[i].startTime - prevEnd) : 0;
        c[i].waitTime     = c[i].startTime - c[i].arrivalTime;
        c[i].timeInSystem = c[i].endTime   - c[i].arrivalTime;
 
        totalWait      += c[i].waitTime;
        totalInSystem  += c[i].timeInSystem;
        totalService   += c[i].serviceTime;
        totalIdle      += c[i].idleTime;
 
        prevEnd = c[i].endTime;
    }
 
    int totalSimTime = prevEnd; /* simulation ends when last customer leaves */
 
    /* ── Print simulation table ── */
    printf(" \nSingle Server Queue Simulation  (20 Customers)\n");
    printf("\n%-5s %-8s %-8s %-8s %-8s %-8s %-8s %-8s %-8s\n",
           "Cust", "Inter", "Arrival", "Ser.", "Ser.", "Ser.", "Wait", "T.Spent", "Idle");
    printf("%-5s %-8s %-8s %-8s %-8s %-8s %-8s %-8s %-8s\n",
           "No.",  "Arriv","Time",    "Time", "Begin","End",   "Time", "in Sys", "Time");
    printf("-----------------------------------------------------------------------------------\n");
 
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        printf("%-5d %-8d %-8d %-8d %-8d %-8d %-8d %-8d %-8d\n",
               i + 1,
               c[i].interArrival,
               c[i].arrivalTime,
               c[i].serviceTime,
               c[i].startTime,
               c[i].endTime,
               c[i].waitTime,
               c[i].timeInSystem,
               c[i].idleTime);
    }
 
    /* ── Performance statistics ── */
    double avgWait        = (double)totalWait       / NUM_CUSTOMERS;
    double avgInSystem    = (double)totalInSystem   / NUM_CUSTOMERS;
    double avgService     = (double)totalService    / NUM_CUSTOMERS;
    double utilization    = ((double)(totalSimTime - totalIdle) / totalSimTime) * 100.0;
    double idlePct        = ((double)totalIdle / totalSimTime) * 100.0;
 
    printf("\n  Performance Metrics\n");
    printf("  -------------------\n");
    printf("  Average Wait Time              : %.2f min\n", avgWait);
    printf("  Average Time Spent in System   : %.2f min\n", avgInSystem);
    printf("  Average Service Time           : %.2f min\n", avgService);
    printf("  Server Utilization             : %.2f %%\n",  utilization);
    printf("  Total Idle Time                : %d min (%.2f %%)\n", totalIdle, idlePct);
    printf("  Total Simulation Time          : %d min\n",  totalSimTime);
 
    return 0;
}