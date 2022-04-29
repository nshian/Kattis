#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int total = 0;
    int refused;
    int groupsize[M];
    for(int i = 0; i < M; i += 1){
        cin >> groupsize[i];
    }
    for(int i = 0; i < M; i += 1){
        if(total+groupsize[i] <= N){
            total += groupsize[i];
        }
        else{
            refused = M-i;
            break;
        }
    }
    cout << refused << endl;
    return 0;
}