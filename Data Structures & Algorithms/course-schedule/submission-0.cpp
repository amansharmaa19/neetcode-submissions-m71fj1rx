class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }

        // Calculate indegree
        for (int i = 0; i < adjList.size(); i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                indegree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        vector<int> topoSort;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (int i = 0; i < adjList[node].size(); i++) {
                int neighbour = adjList[node][i];
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return topoSort.size() == numCourses;
    }
};
