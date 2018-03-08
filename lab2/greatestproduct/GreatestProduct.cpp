//
// Created by krzysztof on 08.03.2018.
//

#include "GreatestProduct.h"


vector<int> OrganizeLastP(vector<int> numbers) // 0-max, .. ,last - min
{
    vector<int> result = numbers;
    int j = result.size()-1;
    while(j> 0 && result[j] > result[j-1])
    {
        int temp = result[j-1];
        result[j-1] = result[j];
        result[j] = temp;
        j--;
    }
    return result;
}

vector<int> OrganizeLastN(vector<int> numbers) // 0-min ,..., last - max
{
    vector<int> result = numbers;
    int j = result.size()-1;
    while(j> 0 && result[j] < result[j-1])
    {
        int temp = result[j-1];
        result[j-1] = result[j];
        result[j] = temp;
        j--;
    }
    return result;
}

int Positive(int a)
{
    if(a<0)
        return -a;
    return a;
}

int GreatestProduct(const vector<int> &numbers, int k)
{
    int result = 1;
    if(numbers.size() < k)
        return 0;
    if(numbers.size() == k)
    {
        for(int a = 0; a< k; a++)
            result*=numbers[a];
        return result;
    }
    vector<int> LargestP;
    vector<int> SmallestN;
    vector<int> LargestN;
    for(int a =0; a<numbers.size(); a++)
    {
        if(numbers[a]<0)
        {
            int temp = numbers[a];
            if(SmallestN.size() < k)
            {
                SmallestN.push_back(numbers[a]);
                SmallestN = OrganizeLastN(SmallestN);
                continue;
            }
            else if(SmallestN[k-1] > numbers[a])
            {
                temp = SmallestN[k-1];
                SmallestN[k-1] = numbers[a];
                SmallestN = OrganizeLastN(SmallestN);
            }
            if(LargestN.size() < k)
            {
                LargestN.push_back(temp);
                LargestN = OrganizeLastP(LargestN);
            }
            else if (LargestN[k-1] <temp)
            {
                LargestN[k-1] = temp;
                LargestN = OrganizeLastP(LargestN);
            }
            continue;
        }
        if(LargestP.size() < k)
        {
            LargestP.push_back(numbers[a]);
            LargestP = OrganizeLastP(LargestP);
        }
        else if(LargestP[k-1] < numbers[a])
        {
            LargestP[k-1] = numbers[a];
            LargestP = OrganizeLastP(LargestP);
        }
    }
    int NegativeNumberUsed;
    if(!(LargestP.size()==0 && (k%2==1)))
    {
        int PositiveI = 0;
        int NegativeI = 0;
        for(int a = 0; a<k;a++)
        {
            if(NegativeI< SmallestN.size() && PositiveI<LargestP.size())
            {
                if (LargestP[PositiveI] > Positive(SmallestN[NegativeI]))
                {
                    result *= LargestP[PositiveI];
                    PositiveI++;
                }
                else
                {
                    result*=SmallestN[NegativeI];
                    NegativeNumberUsed = SmallestN[NegativeI];
                    NegativeI++;
                }
            }
            else if( PositiveI<LargestP.size())
            {
                result*=LargestP[PositiveI];
                PositiveI++;
            }
            else
            {
                result *=SmallestN[NegativeI];
                NegativeNumberUsed = SmallestN[NegativeI];
                NegativeI ++;
            }
        }
        if(result < 0)
        {
            int temp;
            if(NegativeI < SmallestN.size() && PositiveI<LargestP.size())
            {
                int temp1 = (result / NegativeNumberUsed) * LargestP[PositiveI];
                int temp2 = (result/LargestP[PositiveI-1]) * SmallestN[NegativeI];
                if(temp1 > temp2)
                    temp = temp1;
                else
                    temp = temp2;

            }
            else if(NegativeI <SmallestN.size())
            {
                temp = (result/LargestP[PositiveI-1])*SmallestN[NegativeI];
            }
            else
            {
                temp = (result / NegativeNumberUsed) * LargestP[PositiveI];
            }
            result = temp;
        }
    }
    else
    {
        int LargestI = 0;
        int SmallestI = SmallestN.size()-1;
        for(int a = 0; a< k ; a++)
        {
            if(LargestI<LargestN.size())
            {
                result *= LargestN[a];
                LargestI++;
            }
            else
            {
                result*=SmallestN[SmallestI];
                SmallestI--;
            }
        }
    }
    return result;
}