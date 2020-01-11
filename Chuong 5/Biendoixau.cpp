#include<iostream>
#include<math.h>
using namespace std;

const int N = 20;
string X = "abcd";
string Y = "be";

// Buoc 1: S[i,j] la so luong thao tac bien doi min
// de chuyen X[1->i] thanh Y[1->j]
int S[N][N];

void dp()
{
    // Buoc 2: Giai cac bai toan con
    // Buoc 3: Ket hop de giai bai toan ban dau
    S[0][0] = 0;
    for (int j = 1; j <= Y.size(); j++) S[0][j] = j; // j phep chen
    for (int i = 1; i <= X.size(); i++) S[i][0] = i; // i phep xoa
    
    for (int i = 1; i <= X.size(); i++)
    {
        for (int j = 1; j <= Y.size(); j++)
        {
            if (X[i-1] == Y[j-1])
            {
                S[i][j] = S[i-1][j-1];
            } else { // X[i-1] != Y[j-1]
                S[i][j] = 1 + min(
                                min(S[i][j-1], // chen Y[j] vao cuoi doan X[1->i]
                                    S[i-1][j]), // Xoa ki tu X[i]
                                    S[i-1][j-1] // thay the X[i] bang Y[j]
                                );
            }
        }
    }
    
    for (int i = 0; i <= X.size(); i++)
    {
        for (int j = 0; j <= Y.size(); j++)
            cout << S[i][j] << " ";
        cout << endl;
    }
    
    // Buoc 4: Truy nguoc de tim cac phan tu cua day tang
    int r = (int)X.size(), c = (int)Y.size();
    string seq[N]; int nb = 0;
    while (r > 0 && c > 0)
    {
        if (X[r-1] == Y[c-1])
        {
            r--; c--;
        } else { // X[r-1] != Y[c-1]
            if (S[r][c] == S[r][c-1] + 1)
            {
                seq[nb++] = "Chen ki tu o vi tri " + to_string(c) + " cua xau Y vao vi tri " + to_string(r) + " cua xau X";
                c--;
            } else if (S[r][c] == S[r-1][c] + 1){
                seq[nb++] = "Xoa ki tu o vi tri " + to_string(r) + " cua xau X";
                r--;
            } else { // S[r][c] == S[r-1][c-1] + 1
                seq[nb++] = "Thay the ki tu o vi tri " + to_string(r) + " cua xau X bang ki tu o vi tri " + to_string(c) + " cua xau Y";
                r--; c--;
            }
        }
    }
    
    if (r > 0)
    {
        for (int i = r; i > 0; i--)
            seq[nb++] = "Xoa ki tu o vi tri " + to_string(i) + " cua xau X";
    } else if (c > 0) {
        for (int j = c; j > 0; j--)
            seq[nb++] = "Chen ki tu o vi tri " + to_string(j) + " cua xau Y vao vi tri " + to_string(j) + " cua xau X";
    }
    cout << nb << " phep bien doi de chuyen tu (" << X << ") -> (" << Y << "): " << endl;
    for (int k = nb-1; k >= 0; k--)
        cout << " " << (nb - k) << ". " << seq[k] << endl;
}

int main()
{
    dp();
    return 0;
}