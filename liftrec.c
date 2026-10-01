#include <stdio.h>
#include <stdlib.h>



int fw(int a,int b,int *dests,int nrid)
{
  int cost1,cost2,i,sum,temp;
  sum=0;
  for (i=0;i<nrid;i++)
  {
    cost1=0;  //initializeing
    cost2=0;  //initializing
    if (b == -1) 
    {
      temp=dests[i]-a;  //dests[i]-a is the amount of steps a person has to walk if the get off the floor a 
      if (temp>0)       
      {
        sum=sum+temp;
      } 
    }
    else
    {
      if ((dests[i]>a) && (dests[i]<=b))
      {
        cost1=dests[i]-a;
        cost2=b-dests[i];
        if (cost1<cost2)
        {
          sum=sum+cost1;
        }
        else 
        {
          sum=sum+cost2;
        }
      }
    }
  }
  return sum;
}









int M(int i,int j,int *dests,int nrid)
{
  int kati,min,k;
  if ((i==0)||(j==0))       //i=0 means that the number of accepatble stations is 0, if j=o means that same ..it means that the highest floor it will go is the floor 0 
  {
    kati=fw(0,-1,dests,nrid);  //so everyone will only walk,so the cost is all of their steps
    return kati;
  }
  else 
  {
    min=0;
    for (k=0;k<=j;k++)
    {
      //infinity is symbolized as -1 because both are values that in reality can never happen
      kati= M(i-1,k,dests,nrid)-fw(k,-1,dests,nrid)+fw(k,j,dests,nrid)+fw(j,-1,dests,nrid); 
      if (kati<min || k ==0)
      {
        min=kati; 
      }
    }
    return min;
  }
}








int solve(int nrid, int nst, int *dests)
{
  int minj,Mincost,i,j,nfl,max,m;
  max=0;
  for (i=0;i<nrid;i++)
  {
    if (dests[i]>max)
    {
      max=dests[i];
    }
  }
  nfl=max;                 //nfl is the highest destination
  minj=0;                 //initializing
  Mincost=0;             //initializing
  for (j=0;j<=nfl;j++)  //from now on we apply the mathematical functions we are given
  {
    m=M(nst,j,dests,nrid); //calling the M function
    if (m<Mincost || j==0)
    {
      Mincost=m;            //storing the minimum cost 
      minj=j;              //storing the floor where the cost becomes minimum if it becomes the last stop
    }
  }
  if (minj==0)          
  {
    printf("No lift stops\n");        //minj=0 means that mincost exists if the lift doesnt move
  }
  else
  {
   printf("Last stop at floor %d\n",minj); 
  }
  return Mincost;
}








