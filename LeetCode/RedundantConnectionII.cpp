#include "stdafx.h"
#include "RedundantConnectionII.h"

vector<int> Solution::findRedundantDirectedConnection(vector<vector<int>>& edges) {
	/*
    vector<vector<int>> parent(edges.size(), vector<int>());
	vector<vector<int>> path(edges.size(), vector<int>());
    vector<bool> visited(edges.size(), pathlse);
    vector<int> cycle(2, -1);

    int id_two_parents = -1;
    for (auto &e : edges) {
        if (visited[e[0]-1] && visited[e[1]-1]) {
			cycle[0] = e[0];
			cycle[1] = e[1];
		}
        visited[e[0]-1] = true;
        visited[e[1]-1] = true;
        parent[e[1]-1].push_back(e[0]);
		path[e[0]-1].push_back(e[1]);
        if (parent[e[1]-1].size() > 1) {
            id_two_parents = e[1];
		}
    }
    //
    if (id_two_parents < 0) {
        // no node has two parents, means a single cycle, any node in this cycle can be root
        // so return the last cycle edge
        return cycle;
    } else {
        // one node has two parents, must remove one edge from there.
        // we recursively find the parent, 
        // if the last node has no parent, that's the root, we should keep this branch
        // otherwise if this branch is cycle, remove this edge.
        int branch0 = parent[id_two_parents-1][0];
        int branch1 = parent[id_two_parents-1][1];
		int id = branch0;
		vector<int> ans;

		int travel = 0;
        while (parent[id-1].size() != 0 && parent[id-1][0] != id_two_parents) {
            // find the root or the cycle
            id = parent[id-1][0];
			travel++;
        }

        //while (parent[id].size() != 0 && parent[id] != id_two_parents) {
            // find the root or the cycle
        //    id = parent[id];
        //}
        if (id == id_two_parents || travel == 0) {
            // this is the cycle branch, remove this branch
			ans.push_back(branch0);
			ans.push_back(id_two_parents);
            return ans;
        } else {
            // parent[id].size() == 0, the root branch, remove the other branch
			ans.push_back(branch1);
			ans.push_back(id_two_parents);
            return ans;
        }
    }
	*/

    int u, v;
    bool hasCycle = false;
    vector<int> dup_node;  //{child, dup pathther}
    vector<int> ringEdge;
    for(const auto &e: edges){
        u = e[0]; v = e[1];
        //a node has multiple paththers
        if(path.find(v) != path.end()){
            dup_node.push_back(v);
            dup_node.push_back(u);
        }
        else {
			path[v] = u;
		}
        //at most one cycle in the tree
        if(!hasCycle){
            if(hasCycle = checkCycle(v)){
                ringEdge.push_back(u);
                ringEdge.push_back(v);
            }
        }
    }


    if(dup_node.empty()) {
		return ringEdge;
	}

	vector<int> ans;
    if(checkCycle(dup_node[0])) {
		ans.push_back(path[dup_node[0]]);
		ans.push_back(dup_node[0]);
		return ans;
	}
    else {
		ans.push_back(dup_node[1]);
		ans.push_back(dup_node[0]);
		return ans;
	}
}

bool Solution::checkCycle(int v){
    int node = v;
    while(path.find(v) != path.end()){
        v = path[v];
        if(v == node) {
			return true;
		}
    }
    return false;
}