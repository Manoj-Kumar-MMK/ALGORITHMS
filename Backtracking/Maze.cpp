#include <iostream>
using namespace std;

bool check(int a[4][4], int x, int y)
{
    if (x < 4 && y < 4 && x >= 0 && y >= 0 && a[x][y] == 1)
        return true;
    else
        return false;
}
bool solve_sub(int a[4][4], int x, int y, int sol[4][4])
{
    if (x == 3 && y == 3 && a[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (check(a, x, y))
    {
        sol[x][y] = 1;

        if (solve_sub(a, x, y + 1, sol))
            return true;
        if (solve_sub(a, x + 1, y, sol))
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void solve(int a[4][4])
{
    int sol[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    if (solve_sub(a, 0, 0, sol) == false)
    {
        cout << "Solution not found";
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    int a[4][4] = {0};
    int n,x,y;
    cout << "Enter the number of obstacles:";
    cin >> n;
    cout << "Enter the obstacles in the format of x and y cordinate:\n";
    for (int i = 0; i < n;i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
}
        solve(a);
    return 0;
}