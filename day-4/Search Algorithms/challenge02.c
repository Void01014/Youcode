#include<stdio.h>
int main()
{
    int a[] = {1,3,4,5,6,7};
    int to_find ;
    int cu, start=0, finish=5;
    int found = 0;
    printf("enter your number : ");
    scanf("%d",&to_find);
    while(start <= finish)
    {
        cu = (start + finish)/2;
        
        if (a[cu] == to_find)
        {
            printf("found ! ");
            found  = 1 ;
            break;
        }
        else if (a[cu] < to_find)
        {
            start = cu + 1;
            continue;
        }
        else if(a[cu] > to_find)
        {
            finish = cu - 1;
            continue;
        }
        
    }
    if(!found)
    {
        printf("not found");
    }
    
}