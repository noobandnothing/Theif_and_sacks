#include "parts.hpp"
int main()
{
    std::ios_base::sync_with_stdio(false);
    // Test Var
    int Test = 0;
    std::cin>>Test;
    if(Test>= 1 && Test<= 5){
             //EACH TEST LOOP
            while(Test != 0){
                int Num_of_Workhouse = 0;
                std::cin>>Num_of_Workhouse;

                MyStack workhouse_stacks,used_num,tmp_stack;
                elementtype max_value = 0;

                GetNumOfEachWH_Sacks(workhouse_stacks,Num_of_Workhouse);
                ReverseStack(workhouse_stacks);

                for(int counter = 1 ; counter <= Num_of_Workhouse; counter++){
                    elementtype sum = 0;
                    elementtype tmp;

                    for(int tmp_counter = 1 ;tmp_counter < counter;tmp_counter++){
                        tmp_stack.push(workhouse_stacks.top());
                        workhouse_stacks.pop();
                    }
                    tmp = workhouse_stacks.top();
                    workhouse_stacks.pop();
                    workhouse_stacks.push(tmp);
                    ReturnAllAsItwas(tmp_stack,workhouse_stacks);

                    if(tmp == 0){
                        continue;
                    }else{
                            if(FindElement(used_num,tmp)){
                                continue;
                            }else{
                                used_num.push(tmp);
                                bool flag = false;
                                while(!workhouse_stacks.empty()){
                                    if(workhouse_stacks.top() >= tmp){
                                        flag = true;
                                        sum+=tmp;
                                    }else {
                                        if(flag == true){
                                            maxChecking(sum,max_value);
                                                // EXAMPLE 3 0 5 4 4 4
                                                //         3 | 3 3 3 3
                                            GoNext(tmp_stack,workhouse_stacks);
                                            sum = 0;
                                            continue;
                                        }
                                    }
                                    GoNext(tmp_stack,workhouse_stacks);
                                }
                                maxChecking(sum,max_value);
                                ReturnAllAsItwas(tmp_stack,workhouse_stacks);
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
