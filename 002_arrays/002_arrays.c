#include <stdio.h>

#define N1 3 // size of square matrix for 1st exercise
#define N2 5 // size of array to be reversed for 2nd exercise
#define N3 7 // size of '0' and '1' matrix for 3rd exercise
#define N4 9 // size of spirally filled matrix

int main()
{
    // square matrix from 1 to N
    int squareArray[N1 * N1];
    for (int i = 1; i <= N1 * N1; i++)
    {
        squareArray[i] = i;
        printf("%d ", squareArray[i]);
        if (i % N1 == 0)
        {
            printf("\n");
        }
    }

    // reverse array
    int reverseArray[N2] = {1, 2, 3, 4, 5};
    printf("\nOriginal array: ");
    for (int i = 0; i < N2; i++)
    {
        printf("%d ", reverseArray[i]);
    }
    for (int i = 0; i < N2 / 2; i++)
    {
        int temp = reverseArray[i];
        reverseArray[i] = reverseArray[N2 - i - 1];
        reverseArray[N2 - i - 1] = temp; 
    }
    printf("\nReversed array: ");
    for (int i = 0; i < N2; i++)
    {
        printf("%d ", reverseArray[i]);
    }
    
    // top triangle of matrix filled with '0', bottom - with '1'
    printf("\n\nhalf '1' half '0' matrix:\n");
    int triangleMatrix[N3 * N3];
    for (int i = 0; i < N3; i++)
    {
        for (int j = 0; j < N3; j++)
        {
            if ((i + j) < (N3 - 1))
            {
                triangleMatrix[i * N3 + j] = 0;
                printf("%d ", triangleMatrix[i * N3 + j]); 
            } else {
                triangleMatrix[i * N3 + j] = 1;
                printf("%d ", triangleMatrix[i * N3 + j]); 
            }
        }
        printf("\n");
    }
    // fill matrix from 1 to N^2 in spiral
    printf("\nSpiral matrix:\n");
    int spiralMatrix[N4 * N4];
    int width = (N4 - 1) / 2;
    int count = 1;
    for (int i = 0; i < width; i++) // number of 4 sided spiral
    {
        for (int j = 0; j < 4; j++) // side of spiral (top, right, bottom, left)
        {
            if (j == 0) // top row
            {
                for (int k = i; k < N4 - i - 1; k++)
                {
                    spiralMatrix[i * N4 + k] = count;
                    count++;
                }
            } else if (j == 1) // right coloumn
            {
                for (int k = i; k < N4 - i - 1; k++)
                {
                    spiralMatrix[k * N4 + (N4 - i - 1)] = count;
                    count++;
                }
            }  else if (j == 2) // bottom row
            {
                for (int k = N4 - i - 1; k > i; k--)
                {
                    spiralMatrix[(N4 - i - 1) * N4 + k] = count;
                    count++;
                }
            } else if (j == 3) // left coloumn
            {
                for (int k = N4 - i - 1; k > i; k--)
                {
                    spiralMatrix[k * N4 + i] = count;
                    count++;
                }
            }
        }
    }
    spiralMatrix[width * N4 + width] = count;
    for (int i = 0; i < N4 * N4; i++)
    {
        printf("%4d", spiralMatrix[i]);
        if (i % N4 == N4 - 1)
        {
            printf("\n");
        }
    }
    printf("count: %d\n", count);
    return 0;
}

// define all arrays' size