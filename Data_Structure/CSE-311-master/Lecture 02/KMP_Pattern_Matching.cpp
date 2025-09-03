#include <bits/stdc++.h>
using namespace std;

vector<int> ComputeLPS(string Pattern, int P_Size)
{
    vector<int> LPS(P_Size);
    int Length = 0, i = 1;
    while (i < P_Size)
    {
        if (Pattern[i] == Pattern[Length])
        {
            Length++;
            LPS[i] = Length;
            i++;
        }
        else
        {
            if (Length != 0)
            {
                Length = LPS[Length - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}

vector<int> KMPSearch(string Text, string Pattern)
{
    int T_Size = Text.length(), P_Size = Pattern.length();
    vector<int> LPS = ComputeLPS(Pattern, P_Size);
    vector<int> Result;
    int i = 0, j = 0;
    while (i < T_Size)
    {
        if (Text[i] == Pattern[j])
        {
            i++;
            j++;
        }
        if (j == P_Size)
        {
            Result.push_back(i - j);
            j = LPS[j - 1];
        }
        else if (i < T_Size && Pattern[j] != Text[i])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return Result;
}

int main()
{
    string Text, Pattern;
    cout << "Enter The Main Text: ";
    getline(cin, Text);
    cout << "Enter The Searching Text: ";
    getline(cin, Pattern);

    vector<int> Result = KMPSearch(Text, Pattern);

    if (Result.empty())
    {
        cout << "Pattern not found in the text." << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int idx : Result)
        {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
