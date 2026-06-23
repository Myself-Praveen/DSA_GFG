vector<int> v;
class Solution {
    void preprocess() {
        if(!v.empty()) {
            return;
        }
        v.reserve(1000);
        for(int i = 1, sum = 0; sum <= 3e8 ; i++) {
            sum += i * i;
            v.push_back(sum);
        }
    }
public:
    int maxPeopleDefeated(int p) {
        // Code Here
        preprocess();
        return upper_bound(v.begin(), v.end(), p) - v.begin();
    }
};