class Solution {
    vector<int> topoSortUtil(vector<vector<int>>& adjList, vector<int>& present) {
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                indegree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && present[i] == 1) {
                q.push(i);
            }
        }

        vector<int> topoSort;
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
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i] == 1) {
                count++;
            }
        }
        if (topoSort.size() == count) {
            return topoSort;
        }
        return {};
    }
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 0) {
            return "";
        }
        vector<int> present(26, 0);
        for (int i = 0; i < words.size(); i++) {
            string eachWord = words[i];
            for (int j = 0; j < eachWord.size(); j++) {
                present[eachWord[j] - 'a'] = 1;
            }
        }
        vector<vector<int>> adjList(26);
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            if (s1.length() > s2.length() && s1.substr(0, len) == s2) {
                return "";
            }
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> topoSort = topoSortUtil(adjList, present);
        string dictionary = "";
        for (int i = 0; i < topoSort.size(); i++) {
            dictionary += topoSort[i] + 'a';
        }
        return dictionary;
    }
};
  