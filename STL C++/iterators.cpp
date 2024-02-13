#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    cout << "Size: " << v.size() << endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
	vector<int> v = {2,3,4,5,6,7,8};
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	vector<int> ::iterator it = v.begin();			//iterator like a pointer 
	for(it=v.begin(); it!=v.end(); ++it)
		cout << (*it) << endl;

    return 0;
}