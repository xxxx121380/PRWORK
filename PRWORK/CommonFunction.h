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
50ȫ����0~33
51������0~16
52��ս����0~5���� �� �� ��ì צ ذ��
53Զ������6~11���� ʮ�ֹ� ��ǹ Ͷ������ ������ ������ǹ
54Ԫ������12~16������ ���� ���� ���뵶 Ȩ��
55ͷ��17~21��ñ�� ͷ�� սʿͷ�� ����ͷ�� ����ͷ��
56����22~25���� ��ʿ���� ��ʦ���� ���鸱��
57����17~29��ͷ�� ���� �·� ���� ѥ�� ����
58��Ʒ30~32������ ��ָ ����
�鱦33
*/

using namespace std;
string string2UTF8(const std::string& str);
wstring string2wstring(string str);
class cizhui
{
private:
    string description;//��׺����
    string name;//��׺������
    int level;//��׺�ȼ�
    bool iffloat = false, sign = false;//�Ƿ񸡶����Ƿ�С��
    double float1min, float2min, float1max, float2max;//��С��󸡶�ֵ
    int type[34] = { 0 };//��������
    char color;//��׺��ɫ
    int typenum;//��׺�����
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

    wchar_t* pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β��
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
    //��ȡ��������С��������ռ䣬��������С���ַ�����  
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
    TCHAR* buffer = new TCHAR[len + 1];
    //���ֽڱ���ת���ɿ��ֽڱ���  
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';             //����ַ�����β  
    //ɾ��������������ֵ  
    result.append(buffer);
    delete[] buffer;
    return result;
}