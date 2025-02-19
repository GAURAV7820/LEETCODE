//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
int binarysearch(int nums[],int low,int high, int key)
{       
	if(low>high)
		return high+1;
	else
	{
		 int mid=low+(high-low)/2;
		if(nums[mid]==key)
		{
			return mid;
			
		}
		else if(nums[mid]>key)
			return binarysearch(nums,low,mid-1,key);
		else
			return binarysearch(nums,mid+1,high,key);
	}
	return (low>high)?low:high;
}
int searchInsert(int* nums, int numsSize, int target) {
    	int index=binarysearch(nums,0,numsSize-1,target);
        printf("index is :%d",index);
        return index;
}
