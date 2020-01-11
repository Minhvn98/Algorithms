#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
 
void maPhuongBacLe(int A[][MAX+1], int n)
{
    int i = 1;
    int j = n / 2 + 1;
    int k = 1;
    int n2 = n*n;
    while (k <= n2)
    {
        A[i][j] = k;
 
        if (k % n == 0)
        {
            i = i + 1;
            if ( i > n ) i = i - n;
        }
        else
        {
            if (i == 1)
                i = n;
            else
                i--;
            if (j == n)
                j = 1;
            else
                j++;
        }
        k++;
    }
}
 
void maPhuongBacChanChan(int A[][MAX+1], int n)
{
    int k = 1;
    int i = 1;
    int j = 1;
    int n2 = n * n;
 
    do
    {
        if ( (i - j) % 4 == 0 || (i + j -1) % 4 == 0)
            A[i][j] = k;
        else
            A[i][j] = n2 + 1 - k;
 
        k++;
 
        if (j==n)
        {
            j = 1;
            i++;
        }
        else
            j++;
    }
    while (k <= n2);
}
 
void LUX(int A[][MAX+1], int i, int j, int num, char ch)
{
    num = 1 + (num-1)*4;
    i = 1 + (i-1)*2;
    j = 1 + (j-1)*2;
    switch (ch)
    {
    case 'L':
        A[i][j] = num + 3;
        A[i][j+1] = num;
        A[i+1][j] = num + 1;
        A[i+1][j+1] = num + 2;
        break;
    case 'U':
        A[i][j] = num;
        A[i][j+1] = num + 3;
        A[i+1][j] = num + 1;
        A[i+1][j+1] = num + 2;
        break;
    case 'X':
        A[i][j] = num;
        A[i][j+1] = num + 3;
        A[i+1][j] = num + 2;
        A[i+1][j+1] = num + 1;
    }
}
 
void maPhuongBacChanLe(int A[][MAX+1], int n)
{
    int m = n / 2;
    int B[MAX+1][MAX+1];
    maPhuongBacLe(B, m);
 
    char ch;
    int m2 = m / 2;
    int i, j;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= m; j++)
        {
            if (i <= m2)
                ch = 'L';
            else if (i == m2 + 1)
            {
                if (j == m2+1)
                    ch = 'U';
                else
                    ch = 'L';
            }
            else if (i == m2 + 2)
            {
                if (j == m2 + 1)
                    ch = 'L';
                else
                    ch = 'U';
            }
            else
                ch = 'X';
            LUX(A, i, j, B[i][j], ch);
        }
 
}
 
int main()
{
 
    int A[MAX+1][MAX+1];
    int n;
    do
    {
        cout << "n =  ";
        cin >> n;
    }
    while (n < 3 || n > MAX);
 
    if (n % 2 == 1)
    {
        maPhuongBacLe(A, n);
    }
    else if (n % 4 == 0)
    {
        maPhuongBacChanChan(A, n);
    }
    else
    {
        maPhuongBacChanLe(A, n);
    }
 
    int i, j;
 
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << setw(3) << A[i][j] << " ";
        cout << endl;
    }
 
    return 0;
}
