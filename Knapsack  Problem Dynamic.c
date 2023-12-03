#include <stdio.h>
#include<conio.h>
int max(int x, int y)
{
    return (x > y) ? x :y;
}


int knapsack(int Capacity, int weights[], int Value[], int n)
{
    int i, j;
    int K[n + 1][Capacity + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= Capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (weights[i - 1] <= j)
            {
               K[i][j] = max(K[i - 1][j],K[i - 1][j - weights[i - 1]]+Value[i - 1] );
            }

            else
            {
                K[i][j] = K[i - 1][j];
            }

        }
    }
    return K[n][Capacity];

}

int main()
{

     int weight[20],profit[20],numbeOfItem,Capacity;
    int i,j;
    printf("Enter Number of Item :");
    scanf("%d",&numbeOfItem);
    int  n=numbeOfItem;

    for( i=0; i<n; i++)
    {
        printf("Enter Weight of Item [%d]:",i);
        scanf("%d",&weight[i]);
        printf("Enter Profit of Item [%d]:",i);
        scanf("%d",&profit[i]);
    }
    printf("Enter Maximum Capacity For knapsack:");
    scanf("%d",&Capacity);

   printf(" Maximum profit : %d",knapsack(Capacity, weight, profit, n));

    getch();
}
