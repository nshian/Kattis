#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int happiness[n];
    int indexofbjorn;
    for(int i = 0; i < n; i += 1){
        cin >> happiness[i];
        if(happiness[i] == 0){
            indexofbjorn = i;
        }
    }
    long sum = 0;
    for(int i = 0; i < n; i += 1){
        sum += (i+1)*happiness[i];
    } //initial sum
    long sumofleftdiff = 0;
    long sumofrightdiff = 0;
    int mostpositive = 0;
    int mostnegative = 0;
    for(int i = indexofbjorn-1; i >= 0; i -= 1){ //checking leftwards
        sumofleftdiff += happiness[i];
        if(sumofleftdiff > mostpositive){
            mostpositive = sumofleftdiff;
        }
    }
    for(int i = indexofbjorn+1; i <= n-1; i += 1){ //checking rightwards
        sumofrightdiff += happiness[i];
        if(sumofrightdiff < mostnegative){
            mostnegative = sumofrightdiff;
        }
    }
    if(sum + mostpositive >= sum - mostnegative){
        cout << sum + mostpositive << endl;
    }
    else{
        cout << sum - mostnegative << endl;
    }
}