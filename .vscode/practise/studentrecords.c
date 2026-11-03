#include <stdio.h>
#include <stdlib.h>



struct Student {
    int roll;
    char name[20];
    float marks;

};

void sortRecords(struct Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].marks < s[minIdx].marks) {
                minIdx = j;
            }
        }
        // Swap entire struct in one step
        struct Student temp = s[i];
        s[i] = s[minIdx];
        s[minIdx] = temp;
    }
}

void displayRecords(struct Student s[], int n) {
    printf("\nRoll No\tName\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

int main(){
    int n;
    printf("Enter the number of students");
    scanf("%d", &n);
    struct Student s[n];
    for(int i = 0; i<n ; i++){
        printf("Enter Roll No, Name, Marks for student %d: ", i + 1);
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    sortrecords(s,n);
    displayrecords(s,n);
    return 0;

}