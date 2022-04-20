#include<stdio.h>
#include<conio.h>
#define size 20

int main(){
    int n,i,qt,count=0,temp,sq=0,bt[size],wt[size],tat[size],rem_bt[size];
    float awt=0,atat=0;

    printf("Enter number of processes:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter burst time of process p%d:\t",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter quantum time:\t");
    scanf("%d",&qt);
    while(1){
        for(i=0,count=0;i<n;i++){
            temp=qt;
            if(rem_bt[i]==0){
                count++;
                continue;
            }
            if(rem_bt[i]>qt){
                rem_bt[i]=rem_bt[i]-qt;
            }else if(rem_bt[i]>=0){
              temp=rem_bt[i];
              rem_bt[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count){
            break;
        }

    }


    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
    }

    awt=awt/n;
    atat=atat/n;

    printf("\nAverage waiting time:\t%f\n",awt);
    printf("Average Turn around time:\t%f\n",atat);


return 0;
}
