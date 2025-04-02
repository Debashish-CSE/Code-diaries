#include <iostream>

using namespace std;

int main(){
    char c;
    FILE *fp;
    fp = fopen("Input.txt", "w");
        while ((c = getchar()) != EOF){
            fprintf(fp, "%c", c);      
        }
    fclose (fp);

    fp = fopen("Input.txt", "r");
        while((c=getc(fp) != EOF)){
            printf("%c",c);
        }
    fclose(fp);
        
}