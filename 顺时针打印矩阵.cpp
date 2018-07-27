/*
 * Created by Peng Qixiang on 2018/7/24.
 */

/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 * 例如 1  2  3  4
 *     5  6  7  8
 *     9  10 11 12
 *     13 14 15 16
 * 依次打出 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10。
 *
 */

# include <iostream>
# include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
    int height = matrix.size(), width = matrix[0].size();
    int start_height = 0, end_height = height;
    int start_width = 0,  end_width = width;
    int index = 0;
    int change_num = 0;
    while(index < height * width){
        // change width
        if(change_num % 2 == 0){
            //positive direction
            if((change_num / 2) % 2 == 0){
                for(int i = start_width; i < end_width; i++){
                    res.push_back(matrix[start_height][i]);
                    index++;
                }
                start_height++;
            }
            else{
                for(int i = end_width - 1; i >= start_width; i--){
                    res.push_back(matrix[end_height-1][i]);
                    index++;
                }
                end_height--;
            }
        }
        // change height
        else{
            // positive direction
            if(((change_num - 1)  / 2) % 2 == 0){
                for(int i = start_height; i < end_height; i++){
                    res.push_back(matrix[i][end_width-1]);
                    index++;
                }
                end_width--;
            }
            else{
                for(int i = end_height - 1; i >= start_height; i--){
                    res.push_back(matrix[i][start_width]);
                    index++;
                }
                start_width++;
            }
        }
        change_num++;
    }
    return res;
}


int main(){
    vector< vector<int> > test(2, vector<int>(2, 0));

    test[0] = {1, 2};
    test[1] = {3, 4};

    int height = test.size();
    int width = test[0].size();

    vector<int> res = printMatrix(test);
    for(int i = 0; i < height * width; i++){
        cout << res[i] << endl;
    }
    return 0;
}
