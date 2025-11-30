#include <stdio.h>
#include <string.h>
#define MAX 100

struct student {
    char name[30];
    int roll;
    int marks[3];
    float percentage;
    char grade[3];
};

void calculateGrade(struct student *s) {
    float p = s->percentage;
    if (p >= 90) strcpy(s->grade, "A+");
    else if (p >= 80) strcpy(s->grade, "A");
    else if (p >= 70) strcpy(s->grade, "B+");
    else if (p >= 60) strcpy(s->grade, "B");
    else if (p >= 50) strcpy(s->grade, "C");
    else strcpy(s->grade, "F");
}

float getValidMarks() {
    float m;
    while (1) {
        scanf("%f", &m);
        if (m >= 0 && m <= 100) return m;
        printf("Enter valid marks (0-100): ");
    }
}

void sortByPercentage(struct student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j].percentage > s[i].percentage) {
                struct student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    struct student s[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for Student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        float sum = 0;
        printf("Enter marks for 3 subjects:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            s[i].marks[j] = getValidMarks();
            sum += s[i].marks[j];
        }

        s[i].percentage = sum / 3.0;
        calculateGrade(&s[i]);
    }

    float classAvg = 0;
    for (int i = 0; i < n; i++)
        classAvg += s[i].percentage;
    classAvg /= n;

    printf("\nStudent Records\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\nRoll: %d\nPercentage: %.2f\nGrade: %s\n",
               s[i].name, s[i].roll, s[i].percentage, s[i].grade);
    }

    printf("\nClass Average = %.2f\n", classAvg);

    printf("\nStudents above average\n");
    for (int i = 0; i < n; i++)
        if (s[i].percentage > classAvg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);

    printf("\nStudents below average\n");
    for (int i = 0; i < n; i++)
        if (s[i].percentage < classAvg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);

    int rollSearch;
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollSearch);

    printf("\nSearch Result\n");
    for (int i = 0; i < n; i++)
        if (s[i].roll == rollSearch)
            printf("Name: %s, Percentage: %.2f, Grade: %s\n",
                   s[i].name, s[i].percentage, s[i].grade);

    char gradeSearch[3];
    printf("\nEnter grade to search (A+, A, B+, B, C, F): ");
    scanf("%s", gradeSearch);

    printf("\nStudents with Grade %s\n", gradeSearch);
    for (int i = 0; i < n; i++)
        if (strcmp(s[i].grade, gradeSearch) == 0)
            printf("%s (Roll %d)\n", s[i].name, s[i].roll);

    sortByPercentage(s, n);

    printf("\nClass Ranks\n");
    for (int i = 0; i < n; i++)
        printf("Rank %d: %s (%.2f)\n", i + 1, s[i].name, s[i].percentage);

    return 0;
}
