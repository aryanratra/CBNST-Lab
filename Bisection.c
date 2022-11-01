//Bisection Method
#include <stdio.h>
#include <math.h>
float findValueAt(float x)
{
    return x*x*x - 2*x - 5;
}

float bisect(float x1, float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int maxIterations, i = 1;
    float x1, x2, x;
    printf("Enter max number of iterations:\n");
    scanf("%d", &maxIterations);

    do{
        printf("Enter the value of x1 and x2: ");
        scanf("%f%f", &x1, &x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
            printf("Roots are invalid\n");
            continue;
        }
        else
        {
            printf("Roots lie between %f and %f\n", x1, x2);
            break;
        }
    }while(1);

    while (i<=maxIterations)
    {
        x = bisect(x1,x2);
        if(findValueAt(x)*findValueAt(x1)<0)
            x2 = x;
        else if(findValueAt(x)*findValueAt(x2)<0)
            x1 = x;
        printf("Iterations = %d Roots = %f\n", i, x);
        i++;
    }
    printf("Root = %f Total iterations = %d", x, --i);

    return 0;
    
    
}