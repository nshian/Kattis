#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int numbers[n];
    for(int i = 0; i < n; i += 1){
        cin >> numbers[i];
    }
    for(int i = n-1; i >= 0; i -= 1){
        cout << numbers[i] << endl;
    }
}