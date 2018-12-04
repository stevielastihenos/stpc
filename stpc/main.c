#include <stdio.h>
#include <stdlib.h>
#include "time_functions.h"

FILE * fpointer1;
FILE * fpointer2;

void function_1(void);
void function_2(void);

int main () {

    int a;
    printf("Please enter a 0 or a 1 to indicate the mode\n");
    printf("mode 0: function 1 \nmode 1: function 2\n");
    scanf("%d",&a);

    if (a == 0) {
        printf("You have chosen mode 1\n");
        function_1();
    }

    else if(a == 1) {
        printf("You have chosen mode 2\n");
        function_2();

    }
    else printf("You have entered an incorrect value\n");

    return 0;
}

void function_1() {

    fpointer1 = fopen( "textNew.txt" , "r" );
    fpointer2 = fopen( "updatedText.txt" , "w" );

    if(fpointer1 == 0) {
        perror("fopen");
        exit(1);
    }
    char byte;
    start_nanotime();

    while((fscanf(fpointer1, "%c", &byte)) != EOF) {
        fputc(byte, fpointer2);
    }

    stop_timing();
    get_wall_clock_diff();


    fclose(fpointer1);
    fclose(fpointer2);

    printf("time: %d\n", get_nanodiff());
}



void function_2() {


    fpointer1 = fopen( "textNew.txt" , "r" );
    fpointer2 = fopen( "updatedText.txt" , "w" );
    char singleLine[81];
    if(fpointer1 == 0) {
        perror("fopen");
        exit(1);
    }

     start_nanotime();

    while (fscanf(fpointer1, " %81c[^\n]\n", singleLine) != EOF){

        fwrite(singleLine, sizeof(char), sizeof(singleLine), fpointer2);
    }

    stop_timing();
    get_wall_clock_diff();

 printf("time: %d\n", get_nanodiff());

    fclose(fpointer1);
    fclose(fpointer2);
