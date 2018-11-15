/*
Enter an integer which represents the number of rows. Write a program which produces the following shape:
 For entered 4:
*
* *
* * *
* * * *
Use only ONE loop.
*/

#include <stdio.h>
int main() {
    int n, i=0, row ;
    printf("Enter an integer: ");
    scanf("%d",&n);
    for (row = 1; row <= n; ){
        if (i < row){
            printf("* ");
            i++;
            continue;
        }
        else if (i == row){
            printf("\n");
            row++;
            i = 0;
        }
    }
    return 0;
}
