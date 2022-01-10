//
// Created by zhiwei on 1/10/2022.
//

#include "playgroud.h"

struct File {
    File(bool _isFile, string _fileName, string _content)
    {
        isFile = _isFile;
        fileName = _fileName;
        content = _content;
    }
    bool isFile;
    string content;
    string fileName;
    map<string, File*> subFiles;
};

class FileSystem {
public:
    FileSystem() {
        m_root = new File(false, "", "");
    }

    vector<string> ls(string path) {
        auto pathItems = SplitPath(path);
        File *file = m_root;
        for (int i = 1; i < pathItems.size(); i++) {
            file = file->subFiles[pathItems[i]];
        }

        if (file->isFile) {
            return vector<string>{file->fileName};
        } else {
            vector<string> result;
            for (auto &subFile : file->subFiles) {
                result.push_back(subFile.first);
            }
            return result;
        }
    }

    void mkdir(string path) {
        auto pathItems = SplitPath(path);
        File *file = m_root;
        for (int i = 1; i < pathItems.size(); i++) {
            if (file->subFiles.count(pathItems[i]) == 0) {
                file->subFiles[pathItems[i]] = new File(false, pathItems[i], "");
            }

            file = file->subFiles[pathItems[i]];
        }
    }

    void addContentToFile(string filePath, string content) {
        auto pathItems = SplitPath(filePath);
        File *file = m_root;
        for (int i = 1; i < pathItems.size(); i++) {
            if (file->subFiles.count(pathItems[i]) == 0) {
                file->subFiles[pathItems[i]] = new File(false, pathItems[i], "");
            }

            file = file->subFiles[pathItems[i]];
        }

        file->isFile = true;
        file->content += content;
    }

    string readContentFromFile(string filePath) {
        auto pathItems = SplitPath(filePath);
        File *file = m_root;
        for (int i = 1; i < pathItems.size(); i++) {
            file = file->subFiles[pathItems[i]];
        }

        return file->content;
    }

private:
    vector<string> SplitPath(string path)
    {
        stringstream ss;
        ss.str(path);
        string item;
        char delim = '/';
        vector<string> result;
        while (getline(ss, item, delim)) {
            result.push_back(item);
        }

        return result;
    }

    File *m_root = nullptr;
};

int main()
{
    string path = "/a/b/c/d";
    auto ret = FileSystem().ls(path);
    return 0;
}

