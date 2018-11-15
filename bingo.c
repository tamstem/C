/*
 Every player has a ticket with 15 different random numbers between 1 and  90. The winner is the first player with a ticket for which all the numbers have been pulled.
 Program has to simulate the game for  100000 times (generirate one ticket and pull out numbers) and in the end print how many simulations resulted with a certain number of pulls.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    int s = 100000;
    int ticket[15], pull[90], test, random;
    int i, j, k=0, number, tmp, n[90]={0};
    // tmp counter to 15 (full ticket)
    while(k<s){            //simulations
        for (i=0;i<15;i++){    //ticket
            do{
                test=1;
                random=rand()%90+1;
                if(i==0) ticket[i]=random;
                else if(i>0){
                    for(j=0;j<i && test==1;j++){
                        if(ticket[j]==random) test=0;
                    }
                }
            }while(test!=1);
            ticket[i]=random;
        }
        for (i=0;i<90;i++){    //pull
            do{
                test=1;
                random=rand()%90+1;
                if(i==0) pull[i]=random;
                else if(i>0){
                    for(j=0;j<i && test==1;j++){
                        if(pull[j]==random) test=0;
                    }
                }
            }while(test!=1);
            
            pull[i]=random;
        }
        i=0;
        number=0;
        tmp=0;
        do{  //compare ticket and pulls
            for(int j=0;j<15;j++){
                if(pull[i]==ticket[j]) tmp++;
            }
            number=i++;;
        }while(tmp!=15);
        n[number]++;
        k++;
    }
    for(int i=0;i<90;i++){
        if(n[i]!=0) printf("%d  %d\n",i+1,n[i]);
    }
    return 0;
}
