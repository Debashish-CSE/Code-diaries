#include <bits/stdc++.h>
using namespace std;

int main(){
    string name;
    int i,n;
    char c;

    cout<<"Enter the number of students: "<<endl;
    cin>>n;
    getchar();

    FILE *fp = fopen("student.txt", "w");
    for (int i=1; i<=n; i++){
        scanf("%s",name);
        fprintf(fp, "%s\n", name);
    }

    fclose(fp);

}
