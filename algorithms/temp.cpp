#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include <algorithm>

using namespace std;
#define int long long
 int ans=0;

void print(int a[], int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void temp(vector<int> v)
{
    int n=v.size();
    vector<int> len;
    if(v.size()<3)
    {
        return ;
    }
    int prev=v[0];
    int temp_count=1;
    int ans=0;
    vector<int> s;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==prev)
        {
            temp_count++;
        }
        else
        {
            s.push_back(prev);
            prev=v[i];
            len.push_back(temp_count);
            temp_count=1;
        }
    }
    print(v);
    s.push_back(v[v.size()-1]);

    len.push_back(temp_count);

    for(int i=0;i<len.size();i++)
    {
        if(len[i]>2)
        {
            ans=ans+(len[i]-2);
            len[i]=2;
        }
    }
    n-=ans;
    cout<<ans<<endl;
    vector<int> actual;
    for(int i=0;i<s.size();i++)
    {
        int t=s[i];
        for(int j=0;j<len[i];j++)
        {
            actual.push_back(t);
        }
    }
    vector<int> index;
    int cur=0;
    print(actual);
    print(len);
    for(int i=0;i<len.size();i++)
    {
        index.push_back(cur);
        cur+=len[i];
    }
    print(index);
    int start=1;
    for(int i=0;i<len.size();i++)
    {
        if(len[i]==2 && index[i]%2==0)
        {
            ans++;
            n--;
            start=i;
            break;
        }
    }
    cout<<ans<<endl;
    vector<int> final_index;
    for(int i=0;i<len.size();i++)
    {
        if(len[i]==2)
        {
            final_index.push_back(index[i]);
        }
    }
    print(final_index);
    if(final_index.size()>0)
    {
        int c=start;
        int t2=1;
        int j=0;
        while(final_index[j]!=start)
        {
            t2++;
            j++;
        }
        t2=max(t2,j+1);
        for(int i=t2;i<final_index.size();i++)
        {
            if(c%2==final_index[i]%2)
            {
                continue;
            }
            else
            {
                ans++;
                n--;
                c=final_index[i];
            }
        }
    }
    if(n%2!=0)
    {
        ans++;
    }
    cout<<ans;


}
bool helper(vector<int>& nums, int target,int low,int high)
{
    int mid=low+high;
    mid/=2;
    if(nums[mid]==target)
        return true;
    bool x=false;
    bool y=false;
    bool z=false;
    bool a=false;
    if(nums[low]<=nums[mid])
    {
        if(nums[low]<=target && nums[mid]>=target)
        {
            x=helper(nums,target,low,mid-1);
        }
        else
        {
            y=helper(nums,target,mid+1,high);
        }
    }
    if(nums[mid]<=nums[high])
    {
        if(nums[mid]<=target && nums[high]>=target)
        {
            z=helper(nums,target,mid+1,high);
        }
        else
        {
            a=helper(nums,target,low,mid-1);
        }
    }
    return a||z||y||x;
}
bool search(vector<int>& nums, int target) {
    return helper(nums,target,0,nums.size()-1);
}
void printSubsequence(string input, string output,int temp)
{if(input.empty() && temp!=3)
    {
        return;
    }
    if (input.empty()|| temp==3) {
        if(output=="101"||output=="010")
            ans++;
        return;}
    printSubsequence(input.substr(1), output,temp);
    if(output.empty())
    {printSubsequence(input.substr(1), output + input[0],temp+1);
    }
    if(output.size()>0){
        string t=input.substr(1);
        if(output[output.size()-1]!=input[0]){
    printSubsequence(t, output + input[0],temp+1);}}
    return;
}
bool validPalindrome(string s) {
    int c=1;
    int i=0;
    int j=s.size()-1;
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            if(c>0)
            {
                c--;
                if(s[i]==s[j-1] && s[i+1]==s[j])
                {
                    j--;
                    i++;
                }
                else if(s[i+1]==s[j])
                {
                    i++;
                }
                else {
                    j++;
                }

            }
            else
            {
                break;
            }
        }
    }
    if(i>=j)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int largestInteger(int nums) {
    int temp=nums;
    vector<int> o,e;
    while(nums>0)
    {
        if((nums%10)%2==0)
        {
            e.push_back(nums%10);
        }
        else
        {
            o.push_back(nums%10);
        }
        nums/=10;
    }
    string s="";
    nums=temp;
    while(nums>0)
    {
        s=(to_string(nums%10))+s;
        nums/=10;
    }


    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    int i=0;
    while(i<s.size())
    {
        if((s[i]-'0')%2==0)
        {
            int a=e[e.size()-1];
            s[i]=((a+'0'));
            e.pop_back();
        }
        else
        {
            int a=o[o.size()-1];
            s[i]=((a+'0'));
            o.pop_back();

        }
    }
    cout<<s;
    return 0;
}
int maximumProduct(vector<int>& nums, int k) {
    int mod=1000000007;

    map<int,int> ele;
    for(int i=0;i<nums.size();i++)
    {
        ele[nums[i]]++;
    }

    while(k>0)
    {
        auto it=ele.begin();
        if(ele.size()==1)
        {
            break;
        }
        int a=it->first;
        it->second--;
        auto temp=it;
        temp++;
        if(it->second==0)
        {
            ele.erase(it);
        }
        int b=temp->first;
        ele[min(b-a,k)]++;
        k-=(min(b-a,k));

    }
    vector<int> temp(nums.size(),ele.begin()->first);
    nums=temp;
    if(k>0)
    {
        int j=0;
        while(k>0 && j<nums.size())
        {
            nums[j]=nums[j]+1;
            k--;
            if(j==nums.size()-1)
            {
                j=0;
            }
        }
    }
    int ans=nums[0];
    for(int i=1;i<nums.size();i++){
        ans*=nums[i];
        ans%=mod;
    }
    cout<<ans;
    return ans;

}
int32_t main() {
    vector<int> v{6,3,3,2};
   cout<<maximumProduct(v,2);



}

