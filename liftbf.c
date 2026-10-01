#include <stdio.h>
#include <stdlib.h>


int funcost(int *dests, int *stops, int nrid, int nst, int nfl){  		//this function calculates and returns the min cost
  int i, j, temp, mincos, cost2;
  cost2= 0;								                      //total cost
  if (nst == 0) {								               //if nst=0 total cost is the sum of the steps each person has to walk
    for (i = 0; i < nrid; i++) {
      cost2=cost2+ dests[i];					       //summing everyone's steps
    }
  }
  else {									                 //now we are calculating min cost
    for (i = 0; i < nrid; i++){
      mincos = nfl + 1;                  //Initializing mincos as nfl+1 because each person's cost cannot be higher than the maximum ammount of steps+1
      for (j = 0; j < nst; j++){
        temp = dests[i] - stops[j];
        if (temp < 0){                //temp must be positive, even if its not
          temp= temp*(-1);
        }
        if (dests[i] <= temp) {
          temp = dests[i];
        }
        if (temp < mincos){				      //now we find min cost
          mincos = temp;
        }
      }
      cost2=cost2 + mincos;						//calculating the total cost by also adding the min cost
   }
  }
  return cost2;
}


int * funcopy(int *a, int *b, int nst){   					//this function copies stops into savedstops
  int i;
  for(i = 0; i < nst; i++){
    b[i] = a[i];							                    //transferring a to b
  }
  return b;
}




int solve(int nrid, int nst, int *dests) {
  int i, j, nfl, cost1, mincos, flag1, flag2, temp;
	int *stops;
  int *savedstops;
  nfl = 0;
  for (i = 0; i < nrid; i++) {
    if (dests[i] > nfl) {						
      nfl = dests[i];
    }
	}
  stops = malloc(sizeof(int)*(nst));
  if (stops==NULL)
  {
    printf("Cannot allocate memory\n");
    return -1;
  }
  savedstops = malloc(sizeof(int)*(nst)); 					//we use savedstops to save and print stops 
  if (savedstops==NULL)
  {
    printf("Cannot allocate memory\n");
    return -1;
  }
  for (i = 0; i < nst; i++) {						           //initializing stops and savedstops with 0
    stops[i] = 0;
    savedstops[i] = 0;
  }
  mincos = nrid * nfl;							   //min cant be higher than the ammount of people multiplied by the max ammount of steps
  flag1 = 0;                          //flag1 will be 0 until all every possibility is tested.
  while (flag1 == 0) {     						
    i = 1;
    flag2 = 0;
    stops[nst - i]++;
    temp = funcost(dests, stops, nrid, nst, nfl);
    if (temp < mincos) {
      mincos = temp;
      funcopy(stops, savedstops, nst);
    }
    while (flag2 == 0) {
      if (stops[nst - i] < nfl) {
        flag2 = 1;
      }
      else {
        stops[nst - i] = 0;
        i++;
        if (i > nst) {				                 	  //now both while will end
          flag1 = 1;
          flag2 = 1;
        }
        else {
          stops[nst - i]++;
          temp = funcost(dests, stops, nrid, nst, nfl);
          if (temp < mincos) {			            //now we are finding the minimum mincos
            mincos = temp;
            funcopy(stops, savedstops, nst);
          }
        }
      }
    }
  }
	if (nst == 0) {
		printf("No lift stops");
	}
	else {
    printf("Lift stops are: ");
    for (i = 0; i < nst; i++) {
			if (savedstops[i] != 0) {				//savedstops has saved the lift stops
        printf("%d ", savedstops[i]);
			}
    }
	}
  printf("\n");
	cost1 = mincos;
  return cost1;
  free(stops);
  free(savedstops);
}										




