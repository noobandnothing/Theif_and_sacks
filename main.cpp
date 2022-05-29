#include <bits/stdc++.h>

using namespace std;

typedef  long long elementtype;
typedef  vector<int> container;
map<elementtype,int> count_WH_S;

bool FindElement(map<elementtype,int> &g1,elementtype target){
    map<elementtype,int>::iterator x = g1.find(target);
    if(x == g1.end())
        return false;
    else
        return true;
}

/* PROGRAM PARTS */
void GetNumOfEachWH_Sacks(container &WH_S,elementtype WH_num,elementtype &MaxE){
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


int main()
{
    std::ios_base::sync_with_stdio(false);
    // Test Var
    int Test = 0;
    std::cin>>Test;
    if(Test>= 1 && Test<= 5){
             //EACH TEST LOOP
            while(Test != 0){
                int WH_num = 0;
                std::cin>>WH_num;

                container WH_S;
                map<elementtype,int>  used_num;
                elementtype MaxE = -1;
                elementtype max_value = 0;

                GetNumOfEachWH_Sacks(WH_S,WH_num,MaxE);


                for(int counter = 1 ; counter <= WH_num; counter++){
                    elementtype sum = 0;

                    elementtype tmp;
                    tmp = WH_S[counter];
                    if(tmp == 0){
                        continue;
                    }else{
                            if(FindElement(used_num,tmp) == true){
                                continue;
                            }else{
                                used_num.insert(pair<elementtype, int>(tmp,1));
                                bool flag = false;
                                if(tmp == MaxE){
                                    map<elementtype,int>::iterator x = count_WH_S.find(tmp);
                                    if(x->second == 1){
                                        maxChecking(tmp,max_value);
                                        continue;
                                    }
                                }
                                for (container::iterator tmp_it = WH_S.begin(); tmp_it != WH_S.end() ; ++tmp_it){
                                    //cout<<"SUM : "<<tmp <<" := " <<sum<<endl;
                                    if(*tmp_it >= tmp){
                                        flag = true;
                                        sum+=tmp;
                                    }else {
                                        if(flag == true){
                                            maxChecking(sum,max_value);
                                                // EXAMPLE 3 0 5 4 4 4
                                                //         3 | 3 3 3 3
                                            sum = 0;
                                            continue;
                                        }
                                    }
                                }
                                maxChecking(sum,max_value);
                            }
                    }
                }
            if(Test-1 != 0)
                std::cout<<max_value<<"\n";
            else
                std::cout<<max_value;
            Test--;
        }
    }
    return 0;
}
