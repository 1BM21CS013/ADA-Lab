#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{

    int n;
    printf("enter dimension: ");
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                int weight;
                printf("input weights for %d -> %d\n", i, j);
                cin >> weight;
                if (weight)
                {
                    dp[i][j] = weight;
                }
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << "printing the resultant matrix" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}