#include <iostream>
using namespace std;

// Global step counters
int stepRecursive = 0;
int stepIterative = 0;

// Recursive Fibonacci function
int fibRecursive(int n)
{
    stepRecursive++; // Count each function call
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-Recursive Fibonacci function
int fibIterative(int n)
{
    stepIterative = 0;
    if (n == 0)
        return 0;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        stepIterative++; // Count each loop iteration
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Recursive approach
    stepRecursive = 0;
    int fibR = fibRecursive(n);
    cout << "\nRecursive Fibonacci(" << n << ") = " << fibR;
    cout << "\nStep Count (Recursive): " << stepRecursive;

    // Iterative approach
    int fibI = fibIterative(n);
    cout << "\n\nIterative Fibonacci(" << n << ") = " << fibI;
    cout << "\nStep Count (Iterative): " << stepIterative << endl;

    return 0;
}
