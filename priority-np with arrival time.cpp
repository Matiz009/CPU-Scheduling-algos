#include<stdio.h>
#include<conio.h>
#define size 30

int main(){
    int n,i,j,k=1,t,b=0,min,temp[size],burst_t[size],waiting_t[size],arrival_t[size],priority[size],tat[size];
    float awt=0,atat=0;

    printf("Enter the number of processes:\t");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the burst time,arrival time and priority of process p%d:\t",i+1);
        scanf("%d%d%d",&burst_t[i],&arrival_t[i],&priority[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arrival_t[i]<arrival_t[j]){
                t=arrival_t[j];
                arrival_t[j]=arrival_t[i];
                arrival_t[i]=t;

                t=burst_t[j];
                burst_t[j]=burst_t[i];
                burst_t[i]=t;
            }
        }
    }
    for(j=0;j<n;j++){
        b=b+burst_t[j];
        min=burst_t[k];
        for(i=k;i<n;i++){
            min=priority[k];
            if(b>=arrival_t[i]){
                if(priority[i]<min){
                   t=arrival_t[k];
                   arrival_t[k]=arrival_t[i];
                   arrival_t[i]=t;

                   t=burst_t[k];
                   burst_t[k]=burst_t[i];
                   burst_t[i]=t;

                   t=priority[k];
                   priority[k]=priority[i];
                   priority[i]=t;
                }

            }
        }
        k++;
    }

    temp[0]=0;
    printf("Process\t Burst time\tArrival time\tPriority\tWaiting time\t Turn around time\n");
    for(i=0;i<n;i++){
        waiting_t[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+burst_t[i];
        waiting_t[i]=temp[i]-arrival_t[i];
        tat[i]=waiting_t[i]+burst_t[i];
        awt=awt+waiting_t[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_t[i],arrival_t[i],priority[i],waiting_t[i],tat[i]);
    }

    awt=awt/n;
    atat=atat/n;

    printf("Average waiting time:\t%f ",awt);
    printf("\nAverage turn around time:\t%f ",atat);










    return 0;
}
