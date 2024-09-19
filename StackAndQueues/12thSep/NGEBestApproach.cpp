#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[8] = {1, 4, 2, 7, 12, 3, 2, 0};
    int res[8];
    stack<int> s;

    //traverse the array from the back
    for(int i=7; i>=0; i--){
        if(s.empty()){
            //then put -1 into the res arr
            res[i] = -1;
            s.push(arr[i]);
        }
        else if(arr[i] < s.top()){
            //first push the ele into the res array
            res[i] = s.top();
            //then push the ele into the stack 
            s.push(arr[i]);

            //now we can move to the next ele
        }
        else{
            while(!s.empty() && s.top() < arr[i]){
                //the pop out from the array
                s.pop();
            }
            //now we have reached at a point where the top ele is bigger than the arr[i]
            //first append the ele into the res
            if(s.empty()){
                res[i] = -1;
            }else{
                res[i] = s.top();
            }
            //now push the ele into the stack 
            s.push(arr[i]);
        }
    }

    //now we can print the res array
    for(int i=0; i<8; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}