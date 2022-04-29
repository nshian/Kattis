#include <iostream>

int main()
{
    int T; std::cin >> T;
    long long years[T];
    for(int i = 0; i < T; i += 1){
        long long P, R, F; std::cin >> P >> R >> F;
        long long count = 0;
        while(P <= F){
            P *= R;
            count += 1;
        }
        years[i] = count;
    }
    for(int i = 0; i < T; i += 1){
        std::cout << years[i] << '\n';
    }
}