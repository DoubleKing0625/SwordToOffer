/*
 * Created by Peng Qixiang on 2018/9/15.
 */

/*
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 *
 */

# include <iostream>

using namespace std;

class Solution {

public:
    /* 判断条件：
     * 空字符串
     * 正负号检查
     *      只能出现一次且在字符串首部 1
     *      后面必须有合法内容 2
     *      'E', 'e' 除外，其后必须加合法内容 1e+ 错误 3
     * 科学计数法检查
     *      'E'，'e'只能出现一次 1
     *      后面不能有'.' 2
     *      后面必须用合法内容 3
     * 小数检查
     *      '.' 只能出现一次
     * 非正常字符
     */
    bool isNumeric(char* string) {
        bool onlyOneE = false; // 只出现一次E
        bool onlyOnePoint = false; //只出现一次.
        //空字符串
        if(string == NULL)
            return false;
        else{
            // 正负号检查 1
            if(*string == '-' || *string == '+'){
                string++;
                //正负项检查 2
                if(*string == '\0')
                    return false;
            }
            while(*string != '\0'){
                if(*string == 'E' || *string == 'e'){
                    // 科学计数法检查 1
                    if(onlyOneE)
                        return false;
                    else
                        onlyOneE = true;
                    //科学技术法检查 3
                    string++;
                    if(*string == '\0')
                        return false;
                    //正负号检查 3, 牛客没有设置此类型错误案例检查
                    if(*string == '+' || *string == '-') {
                        string++;
                        if (*string == '\0')
                            return false;
                    }
                    string--;
                }
                else if(*string == '.'){
                    //小数检查 1，2
                    if(onlyOneE || onlyOnePoint)
                        return false;
                    else
                        onlyOnePoint = true;
                }
                else if(*string < '0' || *string > '9')
                    return false;

                string++;
            }
        }
        return true;
    }

};

int main(){
    Solution s;
    char* test = "+1e+";
//    while(*test != '\0'){
//        cout << *test << endl;
//        test++;
//    }
    cout << s.isNumeric(test) << endl;
    return 0;
}





