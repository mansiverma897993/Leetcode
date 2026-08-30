class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string x;

        for(int i=0;i<=path.size();i++){
            if(i==path.size() || path[i]=='/'){
                if(x==".."){
                    if(!s.empty()) s.pop_back();
                }else if(!x.empty() && x!=".")
                    s.push_back(x);
                x="";
            }else x+=path[i];
        }

        string ans;
        for(auto &x:s) ans+="/"+x;
        return ans.empty()?"/":ans;
    }
};