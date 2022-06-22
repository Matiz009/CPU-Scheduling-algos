#include<stdio.h>
#include<conio.h>


int main(){

    int size,log_size,log_add,r,d,i,result;
    printf("Enter size of program: ");
    scanf("%d", &size);
    printf("Enter size of logical Address: ");
    scanf("%d",&log_add);
    printf("Enter size of logical Space Up-to 8 bytes: ");
    scanf("%d",&log_size);
    int pages[log_size],frame_size[log_size];
    printf("Enter frames Up-to 8 bytes\n");
    for(i=0;i<log_size;i++)
    {
        scanf("%d",&frame_size[i]);
    }
    for(i=0;i<log_size;i++)
    {
        pages[i]=i;
    }
    d = (log_add / log_size);
    r = (log_add %  log_size);

    result = (log_size * frame_size[d]);
    result += r;

    printf("Page Table\n");
    printf("Pages  Frames\n");
       for(i=0;i<log_size;i++)
        {
          printf("%d      %d\n",pages[i],frame_size[i]);
        }
       if(result > 64)
        {
            printf("Invalid Input Entered !!!");
        }
    else
   {
     printf("The logical address to be converted = %d",result);
   }

   return 0;
}


