//
// Created by ZhiWei Tan on 12/26/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;
const int LEVEL_SPACE = 2;

class Solution {
public:
    int GetLevel(const string strLine)

    {
        auto pos = strLine.find_first_not_of(' ');
        return pos / LEVEL_SPACE;
    }

    /**
     * 对每个文件生成绝对路径
     * @param fileName
     * @param level
     * @param path
     * @return
     */
    string GetAbsolutePath(const string& fileName, int level, stack<string>& path)
    {
        while (level < path.size()) {
            path.pop();
        }

        path.push(fileName);
        stack<string> tmpPath = path;
        string strPath = tmpPath.top();
        tmpPath.pop();
        while (!tmpPath.empty()) {
            strPath = tmpPath.top() + "/" + strPath;
            tmpPath.pop();
        }

        return strPath;

    }

    vector<string> Trans2AbsolutePath(const vector<string>& src)
    {
        stack<string> path;
        vector<string> AbsolutePaths;
        int size = src.size();
        for (int i = 0; i < size; ++i) {
            auto pos = src[i].find_first_not_of(' ');
            int level = pos / LEVEL_SPACE;
            string fileName = src[i].substr(pos);
            string abPath = GetAbsolutePath(fileName, level, path);
            AbsolutePaths.push_back(abPath);
        }

        return AbsolutePaths;
    }

    /**
     * 将文件拷贝到指定目录
     * @param dstPath
     * @param dstPaths
     * @param src
     */
    void Copy2AbsolutePath(string dstPath, vector<string> &dstPaths, const vector<string>& src)
    {
        stack<string> path;
        int size = src.size();
        for (int i = 1; i < size; i++) {
            string res = dstPath;
            auto pos = src[i].find_first_not_of(' ');
            int level = pos / LEVEL_SPACE - 1;
            string fileName = src[i].substr(pos);
            string abPath = GetAbsolutePath(fileName, level, path);
            res.append("/");
            res.append(abPath);
            dstPaths.push_back(res);
        }
    }

    vector<string> CopyDir(const vector<string>& targetDir, int dstDirLine, const vector<string>& srcDir)
    {
        vector<string> result;
        vector<string> TargetAbsDir = Trans2AbsolutePath(targetDir);
        string dstPath = TargetAbsDir[dstDirLine - 1];
        Copy2AbsolutePath(dstPath, TargetAbsDir, srcDir);
        set<string> TargetAbsDirSet(TargetAbsDir.begin(), TargetAbsDir.end());
        for (auto path : TargetAbsDirSet) {
            int level = count(path.begin(), path.end(), '/');
            int pos = path.find_last_of('/');
            string fileName = path.substr(pos + 1);
            string space = "";
            while (level) {
                space.append("  ");
                level--;
            }

            space.append(fileName);
            result.push_back(space);
        }

        return result;
    }
};

inline int ReadInt()
{
    int number;
    cin >> number;
    return number;
}

inline string ReadLine()
{
    string line;
    getline(cin, line);
    return line;
}

inline vector<string> ReadLines(int size)
{
    vector<string> lines(size);
    for (int i = 0; i < size; ++i) {
        lines[i] = ReadLine();
    }
    return lines;
}

template<typename T>
inline void WriteVector(const std::vector<T>& objects, char delimeter = ' ')
{
    auto it = objects.begin();
    if (it == objects.end()) {
        return;
    }

    std::cout << *it;
    for (++it; it != objects.end(); ++it) {
        std::cout << delimeter << *it;
    }
}

int main()
{
    int targetDirNum;
    int dstDirLine;
    cin >> targetDirNum >> dstDirLine;
    cin.ignore();
    vector<string> targetDirStrs = ReadLines(targetDirNum);
    int srcDirNum = ReadInt();
    cin.ignore();
    vector<string> srcDirStrs = ReadLines(srcDirNum);
    Solution solu;
    vector<string> result = solu.CopyDir(targetDirStrs, dstDirLine, srcDirStrs);
    WriteVector(result, '\n');
    return 0;
}

