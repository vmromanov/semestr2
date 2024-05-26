#pragma once

typedef struct student student;

typedef struct studentDataBase studentDataBase;


student* createStudent(const char* name, int age, int course, char** subjects, int num_subjects);

void addGrade(student* students, const char* subject, float grade);

float calculateAverageGrade(student* students);

void addSubject(student* students, const char* subject);

void printstudent(student* stdt);

studentDataBase* createdatabase(size_t size);

void studentAdd(studentDataBase* db, student stdnt);

void PrintDatabase(const studentDataBase* db);

void deleteStudentByNameAndCourse(studentDataBase* db, const char* name, int course);

void addFromConsol(studentDataBase* db);

void deleteStudentByConsol(studentDataBase* db);

void findByConsol(studentDataBase* db);

void sortByConsole(studentDataBase* db);

void deleteDataBase(studentDataBase* db);