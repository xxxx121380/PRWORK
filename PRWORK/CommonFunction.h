#pragma once
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <wchar.h>
#include <windows.h>
#include <tchar.h>
#include <math.h>
/*
50全部：0~33
51武器：0~16
52近战武器0~5：斧 剑 锤 长矛 爪 匕首
53远程武器6~11：弓 十字弓 标枪 投掷武器 游侠弓 游侠标枪
54元素武器12~16：法杖 法珠 手杖 祭祀刀 权杖
55头盔17~21：帽子 头饰 战士头盔 萨满头盔 贤者头盔
56盾牌22~25：盾 骑士盾牌 牧师副手 死灵副手
57防具17~29：头盔 盾牌 衣服 手套 靴子 腰带
58饰品30~32：项链 戒指 护符
珠宝33
*/

using namespace std;
string string2UTF8(const std::string& str);
wstring string2wstring(string str);
class cizhui
{
private:
    string description;//词缀介绍
    string name;//词缀属性名
    int level;//词缀等级
    bool iffloat = false, sign = false;//是否浮动，是否小数
    double float1min, float2min, float1max, float2max;//最小最大浮动值
    int type[34] = { 0 };//可属类型
    char color;//词缀颜色
    int typenum;//词缀类别码
public:
    /*
    void setdescription(string i);
    void setname(string i);
    void setlevel(string i);
    void setsj(string a, string b, string c, string d);
    void settype(string a);
    void setcolor(char a);
    void setsi(bool si);
    int gettype(int i);
    int getlevel();
    string getname();
    string getdescription();
    char getcolor();
    bool getfloat();
    bool getsign();
    float getfloatmin();
    float getfloatmax();
    float getfloatmin2();
    float getfloatmax2();
    */
    void settypenum(int i)
    {
        typenum = i;
    }
    int gettypenum()
    {
        return typenum;
    }
    void setdescription(string i)
    {
        description = i;
    }

    void setname(string i)
    {
        name = i;
    }

    void setlevel(string i)
    {
        level = atoi(i.c_str());
    }

    void setsj(string a, string b, string c, string d)
    {
        double aa, bb, cc, dd;
        aa = atof(a.c_str());
        bb = atof(b.c_str());
        cc = atof(c.c_str());
        dd = atof(d.c_str());
        if (cc != dd || aa != bb)iffloat = true;

        float1min = aa;
        float1max = bb;
        float2min = cc;
        float2max = dd;
    }

    void settype(string a)
    {
        int aa = atoi(a.c_str());
        if (aa >= 0 && aa <= 33)
            type[aa] = 1;
        switch (aa)
        {
        case 50:
            for (int i = 0; i <= 33; i++)
            {
                type[i] = 1;
            }
            break;
        case 51:
            for (int i = 0; i <= 16; i++)
            {
                type[i] = 1;
            }
            break;
        case 52:
            for (int i = 0; i <= 5; i++)
            {
                type[i] = 1;
            }
            break;
        case 53:
            for (int i = 6; i <= 11; i++)
            {
                type[i] = 1;
            }
            break;
        case 54:
            for (int i = 12; i <= 16; i++)
            {
                type[i] = 1;
            }
            break;
        case 55:
            for (int i = 17; i <= 21; i++)
            {
                type[i] = 1;
            }
            break;
        case 56:
            for (int i = 22; i <= 25; i++)
            {
                type[i] = 1;
            }
            break;
        case 57:
            for (int i = 17; i <= 29; i++)
            {
                type[i] = 1;
            }
            break;
        case 58:
            for (int i = 30; i <= 32; i++)
            {
                type[i] = 1;
            }
            break;
        default:
            break;
        }
    }

    void setcolor(char a)
    {
        color = a;
    }

    void setsi(bool si)
    {
        sign = si;
    }

    int gettype(int i)
    {
        return type[i];
    }

    int getlevel()
    {
        return level;
    }

    string getname()
    {
        return name;
    }

    string getdescription()
    {
        return description;
    }

    char getcolor()
    {
        return color;
    }

    bool getfloat()
    {
        return iffloat;
    }

    bool getsign()
    {
        return sign;
    }

    double getfloatmin()
    {
        return float1min;
    }
    double getfloatmax()
    {
        return float1max;
    }
    double getfloatmin2()
    {
        return float2min;
    }
    double getfloatmax2()
    {
        return float2max;
    }
};


string string2UTF8(const std::string& str)
{
    int nwLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

    wchar_t* pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴
    ZeroMemory(pwBuf, nwLen * 2 + 2);

    ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

    int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

    char* pBuf = new char[nLen + 1];
    ZeroMemory(pBuf, nLen + 1);

    ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

    std::string retStr(pBuf);

    delete[]pwBuf;
    delete[]pBuf;

    pwBuf = NULL;
    pBuf = NULL;

    return retStr;
}


wstring string2wstring(string str)
{
    wstring result;
    //获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
    TCHAR* buffer = new TCHAR[len + 1];
    //多字节编码转换成宽字节编码  
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';             //添加字符串结尾  
    //删除缓冲区并返回值  
    result.append(buffer);
    delete[] buffer;
    return result;
}