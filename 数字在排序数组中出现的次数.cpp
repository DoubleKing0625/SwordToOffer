/*
 * Created by Peng Qixiang on 2018/8/9.
 */

/*
 * 数字在排序数组中出现的次数
 * 统计一个数字在排序数组中出现的次数。
 *
 */

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    // binary search
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int firstIndex = biSearchFirst(data, k);
        int lastIndex = biSearchLast(data, k);
        if(firstIndex != -1 && lastIndex != -1) return lastIndex - firstIndex + 1;
        else return 0;

    }

    int biSearchFirst(vector<int> data, int k){
        int start = 0, end = data.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(data[mid] < k) start = mid + 1;
            else if(data[mid] > k) end = mid - 1;
            else if(mid - 1 >= 0 && data[mid - 1] == k) end = mid - 1;
            else return mid;
        }
        return -1;
    }

    int biSearchLast(vector<int> data, int k){
        int start = 0, end = data.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(data[mid] < k) start = mid + 1;
            else if(data[mid] > k) end = mid - 1;
            else if(mid + 1 < data.size() && data[mid + 1] == k) start = mid + 1;
            else return mid;
        }
        return -1;
    }
};

int main(){
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    Solution s = Solution();
    cout << s.GetNumberOfK(test, 2) << endl;
    return 0;
}