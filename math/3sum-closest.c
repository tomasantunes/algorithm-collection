// by thedrafttin

void quickSort(int* nums,int first,int end){  
    int temp,l,r;  
    if(first>=end)return;  
    temp=nums[first];  
    l=first;r=end;  
    while(l<r){  
        while(l<r && nums[r]>=temp)r--;  
        if(l<r)nums[l]=nums[r];  
        while(l<r && nums[l]<=temp)l++;  
        if(l<r)nums[r]=nums[l];  
    }  
    nums[l]=temp;  
    quickSort(nums,first,l-1);  
    quickSort(nums,l+1,end);  
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int begin, end, sum = 0, min = 1e6, sm;
    quickSort(nums, 0, numsSize - 1);
    for(int i = 0; i < numsSize; i++){
        begin = i + 1; end = numsSize - 1;
        while(begin < end){
            sum = nums[i] + nums[begin] + nums[end];
            int difval = abs(target - sum);
            if(difval < min){
                min = difval;
                sm = sum;
            }
            if(sum < target)
               begin++;
            else if(sum > target)
                    end--;
            else if(sum == target)
                    return target;
        }
    }
    return sm;
}