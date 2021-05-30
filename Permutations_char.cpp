#include <iostream>
#include <vector>
#include "Powerset.hpp"
using namespace std;

void swap1(vector<char> :: iterator c1,vector<char> :: iterator c2)
{
    char temp = *c1;
    *c1=*c2;
    *c2=temp;
}

vector<vector<char>> char_permutation(vector<char> word,vector<vector<char>> result, int position,int i)
{
    int decision;
    vector<char> :: iterator itr1;
    vector<char> :: iterator itr2;
    if (i==0)
    {
        result.push_back(word);
    }
    vector<char> auxiliary=word;

    while(position!=word.size())
    {
        auxiliary=word;
        itr1=auxiliary.begin();
        itr2=auxiliary.begin()+position;
        swap1(itr1,itr2);
        decision = isEqual(result,auxiliary);
        if(decision==0)
        {
            result.push_back(auxiliary);
            result = char_permutation(auxiliary,result,1,1);
        }
    position++;
    }
    return result;
}

int main()
{
    vector<char> word{'A','A','B'};
    vector<vector<char>> subsets;
    subsets=Subset(&(word));
    vector<vector<char>> :: iterator itr;
    vector<vector<char>> Final;
    int SUM = 0;

    for(itr=subsets.begin()+1;itr!=subsets.end();itr++)
    {
        int length;
        vector<vector<char>> result;
        result=char_permutation(*itr,result,1,0);
        vector<vector<char>> :: iterator iter=result.begin();
        for (iter = (result).begin(); iter != (result).end(); iter++)
        {
            PrintVector(&(*iter));
        }
        cout<<endl;
        length = result.size();
        cout<<"=> "<<length<<endl;
        SUM = SUM + length;
    }
    cout<<"Total number of possible Permutations :"<<SUM;
    return 0;
}

