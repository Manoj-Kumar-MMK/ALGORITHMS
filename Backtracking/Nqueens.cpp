#include <iostream>
using namespace std;
#define N 4

void print(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool check(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (i = row, j = col; i >= 0 && j <= N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}
bool nQ(int board[N][N], int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (check(board, row, col))
        {
            board[row][col] = 1;

            if (nQ(board, row + 1))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}
void solveQ()
{
    int board[N][N] = {0};
    if (nQ(board, 0))
    {
        cout << "NO SOLUTION";
    }
    else
    {
        print(board);
    }
}
int main()
{
    solveQ();
    return 0;
}