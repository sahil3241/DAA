#include <iostream>
using namespace std;

int stepCount = 0;

int fibonacciRecursive(int n)
{
    stepCount++;
    cout << "Fibonacci " << n << " " << endl;
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter the position of the Fibonacci term you want: ";
    cin >> n;

    int result = fibonacciRecursive(n);
    cout << "Fibonacci term at position " << n << " is " << result << endl;
    cout << "Steps taken: " << stepCount << endl;

    return 0;
}