#pragma once

#include"CommonFunction.h"
void outatt(string path);
void outatt(string path)
{
    string line;
    ifstream in("attribute.txt", ios::in);
    //����ԭʼ��׺
	string rawpath;
	while (!in.eof())
	{
		//������ �Ƿ��з�Χ ���㹫ʽ����
		in >> line;
		stringstream ss(line);
		string name, srange, ssign, srate;
		int range, rate, sign;
		getline(ss, name, ',');

		getline(ss, srange, ',');
		getline(ss, ssign, ',');
		getline(ss, srate);
		range = atoi(srange.c_str());
		sign = atoi(ssign.c_str());
		rate = atoi(srate.c_str());
		rawpath = path;
		rawpath.append("\\����\\");
		rawpath.append(name);
		rawpath.append(".yml");
		locale china("zh_CN.UTF-8");
		wofstream outFile(rawpath, ios::out);
		outFile.imbue(china);
		if (!outFile)
		{
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(-1);
		}
		outFile << "name: " << string2wstring(name) << endl;
		outFile << "tip : []" << endl;
		outFile << "sell :" << endl;
		if (sign == 0)
		{
			outFile << "  score : \'({min.sign}+{max.sign})*100*" << rate << '\'' << endl;
			outFile << "  money : \'({min.sign}+{max.sign})*100*" << rate << '\'' << endl;

		}
		else
		{
			outFile << "  score : \'({min.value}+{max.value})*(1+({min.sign}+{max.sign})/2)*" << rate << '\'' << endl;
			outFile << "  money : \'({min.value}+{max.value})*(1+({min.sign}+{max.sign})/2)*" << rate << '\'' << endl;

		}
		outFile << "view : false" << endl;
		outFile << "affected-by-streng : false" << endl;
		outFile << "streng : \'0\'" << endl;
		if (range == 0)
			outFile << "range : false" << endl;
		else
			outFile << "range : true" << endl;
		outFile.close();
	}
    in.close();

}