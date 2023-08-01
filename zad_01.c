#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500


char* encode_str(const char *str){
    char *result = malloc(strlen(str) + 1);

    for (int i = 0; i < strlen(str); i++){
        if(i%2 == 0){
            result[i] = str[i] + 'A' - 'a';
            //result[i] = str[i] + 'A' - 'Z';
            //encode[i] = 'A';
        } else {
            switch (str[i]) {
                case '0': result[i] = '!'; break;
                case '1': result[i] = '#'; break;
                case '2': result[i] = '/'; break;
                case '3': result[i] = '~'; break;
                case '4': result[i] = '='; break;
                case '5': result[i] = '\''; break;
                case '6': result[i] = '\\'; break;
                case '7': result[i] = '>'; break;
                case '8': result[i] = '.'; break;
                case '9': result[i] = ','; break;
                default: result[i] = str[i]; break;
            }
        }
        //result[i] = '\0';
    }
    return result;

}


int main(){
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    char* result = encode_str(str);
    printf("%s\n", result);

    free(result);
    return 0;

}