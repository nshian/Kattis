#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int score;
    cin >> score;
    if (score >= a)
        cout << "A\n";
    else if (score >= b)
        cout << "B\n";
    else if (score >= c)
        cout << "C\n";
    else if (score >= d)
        cout << "D\n";
    else if (score >= e)
        cout << "E\n";
    else
        cout << "F\n";
    return 0;
}