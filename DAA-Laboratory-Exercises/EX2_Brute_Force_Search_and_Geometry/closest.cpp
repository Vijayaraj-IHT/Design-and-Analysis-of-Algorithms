#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<int> x(n), y(n);

    cout << "Enter the points (x y):\n";
    for (int i = 0; i < n; i++)
        if (!(cin >> x[i] >> y[i])) break;

    double min_dist = INT_MAX;
    int temp1=0;
    int temp2=0;
    int temp3=0;
    int temp4=0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                            (y[i] - y[j]) * (y[i] - y[j]));

            if (d < min_dist)
            {   min_dist=d;
                temp1=x[i];
                temp2=y[i];
                temp3=x[j];
                temp4=y[j];
            }
        }
    }
    cout<<"minimum distance points:" << "(" << temp1 << "," << temp2 << ")" << "(" << temp3 << "," << temp4 << ")" << endl;

    cout << "Minimum distance = " << min_dist << endl;

    return 0;
}