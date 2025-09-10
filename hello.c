#include <stdio.h>




int main()
{
    int num1, num2, solution, i=1;
    int flag = 0;
    char oper, ch;
    printf("enter your exercise: ");
    while ((ch=getchar())!='\n')
    {
        if ((ch=='+') || (ch=='-') || (ch=='*') || (ch=='/'))
        {
            oper = ch;
            flag = 1;
            i=1;
            continue;
        }

        if(!flag)
        {
            if(i==1)
            {
              num1 = ch-'0';
            }
            else
            {
                num1*=10;
                num1+=(ch-'0');
            }
        }
        else
        {
            if(i==1)
            {
                num2 = ch-'0';
            }
            else
            {
                num2*=10;
                num2+=(ch-'0');
            }
        }
        i++;
    }

    switch (oper)
    {
    case '+':
        solution = num1 + num2;
        break;
    
    case '-':
        solution = num1 - num2;
        break;

    case '*':
        solution = num1 * num2;
        break;

    case '/':
        if(num2==0)
        {
            printf("Error: Division by zero\n");
            return 0;
        }
        solution = num1 / num2;
        break;
    
    default:
        printf("ERRO!\n");
        return 0;
    }
    printf("The solution is %d\n", solution);

    return 0;
}