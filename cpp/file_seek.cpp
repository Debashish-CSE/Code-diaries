#include <bits/stdc++.h>

int main(){
    FILE *fp = fopen ("input.txt", "w");
    fputs("Computer Programming Language",fp);
    fclose(fp);

    fp = fopen ("input.txt", "r");
    fseek (fp, 5L, 0); printf("%c\n", getc(fp));
    fseek (fp, 7L, 0); printf("%c\n", getc(fp));
    fseek (fp, 5L, 1); printf("%c\n", getc(fp));
    fseek (fp, -2L, 1); printf("%c\n", getc(fp));

    fclose(fp);
    return 0;
    
}
