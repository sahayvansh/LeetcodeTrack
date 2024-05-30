class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26]={0};
        for(char x:s){
            count[x-'a']++;
        }
        for(char x:t){
            count[x-'a']--;
        }
        for(int x:count){
            if(x!=0)
                return false;
        }
        return true;
    }
};