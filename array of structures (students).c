/*
 Define a structure Student which contains name and surname of a student, student ID and gpa.
 -Create an array of 10 students.
 -Write a function to search for a specific student.
 -Sort students alphabetically using Insertion sort
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxStudents 10
#define MAX_LIMIT 30

typedef struct {
    char name[MAX_LIMIT];
    int ID;
    double gpa;
} Student;


void printStudent(Student arr[], int n) {
    for (int i=0;i<n;i++){
        printf("name: %s, ID: %d, gpa: %lf\n", arr[i].name, arr[i].ID, arr[i].gpa);
    }
}
int search(char key[], Student arr[], int n) {
    //trazi key u arr[0] do arr[n-1]
    //if naden, return lokaciju; if nije naden, return -1
    for (int i = 0; i < n; i++)
        if (strcmp(key, arr[i].name) == 0) return i;
    return -1;
}

void sort(Student arr[], int n) {
    //sort arr[0] do arr[n-1] po namenu koristeci insertion sort
    for (int i = 1; i < n; i++) {
        Student temp = arr[i];
        int k = i - 1;
        while (k >= 0 && strcmp(temp.name, arr[k].name) < 0) {
            arr[k + 1] = arr[k];
            k = k - 1;
        }
        arr[k + 1] = temp;
    }
}
int main() {
    Student stud[MaxStudents];
    char name[MAX_LIMIT];
    char key[MAX_LIMIT];
    char choice;
    
    for (int i = 0; i < MaxStudents; i++){
        printf("Enter name, ID and gpa for %d. student:",i+1);
        scanf (" %[^\n]", &stud[i].name);
        scanf("%d",&stud[i].ID);
        scanf("%lf",&stud[i].gpa);
    }
    printf("Students:");
    printStudent(stud,MaxStudents);
    printf("Search for a student (y/n)?");
    scanf(" %c",&choice);
    while(choice=='y'){
        printf("Upisite name studenta:");
        scanf (" %[^\n]", key);
        int ans = search(key, stud,MaxStudents);
        if (ans == -1) printf("%s nije na arri studenata\n", key);
        else printf("name: %s ID: %d gpa: %lf\n", stud[ans].name, stud[ans].ID, stud[ans].gpa);
        printf("Trazi studenta (y/n)?");
        scanf(" %c",&choice);
    }
    
    printf("Sorted:\n");
    sort(stud, MaxStudents);
    printStudent(stud,MaxStudents);
    return 0;
}

