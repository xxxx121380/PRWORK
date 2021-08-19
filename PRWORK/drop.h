#pragma once

#include"CommonFunction.h"
class drop
{
private:
    string name;//掉落物名
    int level=0;//掉落等级
    double percent=0;//符文掉落概率
public:
    void setlevel(string i)
    {
        level = atoi(i.c_str());
    }
    void setname(string i)
    {
        name = i;
    }
    void setpercent(string i)
    {
        percent = atof(i.c_str());
    }

    double getpercent()
    {
        return percent;
    }


    int getlevel()
    {
        return level;
    }

    string getname()
    {
        return name;
    }
};
void outdrop(string path)
{
    vector<string>equip[101];
    vector<drop> fw;
    int sum, sumhz = 0;
    string line;
    ifstream in("FW.txt", ios::in);
    //读入原始词缀
    while (!in.eof())
    {
        in >> sum;
        for (int i = 1; i <= sum; i++)
        {
            in >> line;
            drop tmpfw;
            stringstream ss(line);
            string name, droplevel, percent;
            getline(ss, name, ',');
            tmpfw.setname(name);
            getline(ss, droplevel, ',');
            tmpfw.setlevel(droplevel);
            getline(ss, percent, ',');
            tmpfw.setpercent(percent);
            fw.push_back(tmpfw);
            
        }
    }
    in.close();
    int mobexp[101] = { 0 };
    int mobexpi = 0;
    ifstream inexp ("mobdata.txt", ios::in);
    while (!inexp.eof())
    {
        //cout << mobexpi << endl;
        inexp >> line;
        mobexp[mobexpi] = atoi(line.c_str());
        mobexpi++;
    }
    inexp.close();
    ifstream inequip("equip.txt", ios::in);
    while (!inequip.eof())
    {
        inequip >> line;
        stringstream ss(line);
        string name, droplevel;
        getline(ss, name, ',');
        getline(ss, droplevel);
        //cout << name << ',' << droplevel << endl;

        equip[atoi(droplevel.c_str())].push_back(name);
    }
    inequip.close();
    //输出掉率
    //一共只要输出钱、经验、符文、装备
    for (int i = 1; i <= 100; i++)
    {

        string title = path;
        title.append("\\掉落\\普通\\普通_"); 
        title.append(to_string(i));
        title.append("级掉落包.yml");
        locale china("zh_CN.UTF-8");
        //wcout.imbue(china);
        wofstream out(title, ios::out);
        out.imbue(china);
        if (!out)
        {
            cout << "打开文件失败！" << endl;
            exit(1);
        }  
        int sumfw = 0;
        double jc = 0.001;
        double sumpercent = 0;
        for (int j = 0; j < fw.size(); j++)
        {
            if (fw[j].getlevel() <= i && j != 33)
                sumpercent += fw[j].getpercent();
            else
            {
                sumfw = j;
                break;
            }
        }
        //cout << i << endl;
        out << _T("普通_") << i << _T("级掉落包:") << endl;
        double money;
        money = (pow(i, 1.5) + 4)*2;

        out << "- type=pxrpgexp;amount=" << to_string(mobexp[i - 1]).c_str() << ";prob=1" << endl;
        out << "- type=money;amount=" << to_string(int(money)).c_str() << ";prob=0.1" << endl;
        
        vector<string>tempequip;
        for (int j = 1; j <= i; j++)
        {
            for (int k = 0; k < equip[j].size(); k++)
            {
                tempequip.push_back(equip[j][k]);
            }
        }
        if (tempequip.size() != 0) {
            out << "- type=equip;id=RandomWeight(random(1,";
            //cout << tempequip.size() << endl;
			out << tempequip.size() << "){";
			for (int j = 0; j < tempequip.size() - 1; j++)
				out << "1,";
			out << "1:";
            for (int j = 0; j < tempequip.size()-1; j++)
            {
                string name = "白_";
                name.append(tempequip[j]);
                out << string2wstring(name) << ',';
            }
            out << _T("白_") << string2wstring(tempequip[tempequip.size()-1]) << "});prob=0.025;level=" << i << endl;
        }
		if (tempequip.size() != 0) {
			out << "- type=equip;id=RandomWeight(random(1,";
			//cout << tempequip.size() << endl;
			out << tempequip.size() << "){";
			for (int j = 0; j < tempequip.size() - 1; j++)
				out << "1,";
			out << "1:";
			for (int j = 0; j < tempequip.size() - 1; j++)
			{
				string name = "蓝_";
				name.append(tempequip[j]);
				out << string2wstring(name) << ',';
			}
			out << _T("蓝_") << string2wstring(tempequip[tempequip.size() - 1]) << "});prob=0.025;level=" << i << endl;
		}
		if (tempequip.size() != 0) {
			out << "- type=equip;id=RandomWeight(random(1,";
			//cout << tempequip.size() << endl;
			out << tempequip.size() << "){";
			for (int j = 0; j < tempequip.size() - 1; j++)
				out << "1,";
			out << "1:";
			for (int j = 0; j < tempequip.size() - 1; j++)
			{
				string name = "黄_";
				name.append(tempequip[j]);
				out << string2wstring(name) << ',';
			}
			out << _T("黄_") << string2wstring(tempequip[tempequip.size() - 1]) << "});prob=0.025;level=" << i << endl;
		}
        for (int j = 0; j < sumfw; j++)
        {
            double truepercent;
            truepercent = jc * (fw[j].getpercent() / sumpercent);
            out << "- type=item;id=";
            out << string2wstring(fw[j].getname());
            out << ";level=";
            out << fw[j].getlevel();
            out << ";prob=";
            out << std::fixed << setprecision(7) << truepercent << endl;
        }
        out.close();
    }
}

