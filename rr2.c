#include<stdio.h>
void main()
{
     int k,j,q,i,n,ts,temp;
     int aw;                      float awt;
     int bt[10],wt[10],te[10],rt[10],at[10];j=0;
     printf("Enter number of processes :\t");
     scanf("%d",&n);
    printf("\n Enter burst time and arrival time\n");
    for(i=0;i<n;i++)
      {
          printf("P%d burst time ",i+1);
          scanf("%d",&bt[i]);
          printf("arrival time   :  ");
          scanf("%d",&at[i]);
          te[i]=0;     wt[i]=0;
      }
    for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
         {
             if(at[i]>at[j])
               {
                    temp=at[i];                                          //sorting according to arrival time
                    at[i]=at[j];
                    at[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
              }
         }
     }
    printf("\n enter time slice\t");
    scanf("%d",&ts); q=0;
    printf("\n process      :")  ;
    for(i=0;i<n;i++)
     {
       printf("  %d",i+1);
      }
    printf("\n Burst time   :");
    for(i=0;i<n;i++)
       {
         printf("  %d",bt[i]); rt[i]=bt[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf("  %d",at[i]);
      }
    printf("\n Gaint chart \n");
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n;i++)
            {
              if(rt[i]==0)  continue;
                   if(rt[i]>ts)
                     {
                        printf("\n %d\t P%d",q,i+1);
                        q=q+ts;
                        rt[i]=rt[i]-ts;
                        te[i]=te[i]+1;
                     }
                  else
                    {
                       printf("\n %d\t P%d",q,i+1);
                       wt[i]=q-te[i]*ts;
                       q=q+rt[i];
                       rt[i]=rt[i]-rt[i];
                    }
            }
       }                                   //end of while
    awt=0;
    printf("\n Process   Waiting time");
    for(i=0;i<n;i++)
       {
                       wt[i]=wt[i]-at[i];
                       printf("\n P%d      :   %d",i+1,wt[i]); awt=awt+wt[i];
        }
    aw=awt;
    printf("\n total waiting time %d",aw);
    printf("\n Avg waiting time %f ",awt/n);
    getch();
 }
