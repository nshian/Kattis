#include <bits/stdc++.h>

using namespace std;

int find_smiley(char *symbols, int i){
    if(symbols[i+1] == ')'){
        cout << i << endl;
        return i+2;
    }
    if(symbols[i+1] == '-' && symbols[i+2] == ')'){
        cout << i << endl;
        return i+3;
    }
    return i+1;
}

int main()
{
    char symbols[2048];
    cin >> symbols;
    int i = 0;
    while(symbols[i] != '\0'){
        if(symbols[i] == ':' || symbols[i] == ';'){
            i = find_smiley(symbols, i);
        }
        else{
            i += 1;
        }
    }
}