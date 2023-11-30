#include <bits/stdc++.h>
using namespace std;

struct node
{
    long data;
    node *store[26];
};

node *create()
{
    node *temp=new node();
   temp->data=0;
    long i;
    for(i=0; i<26; i++)
    {
        temp->store[i]=NULL;
    }
    return temp;
}
template <typename node>
struct trie
{
    node *temp=new node();
    void insert(string s)
    {
        node* root=temp;
        long i;
        for(i=0; i<s.size(); i++)
        {
            root->data++;

            if(root->store[s[i]-'a']==NULL)
            {
            root->store[s[i]-'a']=create();
            }
            root=root->store[s[i]-'a'];
        }
        root->data++;
    }
       bool search(string s)
    {
     node* root=temp;
        long i;
        for(i=0; i<s.size(); i++)
        {
            
            if(root->store[s[i]-'a']==NULL || root->store[s[i]-'a']->data==0)
            {
            return false;
            }
            
            root=root->store[s[i]-'a'];
        }
        
        
        return true;
    }
    void erase(string s)
    {
          node* root=temp;
        long i;
        //optional to check if search(s) is true or false
        for(i=0; i<s.size(); i++)
        {
            root->data--;
            root->store[s[i]-'a'];
        }
        root->data--;
    }
};


int main()
{
    trie <node> tr;
    tr.insert("hello");
    tr.insert("apple");
    cout<<tr.search("help");
    cout<<tr.search("app");
}
