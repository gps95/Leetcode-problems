class NumArray {
private:
    vector<int> vec;
public:
    NumArray(vector<int>& nums) {
        int i=0,sum;
        for(int n:nums){
            sum+=n;
            vec.push_back(sum);
        }
    }

    int sumRange(int l, int r) {
        if(l==0) return vec[r];
        return vec[r]-vec[l-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */