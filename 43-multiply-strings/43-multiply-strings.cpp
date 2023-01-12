class Solution {
public:
    string multiply(string a, string b) {
        if(a=="0"||b=="0")return "0";
        vector<int> res(a.size()+b.size(),0);
        for(int i=a.size()-1;i>=0;--i)
            for(int j=b.size()-1;j>=0;--j){
                res[i+j+1]+=(a[i]-'0')*(b[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        int i = 0;
        string ans = "";
        while (res[i] == 0) i++;
        while (i < res.size()) ans += to_string(res[i++]);
        return ans;
    }
};