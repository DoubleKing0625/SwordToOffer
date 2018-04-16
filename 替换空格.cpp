/*
 * Created by Peng Qixiang on 2018/4/1.
 */

/*
 * 替换空格
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 *
 */

# include <iostream>

using namespace std;

/*
 * 在字符串尾部填充任意字符，使得字符串的长度等于字符串替换之后的长度。
 * 因为一个空格要替换成三个字符（%20），因此当遍历到一个空格时，需要在尾部填充两个任意字符。
 * 令 P1 指向字符串原来的末尾位置，P2 指向字符串现在的末尾位置。
 * P1 和 P2 从后向前遍历，当 P1 遍历到一个空格时，就需要令 P2 指向的位置依次填充 02%（注意是逆序的，
 * 否则就填充上 P1 指向字符的值。
 * 从后向前遍是为了在改变 P2 所指向的内容时，不会影响到 P1 遍历原来字符串的内容。
 * O(n)
 */

void replaceSpace(char *str,int length) {
    int p1 = 0, p2 = length;
    // 填充字符
    while(p1 < length){
        if(str[p1] == ' '){
            str[p2++] = '1';
            str[p2++] = '1';
        }
        p1++;
    }
    // 追加终止符
    str[p2] = '\0';
    // 从后向前遍历
    p1--;
    p2--;
    while(p1 >= 0){
        if(str[p1] == ' '){
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }
        else{
            str[p2--] = str[p1];
        }
        p1--;
    }
}


int main(){
    char str[] = "we are happy";
    replaceSpace(str, 12);
    cout << str << endl;
    return 0;
}





