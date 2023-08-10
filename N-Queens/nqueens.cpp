#include <iostream>
#include <vector>
using namespace std;

bool isValidCell(vector<int> &colMap, vector<int> &diagMap, vector<int> &antiDiagMap, int i, int j, int n)
{
    // if invalid return false
    if (colMap[j])
        return false;
    if (diagMap[i + n - 1 - j])
        return false;
    if (antiDiagMap[i + j])
        return false;
    // if valid return true
    return true;
}
void solver(vector<vector<string>> &nQueens, vector<string> &combination, vector<int> &colMap, vector<int> &diagMap, vector<int> &antiDiagMap, int r, int n)
{
    if (r == n)
    {
        nQueens.push_back(combination);
        return;
    }

    string row(n, '.');
    for (int i = 0; i < n; i++)
    {
        if (isValidCell(colMap, diagMap, antiDiagMap, r, i, n))
        {
            // pushing
            row[i] = 'Q';
            colMap[i] = 1;
            diagMap[r + n - 1 - i] = 1;
            antiDiagMap[r + i] = 1;
            combination.push_back(row);

            // recur
            solver(nQueens, combination, colMap, diagMap, antiDiagMap, r + 1, n);

            // backtrack
            row[i] = '.';
            colMap[i] = 0;
            diagMap[r + n - 1 - i] = 0;
            antiDiagMap[r + i] = 0;
            combination.pop_back();
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> nQueens;
    vector<string> combination;
    vector<int> colMap(n, 0);
    vector<int> diagMap(2 * n - 1, 0);
    vector<int> antiDiagMap(2 * n - 1, 0);

    solver(nQueens, combination, colMap, diagMap, antiDiagMap, 0, n);

    return nQueens;
}
void printNQueens(vector<vector<string>> &nqueens)
{
    for (int i = 0; i < nqueens.size(); i++)
    {
        for (int j = 0; j < nqueens[i].size(); j++)
        {
            for (int k = 0; k < nqueens[i][j].size(); k++)
                cout << nqueens[i][j][k] << " ";
            cout << endl;
        }
        cout << "---------------------\n";
    }
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<string>> nqueens = solveNQueens(n);
    cout << "---------------------\n";
    printNQueens(nqueens);
    cout << "Total count  = " << nqueens.size() << endl;
    return 0;
}