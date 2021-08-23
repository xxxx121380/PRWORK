#pragma once
#include"CommonFunction.h"
using namespace std;
void outshoutao(string path);
void outshoutao(string path)
{
	vector<int> bluelevel, yellowlevel;
	string bluetype = path;
	bluetype.append("\\词缀\\蓝\\type\\blue_type_27.txt");
	string yellowtype = path;
	yellowtype.append("\\词缀\\黄\\type\\yellow_type_27.txt");
	ifstream inFile("equip\\手套.csv", ios::in);
	if (!inFile)
	{
		cout << "打开手套文件失败！" << endl;
		exit(-1);
	}
	ifstream inFile2(bluetype, ios::in);
	if (!inFile2)
	{
		cout << "打开蓝装等级失败！" << endl;
		exit(-1);
	}
	ifstream inFile3(yellowtype, ios::in);
	if (!inFile3)
	{
		cout << "打开黄装等级失败！" << endl;
		exit(-1);
	}
	int i = 0;
	string line;
	string field;
	string name;
	string mindef;
	string maxdef;
	string sign;
	string introduce;
	string authorname;
	int equiplevel;
	while (getline(inFile2, line))
	{
		int i = atoi(line.c_str());
		bluelevel.push_back(i);
	}
	inFile2.close();
	while (getline(inFile3, line))
	{
		int i = atoi(line.c_str());
		yellowlevel.push_back(i);
	}
	inFile3.close();
	while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
	{

		string field;
		istringstream sin(line); //将整行字符串line读入到字符串流sin中

		getline(sin, field, ',');
		name = field.c_str();
		//cout << name;
		string basic_att_path = path;
		basic_att_path.append("\\装备\\手套\\basic\\");
		basic_att_path.append(name);
		basic_att_path.append("基础属性.yml");
		string white_path = path;
		white_path.append("\\装备\\手套\\白\\白_");
		white_path.append(name);
		white_path.append(".yml");
		string blue_path = path;
		blue_path.append("\\装备\\手套\\蓝\\蓝_");
		blue_path.append(name);
		blue_path.append(".yml");
		string yellow_path = path;
		yellow_path.append("\\装备\\手套\\黄\\黄_");
		yellow_path.append(name);
		cout << name << endl;
		yellow_path.append(".yml");
		getline(sin, field, ',');
		mindef = field.c_str();
		getline(sin, field, ',');
		maxdef = field.c_str();
		getline(sin, field, ',');
		equiplevel = atoi(field.c_str());
		getline(sin, field, '_');
		introduce = field.c_str();
		getline(sin, field, ',');
		authorname = field.c_str();
		//cout << authorname<<endl;
		getline(sin, field);
		locale china("zh_CN.UTF-8");
		wofstream outFile(basic_att_path, ios::out);
		outFile.imbue(china);
		if (!outFile)
		{
			cout << "打开文件失败！" << endl;
			exit(1);
		}
		outFile << "entries:" << endl;
		outFile << "  " << string2wstring(name) << _T("_基础_防御值:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: 防御值") << endl;
		outFile << "      min: randomInt(" << string2wstring(mindef) << ',' << string2wstring(maxdef) << ')' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      float: 0" << endl;
		outFile << "      order: 2" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&c&m  &6&m  &e&m  &a&m  &3&m  &9&m  &5&m  &f&l基  础  属  性&r&5&m  &9&m  &3&m  &a&m  &e&m  &6&m  &c&m  \'") << endl;
		outFile << _T("      - \'&7▣ 防御值: &9{attribute.streng.summary}\'") << endl;
		outFile.close();

		wofstream outFile1(white_path, ios::out);
		outFile1.imbue(china);
		if (!outFile1)
		{
			cout << "打开文件失败！" << endl;
			exit(1);
		}
		outFile1 << _T("template: 白装手套模板") << endl;
		outFile1 << "damage: 0" << endl;
		outFile1 << "need-class: []" << endl;
		outFile1 << _T("equip-type: 手套") << endl;
		outFile1 << "can-reset: false" << endl;
		outFile1 << "introduce:" << endl;
		int time = introduce.length() / 40;
		string tempstring;
		int timei = 0;
		while (timei != time)
		{
			tempstring = introduce.substr(int(timei * 40), 40);
			timei++;
			outFile1 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
			//cout << tempstring << endl;
		}
		tempstring = introduce.substr(int(time * 40), introduce.length() - int(time * 40));
		outFile1 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		string temp1 = "&7&m     ";
		outFile1 << "- \'";
		for (int j = 0; j < 48 - temp1.length() - authorname.length(); j++)
			outFile1 << ' ';
		outFile1 << string2wstring(temp1) << "&7&o" << string2wstring(authorname.c_str()) << '\'' << endl;
		outFile1 << "custom: {}" << endl;
		outFile1 << "sell: " << endl;
		outFile1 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
		outFile1 << "  money: \'";
		int money = (equiplevel / 10) * 100 + 100;
		outFile1 << money << '\'' << endl;
		outFile1 << "custom-model-data: 0" << endl;
		outFile1 << "entry:" << endl;
		outFile1 << "  random: " << _T("普通增强防御") << endl;
		outFile1 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
		outFile1 << "type: stone" << endl;
		outFile1 << "gem:" << endl;
		outFile1 << "  driller: false" << endl;
		outFile1 << "hide: 63" << endl;

		outFile1 << "need-level: \'" << equiplevel << '\'' << endl;
		outFile1 << _T("template-not-appraisal: 随机手套") << endl;
		outFile1 << "name: " << string2wstring(name) << endl;
		outFile1 << "can-streng: false" << endl;
		outFile1 << "unbreakable: true" << endl;
		outFile1.close();
		cout << "白装完毕" << endl;

		wofstream outFile3(yellow_path, ios::out);
		outFile3.imbue(china);
		if (!outFile3)
		{
			cout << "打开文件失败！" << endl;
			exit(1);
		}
		int truelevel = 0;
		for (int i = 0; i < int(yellowlevel.size()); i++)
		{
			if (equiplevel == yellowlevel[i]) {
				truelevel = yellowlevel[i];
				break;
			}
			else if (equiplevel < yellowlevel[i]) {
				truelevel = yellowlevel[int(i - 1)];
				break;
			}
		}
		if (truelevel == 0)truelevel = yellowlevel[yellowlevel.size() - 1];

		outFile3 << _T("template: 黄装手套模板") << endl;
		outFile3 << "damage: 0" << endl;
		outFile3 << "need-class: []" << endl;
		outFile3 << _T("equip-type: 手套") << endl;
		outFile3 << "can-reset: false" << endl;
		outFile3 << "introduce:" << endl;
		timei = 0;
		while (timei != time)
		{
			tempstring = introduce.substr(timei * 40, 40);
			timei++;
			outFile3 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		}
		tempstring = introduce.substr(time * 40, int(introduce.length() - time * 40));
		outFile3 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		outFile3 << "- \'";
		temp1 = "&7&m     ";
		for (int j = 0; j < 48 - temp1.length() - authorname.length(); j++)
			outFile3 << ' ';
		outFile3 << string2wstring(temp1) << "&7&o" << string2wstring(authorname.c_str()) << '\'' << endl;
		outFile3 << "custom: {}" << endl;
		outFile3 << "sell: " << endl;
		outFile3 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
		outFile3 << "  money: \'";
		money = (equiplevel / 10) * 100 + 100;
		outFile3 << money << '\'' << endl;
		outFile3 << "custom-model-data: 0" << endl;
		outFile3 << "entry:" << endl;
		outFile3 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
		outFile3 << _T("  random: 黄_类别_27_等级_") << string2wstring(to_string(truelevel)) << endl;
		outFile3 << "type: stone" << endl;
		outFile3 << "gem:" << endl;
		outFile3 << "  driller: false" << endl;
		outFile3 << "hide: 63" << endl;

		outFile3 << "need-level: \'" << equiplevel << '\'' << endl;
		outFile3 << _T("template-not-appraisal: 随机手套") << endl;
		outFile3 << "name: " << string2wstring(name) << endl;
		outFile3 << "can-streng: false" << endl;
		outFile3 << "unbreakable: true" << endl;
		outFile3.close();
		cout << "黄装完毕" << endl;

		wofstream outFile2(blue_path, ios::out);
		outFile2.imbue(china);
		if (!outFile2)
		{
			cout << "打开文件失败！" << endl;
			exit(1);
		}
		truelevel = 0;
		for (int i = 0; i < int(bluelevel.size()); i++)
		{
			if (equiplevel == bluelevel[i]) {
				truelevel = bluelevel[i];
				break;
			}
			else if (equiplevel < bluelevel[i]) {
				truelevel = bluelevel[i - 1];
				break;
			}
		}
		if (truelevel == 0)truelevel = bluelevel[bluelevel.size() - 1];
		outFile2 << _T("template: 蓝装手套模板") << endl;
		outFile2 << "damage: 0" << endl;
		outFile2 << "need-class: []" << endl;
		outFile2 << _T("equip-type: 手套") << endl;
		outFile2 << "can-reset: false" << endl;
		outFile2 << "introduce:" << endl;
		timei = 0;
		while (timei != time)
		{
			tempstring = introduce.substr(timei * 40, 40);
			timei++;
			outFile2 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		}
		tempstring = introduce.substr(time * 40, introduce.length() - time * 40);
		outFile2 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		outFile2 << "- \'";
		temp1 = "&7&m     ";
		for (int j = 0; j < 48 - temp1.length() - authorname.length(); j++)
			outFile2 << ' ';
		outFile2 << string2wstring(temp1) << "&7&o" << string2wstring(authorname.c_str()) << '\'' << endl;
		outFile2 << "custom: {}" << endl;
		outFile2 << "sell: " << endl;
		outFile2 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
		outFile2 << "  money: \'";
		money = (equiplevel / 10) * 100 + 100;
		outFile2 << money << '\'' << endl;
		outFile2 << "custom-model-data: 0" << endl;
		outFile2 << "entry:" << endl;
		outFile2 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
		outFile2 << _T("  random: 蓝_类别_27_等级_") << string2wstring(to_string(truelevel)) << endl;
		outFile2 << "type: stone" << endl;
		outFile2 << "gem:" << endl;
		outFile2 << "  driller: false" << endl;
		outFile2 << "hide: 63" << endl;

		outFile2 << "need-level: \'" << equiplevel << '\'' << endl;
		outFile2 << _T("template-not-appraisal: 随机手套") << endl;
		outFile2 << "name: " << string2wstring(name) << endl;
		outFile2 << "can-streng: false" << endl;
		outFile2 << "unbreakable: true" << endl;
		outFile2.close();
		cout << "蓝装完毕" << endl;

	}
	inFile.close();
}