class Solution {
  public:
    int merge(vector<int>&arr , int start , int mid ,int end){
        vector<int>temp(end-start+1) ;
        int invCt= 0; 
        int idx = 0 ; 
        int i = start ; 
        int j = mid+1 ; 
        while(i<=mid&&j<=end){
            if(arr[i]<=arr[j]){temp[idx++]=arr[i++] ; }
            else {invCt+=mid-i+1; temp[idx++]=arr[j++];}
        }
        while(i<=mid){
            temp[idx++]=arr[i++] ; 
        }
        while(j<=end){
            temp[idx++]=arr[j++];
        }
        for(int i = 0 ; i< idx;i++){
            arr[start+i] = temp[i] ;
        }
        return invCt ; 
    }
    int mergesort(vector<int>&arr,int start , int end){
        int left = 0 ; 
        int right = 0 ; 
        int getCt = 0 ; 
        int mid = start+(end-start)/2 ; 
        if(start<end){
        left = mergesort(arr,start,mid);
        right = mergesort(arr,mid+1,end) ; 
        getCt = merge(arr,start,mid,end);}
        return left+right+getCt ; 
    }
    int inversionCount(vector<int> &arr) {
        int end = arr.size() ;
        return mergesort(arr,0,end-1);
        
    }
};
