
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// by requiemsoul

int cmp(const void *a, const void *b){
return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

int i,j,k,sum,t,total=64;
qsort(nums,numsSize,sizeof(int),cmp);
*returnSize=0;
int **q=(int**)malloc(sizeof(int*)*total);
*returnColumnSizes=(int*)malloc(sizeof(int)*total);
for(i=0;i<numsSize-2;i++)
{
    if(nums[i]>0||nums[i]+nums[i+1]+nums[i+2]>0)
        break;
    if(i>0&&nums[i]==nums[i-1])
        continue;
    j=i+1;
    k=numsSize-1;
    sum=-nums[i];
    while(j<k)
    {
        t=nums[j]+nums[k];
        if(t<sum)
            j++;
        else if(t>sum)
            k--;
        else
        {
            (*returnColumnSizes)[*returnSize]=3;
            q[*returnSize]=(int*) malloc(sizeof(int)*3);
            q[*returnSize][0]=nums[i];
            q[*returnSize][1]=nums[j++];
            q[*returnSize][2]=nums[k--];
            (*returnSize)++;
            while(j<k&&nums[j]==nums[j-1])
                j++;
            while(j<k&&nums[k]==nums[k+1])
                k--;
            if((*returnSize)==total)
            {
                total*=2;
                *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
                q=(int**)realloc(q,sizeof(int*)*total);
            }
        }
    }
}
return q;
}