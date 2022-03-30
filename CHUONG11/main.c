#include <stdio.h>
#include <stdlib.h>

int max(int a[],int n)
{
    int max=a[1];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]-a[i]>max)
              max=a[j]-a[i];
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[20];
    int n;

    FILE* file1;
    FILE* file2;
    file1 = fopen("D:\\SEQUENCEINP.txt","r");
    file2 = fopen("D:\\SEQUENCEOUT.txt","w");
    int i=0;
    while(!feof(file1))
    {
        fscanf(file1,"%d",&a[i]);
        i++;
    }
    n=a[0];
    fprintf(file2,"%d",max(a,n+1));


    fclose(file1);
    return 0;
}

