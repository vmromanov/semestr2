#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct student
{
        char* name;
        int age;
        int course;
        char** subjects;
        float* grades;
        int num_subjects;
}student;

typedef struct studentDataBase
{
    student* students;
    size_t size;
    size_t capacity;
}studentDataBase;

student* createStudent(const char* name, int age, int course, char** subjects, int num_subjects) {
    student* students = (student*)malloc(sizeof(student));
    if (students == NULL)return NULL;
    students->name = malloc(strlen(name) * sizeof(char));
    if (students->name == NULL) 
        {free(students); return NULL; }
    strcpy(students->name, name);
    students->age = age;
    students->course = course;
    students->subjects = subjects;
    students->grades = (float*)malloc(num_subjects * sizeof(float));
    if (students->grades == NULL) { free(students); return(NULL); }
    students->num_subjects = num_subjects;
    return students;
}

void addGrade(student* students, const char* subject, float grade) 
{
    for (int i = 0; i < students->num_subjects; i++) {
        if (strcmp(students->subjects[i], subject) == 0) {
            students->grades[i] = grade;
            return;
        }
    }
    printf("subject %s doesnt found.\n", subject);
}

float calculateAverageGrade(student* students) {
    float sum = 0.0; 
    for (int i = 0; i < students->num_subjects; i++) { 
        sum += students->grades[i]; 
    }
    return sum / students->num_subjects; 
}

void addSubject(student* students, const char* subject) 
{
   
    char** save;
    save = (char**)realloc(students->subjects, (students->num_subjects + 1) * sizeof(char*));
    if (save != NULL) students->subjects = save;
   
    students->subjects[students->num_subjects] = (char*)malloc((strlen(subject) + 1) * sizeof(char));
    if (students->subjects[students->num_subjects] == NULL) { printf("new subject memmory error\n"); return; }
 
    strcpy(students->subjects[students->num_subjects], subject);
   
    students->num_subjects++;
    
    float* gsave;
    gsave = (float*)realloc(students->grades, students->num_subjects * sizeof(float));
    if (gsave != NULL)
        students->grades = gsave;
}

void printstudent(student* stdt)
{
    printf("\nname: %s\n", stdt->name);
    printf("age: %d\n", stdt->age);
    printf("course: %d\n", stdt->course);
    for (int i = 0; i < stdt->num_subjects; ++i)
        printf("%s : %f\n", stdt->subjects[i],stdt->grades[i]);
}

studentDataBase* createdatabase(size_t size)
{
    studentDataBase* db = malloc(sizeof(studentDataBase));
    if (!db)
    {
        printf("data base creation error(memmory)\n");
        return NULL;
    }
    db->students = malloc(size * sizeof(student));
    if (db->students == NULL)
    {
        free(db);
        printf("data base creation error(memmory)\n");
        return NULL;
    }
    db->size = 0;
    db->capacity = size;
    return db;
}

void deleteDataBase(studentDataBase* db)
{
    free(db->students);
    free(db);
    return;
}

void studentAdd(studentDataBase* db, student stdnt)
{
    if (db->size >= db->capacity)
    {
        db->capacity *= 2;
        student* save;
        save = realloc(db->students, db->capacity * sizeof(student));
        if (!save)
        {
            printf("error allocating memm to new student\n");
            return;
        }
        db->students = save;
    }

    db->students[db->size++] = stdnt;
}

void PrintDatabase(const studentDataBase* db)
{
    printf("database:\n");
    for (size_t i = 0; i < db->size; i++)
    {
        printstudent(&db->students[i]);
    }
}

void deleteStudentByNameAndCourse(studentDataBase* db, const char* name, int course) {
    for (size_t i = 0; i < db->size; i++) {
        if (strcmp(db->students[i].name, name) == 0 && db->students[i].course == course) {
            free(db->students[i].name);
            free(db->students[i].grades);
            for (int j = 0; j < db->students[i].num_subjects; j++) {
                free(db->students[i].subjects[j]);
            }
            free(db->students[i].subjects);

            // Перемещаем последний студент вместо удаляемого и уменьшаем размер базы данных
            db->students[i] = db->students[db->size - 1];
            db->size--;

            printf("student %s at %d course deleted.\n", name, course);
            return;
        }
    }
    printf("student %s at %d course doesnt found.\n", name, course);
}


int compareByCourse(const void* a, const void* b) {
    const student* studentA = (const student*)a;
    const student* studentB = (const student*)b;
    return studentA->course - studentB->course;
}


int compareByName(const void* a, const void* b) {
    const student* studentA = (const student*)a;
    const student* studentB = (const student*)b;
    return strcmp(studentA->name, studentB->name);
}


void swap(student* a, student* b) {
    student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(student* arr, int low, int high, int (*compare)(const void*, const void*)) {
    student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if ((*compare)(&arr[j], &pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(student* arr, int low, int high, int (*compare)(const void*, const void*)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);

        quickSort(arr, low, pi - 1, compare);
        quickSort(arr, pi + 1, high, compare);
    }
}

void sortDatabaseByCourse(studentDataBase* db) {
    quickSort(db->students, 0, (long long int)db->size - 1, compareByCourse);
}

void sortDatabaseByName(studentDataBase* db) {
    quickSort(db->students, 0, (long long int)db->size - 1, compareByName);
}

student* findStudentByNameAndCourse(studentDataBase* db, const char* name, int course) {
    for (size_t i = 0; i < db->size; i++) {
        if (strcmp(db->students[i].name, name) == 0 && db->students[i].course == course) {
            return &db->students[i];
        }
    }
    return NULL; 
}

void addFromConsol(studentDataBase* db)
{
    char* name;
    int age, crs, subjectnumb;
    char** sbjkts;
    printf("formate: name,age,course,numberOfSubjects");
    scanf("%s,%d,%d,%d", name, &age, &crs, &subjectnumb);
    sbjkts = malloc(subjectnumb * sizeof(char*));
    if (!sbjkts) 
    {
        printf("cant allocate memmory to subjects");
        return;
    }

    for (int i = 0; i < subjectnumb; ++i)
    {
        printf("enter subject %d:", i + 1);
        scanf("%s", sbjkts[i]);
        printf("\n");
    }
    student* stdnt = createStudent(name, age, crs, sbjkts, subjectnumb);
    if (!stdnt)
    {
        printf("cant create student\n");
        return;
    }

    studentAdd(db, *stdnt);
    free(stdnt);
}

void deleteStudentByConsol(studentDataBase* db)
{
    int course;
    char* name;
    printf("enter name and course\n");
    printf("formate: name,course\n");
    scanf("%s,%d", name, &course);

    deleteStudentByNameAndCourse(db, name, course);
}

void findByConsol(studentDataBase* db)
{
    int course;
    char* name;
    printf("enter name and course(formate: name,course)\n");
    scanf("%s,%d", name, &course);
    student* std = findStudentByNameAndCourse(db, name, course);
    int choose;
    printf("choose what to do with student:\n");
    printf("1 - print average grade\n");
    printf("2 - print student info\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        printstudent(std);
        break;
    case 2:
        printf("average grade: %f\n", calculateAverageGrade(std));
        break;
    default:
        printf("incorrect enter\n");
        break;
    }
    
    return;
}

void sortByConsole(studentDataBase* db)
{
    int choose;
    printf("choose sort tipe\n");
    printf("enter 1 to sort by name\n");
    printf("enter 2 to sort bu course\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        sortDatabaseByName(db);
        break;
    case 2:
        sortDatabaseByCourse(db);
        break;
    default:
        printf("wrong argument, enter 1 or 2\n");
        break;
    }
    printf("data base sorted\n");
}

