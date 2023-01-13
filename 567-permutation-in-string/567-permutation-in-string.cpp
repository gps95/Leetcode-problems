class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size()<s1.size())return false;
        unordered_map<char,int> map;//letter,number of letters found
        
        //fill map with ocurrences of s1
        for(char c:s1)map[c]++;
        int count=map.size();
        
        //iterate till found or end
        int i=0,j=0;
        while(j<s2.size()){
            if(map.find(s2[j])!=map.end()){//if you find a letter,reduce frequency in map
                if(--map[s2[j]] == 0)count--;//if freq=0,count--;
            }
            if(j-i+1 < s1.size()){//window<window size, increase window
                j++;
            }
            else{//window==window size,slide window to right
                if(count==0)return true;// permutation found
                if(map.find(s2[i])!=map.end()){//add char again
                    if(++map[s2[i]]==1)count++;//if freq=1,count++;
                }
                //slide window
                ++i;++j;
            }
        }
        return false;
    }
};