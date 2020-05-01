/*
FIRST BAD VERSION

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

*/

//To reduce Number of calls Use Binary search Instead of Linear Search
//TIME : O(Log(n))

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        int mid ;
        bool bad, bad2;
        while(l<=r){
            mid=(r-l)/2 +l; 
            bad=isBadVersion(mid);
            bad2=isBadVersion(mid-1);
            bool ans=bad ^ bad2;
            if(ans==true) return mid; 
            else if(bad2==true)
                r=mid-1;
            else if(bad==false)
                l=mid+1;   
        }
        return -1;
    }
};

