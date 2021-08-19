#pragma once
#pragma once
#include"CommonFunction.h"
using namespace std;
void outbaoshi(string path);
void outbaoshi(string path)
{
	vector<int> bluelevel, yellowlevel;
	string bluetype = path;
	bluetype.append("\\词缀\\蓝\\type\\blue_type_33.txt");
	string yellowtype = path;
	yellowtype.append("\\词缀\\黄\\type\\yellow_type_33.txt");

	ifstream inFile("equip\\珠宝.csv", ios::in);
	if (!inFile)
	{
		cout << "打开珠宝文件失败！" << endl;
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
	string introduce;
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

	locale china("zh_CN.UTF-8");
	string resourcepath = path;
	resourcepath.append("\\材质\\baoshi.yml");
	wofstream resourse(resourcepath, ios::out);
	resourse.imbue(china);
	if (!resourse)
	{
		cout << "打开文件失败！" << endl;
		exit(1);
	}
	while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
	{

		string field;
		istringstream sin(line); //将整行字符串line读入到字符串流sin中

		getline(sin, field, ',');
		name = field.c_str();
		//cout << name;
		resourse << string2wstring(name) << ':' << endl;
		resourse << "  type: \'icon\'" << endl;
		resourse << "  path: \'textures/misc/bs/" << string2wstring(name) << ".png\'" << endl;
		resourse << "  offsetX: 0.0" << endl;
		resourse << "  offsetY: 0.0" << endl;
		resourse << "  offsetZ: 0.0" << endl;
		resourse << "  scale: 1" << endl;
		resourse << "  size: 0.5" << endl;
		resourse << "  matchCondition:" << endl;
		resourse << "    type: \'stone\'" << endl;
		resourse << "    match: \"" << string2wstring(name) << "\"" << endl;
		string blue_path = path;
		blue_path.append("\\宝石\\珠宝\\实体\\蓝\\蓝_");
		blue_path.append(name);
		blue_path.append(".yml");
		string yellow_path = path;
		yellow_path.append("\\宝石\\珠宝\\实体\\黄\\黄_");
		yellow_path.append(name);
		cout << name << endl;
		yellow_path.append(".yml");

		getline(sin, field, ',');
		equiplevel = atoi(field.c_str());
		getline(sin, field);
		introduce = field.c_str();

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
				truelevel = yellowlevel[i - 1];
				break;
			}
		}
		if (truelevel == 0)truelevel = yellowlevel[yellowlevel.size() - 1];

		outFile3 << _T("template: 黄珠宝模板") << endl;
		outFile3 << _T("damage: 0") << endl;
		outFile3 << _T("introduce:") << endl;
		int time = introduce.length() / 40;
		string tempstring;
		int timei = 0;
		string temp1;
		while (timei != time)
		{
			tempstring = introduce.substr(timei * 40, 40);
			timei++;
			outFile3 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		}
		tempstring = introduce.substr(time * 40, introduce.length() - time * 40);
		outFile3 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;

		outFile3 << "custom: {}" << endl;
		outFile3 << _T("gem-type: 珠宝") << endl;
		outFile3 << "sell:" << endl;
		outFile3 << "  score: \'{entry.random}\'" << endl;
		outFile3 << "custom-model-data: 0" << endl;
		outFile3 << "entry:" << endl;
		outFile3 << _T("  random: 黄_类别_33_等级_") << string2wstring(to_string(truelevel)) << endl;
		outFile3 << "type: stone" << endl;
		outFile3 << "inlaid-equip-type:" << endl;
		outFile3 << _T("- 所有装备") << endl;
		outFile3 << "hide: 63" << endl;
		outFile3 << "name: " << string2wstring(name) << endl;
		outFile3 << "unbreakable: true" << endl;
		outFile3.close();
		cout << "黄宝石完毕" << endl;

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

		outFile2 << _T("template: 蓝珠宝模板") << endl;
		outFile2 << _T("damage: 0") << endl;
		outFile2 << _T("introduce:") << endl;
		time = introduce.length() / 40;
		timei = 0;
		while (timei != time)
		{
			tempstring = introduce.substr(timei * 40, 40);
			timei++;
			outFile2 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
		}
		tempstring = introduce.substr(time * 40, introduce.length() - time * 40);
		outFile2 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;

		outFile2 << "custom: {}" << endl;
		outFile2 << _T("gem-type: 珠宝") << endl;
		outFile2 << "sell:" << endl;
		outFile2 << "  score: \'{entry.random}\'" << endl;
		outFile2 << "custom-model-data: 0" << endl;
		outFile2 << "entry:" << endl;
		outFile2 << _T("  random: 蓝_类别_33_等级_") << string2wstring(to_string(truelevel)) << endl;
		outFile2 << "type: stone" << endl;
		outFile2 << "inlaid-equip-type:" << endl;
		outFile2 << _T("- 所有装备") << endl;
		outFile2 << "hide: 63" << endl;
		outFile2 << "name: " << string2wstring(name) << endl;
		outFile2 << "unbreakable: true" << endl;
		outFile2.close();
		cout << "蓝宝石完毕" << endl;

	}
	inFile.close();
}
