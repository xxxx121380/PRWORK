#pragma once
#include "CommonFunction.h"
using namespace std;
void outblueCZ(string path);

void outblueCZ(string path)
{
    path.append("\\词缀\\蓝");
    vector<cizhui> hz;//后缀
    vector<cizhui> qz;//前缀
    vector<cizhui> typehz[34];//按类型划分后缀
    vector<cizhui> typeqz[34];//前缀
    int sum, sumhz = 0;
    char colorchar;
    string line;
    ifstream in("blueqz.txt", ios::in);
    //读入原始词缀
    if (!in)
    {
        exit(-1);
    }
    while (!in.eof())
    {
        in >> sum;
        in >> colorchar;
        for (int i = 1; i <= sum; i++)
        {
            in >> line;
            cizhui tmphz;
            tmphz.setcolor(colorchar);

            stringstream ss(line);
            string tmp, a1, a2, a3, a4;
            getline(ss, tmp, ',');
            tmphz.setsi(bool(atoi(tmp.c_str())));
            getline(ss, tmp, ',');
            tmphz.setdescription(tmp);
            getline(ss, tmp, ',');
            tmphz.setlevel(tmp);
            getline(ss, tmp, ',');
            tmphz.setname(tmp);
            getline(ss, a1, ',');
            getline(ss, a2, ',');
            getline(ss, a3, ',');
            getline(ss, a4, ',');
            tmphz.setsj(a1, a2, a3, a4);

            while (getline(ss, tmp, ','))
            {
                tmphz.settype(tmp);
            }
            hz.push_back(tmphz);
        }
    }
    cout << hz.size() << endl;
    in.close();
    ifstream in2("bluehz.txt", ios::in);
    //读入蓝色原始后缀
    if (!in2)
    {
        exit(-1);
    }
    while (!in2.eof())
    {
        in2 >> sum;
        in2 >> colorchar;
        for (int i = 1; i <= sum; i++)
        {
            in2 >> line;
            cizhui tmpqz;
            tmpqz.setcolor(colorchar);
            stringstream ss(line);
            string tmp, a1, a2, a3, a4;
            getline(ss, tmp, ',');
            tmpqz.setsi(bool(atoi(tmp.c_str())));
            getline(ss, tmp, ',');
            tmpqz.setdescription(tmp);
            getline(ss, tmp, ',');
            tmpqz.setlevel(tmp);
            getline(ss, tmp, ',');
            tmpqz.setname(tmp);
            getline(ss, a1, ',');
            getline(ss, a2, ',');
            getline(ss, a3, ',');
            getline(ss, a4, ',');
            tmpqz.setsj(a1, a2, a3, a4);
            while (getline(ss, tmp, ','))
            {
                tmpqz.settype(tmp);
            }
            qz.push_back(tmpqz);
        }
    }
    cout << qz.size() << endl;
    in2.close();
    //按装备类型置入词缀
    for (int i = 0; i < int(hz.size()); i++)
    {
        for (int j = 0; j < 34; j++)
        {
            if (hz[i].gettype(j) == 1)
            {
                typehz[j].push_back(hz[i]);
            }
        }
    }
    for (int i = 0; i < int(qz.size()); i++)
    {
        for (int j = 0; j < 34; j++)
        {
            if (qz[i].gettype(j) == 1)
            {
                typeqz[j].push_back(qz[i]);
            }
        }
    }
    for (int i = 0; i < 34; i++)
    {
        string equiptype = path;
        equiptype.append("\\type\\blue_type_");
        equiptype.append(to_string(i));
        equiptype.append(".txt");
        cout << equiptype << endl;
        ofstream outlevel(equiptype);
        int sumlevelhz = 0;
        int sumlevelqz = 0;
        for (int j = 1; j <= 100; j++)
        {
            vector<cizhui> levelhz;
            vector<cizhui> levelqz;
            for (int k = 0; k < int(typehz[i].size()); k++)
            {
                if (typehz[i][k].getlevel() <= j)
                    levelhz.push_back(typehz[i][k]);
            }
            for (int k = 0; k < int(typeqz[i].size()); k++)
            {
                if (typeqz[i][k].getlevel() <= j)
                    levelqz.push_back(typeqz[i][k]);
            }
            if (sumlevelhz == levelhz.size() && sumlevelqz == levelqz.size())continue;
            else
            {
                sumlevelhz = levelhz.size();
                sumlevelqz = levelqz.size();
                outlevel << j << endl;
            }
            string title = path;
            title.append("\\cizhui\\蓝_类别_");
            title += to_string(i); title += "_等级_";   title += to_string(j); title += ".yml";
            locale china("zh_CN.UTF-8");
            wofstream out(title);
            out.imbue(china);
            out << "random-amount: \'if(RandomInt(0,100),>,75{2,1})\'" << endl;
            out << "entries:" << endl;
            for (int k = 0; k < int(levelhz.size()); k++)
            {
                out << _T("  后缀");
                out << k + 1;
                out << ":" << endl;
                out << "    type: attribute" << endl;
                out << "    data:" << endl;
                out << "      id: ";
                out << string2wstring(levelhz[k].getname()) << endl;
                bool iffloat = false, sign = false;
                double floatmin, floatmax, floatmin2, floatmax2;
                iffloat = levelhz[k].getfloat();
                sign = levelhz[k].getsign();
                floatmin = levelhz[k].getfloatmin();
                floatmax = levelhz[k].getfloatmax();
                floatmin2 = levelhz[k].getfloatmin2();
                floatmax2 = levelhz[k].getfloatmax2();
                if (iffloat == false)
                {
                    if (sign == false)
                    {
                        out << "      min: RandomInt(" << int(floatmin) << ',' << int(floatmin2) << ')' << endl;
                        out << "      max: {min}" << endl;
                        out << "      float: 0.0" << endl;
                        out << "      sign: false" << endl;
                    }
                    else
                    {
                        out << "      min: Random(" << floatmin << ',' << floatmin2 << ')' << endl;
                        out << "      max: {min}" << endl;
                        out << "      float: 0.0" << endl;
                        out << "      sign: true" << endl;
                    }
                }
                else
                {
                    out << "      min: RandomInt(" << int(floatmin) << ',' << int(floatmax) << ')' << endl;
                    out << "      max: RandomInt(" << int(floatmin2) << ',' << int(floatmax2) << ')' << endl;
                    out << "      float: 0.0" << endl;
                }
                out << "      display:" << endl;
                out << "      - \'&" << levelhz[k].getcolor() << _T("◈ &f[后缀]");
                out << "  &9";
                out << string2wstring(levelhz[k].getdescription());
                out << "  &";
                out << levelhz[k].getcolor();
                out << string2wstring(levelhz[k].getname());
				if (i == 33)
					out << "&f {attribute.value}\'" << endl;
				else
					out << "&f {attribute.streng.summary}\'" << endl;                out << "      order: 1" << endl;
                out << "      weight: 1" << endl;
                out << "      maximum : 1" << endl;
                out << "      exclude:" << endl;
                for (int m = 0; m < int(levelhz.size()); m++)
                {
                    if (m == k)continue;
                    else
                    {
                        out << _T("      - 后缀");
                        out << m + 1 << endl;
                    }
                }
            }
            for (int k = 0; k < int(levelqz.size()); k++)
            {
                out << _T("  前缀");
                out << k + 1;
                out << ":" << endl;
                out << "    type: attribute" << endl;
                out << "    data:" << endl;
                out << "      id: ";
                out << string2wstring(levelqz[k].getname()) << endl;
                bool iffloat = false, sign = false;
                double floatmin, floatmax, floatmin2, floatmax2;
                iffloat = levelqz[k].getfloat();
                sign = levelqz[k].getsign();
                floatmin = levelqz[k].getfloatmin();
                floatmax = levelqz[k].getfloatmax();
                floatmin2 = levelqz[k].getfloatmin2();
                floatmax2 = levelqz[k].getfloatmax2();
                if (iffloat == false)
                {
                    if (sign == false)
                    {
                        out << "      min: RandomInt(" << int(floatmin) << ',' << int(floatmax) << ')' << endl;
                        out << "      max: {min}" << endl;
                        out << "      float: 0.0" << endl;
                        out << "      sign: false" << endl;
                    }
                    else
                    {
                        out << "      min: Random(" << floatmin << ',' << floatmax << ')' << endl;
                        out << "      max: {min}" << endl;
                        out << "      float: 0.0" << endl;
                        out << "      sign: true" << endl;
                    }
                }
                else
                {
                    out << "      min: RandomInt(" << int(floatmin) << ',' << int(floatmax) << ')' << endl;
                    out << "      max: RandomInt(" << int(floatmin2) << ',' << int(floatmax2) << ')' << endl;
                    out << "      float: 0.0" << endl;
                }
                out << "      display:" << endl;
                out << "      - \'&" << levelqz[k].getcolor() << _T("◈ &f[前缀]");
                out << "  &9";
                out << string2wstring(levelqz[k].getdescription());
                out << "  &";
                out << levelqz[k].getcolor();
                out << string2wstring(levelqz[k].getname());
				if (i==33)
					out << "&f {attribute.value}\'" << endl;
				else
	                out << "&f {attribute.streng.summary}\'" << endl;
                out << "      order: 2" << endl;
                out << "      weight: 1" << endl;
                out << "      maximum : 1" << endl;
                out << "      exclude:" << endl;
                for (int m = 0; m < int(levelqz.size()); m++)
                {
                    if (m == k)continue;
                    else
                    {
                        out << _T("      - 前缀");
                        out << m + 1 << endl;
                    }
                }
            }
            out.close();
        }
        outlevel.close();
    }
}