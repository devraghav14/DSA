#include <iostream>

using namespace std;

int squareRootFinder(int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    int start = 2;
    int end = x / 2;
    int ans = 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid * mid == x)
        {
            return mid;
        }
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int userNum;

    cout << "Enter the number to find the square root : ";
    cin >> userNum;

    int squareRoot = squareRootFinder(userNum);

    cout << "The square root of " << userNum << " is " << squareRoot << endl;
}