// 2 min element laina hai unko add kar dena hai

#include <bits/stdc++.h>
using namespace std;

int minComputation(int files[], int n){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; ++i)
        pq.push(files[i]);

    int count=0;

    while(pq.size() > 1){
        int first_min = pq.top();
        pq.pop();
        int second_min = pq.top();
        pq.pop();

        int temp = first_min + second_min;
        count += temp;
        
        pq.push(temp);
    }

    return count;
}

int main(){
    int files[] = {5, 10, 20, 30, 30};
    int n = sizeof(files)/sizeof(files[0]);

    cout << minComputation(files, n);
    return 0;
}