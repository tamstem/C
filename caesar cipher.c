/*
 Ceasar cipher
 Enter one sentence and one integer. Turn all lowercase letters in a a sentence into uppercase.
 For entered sentence, shift every letter alphabetically for a step k, so that for  k=5 every letter  "A" in a sentence becomes"F", "B" becomes "G",... , "Z" becomes "E".
 Example: For  "String!" and k=5 program prints:
XYWNSL!
 */

#include <stdio.h>
#define MAX_LIMIT 100 // max string length
int main(){
    char str[MAX_LIMIT];
    int i, k;
    
    printf("Unesi string: ");
    fgets(str,MAX_LIMIT,stdin);
    printf("Unesi broj: ");
    scanf("%d", &k);
    k=k%26;
    
    for(int i=0; str[i]!='\0'; i++){ //lowercase to uppercase
        if(str[i]>=97 && str[i]<=122)
            str[i]-=32;
    }
    for (int i=0;str[i]!='\0';i++){
        if(str[i]+k>=65 && str[i]+k<=90)
            str[i]=str[i]+k;
        else if(str[i]+k>90)
            str[i]=str[i]+k-26;
    }
    printf("%s",str);
    return 0;
}
