/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
class SGTTree{
  vector<int> sg;
  public:
  SGTTree(int n)
  {
      sg.resize(4*n);
  }
  int build(int idx,int l,int r,vector<int>& nums)
  {
      if(l==r)
      {
          return sg[idx]=nums[l];
      }
      int mid=l+(r-l)/2;
      int left=build(2*idx+1,l,mid,nums);
      int right=build(2*idx+2,mid+1,r,nums);
      return sg[idx]=min(left,right);
  }
  int minInRange(int idx,int l,int r,int low,int high,vector<int>& nums)
  {
      //Complete Overlap
      if(l>=low and r<=high)
      {
          return sg[idx];
      }
      //No Overlap
      else if(r<low or l>high)
      {
          return INT_MAX;
      }
      //Partial Overlap
      int mid=(l+r)/2;
      int left=minInRange(2*idx+1,l,mid,low,high,nums);
      int right=minInRange(2*idx+2,mid+1,r,low,high,nums);
      return min(left,right);
  }
  void update(int idx,int l,int r,int i,int val)
  {
      if(l==r)
      {
          sg[idx]=val;
          return;
      }
      int mid=(l+r)/2;
      if(i<=mid)
      {
          update(2*idx+1,l,mid,i,val);
      }
      else
      {
          update(2*idx+2,mid+1,r,i,val);
      }
      sg[idx]=min(sg[2*idx+1],sg[2*idx+2]);
  }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    SGTTree t1(n);
    t1.build(0,0,n-1,nums);
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int low;
            cin>>low;
            int high;
            cin>>high;
            int minimum=t1.minInRange(0,0,n-1,low,high,nums);
            cout<<minimum<<endl;
        }
        else
        {
            int idx;
            cin>>idx;
            int val;
            cin>>val;
            t1.update(0,0,n-1,idx,val);
            nums[idx]=val;
            for(auto i:nums)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            
            
        }
    }

    return 0;
}
