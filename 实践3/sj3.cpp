
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <sstream>

using namespace std;

//将字符串转换成大整数
//列表首位放置整数最后一位(个位)
vector<int> string_to_vector(const string& str) 
{
	 vector<int> vec;
	 for(int i = str.size()-1; i >= 0; i--)
     {
        vec.push_back(str[i]-'0');
     }
	 return vec;
}

//将大整数转换成字符串
string vector_to_string(const std::vector<int>& num)
{
	string s="";
	for(int i = num.size()-1; i >= 0; i--)
    {
        s += to_string(num[i]);
    }
	return s;
} 

//如果a>b，返回1，如果a<b，返回-1，否则返回0。
int compare(const std::vector<int>& a, const std::vector<int>& b)
{/*1. 使用 std::vector<int> 来存储大整数，vector中每个元素存储大整数的一个数位。比如整数12345存储为{5,4,3,2,1}。注意，为了后续计算方便，这里低位在前，高位在后。*/
	auto a_size = a.size();
    auto b_size = b.size();
    if(a_size > b_size)
    {
        return 1;
    }
    else if(a_size < b_size)
    {
        return -1;
    }
    else
    {
        for(int i = a_size-1; i >= 0; i--)
        {
            if(a[i] > b[i])
            {
                return 1;
            }
            else if(a[i] < b[i])
            {
                return -1;
            }
        }
        return 0;
    }
}

vector<int> add(const std::vector<int>& a, const std::vector<int>& b)
{
    if(a.empty())
    {
        return b;
    }
    if(b.empty())
    {
        return a;
    }
	int jin_wei = 0;
    int ben_wei = 0;
    auto min_absize = min(a.size(), b.size());
    const vector<int> *max_vec = (a.size() > b.size())?&a:&b;
    vector<int> res_vec;
    for(auto i = 0; i < min_absize; i++)
    {
        ben_wei = a[i] + b[i] + jin_wei;
        if(ben_wei >= 10)
        {
            ben_wei -= 10;
            jin_wei = 1;
        }
        else
        {
            jin_wei = 0;
        }
        res_vec.push_back(ben_wei);
    }
    
    for(auto i = min_absize; i < max(a.size(), b.size()); i++)
    {
        ben_wei = (*max_vec)[i] + jin_wei;
        if(ben_wei >= 10)
        {
            ben_wei -= 10;
            jin_wei = 1;
        }
        else
        {
            jin_wei = 0;
        }
        res_vec.push_back(ben_wei);
    }
    if(jin_wei == 1)
    {
        res_vec.push_back(1);
    }
    return res_vec;
}

//假设a大于等于b
vector<int> subtract(const std::vector<int>& a, const std::vector<int>& b)
{
	vector<int> vec_res;
    if(compare(a,b) == -1)
    {
        return subtract(b,a);
    }
    int dang_wei = 0;
    int tui_wei = 0;
    for(auto i = 0; i < min(a.size(), b.size()); i++)
    {
        dang_wei = a[i] - b[i] - tui_wei;
        if(dang_wei < 0)
        {
            dang_wei += 10;
            tui_wei = 1;
        }
        else
        {
            tui_wei = 0;
        }
        vec_res.push_back(dang_wei);
    }
    for(auto i = min(a.size(),b.size()); i < max(a.size(),b.size()); i++)
    {
        dang_wei = a[i]  - tui_wei;
        if(dang_wei < 0)
        {
            dang_wei += 10;
            tui_wei = 1;
        }
        else
        {
            tui_wei = 0;
        }
        vec_res.push_back(dang_wei);
    }
    while(vec_res.size() > 1 && vec_res.back() == 0)
    {
        vec_res.pop_back();
    }
    return vec_res;
}
vector<int> multiply_orl(const std::vector<int>& a, const std::vector<int>& b){
	//以下为竖式实现;
    auto a_size = a.size();
    auto b_size = b.size();
    vector<int> vec_res(a_size+b_size+1,0);
    for(auto i = 0; i < a_size; i++){
        int jin_wei = 0;
        for(auto j = 0; j < b_size; j++){
            int ben_wei = a[i]*b[j] + vec_res[i+j] + jin_wei;
            jin_wei = ben_wei/10;
            vec_res[i + j] = ben_wei % 10;
        }
        if(jin_wei > 0){
            vec_res[i + b_size] += jin_wei;
        }
    }
    while(vec_res.size() > 1 && vec_res.back() == 0){
        vec_res.pop_back();
    }
    return vec_res;}
vector<int> multiply(const std::vector<int>& a, const std::vector<int>& b)
{
    //以下为kalasuba算法
    auto a_size = a.size();
    auto b_size = b.size();
    if(a_size <= 4 || b_size <= 4)
    {
        return multiply_orl(a,b);
    }
    else
    {
        int k = min(a_size, b_size)/2;
        if(k<2){k = 2;}
        //初始化a = a_0 + a_1*10^k;
        vector<int> a_0(k);
        vector<int> a_1(a_size - k);
        for(int i = 0; i < a_size; i++)
        {
            if(i < k)
            {
                a_0[i] = a[i];
            }
            else
            {
                a_1[i-k] = a[i];
            }
        }
        vector<int> b_0(k);
        vector<int> b_1(b_size - k);
        for(int i = 0; i < b_size; i++)
        {
            if(i < k)
            {
                b_0[i] = b[i];
            }
            else
            {
                b_1[i-k] = b[i];
            }
        }

        //计算中间变量;
        vector<int> w_0 = multiply(a_0 , b_0);
        vector<int> w_2 = multiply(a_1 , b_1);
        vector<int> w_1 = multiply(add(a_1, b_0),add(a_0,b_1));
        w_1 = subtract(subtract(w_1, w_2),w_0);

        w_2.insert(w_2.begin(), k*2,0);
        w_1.insert(w_1.begin(), k, 0);

        return add(w_2,add(w_1,w_0));
    }
    
}
int main()
{
    std::string str1, str2;
    std::cout << "输入第一个大整数: ";
    std::cin >> str1;
    std::cout << "输入第二个大整数: ";
    std::cin >> str2;

    std::vector<int> a = string_to_vector(str1);
    std::vector<int> b = string_to_vector(str2);

    int r = compare(a, b);
    if (r < 0) std::cout << str1 << " < " << str2 << std::endl;
    else if (r == 0) std::cout << str1 << " == " << str2 << std::endl;
    else if (r > 0) std::cout << str1 << " > " << str2 << std::endl;

    std::vector<int> result = add(a, b);
    std::cout << "相加结果: " << vector_to_string(result) << std::endl;

    result = subtract(a, b);
    std::cout << "相减结果: " << vector_to_string(result) << std::endl;

    result = multiply_orl(a, b);
    std::cout << "相乘结果: " << vector_to_string(result) << std::endl;

    return 0;
}
