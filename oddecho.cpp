#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string words[N];
    for(int i = 0; i < N; i += 1){
        cin >> words[i];
    }
    for(int i = 0; i < N; i += 1){
        if(i % 2 == 0){
            cout << words[i] << endl;
        }
    }
}