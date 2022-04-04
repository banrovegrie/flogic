#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":" << endl;
        
        int n, m;
        cin >> n >> m;
    
        cout << "..+-+";
        for (int i = 0; i < m - 2; i++)
            cout << "-+";
        cout << endl;

        cout << "..|.|";
        for (int i = 0; i < m - 2; i++)
            cout << ".|";
        cout << endl;
        cout << "+-+-+";
        for (int i = 0; i < m - 2; i++)
            cout << "-+";
        cout << endl;
        
        for (int i = 0; i < n - 1; i++)
        {
            cout << "|.|";
            for (int j = 0; j < m - 1; j++)
                cout << ".|";
            cout << endl;
            
            cout << "+-+";
            for (int j = 0; j < m - 1; j++)
                cout << "-+";
            cout << endl;
        }
    }   
}