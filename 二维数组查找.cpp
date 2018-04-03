/*
 * Created by Peng Qixiang on 2018/3/23.
 */

/*
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *
 */

# include <iostream>
# include <vector>

using namespace std;

// 取右上角数字，每次排除一列或一行

bool Find(int target, vector< vector<int> > array) {

    int length = array.size();
    int width = array[0].size();
    int i = 0, j = width - 1;
    bool res = false;

    while(i < length && j >= 0 ){
        if(array[i][j] == target){
            res = true;
            break;
        }
        else if(array[i][j] < target){
            i++;
            continue;
        }
        else{
            j--;
            continue;
        }
    }

    return res;
}


int main(){
    vector< vector<int> > test(3, vector<int>(2, 0));

    test[0] = {1,2,3,4};
    test[1] = {5,6,7,8};
    test[2] = {9,10,11,12};

    if(Find(18, test)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}





