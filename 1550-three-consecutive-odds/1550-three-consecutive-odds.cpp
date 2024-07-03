class Solution {
public:
    bool isOdd(int n){
        return n%2!=0;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(isOdd(arr[i])){
                cnt++;
                if(cnt==3)
                    return true;
            }
            if(!isOdd(arr[i])){
                cnt=0;
            }
        }
        return false;
    }
};