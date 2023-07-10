#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
class SET{
    public:
    set <int> s1={1,2,3,4,5};
    set <int> s2={2,3,4};
    void ismember(int i){
        if(s1.count(i)>0){
            cout<<i<<" is the member of set\n";
        }
        else{
            cout<<i<<" is not the memeber of set\n";
        }
    }
    void unionof(){
        set <int> s2={6,7,8,9,10};
        set <int> s3;
        set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
        for (auto i:s3){
            cout<<i<<" ";
        }
        cout<<endl;

    }
    void is_subset(){
        bool issubset=includes(s1.begin(),s1.end(),s2.begin(),s2.end());
        if(issubset){
            cout<<"s2 is the subset of s1\n";

        }
        else{
            cout<<"s2 is not subset of s1\n";
        }
    }
    void set_diff(){
        set <int> s3;
        set_difference(s1.begin(),s2.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
        for (auto i:s3){cout<<i<<" ";}
        cout<<endl;

    }
    void symmetric_diff(){
        set <int> s3;
        set_symmetric_difference(s1.begin(),s2.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
        for (auto i:s3){cout<<i<<" ";}
        cout<<endl;
    }
    void powerset(){
        int s1[]={1,2,3};
        int size=sizeof(s1)/sizeof(s1[0]);
        int pset_size=pow(2,size);
        int i,j;
        for(int i=0;i<pset_size;i++){
            for(int j=0;j<size;j++){
                if(i&(i<<j)){
                    cout<<s1[j];
                }
            }
            cout<<endl;
        
        }
    }
    void cartesian(){
        int arr1[]={1,2,3};
        int arr2[]={4,5,6};
        int n1=sizeof(arr1)/sizeof(arr1[0]);
        int n2=sizeof(arr2)/sizeof(arr2[0]);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                printf("{%d,%d}, ",arr1[1],arr2[j]);
            }
        }
    }
};
int main(){
    SET s4;
    s4.ismember(2);
    s4.unionof();
    s4.is_subset();
    s4.set_diff();
    s4.symmetric_diff();
    s4.powerset();
    s4.cartesian();
    return 0;
}