/*
 * Created by Peng Qixiang on 2018/4/16.
 */

/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个!!!!!!非递减排序!!!!!!的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 也有可能出现[1,0,1,1,1]
 */


# include <iostream>
# include <vector>

using namespace std;
//顺序查找
int FindMin(vector<int> rotateArray, int low, int high){
    int res = rotateArray[low];
    for(int i = low + 1; i <= high; i++){
        if(rotateArray[i] < res){
            res = rotateArray[i];
        }
    }
    return res;
}

int minNumberInRotateArray(vector<int> rotateArray){
    int size = rotateArray.size();
    // 出错处理
    if(size == 0){
        return 0;
    }
    int low = 0;
    int high = size - 1;
    int mid;
    while(rotateArray[low] >= rotateArray[high]){//不能用low < high 判断
        if(high - low == 1){
            mid = high;
            break;
        }
        mid = (low + high) / 2;
        // 有相等元素
        if (rotateArray[mid] == rotateArray[low] && rotateArray[mid] == rotateArray[high]){
            return FindMin(rotateArray, low, high);
        }
        else if(rotateArray[mid] >= rotateArray[low]) {// mid in part1 非递减 >= !!!
            low = mid;
            continue;
        }
        else{
            high = mid;
            continue;
        }
    }
    return rotateArray[mid];
}


int main(){
    vector<int> a = vector<int>(8,0);
    a[0] = 7;
    a[1] = 8;
    a[2] = 1;
    a[3] = 2;
    a[4] = 3;
    a[5] = 4;
    a[6] = 5;
    a[7] = 6;
    cout << minNumberInRotateArray(a) << endl;
    return 0;
}





