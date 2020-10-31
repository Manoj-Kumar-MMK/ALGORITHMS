#include<iostream>
using namespace std;
void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"->";
    }
}
void search(int* arr,int n,int data){
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==data){
            found=true;
            cout<<"Element "<<data<<"is found at index:"<<i<<endl;
            break;
        }
    }
    if(!found)
        cout<<"Element not found";
}

int binarySearch(int *arr,int n,int data){
    int l,r,mid;
    l=0;
    r=n-1;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==data)
            return mid;
        else if(data<arr[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
void bubblesort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int flag=0,temp;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }   
        }
        if(flag==0)
        break;
    }
}
void insertionsort(int *arr,int n){
    int j,temp;
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void selectionsort(int *a,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i)
            swap(a[i],a[min]);
    }
}
int partition(int *a,int lb,int ub){
    int p,start,end;
    p=a[lb];
    start=lb;
    end=ub;
    while(start<end){
        while(a[start]<=p)
            start++;
        while(a[end]>p)
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[lb],a[end]);
    return end;
}
void quicksort(int *a,int lb,int ub){
    int loc;
    if(lb<ub){
        loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
void merge(int *a,int lb,int mid,int ub){
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    int *b=new int[ub];
    while(i<=mid && j<=ub){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    if(i>mid){
        while(j<=ub)
            b[k++]=a[j++];
    }
    else
    {
        while(i<=mid)
            b[k++]=a[i++];
    }    
    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}
void mergesort(int *a,int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }

}
void countsort(int *a,int n){
    int k=a[0],i;
    for(i=1;i<n;i++){
        if(a[i]>k)
            k=a[i];
    }
    int b[n],count[k+1];
    for(i=0;i<k+1;i++)
        count[i]=0;
    for(i=0;i<n;i++)
        ++count[a[i]];
    for(i=1;i<k+1;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
        b[--count[a[i]]]=a[i];
    for(i=0;i<n;i++)
        a[i]=b[i];
}
void countsortrad(int *a,int n,int pos){
    int i,b[n],count[10]={};
    for(i=0;i<n;i++)
        ++count[(a[i]/pos)%10];
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
        b[--count[(a[i]/pos)%10]]=a[i];
    for(i=0;i<n;i++)
        a[i]=b[i];
}
void radixsort(int *a,int n){
    int i,max=a[0];
    for(i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    for(int pos=1;max/pos>0;pos*=10)
        countsortrad(a,n,pos);
}
void shellsort(int *a,int n){
    int i,j,gap;
    for(gap=n/2;gap>=1;gap/=2){
        for(j=gap;j<n;j++){
            for(i=j-gap;i>=0;i-=gap){
                if(a[i+gap]>a[i])
                    break;
                else
                    swap(a[i+gap],a[i]);             
            }
        }
    }
}
void heapify(int *arr,int n,int i){
    int  lar=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[lar])
        lar=l;
    if(r<n && arr[r]>arr[lar])
        lar=r;
    if(lar!=i){
        swap(arr[i],arr[lar]);
        heapify(arr,n,lar);
    }
}
void heapsort(int *arr,int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}
int main(){
    int *arr,n,data,c;
    char ch;
    cout<<"Enter number of elements";
    cin>>n;
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    label:
    cout<<"1.print\n2.search\n3.binary search\n4.bubble sort\n5.insertion sort\n6.selectionsort\n7.quicksort\n8.mergesort\n9.countsort\n10.radixsort\n11.shellsort\n12.heapsort\nEnter your choice:";
    cin>>c;
    switch(c){
        case 1:
        printArr(arr,n);
        break;
        case 2:
        cout<<"Enter the element to be found";
        cin>>data;
        search(arr,n,data);
        break;
        case 3:
        cout<<"Enter the element to be found";
        cin>>data;
        cout<<"Element found at:"<<binarySearch(arr,5,data);
        break;
        case 4:
        bubblesort(arr,n);
        break;
        case 5:
        insertionsort(arr,n);
        break;
        case 6:
        selectionsort(arr,n);
        break;
        case 7:
        quicksort(arr,0,n);
        break;
        case 8:
        mergesort(arr,0,n);
        break;
        case 9:
        countsort(arr,n);
        break;
        case 10:
        radixsort(arr,n);
        break;
        case 11:
        shellsort(arr,n);
        break;
        case 12:
        heapsort(arr,n);
        break;
        default:
        cout<<"INVALID RESPONSE";
        break;

    }
    cout<<"\nDo you want to try again(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}