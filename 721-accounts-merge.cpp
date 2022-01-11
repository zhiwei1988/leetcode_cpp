//
// Created by zhiwei on 1/11/2022.
//

#include "playgroud.h"

class DSU {
public:
    DSU(int num)
    {
        for (int i = 0; i < num; i++) {
            parent.push_back(i);
        }
    }

    int Find(int x)
    {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y)
    {
        parent[Find(x)] = Find(y);
    }

private:
    vector<int> parent;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> email2Name;
        map<string, int> email2Id;
        int id = 0;
        DSU dsu(30000);
        for (int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                email2Name[email] = name;
                if (email2Id.count(email) == 0) {
                    email2Id[email] = id++;
                }

                // 同一个 email 可能出现在不同的 account
                // 如果不同 account 中出现了同一个 email，则这些 account 属于同一个人

                // 同一个 account 中的 email 可能属于同一个人
                // 将这些 email 放在同一个集合中
                dsu.Union(email2Id[accounts[i][1]], email2Id[email]);
            }
        }

        map<int, vector<string>> persons;
        for (auto iter = email2Id.begin(); iter != email2Id.end(); iter++) {
            int id = dsu.Find(iter->second);
            if (persons.count(id) == 0) {
                persons[id].push_back(email2Name[iter->first]);
            }

            persons[id].push_back(iter->first);
        }

        vector<vector<string>> result;
        for (auto iter = persons.begin(); iter != persons.end(); iter++) {
            result.push_back(iter->second);
        }

        return result;
    }
};

int main()
{
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, 
                                       {"John", "johnnybravo@mail.com"}, 
                                       {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
                                       {"Mary", "mary@mail.com"}};
    auto ret = Solution().accountsMerge(accounts);
    return 0;
}

