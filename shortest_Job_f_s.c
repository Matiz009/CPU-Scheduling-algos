#include<stdio.h>

int main ()
{
  int n;
  int w_t = 0;
  int total = 0;
  int average = 0;
  printf ("Enter the number of processes:\t");
  scanf ("%d", &n);
  int array[n];
  int i;
  int j;
  int temp;
  for (i = 0; i < n; i++)
    {
      printf ("\n\nEnter the burst time for the %d process:\t", i + 1);
      scanf ("%d", &array[i]);

    }
  for (i = 0; i < n; i++)
    {
      printf ("\n\nBurst time for the %d process:\t%d\n", i + 1, array[i]);

    }

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n - i - 1; j++)
	{
	  if (array[j] > array[j + 1])
	    {
	      // swap the elements
	      temp = array[j];
	      array[j] = array[j + 1];
	      array[j + 1] = temp;
	    }
	}
    }
  printf ("\nWait time for the process:\t%d\n", w_t);
  for (i = 0; i < n - 1; i++)
    {
      w_t = array[i] + w_t;
      printf ("\nWait time for the next process:\t%d\n\n\n", w_t);
      total = total + w_t;
    }
    
  for (i = 0; i < n; i++)
    {
      printf ("-\t");
      for (j = 0; j < total; j++)
	{
	  printf ("|\t");
	}
    }
  average = total / n;
  printf ("\n\nAverage time:\t%d\n", average);




  return 0;
}
