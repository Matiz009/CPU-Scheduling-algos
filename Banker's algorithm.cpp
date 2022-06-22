#include <stdio.h>
int main ()
{

	int number_of_processes, number_of_resources, i, j, k;
		printf("Enter number of processes:\t");
		scanf("%d",&number_of_processes);
  
  		printf("Enter number of resources:\t");
  		scanf("%d",&number_of_resources);
  
  	int alloc[number_of_processes][number_of_resources];
  	int max[number_of_processes][number_of_resources];
  	int avail[number_of_resources];
  
   		//Allocation
 		printf("Enter the allocation Matrix row wise:\t\n");
 		for(i=0;i<number_of_processes;i++){
		 	for(j=0;j<number_of_resources;j++){
        	scanf("%d",&alloc[i][j]);
    	}	
 	}
		printf("Allocation:\n");
		for (i = 0; i < number_of_processes; i++)
    {
    	for (j = 0; j < number_of_resources; j++)
	{
		printf ("%d\t", alloc[i][j]);
	}
    	printf ("\n");    
 	} 	

		//Maximum
		printf("Enter the Max Matrix row wise:\n");
 		for(i=0;i<number_of_processes;i++){
    		for(j=0;j<number_of_resources;j++){
        	scanf("%d",&max[i][j]);
    	}
 	}
 		printf("Maximum:\n");
		for (i = 0; i < number_of_processes; i++)
    {
    	for (j = 0; j < number_of_resources; j++)
	{
		printf ("%d\t", max[i][j]);
	}
    	printf ("\n");    
 	} 	

		//Available
		printf("Enter the Available Matrix:\n");
		for(i=0;i<number_of_resources;i++){
		scanf("%d",&avail[i]);
 	}

 
	int f[number_of_processes], ans[number_of_processes], ind = 0;
  	for (k = 0; k < number_of_processes; k++)
    {
      	f[k] = 0;
    }

	//Need Matrix
  	int need[number_of_processes][number_of_resources];
  	for (i = 0; i < number_of_processes; i++)
    {
    	for (j = 0; j < number_of_resources; j++)
		need[i][j] = max[i][j] - alloc[i][j];
    }
  	printf ("Need Matrix:\n");
  	for (i = 0; i < number_of_processes; i++)
    {
    	for (j = 0; j < number_of_resources; j++)
	{
		printf ("%d\t", need[i][j]);
	}
    	printf ("\n");
    }

//-----Safe state algorithm-----//

int y = 0;
	for (k = 0; k < number_of_processes; k++)
    {
    	for (i = 0; i < number_of_processes; i++)
	{
		if (f[i] == 0)
	    {

	    	int flag = 0;
	    	for (j = 0; j < number_of_resources; j++)
		{
		if (need[i][j] > avail[j])
		{
			flag = 1;
			break;
		}
	}

		if (flag == 0)
		{
			ans[ind++] = i;
			for (y = 0; y < number_of_resources; y++)
			avail[y] += alloc[i][y];
			f[i] = 1;
		}
		}
	}
}

int flag = 1;
	for (i = 0; i < number_of_processes; i++)
    {
    	if (f[i] == 0)
	{
		flag = 0;
		printf ("The system is not in safe sequence.");
		break;
		return 0;
	}
}
	if (flag == 1)
    {
    	printf ("Following is the Safe Sequence:\n");
		for (i = 0; i < number_of_processes - 1; i++)
		printf (" P%d ->", ans[i]);
      	printf (" P%d", ans[number_of_processes - 1]);
    }

//-----Resource request algorithm-----//
int process, request[number_of_resources];

	flag = 0;
  	while (flag != 1)
    {
    	flag = 1;
		fflush (stdin);		// method used to clean the buffer memory
      	printf ("\nProcess requesting for resources:");
      	scanf ("%d", &process);
      	char resource = 'P0';
      	for (k = 0; k < number_of_resources; k++)
	{
	  	fflush (stdin);
	 	printf ("Enter number of resource %c requested by process %d: ",resource, process+1);
	  	scanf ("%d", &request[k]);
	  	resource++;
	}
      	for (i = 0; i < number_of_resources; i++)
	{
	  	if (request[i] > need[number_of_processes - 1][i])
	    {
	    	flag = 0;
	    }
	}
      if (flag == 0)
	{
	  	printf ("Request resources are greater than need.\n");
	  	return 0;
	}
		flag = 1;
		for (i = 0; i < number_of_resources; i++)
	{
	  	if (request[i] > avail[i])
	    {
	    	flag = 0;
	    }
	}
    	if (flag == 0)
	{
		printf ("Process %d should wait.\n", process);
	}
}  
	for (i = 0; i < number_of_resources; i++)
    {
    	avail[i] = avail[i] - request[i];
      	alloc[process - 1][i] = alloc[process - 1][i] + request[i];
      	need[process - 1][i] = need[process - 1][i] - request[i];
    }

y = 0;
	for (k = 0; k < number_of_processes; k++)
    {
    	for (i = 0; i < number_of_processes; i++)
	{
	  	if (f[i] == 0)
	    {
			int flag = 0;
			for (j = 0; j < number_of_resources; j++)
		{
		if (need[i][j] > avail[j])
		{
			flag = 1;
			break;
		}
	}
		if (flag == 0)
		{
			ans[ind++] = i;
			for (y = 0; y < number_of_resources; y++)
			avail[y] += alloc[i][y];
			f[i] = 1;
		}
	}
	}
}
	flag = 1;
	for (i = 0; i < number_of_processes; i++)
    {
    	if (f[i] == 0)
	{
		flag = 0;
		printf ("The following system is not safe");
		break;
	}
}
	if (flag == 1)
    {
    	printf ("Following is the SAFE Sequence\n");
    	for (i = 0; i < number_of_processes - 1; i++)
		printf (" P%d ->", ans[i]);
    	printf (" P%d", ans[number_of_processes - 1]);
    }
  return 0;
}
