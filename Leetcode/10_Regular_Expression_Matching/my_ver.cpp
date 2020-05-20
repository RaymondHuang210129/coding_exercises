class Solution {
public:
    
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
    
    bool isMatch(string& s, string& p, int sindex, int pindex) {
        string spart = s.substr(sindex);
        string ppart = p.substr(pindex);
        if (spart.length() == 0 && ppart.length() == 0) return true;
        if (spart.length() != 0 && ppart.length() == 0) return false;
        if (spart.length() == 0 && ppart.length() != 0) {
            if (ppart.length() == 1) {
                return false;
            } else if (ppart.length() == 2 && ppart[1] == '*') {
                return true;
            }
        }
        if (ppart[0] == '.') {
            if (ppart.length() >= 2 && ppart[1] == '*') { // .* means any numbers of characters
                for (int i = 0;i <= s.length() - sindex; i++) {
                    if (isMatch(s, p, sindex + i, pindex + 2) == true) return true;
                }
                return false;
            } else { // . means an arbitrary character
                if (spart.length() == 0) return false;
                return isMatch(s, p, sindex + 1, pindex + 1);
            }
        } else {
            if (ppart.length() >= 2 && ppart[1] == '*') { // a* means any number of 'a's 
                for (int i = 0; i <= s.length() - sindex; i++) {
                    if (i >= 1 && spart[i - 1] != ppart[0]) break; 
                    if (isMatch(s, p, sindex + i, pindex + 2)) return true;
                }
                return false;
            } else { // a means an character 'a'
                if (ppart[0] == spart[0]) {
                    return isMatch(s, p, sindex + 1, pindex + 1);
                } else return false;
            }
        }
    }
};