#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[4] = {3, 4, 6, 5};
    stack<int> s;
    int res[4];
    int flag = 0;

    for(int i=0; i<4; i++){
        int min = i;
        for(int j=i; j<4; j++){
            if(arr[j]>arr[min]){
                min = j;
                flag = 1;
            }
        }
        //here i have the max ele that is on the right
        //push this ele to the stack
        if(flag == 1){
            s.push(arr[min]);
            flag = 0;
        }else{
            s.push(-1);
        }
        
    }

    //all the ele are pushed into the stack 
    for(int i=3; i>=0; i--){
        //push the ele into another array
        res[i] = s.top();
        s.pop();
    }

    for(int i=0; i<4; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}