class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        long long left = 1;
        long long right = x;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == x) return mid;
            if (square > x) right = mid - 1;
            else left = mid + 1;
        }
        
        return right;
    }
};