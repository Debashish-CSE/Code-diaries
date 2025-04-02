#include <stdio.h>
#include <time.h>

//Calculate time elapsed to run this program
int main(){
    clock_t start_time, end_time;
    double time_elapsed;
    start_time = clock();
    int a = 0;
    for (int i=0; i<1000000000; i++){
        a++;
    }
    end_time = clock();
    time_elapsed = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time elapsed to run this program: %lf\n",time_elapsed);
    return 0;
}