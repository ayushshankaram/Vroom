/*
PsuedoCode 

mergeSort(arr , low , high)    {Low - Index of first element  , High - Index of last element}
{

if (low == high) return;  {as its a single element array}

mid = (low+high)/2
mergeSort(arr,low,mid)
mergerSort(arr,mid+1,high)
merge(arr , low , mid , high )



}


6n(logn + 1)   {log of base 2} --> Time Complexity (6n = work for each step , logn+1 = total times the work needs to done or number of times the main array needs to divided (halved) to get single elements )
*/ 



/*
Merging concept 
TempArray = {}


// Using two pointer for both small arrays!

left = low
right = mid+1 

while ( left <= mid && right <= high) {

    if (arr[left]<=arr[right]) {

        temparray.append(arr[left])
        left  += 1 ; 
    }


    else {
        temparray.append(arr[right])
        right  += 1 ; 
    }
}



while ( left <=mid) {
    temparray.append(arr[left])
        left  += 1 ; 
}


while (right <= high) {
    temparray.append(arr[right])
        right  += 1 ; 
}
*/


#include <iostream>
#include <vector>
using namespace std; 

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);    //Instead of push_back try emplace_back.
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}
