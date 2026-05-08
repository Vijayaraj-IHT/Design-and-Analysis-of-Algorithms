#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;
    int i = 0, j = 0;
    bool found = false;

    cout << "Enter text: ";
    getline(cin,text);

    cout << "Enter pattern: ";
    cin >> pattern;
    int n = 0, m = 0;
    for(int a=0;text[a]!='\0';a++)
        n++;
    for(int a=0;pattern[a]!='\0';a++)
        m++;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j = 0;
        }

        if (j == m)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Pattern found at " << i - m + 1 << "th position." << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}