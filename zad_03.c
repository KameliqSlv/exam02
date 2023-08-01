#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[]){
    if(argc == 0){
        fprintf(stderr, "Invalid nummber of argument\n");
        return EXIT_FAILURE;
    }

    double sum = 0.0;


    char *arr[20];

   

    
    for (size_t i = 0; i<argc; i++) {
        //arr[i] = argv[i];

        double int_val = atof(argv[i]);
        sum += int_val;
        

        


    } 

   

    printf("Sum = %.2lf\n", sum);
    
}