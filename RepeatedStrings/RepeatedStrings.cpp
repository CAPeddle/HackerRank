// RepeatedStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.hackerrank.com/challenges/repeated-string
//


//do math to reduce overflow 
#include <iostream>
long long repeatedString(std::string s, long long n) {
    if (s.length() == 1 && s == "a") return n;

    auto aInSubstring = std::count(s.begin(), s.end(), 'a');

    auto ldivresult = lldiv(n, s.length());

    if (ldivresult.rem == 0) {
        return aInSubstring * ldivresult.quot;
    }

    auto aInPartSubstring = std::count(s.begin(), s.begin() + ldivresult.rem, 'a');

    auto substringContains = aInSubstring * ldivresult.quot;
    return aInSubstring * ldivresult.quot + aInPartSubstring;

}


int main()
{
    {
        std::string s = "epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq";
        long long n = 549382313570;
        std::cout << s << " : " << repeatedString(s, n) << "\n";
    }

    {
        //aba|aba|aba|aba|aba|aba|
        //123|456|789|0
        std::string s = "aba";
        long n = 10;
        std::cout << s << " : " << repeatedString(s, n) << "\n";
    }

    {
        //10 mod strLength(5) = 0; 
        //abcac|abcac|abcacabcacabcacabcac
        //12345|67890|
        std::string s = "abcac";
        long n = 10; 
        std::cout << s << " : " << repeatedString(s,n) << "\n";
    }

    {
        std::string s = "a";
        long n = 1000000000000l;
        std::cout << s << " : " << repeatedString(s, n) << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
