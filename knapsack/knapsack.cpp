#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int limit;
    int maxVal = INT_MIN;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter weight limit: ";
    cin >> limit;
    vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));
    vector<int> values(n, 0);
    vector<int> weights(n, 0);

    cout << "Enter all values" << endl;
    for (int i = 0; i < n; i++)
        cin >> values[i];
    cout << "Enter all weights" << endl;
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    for (int j = 0; j < limit + 1; j++)
    {
        for (int i = 0; i < n + 1; i++)
        {            
            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else if (j <= weights[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);            
        }
    }
    cout<<"DP table:"<<endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < limit + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout<<"Max Profit: "<<dp[n][limit];
    return 0;
} 
