// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ceilDivide(int x, int num) {
        if(x % num == 0) {
            return x/num;
        } else {
            return x/num + 1;
        }
    }
    int giveLeftIndex(vector<int>& nums, int i , int j, int &a) {
        int ind = -1;
        while(i <= j) {
            int mid = (i+j)/2;
            if(a == nums[mid]) {
                ind = mid;
                j = mid - 1;
            } else if(a < nums[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        if(ind != -1) {
            return ind;
        } else {
            return i;
        }
    }
    int giveRightIndex(vector<int>& nums, int i , int j, int &b) {
        int ind = -1;
        while(i <= j) {
            int mid = (i+j)/2;
            if(b == nums[mid]) {
                ind = mid;
                i = mid + 1;
            } else if(b < nums[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        if(ind != -1) {
            return ind;
        } else {
            return j;
        }
    }
	int TotalPairs(vector<int>&nums, int x, int y){
	    // Code here
	    int n = nums.size();
        int ans = 0;
	    sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++) {
            int num = nums[i];
            int a = ceilDivide(x, num);
            int b = y/num;
            int left = giveLeftIndex(nums, i+1, n-1, a);
            int right = giveRightIndex(nums, i+1, n-1, b);
            if(left <= right) {
                ans += right - left + 1;
            }
        }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, x, y;
		cin >> n >> x >> y;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.TotalPairs(nums, x, y);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends