#include<bits/stdc++.h>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {

    int n;
    cin >> n;

    //variable size array
    int* arr = new int[n];

    //taking input in array
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int ans = getSum(arr,n); 

    cout << "answer is " << ans << endl;

    //case1
    while(true) {
        int i = 5;
    }

    //case2
    while(true) {
        int* ptr = new int;
    }
    /*char ch = 'q';
    cout << sizeof(ch) << endl;

    char* c = &ch;
    cout << sizeof(c) << endl;*/


    return 0;
}