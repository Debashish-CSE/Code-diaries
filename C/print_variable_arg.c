#include <stdio.h>
#include <stdarg.h>

int max(int num_args,...);
void my_printf(char* format, ...);


int main()
{
    my_printf("Max: %d\n", max(7, 1, 5, 3, 9, 2, 8, 4));
    my_printf("My name is %s and I am %d years old.\n", "Debashish", 21);

    return 0;
}


//max function that takes variable number of arguments
int max(int num_args, ...){
    
    va_list args;
    
    va_start(args, num_args);
    int max = 0;

    for (int i=0; i<num_args; i++){
        int x = va_arg(args, int);
        
        if(i == 0) max = x;
        else if(x > max) max = x;
        
    }

    va_end(args);

    return max;
}


//write printf as a variable argument function
void my_printf(char* format, ...){

    va_list args;
    va_start(args, format);

    char* ptr = format;
    while (*ptr != '\0') {
        if (*ptr == '%' && *(ptr + 1) != '\0') {
            ptr++;  // Move to format specifier

            if (*ptr == 'd') {
                int i = va_arg(args, int);
                printf("%d", i);
            } 
            else if (*ptr == 'f') {
                double f = va_arg(args, double);
                printf("%f", f);
            } 
            else if (*ptr == 'c') {
                int c = va_arg(args, int);  // char is promoted to int
                printf("%c", c);
            } 
            else if (*ptr == 's') {
                char* s = va_arg(args, char*);
                printf("%s", s);
            } 
            else if (*ptr == '%') {
                putchar('%');
            } 
            else {
                // Unsupported specifier
                putchar('%');
                putchar(*ptr);
            }
        } 
        
        else {
            putchar(*ptr);
        }
        ptr++;
    }

    va_end(args);
    
}


    // // Check for precision like %.2f
            // if (*ptr == '.' && isdigit(*(ptr + 1))) {
            //     ptr++; // move to digit after '.'

            //     int precision = 0;
            //     while (isdigit(*ptr)) {
            //         precision = precision * 10 + (*ptr - '0');
            //         ptr++;
            //     }

            //     if (*ptr == 'f') {
            //         double f = va_arg(args, double);

            //         // Dynamically create format string like "%.2f"
            //         char fmt[10];
            //         snprintf(fmt, sizeof(fmt), "%%.%df", precision);
            //         printf(fmt, f);
            //     } else {
            //         // Unsupported format like %.2x
            //         putchar('%');
            //         putchar('.');
            //         printf("%d", precision);
            //         putchar(*ptr);
            //     }
            // }