#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y); 
}

int minOperations(int *nums,int numsSize,int k)
{
    qsort(nums,numsSize,sizeof(int),compare);
    int operations =0;
    int newSize=numsSize;
    while(newSize>1&&nums[0]<k)
    {
        long long x=nums[0],y=nums[1];
        long long new=(x*2)+y;
        nums[1]=(int)new;
        for(int i=0;i<newSize-1;i++)
        {
            nums[i]=nums[i+1];
        }
        newSize--;
        qsort(nums,newSize,sizeof(int), compare);
        operations++;
      
    
    }
    return operations;
}
int main()
{
    int numsSize,k;
    int nums[]={2,11,10,1,3};
    k=10;
    numsSize=sizeof(nums)/sizeof(nums[0]);
    int result=minOperations(nums,numsSize,k);
    printf("the minimum operation required for this operation is %d",result);
    return 0;
}