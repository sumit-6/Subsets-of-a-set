#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<char>* V)
{
    vector<char> :: iterator iter;
    cout<<"[";
    for (iter = (*V).begin(); iter != (*V).end(); iter++)
    {
        if ((iter+1) != (*V).end())
        cout<<*iter<<",";
        else
        cout<<*iter;
    }
    cout<<"]";
}

int isEqual(vector<vector<char>> result,vector<char> word)
{
    vector<char> :: iterator i1;
    vector<char> :: iterator i2;
    vector<vector<char>> :: iterator itr=result.begin();
    for(itr=result.begin();itr!=result.end();itr++)
    {
        i1=(word).begin();
        i2=(*itr).begin();
        if (word.size() != (*itr).size())
        {
            continue;
        }
        else
        {
            if(equal(i1,word.end(),i2) == true)
            {
                return 1;
            }
        }
    }
    return 0;
}

vector<char> Concatenate(vector<char>* V1,vector<char>* V2)
{
    vector<char> Concat = (*V1);
    vector<char> :: iterator iter;
    for(iter = (*V2).begin(); iter != (*V2).end(); iter++)
    {
        (Concat).push_back(*iter);
    }
    return Concat;
}

vector<vector<char>> Concatenate2D(vector<vector<char>>* V1,vector<vector<char>>* V2)
{
    vector<vector<char>> Concat = (*V1);
    vector<vector<char>> :: iterator iter;
    for(iter = (*V2).begin(); iter != (*V2).end(); iter++)
    {
        (Concat).push_back(*iter);
    }
    return Concat;
}

vector<vector<char>> Cross(vector<vector<char>>* V1,vector<vector<char>>* V2)
{
    vector<vector<char>> cross;
    vector<vector<char>> :: iterator iter1;
    vector<vector<char>> :: iterator iter2;
    for (iter1 = (*V1).begin(); iter1 != (*V1).end(); iter1++)
    {
        for (iter2 = (*V2).begin(); iter2 != (*V2).end(); iter2++)
        {
            cross.push_back(Concatenate(&(*iter1),&(*iter2)));
        }
    }
    return cross;
}

vector<vector<char>> FindSubset(vector<char>* V,vector<vector<char>>* Collection,int i)
{
    vector<vector<char>> X = {{}};
    if (i == 0)
    {
        *Collection = X;
    }
    int Size = (*V).size();
    if (Size != 1)
    {
        vector<char> :: iterator Start = (*V).begin();
        vector<char> :: iterator End = (*V).begin()+ (Size/2);
        vector<char> V1;
        for (Start = Start; Start != End; Start++)
        {
                V1.push_back(*Start);
        }
        Start = (*V).begin() + (Size/2);
        End = (*V).end();
        vector<char> V2;
        for (Start = Start; Start != End; Start++)
        {
                V2.push_back(*Start);
        }
        vector<vector<char>> Vector1;
        vector<vector<char>> Vector2;
        Vector1 = FindSubset(&V1,Collection,1);
        Vector2 = FindSubset(&V2,Collection,1);
        vector<vector<char>> Final;
        Final = Cross(&Vector1,&Vector2);
        vector<vector<char>> :: iterator iter;
        for(iter = Final.begin(); iter != Final.end(); iter++)
        {
            int decision = 0;
            vector<vector<char>> :: iterator itr;
            for(itr = (*Collection).begin(); itr != (*Collection).end(); itr++)
            {
                if((*itr).size() == (*iter).size())
                {
                    if(equal((*itr).begin(),(*itr).end(),(*iter).begin()) == true)
                    {
                        decision = 1;
                        break;
                    }
                }
                else
                {
                    decision = 0;
                }
            }
            if (decision == 0)
            {
                (*Collection).push_back(*iter);
            }
        }
        return (*Collection);
    }
    else
    {
        vector<vector<char>> Result = {{},*V};
        return Result;
    }
}

vector<vector<char>> Subset(vector<char>* V)
{
    vector<vector<char>> Collection;
    return FindSubset(V,&Collection,0);
}
