#include<bits/stdc++.h>
using namespace std;

void setupIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void selection_sort(int arr[], int n){  // Time Complextiy: O(n^2) -> Worst, Avg & Best-case
    for(int i=0; i<=n-2; i++){
        int mini_Idx = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[mini_Idx]){
                mini_Idx = j;
            }
        }
        swap(arr[i], arr[mini_Idx]);
    }
}

void bubble_sort(int arr[], int n){ // Time Complextiy: O(n^2) -> Worst & Avg-case, Best-case: O(n)
    for(int i=n-1; i>=1; i--){
        bool didSwap = false;   // for best-case: O(n)
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = true;
            }
        }
        if(!didSwap)
            break;
    }
}

void recursive_bubble_sort(int arr[], int n){ // Time Complextiy: O(n^2) -> Worst & Avg-case, Best-case: O(n)
    if(n==1) return;

    bool didSwap = false;
    for(int j=0; j<=n-2; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
            didSwap = true;
        }
    }
    if(didSwap == false) return;
    recursive_bubble_sort(arr, n-1);
}

void insertion_sort(int arr[], int n){  // Time Complextiy: O(n^2) -> Worst & Avg-case, Best-case: O(n)
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

class recursiveInsertionSort_class{ // // Time Complextiy: O(n^2) -> Worst & Avg-case, Best-case: O(n)
    public:
    void recursive_insertion_sort(int arr[], int n){
        recursive_insertionSort(arr, 0, n);
    }

    void recursive_insertionSort(int arr[], int i, int n){
        if(i == n) return;

        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
        recursive_insertionSort(arr, i+1, n);
    }

};

class mergeSort_class{  // Time Complextiy: O(nlogn) -> Worst-case, Avg-case & Best-case: O(n), Space Complexity: O(n)
    public:
    void merge_sort(int arr[], int n){ 
        MS(arr, 0, n-1);
    }

    void MS(int arr[], int low, int high){
        if(low>=high) return;
    
        int mid = (low+high)/2;
        MS(arr, low, mid);
        MS(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    
    void merge(int arr[], int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid+1;
        while(left <= mid && right <=high){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
                right++;
        }
    
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    
};

class quickSort_class{  // Time Complextiy: O(nlogn) -> Best & Avg-case, Worst-case: O(n^2), Space Complexity: O(1)
    /*
    The worst-case time complexity of Quick Sort occurs when the pivot selection leads to highly unbalanced partitions. This happens when:
        1) The pivot is always the smallest or largest element in the partition.
        2) The partitioning results in one side with n-1 elements and the other with 0 elements.
    */
    
    public:
    void quick_sort(int arr[], int n){
        qs(arr, 0, n-1);
    }

    void qs(int arr[], int low, int high){
        if(low < high) {    // stop if size is 1
            int pIndex = partition(arr, low, high);
            qs(arr, low, pIndex-1);
            qs(arr, pIndex+1, high);
        }
    }

    int partition(int arr[], int low, int high){
        int pivot = arr[low];
        int i=low, j=high;

        while(i<j) {
            while(arr[i]<=pivot && i<=high-1){  // find i, for arr[i] > pivot (i moves right until it finds an element greater than the pivot)
                i++;
            }
            while(arr[j]>pivot && j>=low+1){    // find j, for arr[j] < pivot (j moves left until it finds an element smaller than or equal to the pivot)
                j--;
            }

            if(i<j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]); // swap(pivot, j)
        return j;

    }
};

int main() {
    setupIO();
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)  cin >> arr[i];

    // selection_sort(arr, n);

    // bubble_sort(arr, n);

    // recursive_bubble_sort(arr,n);

    // insertion_sort(arr, n);

    // recursiveInsertionSort_class recursiveInsertionSortObj;
    // recursiveInsertionSortObj.recursive_insertion_sort(arr, n);

    // mergeSort_class mergeSortObj; 
    // mergeSortObj.merge_sort(arr, n);
    
    // quickSort_class quickSortObj;
    // quickSortObj.quick_sort(arr, n);

    for(int num: arr)   cout << num << " ";
    
    return 0;
}