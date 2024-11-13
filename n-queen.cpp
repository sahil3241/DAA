#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nQueen(arr, x + 1, n))
            {
                return true;
            }
            else
            {
                arr[x][col] = 0;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    int firstQueenCol;
    cout << "Enter the column (0 to " << n - 1 << ") to place the first queen in row 0: ";
    cin >> firstQueenCol;

    if (firstQueenCol < 0 || firstQueenCol >= n)
    {
        cout << "Invalid column for the first queen. Please enter a column between 0 and " << n - 1 << ".\n";
        return 1;
    }

    arr[0][firstQueenCol] = 1;

    if (nQueen(arr, 1, n))
    {
        cout << "Solution found:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}