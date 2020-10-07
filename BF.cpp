//
// Created by fhz on 2020/10/7.
// Brute Force algorithm
// Determines whether one string is a substring of another.

#include <iostream>
#include <string>

using namespace std;

int BruteForce(string S, string T)
{
    int i = 0;
    int j = 0;

    // Searching
    while (i < S.length() && j < T.length())
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        } else
        {
            i = i - j + 1;
            j = 0;
        }
    }


    if( j >= T.length())        // Match success
    {
        return i - T.length();  // Return the position of the father string.
    } else                      // Match failed
        return 0;

}

int main()
{
    string S = "ColinFangYpw";
    string T = "Fang";

    cout<<BruteForce(S,T)<<endl;

    return 0;
}