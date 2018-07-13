#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int word_size,x,i,j;
    string word,temp_word;
    int suffix_max,tKase;

    cin >> tKase;

    while(tKase--)
    {
        word.clear();
        temp_word.clear();
        suffix_max = 0;

        cin >> word;

        word_size = word.length();

        for(i = word_size-1,j = 0; i >= 0; i--)
        {
            if(word.at(i) >= suffix_max)
            {
                suffix_max = word.at(i);
                temp_word+= word.at(i);
                j++;
            }
            else
            {
                for(int k = 0; k < j; k++)
                {
                    if(temp_word[k] > word.at(i))
                    {
                        swap(temp_word.at(k),word.at(i));

                        word.replace(i+1,j,temp_word);

                        break;
                    }
                }
                break;
            }
        }

        if(i < 0)
            word = "no answer";
        cout << word << "\n";

    }

    return 0;
}
