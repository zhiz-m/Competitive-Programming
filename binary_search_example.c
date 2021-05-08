typedef int Data;

// returns the smallest index i such that arr[i] >= val, 
//   or returns N if no such index exists
int lower_bound(Data arr[], int N, Data val){
    int L = 0, R = N;
    while(R - L > 1){
        int mid = (L + R) / 2;
        if (arr[mid] < val) L = mid;
        else R = mid;
    }
    return R;
}

