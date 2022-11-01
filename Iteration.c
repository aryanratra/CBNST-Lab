//Iteration Method
#include <stdio.h>
#include<math.h>
#define EPSILON 0.0001

float f(float x)
{
    return x*x*x + x*x - 1;
}

float findValueAt(float x)
{
    return 1/sqrt(1+x);
}

float differentiate(float x)
{
    return 1/2.0 * (pow(1,pow((1,x), 3/2.0)));
}

int main()
{
    int maxIterations, i=1;
    float a, b, x, x0;
    printf("Enter Maximum number of iterations:\n");
    scanf("%d", &maxIterations);

    do
    {
        printf("Enter the value of a and b(starting boundary)");
        scanf("%f%f", &a, &b);
        if(f(a) * f(b) > 0)
        {
            printf("Roots are Invalid\n");
            continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n", a, b);
            break;
        }
    } while (1);

    x0 = (a + b)/2;

    if(fabs(differentiate(x0)) < 1)
        printf("Function Form is Correct. Iteration Method can be applied.\n");
    else
    {
        printf("Function Form is not Correct. Iteration Method can't be applied.\n");
        return 0;
    }

    for(i = 1; i <= maxIterations; i++)
    {
        x = findValueAt(x0);

        if(fabs(x-x0)<EPSILON)
        {
            printf("Iterations = %d Final Root = %f\n", i, x);
            return 0;
        }
        printf("Iterations = %d Roots = %f\n", i, x);
        x0 = x;
    }
    printf("Root = %f Total Iterations = %d", x, --i);
    return 0;
}