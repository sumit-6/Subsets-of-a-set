#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> Concatenate(vector<int>* V1,vector<int>* V2)
{
    vector<int> Concat = (*V1);
    vector<int> :: iterator iter;
    for(iter = (*V2).begin(); iter != (*V2).end(); iter++)
    {
        (Concat).push_back(*iter);
    }
    return Concat;
}

vector<vector<int>> Cross(vector<vector<int>>* V1,vector<vector<int>>* V2)
{
    vector<vector<int>> cross;
    vector<vector<int>> :: iterator iter1;
    vector<vector<int>> :: iterator iter2;
    for (iter1 = (*V1).begin(); iter1 != (*V1).end(); iter1++)
    {
        for (iter2 = (*V2).begin(); iter2 != (*V2).end(); iter2++)
        {
            cross.push_back(Concatenate(&(*iter1),&(*iter2)));
        }
    }
    return cross;
}

vector<vector<int>> Subset(vector<int>* V)
{
    int Size = (*V).size();
    if (Size != 1)
    {
        vector<int> :: iterator Start = (*V).begin();
        vector<int> :: iterator End = (*V).begin()+ (Size/2);
        vector<int> V1;
        for (Start = Start; Start != End; Start++)
        {
                V1.push_back(*Start);
        }
        Start = (*V).begin() + (Size/2);
        End = (*V).end();
        vector<int> V2;
        for (Start = Start; Start != End; Start++)
        {
                V2.push_back(*Start);
        }
        vector<vector<int>> Vector1;
        vector<vector<int>> Vector2;
        Vector1 = Subset(&V1);
        Vector2 = Subset(&V2);
        vector<vector<int>> Final;
        Final = Cross(&Vector1,&Vector2);
        return Final;
    }
    else
    {
        vector<vector<int>> Result = {{},*V};
        return Result;
    }
}

void PrintVector(vector<int>* V)
{
    vector<int> :: iterator iter;
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

int main()
{
    vector<int> A1{1,3,5,6,2};
    vector<vector<int>> Result;

    Result = Subset(&A1);
    vector<vector<int>> :: iterator iter;
    cout<<"["<<endl;
    for (iter = Result.begin(); iter != Result.end(); iter++)
    {
        PrintVector(&(*iter));
        if (iter+1 != Result.end())
            cout<<","<<endl;
        else
            cout<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}
