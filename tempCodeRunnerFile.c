#include <stdio.h>
#include <stdlib.h>

void avgWaitTime(int t[], int at[], int n)
{
    int totalWaitTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitTime += t[i] - at[i];
    }
    printf("\nAvg Waiting Time = %.2f", (float)totalWaitTime / n);
}

void avgTurnAroundTime(int t[], int at[], int n)
{
    int totalTurnAroundTime = 0;
    for (int i = 1; i < n + 1; i++)
    {
        totalTurnAroundTime += t[i] - at[i - 1];
    }
    printf("\nAvg Turnaround Time = %.2f", (float)totalTurnAroundTime / n);
}

int main()
{

    printf("First Come First Serve CPU Scheduling Algorithm\n");

    int numProcesses;

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Dynamically Creating Arrays For Getting Values of Burst Times and Arrival Times and Completion Times
    int *burstTimes = (int *)malloc(numProcesses * sizeof(int));
    int *arrivalTimes = (int *)malloc(numProcesses * sizeof(int));
    int *completionTimes = (int *)malloc((numProcesses + 1) * sizeof(int));

    // Get burst times
    printf("Enter the burst times: ");
    for (int i = 0; i < numProcesses; i++)
    {
        scanf("%d", &burstTimes[i]);
    }

    // Get arrival times
    printf("Enter the arrival times: ");
    for (int i = 0; i < numProcesses; i++)
    {
        scanf("%d", &arrivalTimes[i]);
    }

    int endTime = 0;
    completionTimes[0] = endTime;

    // Calculate completion times
    for (int i = 0; i < numProcesses; i++)
    {
        endTime += burstTimes[i];
        completionTimes[i + 1] = endTime;
    }

    avgWaitTime(completionTimes, arrivalTimes, numProcesses);

    avgTurnAroundTime(completionTimes, arrivalTimes, numProcesses);

    free(burstTimes);
    free(arrivalTimes);
    free(completionTimes);

    return 0;
}
