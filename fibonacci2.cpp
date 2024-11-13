#include <iostream>
using namespace std;

int fibonacciIterative(int n)
{
    int stepCount = 0;

    if (n <= 1)
    {
        stepCount++;
        cout << "Steps taken: " << stepCount << endl;
        return n;
    }

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        stepCount++;
    }

    cout << "Steps taken: " << stepCount << endl;
    return b;
}

int main()
{
    int n;
    cout << "Enter the position of the Fibonacci term you want: ";
    cin >> n;

    int result = fibonacciIterative(n);
    cout << "Fibonacci term at position " << n << " is " << result << endl;

    return 0;
}