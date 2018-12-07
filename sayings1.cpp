/************************************************
 * @FileName:    sayings1.cpp
 * @Author:      Guohao.Chen
 * @Date:        2018.12.07
 * @Description: using expanded String class
************************************************/
#include <iostream>
#include "stringgood.h"

const int ArSize = 10;
const int MaxLen = 81;

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];

    // temporary string storage
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
        {
            break;
        }
        else
        {
            sayings[i] = temp; // 重载赋值 String = C string
        }
    }
    int total = i;

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
        {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }

        // 寻找最短的和首字母最前的
        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        cout << "Shortest sayings:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany() 
            << " String objects. Bye.";
    }
    else
    {
        cout << "No input! Bye.\n";
    }
    //cin.get();
    return 0;
}