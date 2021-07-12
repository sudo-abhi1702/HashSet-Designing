#include<bits/stdc++.h>
using namespace std;

struct bucket   //slower bucket
{
   vector<int>v;
   void add(int x)
   {
       if(std::find(v.begin(),v.end(),x)==v.end())
       {
           v.push_back(x);
       }
   }
   void remove(int x)
   {
       if(std::find(v.begin(),v.end(),x)==v.end())
       return;
       v.erase(std::find(v.begin(),v.end(),x));
   }
   bool find(int x)
   {
        if(std::find(v.begin(),v.end(),x)==v.end())
        return 0;
        else return 1;
   }
};
class hashSet   //slower hashSet
{

    int no_of_buckets;
    bucket* container;

    int hash_function(int x)
    {
        return x%no_of_buckets;
    }

    public:
    hashSet(int buckets_required)
    {
        no_of_buckets=buckets_required;
        container=new bucket[buckets_required];
    }
    void insert(int x)
    {
        int b_no=hash_function(x);
        container[b_no].add(x);
    }
    void remove(int x)
    {
        int b_no=hash_function(x);
        container[b_no].remove(x);
    }
    bool find(int x)
    {
        int b_no=hash_function(x);
        return container[b_no].find(x);
    }
};



//////////Faster HashSet starts from here/////
struct fastBucket    
{
   set<int>v;
   void add(int x)
   {
       v.insert(x);
   }
   void remove(int x)
   {
       v.erase(x);
   }
   bool find(int x)
   {
        if(v.find(x)==v.end())
        return 0;
        else return 1;
   }
};


class fastHashSet
{

    int no_of_buckets;
    fastBucket* container;

    int hash_function(int x)
    {
        return x%no_of_buckets;
    }

    public:
    fastHashSet(int buckets_required)
    {
        no_of_buckets=buckets_required;
        container=new fastBucket[buckets_required];
    }
    void insert(int x)
    {
        int b_no=hash_function(x);
        container[b_no].add(x);
    }
    void remove(int x)
    {
        int b_no=hash_function(x);
        container[b_no].remove(x);
    }
    bool find(int x)
    {
        int b_no=hash_function(x);
        return container[b_no].find(x);
    }
};

int main()
{
    fastHashSet hs(10);
    hs.insert(12);
    hs.insert(5);
    hs.insert(3);
    hs.remove(5);
    
   

    cout <<hs.find(13);
}
