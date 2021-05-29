// BasicProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "MarkSheetStructs.h"
#include <stdlib.h>
#define BATCH_SIZE 20
#define getNumber() rand() % 90 
#define NUM_TERMS 4
#define NUM_SUBS  5
const char* globSubject[NUM_SUBS] = {"Math", "Science", "Literature", "Biology", "Mechanics" };

int populateSubs(sub* term) {
    // term = (sub*)malloc(NUM_SUBS * sizeof(sub));
    // if(term == NULL) return EXIT_FAILURE;
    for (int i = Math; i < NUM_SUBS; i++) {
        term[i]._mark = getNumber();
        term[i]._subject = globSubject[i];
    }
    return EXIT_SUCCESS;
}

int populateSubsForAllTerm(markSheet* terms) {
    terms->_firstTerm = (sub*)malloc(NUM_SUBS * sizeof(sub));
    terms->_secondTerm = (sub*)malloc(NUM_SUBS * sizeof(sub));
    terms->_thirdTerm = (sub*)malloc(NUM_SUBS * sizeof(sub));
    terms->_fourthTerm = (sub*)malloc(NUM_SUBS * sizeof(sub));
    if (terms->_firstTerm == NULL ||
        terms->_secondTerm == NULL ||
        terms->_thirdTerm == NULL ||
        terms->_fourthTerm == NULL) {
        return EXIT_FAILURE;
    }


    populateSubs(terms->_firstTerm);
    populateSubs(terms->_secondTerm);
    populateSubs(terms->_thirdTerm);
    populateSubs(terms->_fourthTerm);
    return EXIT_SUCCESS;
}

int populateAllMarksheets(student* batch) {

    for (int n = 0; n < BATCH_SIZE; n++) {
        batch[n]._roll = n;
        batch[n]._terms = (markSheet*)malloc(sizeof(markSheet));
        if (batch[n]._terms == NULL) return EXIT_FAILURE;
        populateSubsForAllTerm(batch[n]._terms);
    }
    return EXIT_SUCCESS;
}

void oneTermData(sub* term) {
    static int count = 0;
    printf("\nFor term %d:\n", ++count);
    if (term == NULL) { return; }
    for (int j = 0; j < NUM_SUBS; ++j) {
        printf("%s: %d  ", term[j]._subject, term[j]._mark);
    }
    puts("\n");
}

void getDataForStudent(int roll, student* batch) {
    student st = batch[roll];
    printf("Result of Roll: %d\n", st._roll + 1);
    markSheet* terms = (st._terms);
    if (terms == NULL) { return; }


    oneTermData(terms->_firstTerm);
    oneTermData(terms->_secondTerm);
    oneTermData(terms->_thirdTerm);
    oneTermData(terms->_fourthTerm);
}

int main()
{
    student* batch = (student*) malloc(BATCH_SIZE*sizeof(student));
    if(batch == NULL ) return EXIT_FAILURE;
    int roll = -1;

    populateAllMarksheets(batch);
    printf("Please enter student Roll Number: ");
    scanf_s("%d", &roll);
    if(roll<= 0 || roll > BATCH_SIZE ){printf("\nInvalid Roll number");}
    else{
        roll = roll - 1; // setting actual roll Number in storage staring from index 0
        getDataForStudent(roll, batch);
    }
    return EXIT_SUCCESS;
}
