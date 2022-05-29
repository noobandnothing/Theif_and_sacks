#include <bits/stdc++.h>
using namespace std;

typedef  long long elementtype;
typedef  vector<int> container;
elementtype MaxE = -1;
map<elementtype,int> count_WH_S;

bool FindElement(map<elementtype,int> &g1,elementtype target){
    map<elementtype,int>::iterator x = g1.find(target);
    if(x->second == 0)
        return false;
    else
        return true;
}

/* PROGRAM PARTS */
void GetNumOfEachWH_Sacks(container &WH_S,elementtype WH_num){
    elementtype input;
    map<elementtype,int>::iterator x;
    for(int counter = 0; counter < WH_num; counter++){
        std::cin >> input;
        if(input > MaxE)
            MaxE = input;
        WH_S.push_back(input);
        x = count_WH_S.find(input);
        if(x->second == 0){
            count_WH_S.insert(pair<int, int>(input,1));
            x = count_WH_S.find(input);
        }else{
            x = count_WH_S.find(input);
            x->second = x->second+1;
        }
    }
}

void maxChecking(elementtype &sum,elementtype &max_value){
    if(sum != 0 )
        if(sum > max_value)
            max_value = sum;
}
