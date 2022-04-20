#include<stdio.h>
#define size 10
int main(){
    int arrivalTime[size],burstTime[size],endTime[size],waitingTime[size],tat[size];
    int n,temp,total_time,minimum,i,j,a;
    float averageWaitingTime=0,sum_of_waitingTime=0,sum_of_turn_around_Time=0;
    printf("Enter the number of processes:\t");
    scanf("%d",&n);
        for(i=0;i<n;i++){
            printf("Enter the arrival time and burst time of process p%d:\t",i+1);
            scanf("%d%d",&arrivalTime[i],&burstTime[i]);
        }

            for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    if(burstTime[i]>burstTime[j]){
                        temp=arrivalTime[i];
                        arrivalTime[i]=arrivalTime[j];
                        arrivalTime[j]=temp;

                        temp=burstTime[i];
                        burstTime[i]=burstTime[j];
                        burstTime[j]=temp;
                    }
                }
            }

            minimum=arrivalTime[0];

                for(i=0;i<n;i++){
                    if(minimum>arrivalTime[i]){
                        minimum=arrivalTime[i];
                        a=i;
                    }
                }

                total_time=minimum;
                endTime[a]=total_time+burstTime[a];
                total_time=endTime[a];

                for(i=0;i<n;i++){
                    if(arrivalTime[i]!=minimum){
                        endTime[i]=burstTime[i]+total_time;
                        total_time=endTime[i];
                    }
                }

                  for(i=0;i<n;i++){
                    tat[i]=endTime[i]-arrivalTime[i];
                    sum_of_turn_around_Time=sum_of_turn_around_Time+tat[i];
                    waitingTime[i]=tat[i]-burstTime[i];
                    sum_of_waitingTime=sum_of_waitingTime+waitingTime[i];
                  }
                    averageWaitingTime=sum_of_waitingTime/n;
                    printf("Average waiting time:\t%f",averageWaitingTime);




    return 0;
}
