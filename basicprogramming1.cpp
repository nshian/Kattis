#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, t;
    cin >> N >> t;
    int A[N];
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }
    if(t == 1){
        cout << "7" << endl;
    }
    else if(t == 2){
        if(A[0] > A[1]){
            cout << "Bigger" << endl;
        }
        else if(A[0] == A[1]){
            cout << "Equal" << endl;
        }
        else{
            cout << "Smaller" << endl;
        }
    }
    else if(t == 3){
        int median = max(min(A[0], A[1]), min(max(A[0], A[1]), A[2]));
        cout << median << endl;
    }
    else if(t == 4){
        long long sum = 0;
        for(int i = 0; i < N; i += 1){
            sum += A[i];
        }
        cout << sum << endl;
    }
    else if(t == 5){
        long long sum = 0;
        for(int i = 0; i < N; i += 1){
            if(A[i] % 2 == 0){
                sum += A[i];
            }
        }
        cout << sum << endl;
    }
    else if(t == 6){
        char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i = 0; i < N; i += 1){
            cout << letters[A[i] % 26];
        }
    }
    else{
        bool stopped = false;
        int prev_index = 0;
        int hops = 0;
        int curr_index = A[prev_index];
        while(!stopped){
            hops += 1;
            if(hops > N-1){
                cout << "Cyclic" << endl;
                stopped = true;
            }
            else{
                curr_index = A[prev_index];
                if(curr_index >= N){
                    cout << "Out" << endl;
                    stopped = true;
                }
                else if(curr_index == N-1){
                    cout << "Done" << endl;
                    stopped = true;
                }
                prev_index = curr_index;
            }
        }
    }
    return 0;
}