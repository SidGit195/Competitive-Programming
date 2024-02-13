/*
Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int profit, weight;

    // Constructor
    // Item(int profit, int weight){
    //     this->profit = profit;
    //     this->weight = weight;
    // }
};

static bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    
    return r1 > r2;         // decreasing order 
}

//main greedy problem to solve
double fractionalknapsack(int W, struct Item arr[], int n){

    sort(arr, arr + n, cmp);

    double finalvalue = 0;

    for(int i=0; i<n; ++i){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else{
            finalvalue += W*((double)arr[i].profit/arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main(){
    int W = 50;
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << fractionalknapsack(W, arr, n) ;

    return 0;
}