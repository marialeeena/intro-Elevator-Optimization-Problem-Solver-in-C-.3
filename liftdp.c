#include <stdio.h>
#include <stdlib.h>

int fw(int a, int b, int * dests, int nrid) {   //same as in the recursive method
    int cost1, cost2, i, sum, temp;
    sum = 0;
    for (i = 0; i < nrid; i++) {
        cost1 = 0;
        cost2 = 0;
        if (b == -1) {
            temp = dests[i] - a;
            if (temp > 0) {
                sum = sum + temp;
            }
        } else {
            if ((dests[i] > a) && (dests[i] <= b)) {
                cost1 = dests[i] - a;
                cost2 = b - dests[i];
                if (cost1 < cost2) {
                    sum = sum + cost1;
                } else {
                    sum = sum + cost2;
                }
            }
        }
    }
    return sum;
}


int solve(int nrid, int nst, int * dests) {
    int minj, Mincost, i, j, nfl, max, min, ** Marray;
    int k,kati,** Karray,mink,*stops,value,value2,temp,a;
    max = 0;
    for (i = 0; i < nrid; i++) {
        if (dests[i] > max) {
            max = dests[i];
        }
    }
    nfl = max;
    minj = 0;

    Marray = malloc((nst + 1) * sizeof(int * ));               //same as the memoization method where w ehad the t array
    if (Marray == NULL) {
        return -1;
    }
    for (i = 0; i <= nst; i++) {
        Marray[i] = malloc((nfl + 1) * sizeof(int));
        if (Marray[i] == NULL) {
            return -1;
        }
    }

    Karray = malloc((nst + 1) * sizeof(int * ));                  //creating the 2D array where we will store the k values
    if (Karray == NULL) {
        return -1;
    }
    for (i = 0; i <= nst; i++) {
        Karray[i] = malloc((nfl + 1) * sizeof(int));
        if (Karray[i] == NULL) {
            return -1;
        }
    }

    stops=malloc(nrid*sizeof(int));                        //creating the 1D array where we will store the floors where it will stop
    if (stops==NULL)
    {
      printf("Cannot allocate memory\n");
      return -1;
    }

    
    for (j = 0; j <= nfl; j++) {                     //initializing the first line of the array,so that we have the base for the next 3for loop to step on
        Marray[0][j] = fw(0, -1, dests, nrid);
    }

    for (j = 0; j <= nfl; j++) {                      //initializing the first line of the array
        Karray[0][j] = j;
    }


    Mincost = Marray[0][0];
    for (i = 1; i <= nst; i++) {
        for (j = 0; j <= nfl; j++) {
            min = -1;
            for (k = 0; k <= j; k++) {                             //this for loop is the same as the one in M in the recursive method except now we dont do recursive,we have already stored in the Marray the previous value so we use it to create the next
              kati = Marray[i - 1][k] - fw(k, -1, dests, nrid) + fw(k, j, dests, nrid) + fw(j, -1, dests, nrid);
                if (kati < min || k == 0) 
                {
                  min = kati;
                  mink=k;        //keeping the min k
                }
            }
            Karray[i][j] = k;    //storing the mink in the Karray
            Marray[i][j] = min;  
            if (min < Mincost) {   //same as in the recursive method
                Mincost = min;
                minj = j;
            }
        }
    }


  


    j=minj;        //we want to start viewing Karray from the place where laststop is stored towards the start of the array
    a=0;
    for (i=nst;i>=0;i--)
    {
       value2=Karray[i][j];     
       j=value2;
       stops[a]=j;              //lift will stop where Mij became min
       a++;
    }



    for(i=0;i<=nst;i++)
    {
      for(j=0;j<=nfl;j++)
      {
        printf("%3d ",Marray[i][j]);
      }
      printf("\n");
    }
    
    for(i=0;i<=a;i++)
    {
        //printf("%d ",stops[i]);  this is in a comment because it doesnt print the correct things
    }

  
    if (minj == 0) {
        printf("No lift stops\n");
    } else {
        printf("Last stop at floor %d\n", minj);
    }
    return Mincost;
    free (Marray);
    free (Karray);
    free (stops);
}

