#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]);
void displayMatrix(int rows, int cols, int matrix[10][10]);
void addMatrices(int rows, int cols, int A[10][10], int B[10][10]);
void multiplyMatrices(int r1, int c1, int A[10][10], int r2, int c2, int B[10][10]);
void transposeMatrix(int rows, int cols, int matrix[10][10]);

int main()
{
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if(r1 != r2 || c1 != c2)
            {
                printf("Addition not possible! Matrices must have the same dimensions.\n");
                return 0;
            }

            printf("\nEnter elements of Matrix A:\n");
            inputMatrix(r1, c1, A);

            printf("\nEnter elements of Matrix B:\n");
            inputMatrix(r2, c2, B);

            addMatrices(r1, c1, A, B);
            break;

        case 2:
            printf("\nEnter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if(c1 != r2)
            {
                printf("Multiplication not possible!\n");
                printf("Columns of Matrix A must equal rows of Matrix B.\n");
                return 0;
            }

            printf("\nEnter elements of Matrix A:\n");
            inputMatrix(r1, c1, A);

            printf("\nEnter elements of Matrix B:\n");
            inputMatrix(r2, c2, B);

            multiplyMatrices(r1, c1, A, r2, c2, B);
            break;

        case 3:
            printf("\nEnter rows and columns of Matrix: ");
            scanf("%d%d", &r1, &c1);

            printf("\nEnter elements of Matrix:\n");
            inputMatrix(r1, c1, A);

            transposeMatrix(r1, c1, A);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void inputMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int A[10][10], int B[10][10])
{
    int result[10][10];
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nResultant Matrix after Addition:\n");
    displayMatrix(rows, cols, result);
}

void multiplyMatrices(int r1, int c1, int A[10][10], int r2, int c2, int B[10][10])
{
    int result[10][10];
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix after Multiplication:\n");
    displayMatrix(r1, c2, result);
}

void transposeMatrix(int rows, int cols, int matrix[10][10])
{
    int transpose[10][10];
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose Matrix:\n");
    displayMatrix(cols, rows, transpose);
}
