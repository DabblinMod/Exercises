

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i, j, index=0;
    int nums3[nums1Size + nums2Size];
    int nums3Size=nums1Size + nums2Size;
    double result;
    for(i=0; i < nums1Size; i++){
        nums3[index++]=nums1[i];
        if(i==nums1Size-1){
            for(j=0; j < nums2Size; j++){
                nums3[index++]=nums2[j];
            }
        }
    }
    for(i=0; i < nums3Size-1; i++){//Sort the list
        if(nums3[i] > nums3[i+1]){//if larger number is in front move it behind
            j=nums3[i];//save the larger num
            nums3[i]=nums3[i+1];
            nums3[i+1]=j; //move it to end
        }
    }

    int mid=nums3Size/2;
    double value=0;
    for(i=0; i < nums3Size; i++){
        if(i==mid){
            if(mid%2==0){//if the length of num3 is even
                value=nums3[mid];
            }
            else if(mid%2==1){//if lengtjh of num3 is odd
                value=(nums3[mid] + nums3[mid+1])/2;
            }
        }
    }
    return value;
}