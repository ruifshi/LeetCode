#include "stdafx.h"
#include "EvaluateDivision.h"

double Solution::Helper(string A, string B, unordered_map<string, unordered_map<string, double>> graph, unordered_set<string> visited) {
	if(A == B) {
		return 1.0;
	}
	visited.insert(A);
	for(auto element : graph[A]) {
		string C = element.first;
		if(visited.find(C) != visited.end()) {
			continue;
		}

		double val = Helper(C, B, graph, visited);

		if(val > 0) {
			return val * graph[A][C];
		}
	}

	return -1.0;
}

Node* Solution::findParent(Node* node) {
    if (node -> parent == node)
        return node;
    node -> parent = findParent(node -> parent);
    return node -> parent;
}

void Solution::unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
    Node* parent1 = findParent(node1), *parent2 = findParent(node2);
    double ratio = node2 -> value * num / node1 -> value;
    for (auto it = map.begin(); it != map.end(); it ++)
        if (findParent(it -> second) == parent1)
            it -> second -> value *= ratio;
    parent1 -> parent = parent2;
}

vector<double> Solution::calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	/*
	unordered_map<string, unordered_map<string, double>> graph;

	for(int i = 0; i < equations.size(); i++) {
		string A = equations[i].first;
		string B = equations[i].second;
		double val = values[i];
		graph[A][B] = val;
		graph[B][A] = 1.0/val;
	}

	vector<double> solution;
	for(auto element: queries) {
		string A = element.first;
		string B = element.second;
		if(graph.find(A) == graph.end() || graph.find(B) == graph.end()) {
			solution.push_back(-1.0);
			continue;
		}
		unordered_set<string> visited;
		solution.push_back(Helper(A, B, graph, visited));
	}

	return solution;
	*/

    unordered_map<string, Node*> map;
    vector<double> res;
    for (int i = 0; i < equations.size(); i ++) {
        string s1 = equations[i].first, s2 = equations[i].second;
        if (map.count(s1) == 0 && map.count(s2) == 0) {
            map[s1] = new Node();
            map[s2] = new Node();
            map[s1] -> value = values[i];
            map[s2] -> value = 1;
            map[s1] -> parent = map[s2];
        } else if (map.count(s1) == 0) {
            map[s1] = new Node();
            map[s1] -> value = map[s2] -> value * values[i];
            map[s1] -> parent = map[s2];
        } else if (map.count(s2) == 0) {
            map[s2] = new Node();
            map[s2] -> value = map[s1] -> value / values[i];
            map[s2] -> parent = map[s1];
        } else {
            unionNodes(map[s1], map[s2], values[i], map);
        }
    }

    for (auto query : queries) {
        if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
            res.push_back(-1);
        else
            res.push_back(map[query.first] -> value / map[query.second] -> value);
    }
    return res;
}