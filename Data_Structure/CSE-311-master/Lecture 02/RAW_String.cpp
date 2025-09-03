#include "RAW_String.h"

int main()
{
    char S1[MAX_SZ], S2[MAX_SZ];
    int choice;
    do
    {
        cout << "\nString Operations Menu:\n";
        cout << "1. Length\n";
        cout << "2. Substring\n";
        cout << "3. Index (Pattern Search)\n";
        cout << "4. Concatenation\n";
        cout << "5. Insert\n";
        cout << "6. Delete\n";
        cout << "7. Replace\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Length of the string: " << Length(S1) << endl;
            break;
        }
        case 2:
        {
            int Start, len;
            cout << "Enter the string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter Starting index and length for substring: ";
            cin >> Start >> len;
            cin.ignore();
            char *sub = SUBSTRING(S1, Start, len);
            cout << "Substring: " << sub << endl;
            delete[] sub;
            break;
        }
        case 3:
        {
            cout << "Enter the main text: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter the pattern to search: ";
            cin.getline(S2, MAX_SZ);
            int idx;
            idx = INDEX(S1, S2);
            if (idx == -1)
            {
                cout << "Pattern not found.\n";
            }
            else
            {
                cout << "Pattern found at index: " << idx << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter the first string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter the second string: ";
            cin.getline(S2, MAX_SZ);
            char *concatResult;
            concatResult = CONCATENATION(S1, S2);
            cout << "Concatenated string: " << concatResult << endl;
            delete[] concatResult;
            break;
        }
        case 5:
        {
            int pos;
            cout << "Enter the main string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter the string to insert: ";
            cin.getline(S2, MAX_SZ);
            cout << "Enter the position to insert: ";
            cin >> pos;
            cin.ignore();
            char *insertResult = INSERT(S1, pos, S2);
            cout << "String after insertion: " << insertResult << endl;
            delete[] insertResult;
            break;
        }
        case 6:
        {
            int pos, len;
            cout << "Enter the main string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter the position and length to delete: ";
            cin >> pos >> len;
            cin.ignore();
            char *deleteResult = DELETE(S1, pos, len);
            cout << "String after deletion: " << deleteResult << endl;
            delete[] deleteResult;
            break;
        }
        case 7:
        {
            cout << "Enter the main string: ";
            cin.getline(S1, MAX_SZ);
            cout << "Enter the pattern to replace: ";
            cin.getline(S2, MAX_SZ);
            char P2[MAX_SZ];
            cout << "Enter the replacement pattern: ";
            cin.getline(P2, MAX_SZ);
            char *replaceResult = REPLACE(S1, S2, P2);
            cout << "String after replacement: " << replaceResult << endl;
            delete[] replaceResult;
            break;
        }
        case 8:
        {
            cout << "Exiting program...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again.\n";
        }
        }
    } while (choice != 8);

    return 0;
}
