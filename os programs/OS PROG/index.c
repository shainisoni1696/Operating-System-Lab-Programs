#include<bits/stdc++.h>
int main()
{
 
  int n;
     cout<<"enter the no of files"<<endl;
      cin>>n;
         int b[n];
        map<int,string>m(n);
         vector<vector<int>> v(n);
         for(int i=0;i<n;i++)
          {
             cout<<"Enter the name of file :";
             string s;
             cin>>s;
             m[i]=s;
             cout<<"Enter the no. of blocks :";
             cin>>b[i];
              cout<<"Enter the blocks :";
             for(int j=0;j<blocks;j++)
              {
                  int x;
                  cin>>x;
                  v[i].push_back(x);
              }
           }

  cout<<"Enter the file to be searched\n";
    string str;
     cin>>str;
     
   for(int i=0;i<n;i++)
     {
          if(m[i]==str)
              {
                   cout<<"Fname\tNo of blocks\tBlocks occupied\n";
                   cout<<str<<"\t"<<b[i]<<"\t";
                    int size=v[i].size();
                    for(int j=0;j<size;j++)
                      cout<<v[i][j]<<" ";
                      break;
                 }
     }
return 0;
}

                   
