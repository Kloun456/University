#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
const int n = 40;
int count = 0;  // for symbols
float eps = 1e-12;

void Print_array(int *x), Fill_array(int *x), Print_numb(int *x, int );
int min(int *x), min1(int *x, int ), digits(FILE *my_file), symbols(FILE *my_file), sum(int *x, int );
float Solution(float , float), f(float );

int main()
{
    int x[10] = {1,-2,-3,4,5,6,-7,8,9,0}, i = 0;
    char c;
    FILE *my_file;

    // 1)
    Print_array(x);
    printf("\nmin = %d", min(x));

    // 2)
    /*while(i < n)
    {
        scanf("%d",&x[i]);
        if (x[i] < 0)
            break;
        i++;
    }
    printf("Sum of elements = %d",sum(x,0));*/

    // 3)
    /*if ((my_file = fopen("My_file.txt","r"))==0)
    {
        printf("\nFile is not open!\n");
    }
    else
    {
        printf("\nFile is open!\n");
    }
    printf("Quantity symbols = %d\t", symbols(my_file));
    count = 0;
    rewind(my_file);
    printf("quantity digits = %d\n", digits(my_file));
    fclose(my_file); */

    // 4)
    /*Print_array(x);
    Print_numb(x,i);*/

    // 5)
    /*printf("%.3f", Solution(-6,0));*/
}

int min (int *x) // function min
{
    return min1(x, 0);
}

int min1(int *x, int k) // recursion min
{
    if (k == 9)
        return x[9];
    if (x[k]< min1(x,k+1))
        return  x[k];
    else
        return min1(x,k+1);
}

float Solution(float a, float b)
{
    float x = (a + b) / 2.0;
    if (abs(a - b) < eps)
        return x;
    if (!f(x))
        return x;
    if (f(x) * f(a) > 0)
        return Solution(x, b);
    else
        return Solution(a, x);
}

float f(float x)
{
    return pow(x,2) + 3 * x - 10;
}

void Print_numb(int *x, int i)
{
    if (x[i] == 0)
        return 0;
    if (x[i] < 0)
    {
        printf("%d\t",x[i]);
        Print_numb(x,i+1);
    }
    else
    {
        Print_numb(x,i+1);
        printf("%d\t",x[i]);
    }

}

int sum(int *x, int l)
{
    if (x[l] < 0)
        return 0;
    else
        return sum(x,l+1) + x[l];

}

int digits(FILE *my_file)
{
    char c;
    if((c = fgetc(my_file))!= EOF || isdigit(c = fgetc(my_file)) )
    {
        if (isdigit(c))
            count++;
        digits(my_file);
    }
    else
        return count;
}

int symbols(FILE *my_file)
{
    char c;
    if((c = fgetc(my_file))!= EOF)
    {
        count++;
        symbols(my_file);
    }
    else
        return count;
}



void Fill_array(int *x)
{
    srand(time(0));
    for (int i = 0; i < 40; i++)
    {
        x[i] = rand() % 32;
        if (x[i] == 0)
            x[i] = 21;
    }
}

void Print_array(int *x)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", x[i]);
}
