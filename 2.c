#include<stdio.h>
#include<string.h>
char str[100],pat[50],rep[50],res[200];
int c=0,i=0,j=0,m=0,k,flag=0;
void StringMath(){
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!=0;k++,j++){
                    res[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else{
            res[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }


    }
res[j]='\0';
}
int main(){
    printf("Enter the main string :");
    scanf("%[^\n]s",str);

    getchar();

    printf("\nEnter the pat string :");
    scanf("%[^\n]s",pat);
    getchar();

    printf("\n Enter the replacement string:");
    scanf("%[^\n]s",rep);
    

    printf("\n The string before patter matching is :\n %s",str);
    StringMath();
    if(flag==1) 
    printf("\n THe string after pattern matching & replacing is :\n %s",res);
    else
    printf("\n Patter string is not found ");
return 0;
}