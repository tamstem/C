/*
Guessing game (fair).
A mouse is hiding in one of three holes.
Players goal is to guess the hole in which the mouse hid (the position of a mouse is random). Player has some initial amount of money and every time he wants to play, he has to specify his bet. If the player guesses the hole, his bet doubles. If he doesn't guess correctly, he losses the invested money.
    */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int bet, total_money;
    int guess;
    
    printf("Enter total amount of money: ");
    
    scanf("%d", &total_money);
    
    while (total_money > 0) {
        printf("\nEnter your bet: ");
        scanf("%d", &bet);
        if (total_money == 0 || bet > total_money)
            break;
        char Hole[3] = { 'N', 'R', 'N' };
        printf("\nWait !! The mouse is moovig...\n");
        srand((time(NULL)));
        int i, x, y, temp;
        //moovih mouse for 5 times
        
        for (i = 0; i < 5; i++) {
            x = rand() % 3;
            y  = rand() % 3;
            temp = Hole[x];
            Hole[x] = Hole[y];
            Hole[y] = temp;
        }
        
        
        
        printf("\nEnter your guess: ");
        
        scanf("%d", &guess);
        
        if (Hole[guess - 1] == 'R') {
            (total_money) += 2 * bet;
            printf("You win!");
            printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]);
            printf("\nNow you have %d money\n", total_money);
        }
        
        else {
            (total_money) -= bet;
            printf("You lose!  ");
            printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]);
            printf("\nNow you have %d money\n", total_money);
        }
    }
    
    
    if (total_money == 0 || bet > total_money) {
        printf("Not enough money! Game over! ");
    }
    return 0;
}

