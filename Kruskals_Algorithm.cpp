#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b){
	return a[2] < b[2];
}
void makeSet(vector<int>&parent,int n,vector<int>&rank){
	for(int i=0;i<n;i++){
		parent[i]=i;
		rank[i]=0;
	}
}
int findParent(vector<int>&parent,int node){
	if(parent[node]==node){
		return node;
	}
	return parent[node]=findParent(parent, parent[node]);
}
void makeUnion(int u, int v, vector<int>&parent,vector<int>&rank){
	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[v]<rank[u]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}

}
int kruskalMST(int n, vector<vector<int>> &edges)
{
	sort(edges.begin(),edges.end(),cmp);

	vector<int>parent(n);
	vector<int>rank(n);
	makeSet(parent,n,rank);

	int minWeight=0;
	for(int i=0;i<edges.size();i++){
		int u = findParent(parent, edges[i][0]);
		int v = findParent(parent, edges[i][1]);

		if(u!=v){
			minWeight += edges[i][2];
			makeUnion(u,v,parent,rank);
		}
	}
	return minWeight;



}


int main(){
    int n = 5; // Number of nodes in the graph
    vector<vector<int>> edges = {
        {0, 1, 2}, 
        {0, 3, 6}, 
        {1, 2, 3}, 
        {1, 3, 8}, 
        {1, 4, 5}, 
        {2, 4, 7}
    }; // Format {node1, node2, weight}

    int minWeight = kruskalMST(n, edges);
    cout << "The weight of the minimum spanning tree is: " << minWeight << endl;

    return 0;
}