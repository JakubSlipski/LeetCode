#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        std::vector<std::string> letterLogs, digitLogs;
        
       
        for (const std::string& log : logs) {
            int idx = log.find(' ');
            if (std::isalpha(log[idx + 1])) {
                letterLogs.push_back(log);
            } else {
                digitLogs.push_back(log);
            }
        }
        
       
        std::sort(letterLogs.begin(), letterLogs.end(), [](const std::string& log1, const std::string& log2) {
            int idx1 = log1.find(' ');
            int idx2 = log2.find(' ');
            std::string content1 = log1.substr(idx1 + 1);
            std::string content2 = log2.substr(idx2 + 1);
            std::string identifier1 = log1.substr(0, idx1);
            std::string identifier2 = log2.substr(0, idx2);
            
            if (content1 == content2) {
                return identifier1 < identifier2;
            }
            return content1 < content2;
        });
        
        
        std::vector<std::string> result;
        for (const std::string& log : letterLogs) {
            result.push_back(log);
        }
        for (const std::string& log : digitLogs) {
            result.push_back(log);
        }
        
        return result;
    }
};
