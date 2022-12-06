#include <stdio.h>
int convert(int i)
{
    if (i > 0)
    {
        convert (i/2);
        printf("%d",i%2);
    }
}
void main()
{
    int i;
    printf("Input a decimal number: ");
    scanf("%d",&i);
    
    printf("Binary number = ");
    convert(i);
}
