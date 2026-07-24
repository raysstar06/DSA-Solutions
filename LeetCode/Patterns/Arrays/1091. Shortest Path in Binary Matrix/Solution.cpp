class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&adj) {
        int sr=0,sc=0;
        int n=adj.size();
        int dr=n-1,dc=n-1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        if(adj[sr][sc]==1 or adj[dr][dc]==1)return -1;
        dist[sr][sc]=0;
        q.push({0,{sr,sc}});
        int ans=-1;
        while(!q.empty()){
            int d=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==dr && col==dc){
                return d+1;
            }
            int arr1[]={-1,-1,-1, 0, 0, 1, 1, 1};
            int arr2[]={-1, 0, 1,-1, 1,-1, 0, 1};
            for(int i=0;i<8;i++){
                int nr=row+arr1[i];
                int nc=col+arr2[i];
                int ndis=d+1;
                if(nr<0 or nc<0 or nr>=n or nc>=n)continue;
                if(ndis<dist[nr][nc] && adj[nr][nc]==0){
                    dist[nr][nc]=ndis;
                    q.push({ndis,{nr,nc}});
                }
            }
        }
        return ans;
        }
};