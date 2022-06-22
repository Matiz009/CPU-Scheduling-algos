#include<stdio.h>

int main(){

int block_size[100],process_size[100],flags[100],block_no,process_no,allocated[100];
int i,j=0;

//initializing values
for(i=0;i<100;i++){
    flags[i]=0;
    allocated[i]=-1;
}
printf("Enter number of blocks:\t");
scanf("%d",&block_no);
for(i=0;i<block_no;i++){
    printf("Enter size of block %d:\t",i+1);
    scanf("%d",&block_size[i]);
}

printf("Enter number of processes:\t");
scanf("%d",&process_no);

for(i=0;i<process_no;i++){
    printf("Enter the size of process %d:\t",i+1);
    scanf("%d",&process_size[i]);
}

for(i=0;i<block_size;i++){
    for(j=0;j<process_size;j++){
        if(flags[j]==0 &&block_size[j]>process_size[i]){
            allocated[i]=i;
            flags[j]=1;
            break;
        }
    }
}

printf("\nBlock number\tSize\t\tProcess no\t\tSize");
for(i=0;i<block_no;i++){
    if(flags[i]==1){
        printf("%d\t\t\t%d",allocated[i]+1,process_size[allocated[i]]);
    }else{
        printf("Not allocated\n");
    }
}

return 0;
}
