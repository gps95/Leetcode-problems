public class Solution {
    public int LengthOfLongestSubstring(string s) {
       int maximum=0,count=0,lastDuplicate=0;
        Dictionary<char,int> dic = new Dictionary<char,int>();
        for(int i=0;i<s.Length;++i){
            if(dic.ContainsKey(s[i])){//duplicate
                if(lastDuplicate<dic[s[i]])lastDuplicate= dic[s[i]];
                count=i-lastDuplicate;
                dic[s[i]]=i;
            }
            else{//new char
                dic.Add(s[i],i);//insert in map
                ++count;
            }
            if(count>maximum)maximum=count;
        }
        return maximum;
    }
}