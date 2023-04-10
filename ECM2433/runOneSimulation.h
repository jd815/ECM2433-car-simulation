#include <stdio.h>
#include <stdlib.h>
struct leftQ{
   int waitTime;
   char finished;
   struct leftQ *next;
};
struct rightQ{
   int waitTime;
   char finished;
   struct rightQ *next;
};
struct results{
   int countL;
   float averageWaitL;
   int maxWaitL;
   int clearTimeL;
   int countR;
   float averageWaitR;
   int maxWaitR;
   int clearTimeR;
};
struct results* runOneSimulation(int ranL, int ranR, int timeL, int timeR);

