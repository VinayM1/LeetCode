class Solution {
public:
    double myPow(double x,  long long n) {
        long long N = n;
        if(N == 0){
            return 1;
        }
        if(N < 0){
            return 1 / myPow(x,-N);
        }
        double half = myPow(x, N/ 2);
        if(N%2 == 0){
            return half*half;
        }
        else{
            return x*half*half;
        }
    }
};