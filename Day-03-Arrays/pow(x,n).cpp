class Solution {
public:
    double myPow(double x, int n) {
        // making power +ve 
        long long power= abs(n);
        double ans=1.0;
        while(power){
            // if power is odd than mulitply the base with ans
            if(power%2){
                ans *=x;
                power--;
            }
            // if power is even than square the base and make the power half
            else{
                 x*=x;
                 power /=2;
            }
        }
        if(n<0) return 1.0/ans;
        else return ans;
    }
};