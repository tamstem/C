/*
 Slot mchine - player wins if he gets 3 identical symbols.
 Symbols are: cherries , bells, plums, lemons, melons, 7
 Save sybols in an array
 char symbols[]={'c','b','p','l','m','7'};
 Program simulates game for N=1000000 times and prints the probability that the player wins.
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    
    int cnt=0;
    int N=1000000;
    srand(time(NULL));
    char symbols[]={'c','b','p','l','m','7'};
    char game[3];
    
    for(int j=0;j<N;j++){
        for (int i=0;i<3;i++){
            game[i]=symbols[rand()%6];
        }
        if(game[0]==game[1] && game[1] ==game[2]) cnt++;
    }
    printf("probability %lf \n",cnt/(double)N);
    return 0;
} 
