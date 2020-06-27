#include<iostream>
#include<algorithm>
using namespace std;
void bubblesort(int*a,int b);
void afterprint(int*a,int b);
int main(){
    int size;                    //input size
    int x;                     
    int *string;                // input array
    cout<<"輸入你的siez:";
    cin>>size;
    cout<<"輸入想sort的數字:";
    for(int i=0;i<size;i++){   // initiallize input array
        cin>>x;
        string[i]=x;
    }
    bubblesort(string,size);
    afterprint(string,size);
    return 0;
}
void bubblesort(int*a,int b){        //sort method
    for(int i=0;i<b-1;i++){
        for(int j=0;j<b-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }

}
void afterprint(int*a,int b){       // print the array after sort
    for(int i=0;i<b;i++){
        cout<<a[i]<<" ";
    }
}