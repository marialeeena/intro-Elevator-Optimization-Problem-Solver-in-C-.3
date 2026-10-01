#include <stdio.h>
#include <stdlib.h>



int fw(int a,int b,int *dests,int nrid)    //same with rec
{
  int cost1,cost2,i,sum,temp;
  sum=0;
  for (i=0;i<nrid;i++)
  {
    cost1=0;
    cost2=0;
    if ((b==-1)|| ((a==0) && (b==0)))
    {
      temp=dests[i]-a;
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









int M(int i,int j,int *dests,int nrid,int **t)
{
  int kati,min,k,temp;

  if ((i==0)||(j==0))  //same as rec
  {
    if (t[i][j]==-1)  //if we have never calculated it before,calculate it
    {
      kati=fw(0,-1,dests,nrid);
      t[i][j]=kati;
    }
    return t[i][j];  
  }
  else 
  {
    min=0;
    for (k=0;k<=j;k++)
    {
      if (t[i-1][k]==-1)  //if we have never calculated it before,calculate it
      {
        t[i-1][k]=M(i-1,k,dests,nrid,t);
        kati=t[i-1][k]-fw(k,-1,dests,nrid)+fw(k,j,dests,nrid)+fw(j,-1,dests,nrid);
      }
      else
      {
        kati= (t[i-1][k])-fw(k,-1,dests,nrid)+fw(k,j,dests,nrid)+fw(j,-1,dests,nrid);
      }
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
  int minj,Mincost,i,j,nfl,max,m,**t;
  max=0;
  for (i=0;i<nrid;i++)
  {
    if (dests[i]>max)
    {
      max=dests[i];
    }
  }
  nfl=max;
  minj=0;
  Mincost=0;


  
  t=malloc((nst + 1) * sizeof(int * ));   //dynamically creating an array where we will store the values of the M function that we have already calculated once
  if (t==NULL) 
  {
    return -1;
  }
  for (i=0; i<=nst; i++) 
  {
    t[i]=malloc((nfl + 1) * sizeof(int));
    if (t[i]==NULL) 
    {
      return -1;
    }
  }
  for (i=0; i<=nst; i++) 
  {
    for (j=0; j<=nfl; j++) 
    {
      t[i][j]=-1;   //initializing the array
    }
   }



  for (j=0;j<=nfl;j++)
  { 
    if (t[nst][j]==-1)     //if we have never calculated it before,calculate it
    {
      m=M(nst,j,dests,nrid,t);
    }
    else                 //if we have,dont
    {
      m=t[nst][j];
    }

    
    if (m<Mincost || j==0)
    {
      Mincost=m;
      minj=j;
    }
  }
  if (minj==0)
  {
    printf("No lift stops\n");
  }
  else
  {
   printf("Last stop at floor %d\n",minj); 
  }
  return Mincost;
  free(t);
}


