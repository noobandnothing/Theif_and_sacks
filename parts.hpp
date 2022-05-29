#include <iostream>
#include <stack>
typedef long long elementtype;
typedef std::stack<elementtype> MyStack;

bool FindElement(MyStack sample ,elementtype target){
    while(!sample.empty()){
        if(sample.top()== target)
            return true;
        sample.pop();
    }
    return false;
}

void ReverseStack(MyStack &sample){
    MyStack tmp;
    while(!sample.empty()){
        tmp.push(sample.top());
        sample.pop();
    }
    sample = tmp;
}


/* PROGRAM PARTS */

void GetNumOfEachWH_Sacks(MyStack &workhouse_stacks,elementtype Num_of_Workhouse){
    elementtype input;
    for(int counter = 0; counter < Num_of_Workhouse ; counter++){
        std::cin >> input;
        workhouse_stacks.push(input);
    }
}

void ReturnAllAsItwas(MyStack &tmp_stack,MyStack &workhouse_stacks){
    while(!tmp_stack.empty()){
        workhouse_stacks.push(tmp_stack.top());
        tmp_stack.pop();
    }
}

void maxChecking(elementtype &sum,elementtype &max_value){
    if(sum != 0 )
        if(sum > max_value)
            max_value = sum;
}

void GoNext(MyStack &tmp_stack,MyStack &workhouse_stacks){
    tmp_stack.push(workhouse_stacks.top());
    workhouse_stacks.pop();
}
