// A digital clock using C
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int main(){
    time_t rawtime;
    struct tm *timeinfo;

    // Get current system time
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Initialize hour, minute, and second with current time values
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;
    int second = timeinfo->tm_sec;
    printf("hour : minute : second - ");
    while(1){
        // Record start time of the iteration
        clock_t start = clock();

        system("cls");  //to clear the screen after each output. for linux, system("clear");
        printf("%02d : %02d : %02d",hour,minute,second);
        fflush (stdout); //clear the output buffer in gcc

        second++;
        if(second == 60){
            minute++;
            second = 0;
        }
        if(minute == 60){
            hour++;
            minute = 0;
        }
        if(hour == 24){
            hour = 0;
            minute = 0;
            second = 0;
        }
        // calculate time taken for processing
        clock_t end = clock();
        double time_taken = ((double)(end - start))/CLOCKS_PER_SEC*1000.0;
        
        //Adjust sleep time to compensate for processing time
        Sleep(1000-time_taken);   //here Sleep(1000) is meaning 1000 milisecond=1 second(for windows). For linux sleep(1), which is from <unistd.h> header file  
    }

    return 0;
}
