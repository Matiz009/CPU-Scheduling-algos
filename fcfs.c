#include<stdio.h>
#include<string.h>
#define size 10

int main(){
            char processName[size][size],t[size];
            int arrival_time[size];
            int burst_time[size];
            int start_time[size];
            int end_time[size];
            int waiting_time[size];
            int i,j,n,temp;
            int total;
            printf("Enter the number of processes:\t");
            scanf("%d",&n);

                for(i=0;i<n;i++){
                    printf("Enter the process Name, arrival time and burst time of process %d:\t",i+1);
                    scanf("%s%d%d",processName[i],&arrival_time[i],&burst_time[i]);
                }
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        if(arrival_time[i]<arrival_time[j]){
                            temp=arrival_time[i];
                            arrival_time[i]=arrival_time[j];
                            arrival_time[j]=temp;
                            temp=burst_time[i];
                            burst_time[i]=burst_time[j];
                            burst_time[j]=temp;
                            strcpy(t,processName[i]);
                            strcpy(processName[i],processName[j]);
                            strcpy(processName[j],t);
                        }
                    }
                }

                    for(i=0;i<n;i++){
                        if(i==0)
                            start_time[i]=arrival_time[i];
                        else
                                start_time[i]=end_time[i-1];
                                waiting_time[i]=start_time[i]-arrival_time[i];
                                end_time[i]=start_time[i]+burst_time[i];

                    }

                    printf("\nProcess || Arrival || Burst || Waiting || Start || Finish");

                    for(i=0;i<n;i++){
                        printf("\n%s\t\t%d\t%d\t%d\t%d\t%d",processName[i],arrival_time[i],burst_time[i],waiting_time[i],start_time[i],end_time[i]);
                        total+=waiting_time[i];
                    }

                    printf("\nAverage waiting time:%f\n",(float)total/n);



return 0;
}
