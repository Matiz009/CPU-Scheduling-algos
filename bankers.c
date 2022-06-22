#include<stdio.h>
#include<stdlib.h>

int main(){

int number_of_processes;
int number_of_resources;
int i,j,k,y;
int allocation_matrix[100][100];
int max_matrix[100][100];
int available_resources[100];
int index=0;
int flag=0;

printf("Enter the number of processes:\t");
scanf("%d",&number_of_processes);
printf("Enter the number of resources:\t");
scanf("%d",&number_of_resources);

//Now we get the values in allocation matrix

printf("Enter the allocation Matrix:\n");
 for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        scanf("%d",&allocation_matrix[i][j]);
    }
 }

 printf("Enter the Maximum Requirement Matrix:\n");
 for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        scanf("%d",&max_matrix[i][j]);
    }
 }

 printf("Enter the Available Matrix:\n");
 for(i=0;i<number_of_resources;i++){
    scanf("%d",&available_resources[i]);
 }
 
int finished[number_of_processes];
int safe_sequence[number_of_processes];
int work[number_of_resources];
int need_Matrix[number_of_processes][number_of_resources];


for(i=0;i<number_of_resources;i++){
    work[i]=available_resources[i];
}

for(i=0;i<number_of_processes;i++){
   finished[i]=0;
}

//Now we calculate need matrix

for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        need_Matrix[i][j]=max_matrix[i][j]-allocation_matrix[i][j];
    }
}

//displaying the need matrix
printf("Need Matrix is \n");
 for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        printf("%d\t",need_Matrix[i][j]);
    }
    printf("\n");
}


    flag = 0;
    int count = 0, count2 = 0;

    for(i=0; i < number_of_resources; i++){
        work[i] = available_resources[i];
        finished[i] = 0;
    }

    for(i=0; i < number_of_processes; i++){
        finished[i] = 0;
    }
    int z =0;
    while(flag == 0){

        if (finished[count] == 0) {
        int flag2 = 0;
            for ( j = 0; j < number_of_resources; j++) {
                if (need_Matrix[count][j] > work[j]){
                    flag2 = 1;
                    z++;
                    break;
                }
            }
            if(flag2 == 0){
                for( i=0; i < number_of_resources; i++){
                    work[i] = work[i] + allocation_matrix[count][i];
                }
                finished[count] = 1;
                safe_sequence[count2++] = count;
                z =0;
            }
        }

    
        count++;
        if(count >= number_of_processes){
            count = 0;
        }

        flag = 1;



        for( i=0; i < number_of_processes; i++){
            if(finished[i] == 0){
                flag = 0;
            }
            
        }

        if(z >= number_of_processes){
            printf("The system is in the Deadlock!!!");
            flag = 0;
            break;
        }


    }
    if(flag == 1){
        printf("Following is the safe sequence:\n");
        for( i=0; i < count2; i++){
            printf("P->%d ",safe_sequence[i]+1);
        }
    }
    
    int process, request[number_of_resources];
    int flag3 = 0;
    while(flag3!=1){
        flag3 =1;
        fflush(stdin);
        printf("\nEnter the Process requesting ");
        scanf("%d",&process);
        char resource = 'A';
        int k;
        for(k = 0; k < number_of_resources; k++){
            fflush(stdin);
            printf("Enter number of resource %c requested by process %d: ",resource,process);
            scanf("%d",&request[k]);
            resource++;
        }
        for( i=0; i < number_of_resources; i++){
            if(request[i]>need_Matrix[process-1][i]){
                flag3 = 0;
            }
        }


        if(flag3 == 0){
            printf("Request greater than need!!!\n");
            return 0;
        }

        flag = 1;
        for(i=0; i < number_of_resources; i++){
            if(request[i]>available_resources[i]){
                flag3 = 0;
            }
        }

        if(flag == 0){
            printf("Process %d must wait.\n",process);
        }
    }
    for( i=0; i < number_of_resources; i++){
        available_resources[i] = available_resources[i] - request[i];
        allocation_matrix[process-1][i] = allocation_matrix[process-1][i] + request[i];
        need_Matrix[process-1][i] = need_Matrix[process-1][i] - request[i];
    }

for(i=0;i<number_of_resources;i++){
    work[i]=available_resources[i];
}

for(i=0;i<number_of_processes;i++){
   finished[i]=0;
}

//Now we calculate need matrix

for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        need_Matrix[i][j]=max_matrix[i][j]-allocation_matrix[i][j];
    }
}

//displaying the need matrix
printf("Need Matrix is \n");
 for(i=0;i<number_of_processes;i++){
    for(j=0;j<number_of_resources;j++){
        printf("%d\t",need_Matrix[i][j]);
    }
    printf("\n");
}


    flag = 0;
    int count3 = 0, count4 = 0;

    for(i=0; i < number_of_resources; i++){
        work[i] = available_resources[i];
        finished[i] = 0;
    }

    for(i=0; i < number_of_processes; i++){
        finished[i] = 0;
    }
     z =0;
    while(flag == 0){

        if (finished[count3] == 0) {
        int flag2 = 0;
            for ( j = 0; j < number_of_resources; j++) {
                if (need_Matrix[count3][j] > work[j]){
                    flag2 = 1;
                    z++;
                    break;
                }
            }
            if(flag2 == 0){
                for( i=0; i < number_of_resources; i++){
                    work[i] = work[i] + allocation_matrix[count3][i];
                }
                finished[count3] = 1;
                safe_sequence[count4++] = count3;
                z =0;
            }
        }

    
        count3++;
        if(count3 >= number_of_processes){
            count3 = 0;
        }

        flag = 1;



        for( i=0; i < number_of_processes; i++){
            if(finished[i] == 0){
                flag = 0;
            }
            
        }

        if(z >= number_of_processes){
            printf("The system is in the Deadlock!!!");
            flag = 0;
            break;
        }


    }
    if(flag == 1){
        printf("Following is the safe sequence:\n");
        for( i=0; i < count4; i++){
            printf("P->%d ",safe_sequence[i]+1);
        }
    }
    

 
 return 0;
}
