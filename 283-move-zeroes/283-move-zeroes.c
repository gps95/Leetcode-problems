void moveZeroes(int* nums, int numsSize){
    int snowBallSize = 0; 
    for (int i=0;i<numsSize;i++){
        if(!nums[i]) snowBallSize++; 
        else if(snowBallSize > 0) {
            nums[i-snowBallSize]=nums[i];
            nums[i]=0;
        }
    }
}