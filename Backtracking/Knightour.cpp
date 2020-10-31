#include <iostream>
using namespace std;
int x_arr[] = {1, 2, 1, 2, -1, -2, -1, -2};
int y_arr[] = {2, 1, -2, -1, 2, 1, -2, -1};
static int ct = 0;

bool isSafe(int b[8][8], int x, int y)
{
    if (x >= 0 && y >= 0 && x < 8 && y < 8 && b[x][y] == 0)
        return true;
    return false;
}

bool Ktour_h(int b[8][8], int x, int y)
{
    if (ct == 63)
    {
        return true;
    }
    b[x][y] = ct;
    for (int i = 0; i <=7; i++)
    {
        int n_x = x + x_arr[i];
        int n_y = y + y_arr[i];
        if (isSafe(b, n_x, n_y) == true){
            b[n_x][n_y]=++ct;
            if(Ktour_h(b,n_x,n_y)==true)
                return true;
            else
            {
                --ct;
                b[n_x][n_y]=0;
            }
        }
    }
    return false;
}

void Ktour()
{
    int b[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            b[i][j] = 0;
        }
    }
    if (Ktour_h(b, 0, 0) == false)
        cout << "Solution does not exist";
    else
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    Ktour();
    return 0;
}