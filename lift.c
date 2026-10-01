#include <stdio.h>
#include <stdlib.h>
#include  "liftrec.h"
#include  "liftbf.h"
#include  "liftmem.h"
#include  "liftdp.h"



int main(void)
{
  int nrid,nst,*dests,max,i,nfl,j,laststop,m,Mincost,minj,all;
  //printf("How many people will get on the elevator?\n");
  if (scanf("%d", &nrid)!=1)
  {
    printf("Not acceptable value\n");
    return-1;
  }
  if (nrid<0)
  {
    printf("Not acceptable value\n");
    return-1;
  }
  //printf("How many stops can the elevator make?\n");
  if (scanf("%d", &nst)!=1)               //user input can only be numerical digits,and positive
  {
    printf("Not acceptable value\n");
    return-1;
  }
  if (nst<0)
  {
    printf("Not acceptable value\n");
    return-1;
  }
  dests=malloc(nrid*sizeof(int));    //dynamically allocating memory for the array of destinations 
  if (dests==NULL)
  {
    printf("Cannot allocate memory\n");
    return -1;
  } 
  //printf("Which are the passengers' destinations?\n");
  for (i=0;i<nrid;i++)
  { 
    if (scanf("%d", &dests[i])!=1)          //user input can only be numerical digits,and positive
    {
      printf("Not acceptable value\n");
      return-1;
    }
    if (dests[i]<0)
    {
      printf("Not acceptable value\n");
      return-1;
    }
  }
  
  all=solve(nrid,nst,dests);
  printf("Cost is: %d\n",all);
  return 0;
  free(dests);
}
