#include <runSimulations.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
   srand(time(0));
   int ranL = atoi(argv[1]);
   int ranR = atoi(argv[2]);
   int timeL = atoi(argv[3]);
   int timeR = atoi(argv[4]);

   runSimulations(ranL, ranR, timeL, timeR);
   return 0;
}
void runSimulations(int ranL, int ranR, int timeL, int timeR){
   struct results* result=NULL;
   struct results* temp=NULL;

   int i;
   result = runOneSimulation(ranL, ranR, timeL, timeR);
   for(i=0;i<100;i++){
      temp= runOneSimulation(ranL, ranR, timeL, timeR);
      result->countL += temp->countL;
      result->averageWaitL += temp->averageWaitL;
      if(result->maxWaitL < temp->maxWaitL){
         result->maxWaitL = temp->maxWaitL;
      }
      result->clearTimeL +=temp->clearTimeL;
      result->countR += temp->countR;
      result->averageWaitR += temp->averageWaitR;
      if(result->maxWaitR < temp->maxWaitR){
         result->maxWaitR = temp->maxWaitR;
      }
      result->clearTimeR += temp->clearTimeR;
      free(temp);
   }
   result->countL = result->countL/100;
   result->averageWaitL = result->averageWaitL/100;
   result->clearTimeL = result->clearTimeL/100;
   result->countR = result->countR/100;
   result->averageWaitR = result->averageWaitR/100;
   result->clearTimeR = result->clearTimeR/100;

   printf("Parameter values:\n");
   printf("   from left:\n      traffic arrival rate:%3d\n      traffic light period:%3d\n", ranL, timeL);
   printf("   from right:\n      traffic arrival rate:%3d\n      traffic light period:%3d\n", ranR, timeR);
   printf("Results (averaged over 100 runs):\n");
   printf("   from left:\n      number of vehicles:%7d\n      average waiting time:%7.2f\n      maximum waiting time:%4d\n      clearence time:%10d\n", result->countL, result->averageWaitL, result->maxWaitL,result->clearTimeL);
   printf("   from right:\n      number of vehicles:%7d\n      average waiting time:%7.2f\n      maximum waiting time:%4d\n      clearence time:%10d\n", result->countR, result->averageWaitR, result->maxWaitR, result->clearTimeR);
}
