void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

void reverse(int *ini, int *fin){
    while(ini<fin){
        swap(ini++,--fin);
    }
}

void rotate(int *nums, int numsSize, int k){
    k=numsSize -k %numsSize;
    reverse(nums,nums+k);
    reverse(nums+k,nums+numsSize);
    reverse(nums,nums+numsSize);
}