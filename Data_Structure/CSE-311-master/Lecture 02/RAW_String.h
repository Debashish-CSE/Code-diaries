#include <bits/stdc++.h>
#define MAX_SZ 10001
using namespace std;

int Length(char S[MAX_SZ])
{
    int Count = 0;
    for (int i = 0; S[i] != '\0'; i++)
    {
        Count++;
    }
    return Count;
}

char *SUBSTRING(char S[MAX_SZ], int Initial, int Len)
{
    char *CP = new char[Len + 1];
    for (int i = Initial, j = 0; j < Len && S[i] != '\0'; i++, j++)
    {
        CP[j] = S[i];
    }
    CP[Len] = '\0';
    return CP;
}

int INDEX(char Text[MAX_SZ], char Pattern[MAX_SZ])
{
    int T_Size = strlen(Text);
    int P_Size = strlen(Pattern);

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
    i = 0;
    int j = 0;
    while (i < T_Size)
    {
        if (Text[i] == Pattern[j])
        {
            i++;
            j++;
        }
        if (j == P_Size)
        {
            return i - j;
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
    return -1;
}

char *CONCATENATION(char S1[MAX_SZ], char S2[MAX_SZ])
{
    int Len1 = Length(S1);
    int Len2 = Length(S2);
    char *CP = new char[Len1 + Len2 + 1];
    int j = 0;
    for (int i = 0; i < Len1; i++)
    {
        CP[j] = S1[i];
        j++;
    }
    for (int i = 0; i < Len2; i++)
    {
        CP[j] = S2[i];
        j++;
    }
    CP[j] = '\0';
    return CP;
}

char *INSERT(char S1[MAX_SZ], int Position, char S2[MAX_SZ])
{
    int Len1 = Length(S1);
    int Len2 = Length(S2);
    char *Result = new char[Len1 + Len2 + 1];
    int j = 0;
    for (int i = 0; i < Position && i < Len1; i++)
    {
        Result[j] = S1[i];
        j++;
    }
    for (int i = 0; i < Len2; i++)
    {
        Result[j] = S2[i];
        j++;
    }
    for (int i = Position; i < Len1; i++)
    {
        Result[j] = S1[i];
        j++;
    }
    Result[j] = '\0';
    return Result;
}

char *DELETE(char S[MAX_SZ], int Position, int Len)
{
    int OriginalLen = Length(S);
    int NewLen = OriginalLen - Len;
    char *Result = new char[NewLen + 1];
    int j = 0;
    for (int i = 0; i < Position && i < OriginalLen; i++)
    {
        Result[j] = S[i];
        j++;
    }
    for (int i = Position + Len; i < OriginalLen; i++)
    {
        Result[j] = S[i];
        j++;
    }
    Result[j] = '\0';
    return Result;
}

char *REPLACE(char Text[MAX_SZ], char Pattern1[MAX_SZ], char Pattern2[MAX_SZ])
{
    int T_Size = Length(Text);
    int P1_Size = Length(Pattern1);
    int P2_Size = Length(Pattern2);

    int StartIndex = INDEX(Text, Pattern1);
    if (StartIndex == -1)
    {
        return Text;
    }

    int NewSize = T_Size - P1_Size + P2_Size;
    char *Result = new char[NewSize + 1];

    int j = 0;
    for (int i = 0; i < StartIndex; i++)
    {
        Result[j] = Text[i];
        j++;
    }
    for (int i = 0; i < P2_Size; i++)
    {
        Result[j] = Pattern2[i];
        j++;
    }
    for (int i = StartIndex + P1_Size; i < T_Size; i++)
    {
        Result[j] = Text[i];
        j++;
    }
    Result[j] = '\0';
    return Result;
}