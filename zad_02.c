#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char model[20];
    uint8_t maxspeed;
    double price;
}Car;

int cmp_by_model_inc(const void* a, const void* b){
    return strcmp(((Car*)a)->model, ((Car*)b)->model);
}

int cmp_by_model_dec(const void* a, const void* b){
    return strcmp(((Car*)b)->model, ((Car*)a)->model);
}

int cmp_by_maxspeed_inc(const void* a, const void* b){
    return ((Car*)a)->maxspeed - ((Car*)b)->maxspeed;
}

int cmp_by_maxspeed_dec(const void* a, const void* b){
    return ((Car*)b)->maxspeed - ((Car*)a)->maxspeed;
}

int cmp_by_price_inc(const void* a, const void* b){
    return ((Car*)a)->price - ((Car*)b)->price;
}

int cmp_by_price_dec(const void* a, const void* b){
    return ((Car*)b)->price - ((Car*)a)->price;
}





int (*GetComparator (int n))(const void*, const void*){
    if(n == 1) return cmp_by_model_inc;
    else if (n == 2) return cmp_by_model_dec;
    else if(n == 3) return cmp_by_maxspeed_inc;
    else if(n == 4) return cmp_by_maxspeed_dec;
    else if(n == 5) return cmp_by_price_inc;
    else if(n == 6) return cmp_by_price_dec;
    else return NULL;
}


int main(){
    Car car[10];
    for (size_t i = 0; i < 10; i++){
        char model[20];
        int length = rand() % 10;
        for (size_t j = 0; j < length; j++){
            model[j] = 'A' + (rand() % 26);
        }
        model[length] = '\0';
        // край на генерирането на случайната марка

        //arr[i ] = -100 + rand() % 201;
        // [100 - 300]
        car[i].maxspeed = 100 + rand() % 401;
        //kraj

        //[1000.00 - 100 000.00]
        car[i].price = (double)10000  + rand() % 1000000/10.;
        //kraj
    }

    int n;
    printf("Ender a num between 1 and 6: ");
    scanf("%d", &n);
    
    //int *p = &n;
    //GetComparator(n);

    // qsort(arr,N,sizeof(points), compare_ints__inc);
    qsort(car, sizeof(car)/sizeof(car[0]), sizeof(Car), GetComparator(n));

    for(size_t i = 0; i < 10; i++){
        printf("Model = %s, Maxspeed = %d, Price = %.2lf\n", car[i].model, car[i].maxspeed, car[i].maxspeed, car[i].price);
    }
    printf("\n");

    return 0;
}