#include <stdio.h>


struct process{
    int burst_time;
    int priority;
};


int main(){
    int processes,sum = 0, sum2 = 0;

    printf("Enter Number of processes:");
    scanf("%d",&processes);

    struct process pro[processes];
    int wait_time[processes];
    int x,z,i,j;

    for(x = 0; x < processes; x++){

        printf("Enter burst time of process %d: ",x+1);
        scanf("%d",&pro[x].burst_time);

        printf("Enter priority of process %d: ",x+1);
        scanf("%d",&pro[x].priority);
    }

    for(i = 0; i < processes; i++){
        int z;
        for(z = 0; z < processes; z++){
            if(i+1 == pro[z].priority){
                break;
            }
        }
        wait_time[z] = sum;
        for( j = 0; j < pro[z].burst_time; j++){
            printf("-");
            sum++;
        }
        printf("|");
    }

        printf("\n");

    for( z = 0; z < processes; z++){
        printf("Wait time of process %d: %d",z+1,wait_time[z]);
        printf("\n");
        sum2 = sum2 + wait_time[z];
    }

    printf("Average wait time of processes: %d",sum2/processes);


}
