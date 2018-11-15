/*
 There are 5 candidates and 20 voters (each allowed only one vote) in an election. Votes are recorded as a number from 1 to 5 and any vote that is not a number from 1 to 5 is invalid. Determine the winner.
 */

#include <stdio.h>
#define MAX_CAND_LIM 5
#define MAX_NAME_LIM 30
#define MAX_VOTES_LIM 20

typedef struct {
    char candidate_name[MAX_NAME_LIM];
    int number_of_votes;
} Candidate;

typedef struct { int valid, invalid; } Vote_Counter;

void init_candidates(Candidate candidates[], int candidates_len){
    for (int i = 0; i < candidates_len; i++){
        scanf(" %[^\n]", candidates[i].candidate_name);
        candidates[i].number_of_votes = 0;
    }
}

void init_votes(int votes[], int votes_len) {
    for (int i = 0; i < votes_len; i++) {
        scanf("%d", &votes[i]);
    }
}

Vote_Counter analyse_votes(Candidate candidates[], int candidates_len, int votes[], int votes_len){
    Vote_Counter tmp;
    tmp.valid = tmp.invalid = 0;
    for (int i = 0; i < votes_len; i++) {
        if (votes[i] < 1 || votes[i] > candidates_len) {
            tmp.invalid++;
        }
        else {
            candidates[votes[i] - 1].number_of_votes++;
            tmp.valid++;
        }
    }
    return tmp;
}
int winner(Candidate candidates[], int candidates_len) {
    // returns the index of the winner (candidate with highest number of votes)
    int big = 0;
    for (int i = 0; i < candidates_len; i++)
        if (candidates[i].number_of_votes > candidates[big].number_of_votes)
            big = i;
    return big;
}

void sort(Candidate candidates[], int candidates_len) {
    // sort candidates[0..N] in descending order by number_of_votes
    Candidate key;
    for (int i = 1; i < candidates_len; i++) {
        key = candidates[i];
        int j = i - 1;
        while (j >= 0 && key.number_of_votes > candidates[j].number_of_votes){
            candidates[j + 1] = candidates[j];
            --j;
        }
        candidates[j + 1] = key;
    }
}

void print(Candidate candidates[], int candidates_len, Vote_Counter c){
    printf("Number of valid votes: %d\n", c.valid);
    printf("Number of invalid votes: %d\n", c.invalid);
    printf("Candidate       Results\n\n");
    for (int i = 0; i < candidates_len; i++)
        printf("%-15s %3d\n", candidates[i].candidate_name, candidates[i].number_of_votes);
    printf("Winner(s)\n");
    int win_idx = winner(candidates, candidates_len);
    int win_br_glasova = candidates[win_idx].number_of_votes;
    for (int i = 0; i < candidates_len; i++)
        if (candidates[i].number_of_votes == win_br_glasova)
            printf("%s\n", candidates[i].candidate_name);
}

int main() {
    Candidate candidates[MAX_CAND_LIM];
    Vote_Counter counter;
    int votes[MAX_VOTES_LIM];
    
    printf("Enter candidates:\n");
    init_candidates(candidates, MAX_CAND_LIM);
    
    printf("Enter votes:\n");
    init_votes(votes, MAX_VOTES_LIM);
    
    counter=analyse_votes(candidates, MAX_CAND_LIM, votes, MAX_VOTES_LIM);
    
    sort(candidates,  MAX_CAND_LIM);
    print(candidates, MAX_CAND_LIM, counter);
    
    return 0;
}
