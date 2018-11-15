/*
 de Méré (gambler, 17 century)
 First game: roll one dice. What is the probability that in 4 rolls we get 6 at least once?
 Second game: roll two dice. What is the probability that in 24 rolls we get double 6 at least once?
 Simulate both games N times and determine the probabilities.
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    int cnt_roll6=0, cnt_roll66=0; //counters
    int j=1, k=1;
    int roll,roll1,roll2;   // dice rolls
    long int N;   //number of  simulations
    float prob1,prob2;    //probabilities
    srand(time(NULL));
    printf("Enter number of simulations: ");
    scanf("%d",&N);
    while(k<=N)    {
        //simulate first game  N times
        //count  roll 6 at least once
        for(int i = 0 ; i < 4 ; i++){
            roll=rand()%6+1; //roll dice
            if(roll==6) {cnt_roll6++; break;}
        }
        
        //simulate second game N times
        //count roll double6 at least once
        for(int i = 0 ; i < 24 ; i++){
            roll1=rand()%6+1; //roll 2 dice
            roll2=rand()%6+1;
            if(roll1==6 &&roll2==6) {cnt_roll66++; break;}
        }
        k++;
    }
    prob1=cnt_roll6/(double)N; //probability1
    prob2=cnt_roll66/(double)N;//probability2
    
    printf("Probability that in 4 rolls we get 6 at least once is %f\n",prob1);
    printf("Probability that in 24 rolls we get double 6 at least once is %f\n",prob2);
    return 0;
}



