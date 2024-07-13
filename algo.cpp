class disjointset{
   vector<int> parent,rank,size;
   public:
   disjointset(int n){
       parent.resize(n+1);
       rank.resize(n+1,0);
       size.resize(n+1,0);
       for(int i=0;i<=n;i++){
           parent[i]=i;
           size[i]=1;
       }
   }   
       
       int findparent(int x){
           if(x==parent[x]){
               return x;
           }
           return parent[x]=findparent(parent[x]);
       }
       void unionsize(int u,int v){
           int pu = findparent(u);
           int pv = findparent(v);
           if(pu==pv) return;
           if(size[pu]<size[pv]){
               parent[pu]=pv;
               size[pv]+=size[pu];
           }
           else if(size[pv]<size[pu]){
               parent[pv]=pu;
               size[pu]+=size[pv];
           }
           else if(size[pu]==size[pv]){
               parent[pu]=pv;
               size[pv]+=size[pu];
           }
           
       }
       void unionrank(int u,int v){
           int pu = findparent(u);
           int pv = findparent(v);
           if(rank[pu]<rank[pv]){
               parent[pu]=pv;
           }
           else if(rank[pv]<rank[pu]){
               parent[pv]=pu;
           }
           else if(rank[pu]==rank[pv]){
               parent[pu]=pv;
               rank[pv]++;
           }
       }
   
};
