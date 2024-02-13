/*
------------------------- Concept ------------------------------
# 1 machine, 1 unit time for all jobs
# profit ke decresing order me saare jobs ko set kar denge
# our unko unki deadline or min no. of bande ke last me schedule kar dena hai (postion bharte chalna hai last se)
# high priority wale jobs ko phele moka pichhe se 
# very simple

*/

#include <bits/stdc++.h>
using namespace std;

struct job{
    char id;
    int dl;         // deadline
    int profit;
};

bool cmp(struct job a, struct job b){
    return a.profit > b.profit;
}

void printJobScheduling(struct job arr[], int n){
    sort(arr, arr+n, cmp);

    bool slot[n] = {false};
    int result[n];

    for(int i=0; i<n; ++i){     // n --> total bande
        for(int j=min(n, arr[i].dl)-1; j>=0; --j){        // slot acc. to bande
            if(slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for(int i=0; i<n; ++i){         // max n slot can be given
        if(slot[i] == true)
            cout << arr[result[i]].id << " ";          // arr[result[i]] --> that person
    }
}

int main(){
    struct job a[] = {{'a', 2, 100},
    {'b', 1, 19},
    {'c', 2, 27},
    {'d', 1, 25},
    {'e', 3, 15} };

    int n = sizeof(a)/sizeof(a[0]);

    cout << "Maximum profit sequence of jobs" << endl;

    printJobScheduling(a, n);
    return 0;
}