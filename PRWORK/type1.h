#pragma once
#include"CommonFunction.h"
using namespace std;
void outtype1(string path);
void outtype1(string path)
{
	ifstream inFile("equip\\type1.csv", ios::in);
	if (!inFile)
	{
		cout << "打开装备文件失败！" << endl;
		exit(-1);
	}
	int SumType = 0, EquipTypeNum = 0,EquipNum=0;//这类模板数量,大类数字
	string EquipType,EquipEx;//装备大类,装备长相
	vector<int> BlueLevel, YellowLevel;//大类装备各等级
	string BlueTypePath, YellowTypePath;//大类装备等级文件路径
	inFile >> SumType;
	for (int i = 0; i < SumType; i++)
	{
		inFile >> EquipType;
		inFile >> EquipTypeNum;
		inFile >> EquipNum;
		inFile >> EquipEx;
		BlueTypePath = path;
		BlueTypePath.append("\\词缀\\蓝\\type\\blue_type_");
		BlueTypePath.append(to_string(EquipTypeNum));
		BlueTypePath.append(".txt");
		YellowTypePath = path;
		YellowTypePath.append("\\词缀\\黄\\type\\yellow_type_");
		YellowTypePath.append(to_string(EquipTypeNum));
		YellowTypePath.append(".txt");

		ifstream inFile2(BlueTypePath, ios::in);
		if (!inFile2)
		{
			cout << "打开蓝装等级失败！" << endl;
			exit(-1);
		}
		ifstream inFile3(YellowTypePath, ios::in);
		if (!inFile3)
		{
			cout << "打开黄装等级失败！" << endl;
			exit(-1);
		}
		//记录当前词缀等级
		string line;
		while (getline(inFile2, line))
		{
			int i = atoi(line.c_str());
			BlueLevel.push_back(i);
		}
		inFile2.close();
		while (getline(inFile3, line))
		{
			int i = atoi(line.c_str());
			YellowLevel.push_back(i);
		}
		inFile3.close();
		for (int j = 0; j < EquipNum; j++)
		{
			string field, name, mindef, maxdef, sign, introduce, authorname;
			int equiplevel;
			int truelevel = 0;//装备真实词缀等级
			inFile >> line;
			istringstream sin(line); //将整行字符串line读入到字符串流sin中

			getline(sin, field, ',');
			name = field.c_str();
			cout << name << endl;
			string BasicPath = path;
			BasicPath.append("\\装备\\");
			BasicPath.append(EquipType);
			BasicPath.append("\\basic\\");
			BasicPath.append(name);
			BasicPath.append("基础属性.yml");
			string white_path = path;
			white_path.append("\\装备\\");
			white_path.append(EquipType);
			white_path.append("\\白\\白_");
			white_path.append(name);
			white_path.append(".yml");
			string BluePath = path;
			BluePath.append("\\装备\\");
			BluePath.append(EquipType);
			BluePath.append("\\蓝\\蓝_");
			BluePath.append(name);
			BluePath.append(".yml");
			string YellowPath = path;
			YellowPath.append("\\装备\\");
			YellowPath.append(EquipType);
			YellowPath.append("\\黄\\黄_");
			YellowPath.append(name);
			YellowPath.append(".yml");

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
			getline(sin, field);
			locale china("zh_CN.UTF-8");
			//白装属性输出
			wofstream outFile(BasicPath, ios::out);
			outFile.imbue(china);
			if (!outFile)
			{
				cout << "打开白装输出文件失败！" << endl;
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
			outFile << _T("      - \'&7▣ 防御值: &9{attribute.streng.summary}\'") << endl;
			outFile.close();
			//白装装备输出
			wofstream outFile1(white_path, ios::out);
			outFile1.imbue(china);
			if (!outFile1)
			{
				cout << "打开白装输出文件失败！" << endl;
				exit(1);
			}
			outFile1 << _T("template: 白装模板1") << endl;
			outFile1 << "damage: 0" << endl;
			outFile1 << "need-class: []" << endl;
			outFile1 << _T("equip-type: ");
			outFile1 << string2wstring(EquipType) << endl;;
			outFile1 << "can-reset: false" << endl;
			outFile1 << "introduce:" << endl;
			int time = introduce.length() / 40;
			string tempstring;
			int timei = 0;
			while (timei != time)
			{
				tempstring = introduce.substr(timei * 40, 40);
				timei++;
				outFile1 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
				//cout << tempstring << endl;
			}
			tempstring = introduce.substr(time * 40, int(introduce.length() - time * 40));
			outFile1 << "- \'&7&o" << string2wstring(tempstring) << '\'' << endl;
			string temp1 = "&7&m     ";
			outFile1 << "- \'";
			for (int j = 0; j < 48 - temp1.length() - authorname.length(); j++)
				outFile1 << ' ';
			outFile1 << string2wstring(temp1) << "&7&o" << string2wstring(authorname.c_str()) << '\'' << endl;
			outFile1 << "custom: " << endl;
			outFile1 << _T("  装备类型: \'") << string2wstring(EquipType) << '\'' << endl;
			outFile1 << "sell: " << endl;
			outFile1 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
			outFile1 << "  money: \'";
			int money = (equiplevel / 10) * 100 + 100;
			outFile1 << money << '\'' << endl;
			outFile1 << "custom-model-data: 0" << endl;
			outFile1 << "entry:" << endl;
			outFile1 << "  random: " << _T("普通增强防御") << endl;
			outFile1 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
			outFile1 << "type: " <<string2wstring(EquipEx)<< endl;
			outFile1 << "gem:" << endl;
			outFile1 << "  driller: false" << endl;
			outFile1 << "hide: 63" << endl;

			outFile1 << "need-level: \'" << trunc(equiplevel * 0.75) + 1 << '\'' << endl;
			outFile1 << _T("template-not-appraisal: 随机") << string2wstring(EquipType) << endl;
			outFile1 << "name: " << string2wstring(name) << endl;
			outFile1 << "can-streng: false" << endl;
			outFile1 << "unbreakable: true" << endl;
			outFile1.close();
			cout << "白装完毕" << endl;

			//生成蓝装
			wofstream outFile2(BluePath, ios::out);
			outFile2.imbue(china);
			if (!outFile2)
			{
				cout << "打开文件失败！" << endl;
				exit(1);
			}
			truelevel = 0;
			for (int i = 0; i < int(BlueLevel.size()); i++)
			{
				if (equiplevel == BlueLevel[i]) {
					truelevel = BlueLevel[i];
					break;
				}
				else if (equiplevel < BlueLevel[i]) {
					truelevel = BlueLevel[i - 1];
					break;
				}
			}
			if (truelevel == 0)truelevel = BlueLevel[BlueLevel.size() - 1];
			outFile2 << _T("template: 蓝装模板1") << endl;
			outFile2 << "damage: 0" << endl;
			outFile2 << "need-class: []" << endl;
			outFile2 << _T("equip-type: ");
			outFile2 << string2wstring(EquipType) << endl;;
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
			outFile2 << "custom: " << endl;
			outFile2 << _T("  装备类型: \'") << string2wstring(EquipType) << '\'' << endl;
			outFile2 << "sell: " << endl;
			outFile2 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
			outFile2 << "  money: \'";
			money = (equiplevel / 10) * 100 + 100;
			outFile2 << money << '\'' << endl;
			outFile2 << "custom-model-data: 0" << endl;
			outFile2 << "entry:" << endl;
			outFile2 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
			outFile2 << _T("  random: 蓝_类别_") << EquipTypeNum << _T("_等级_") << string2wstring(to_string(truelevel)) << endl;
			outFile2 << "type: " << string2wstring(EquipEx) << endl;
			outFile2 << "gem:" << endl;
			outFile2 << "  driller: false" << endl;
			outFile2 << "hide: 63" << endl;

			outFile2 << "need-level: \'" << trunc(equiplevel*0.75)+1 << '\'' << endl;
			outFile2 << _T("template-not-appraisal: 随机") << string2wstring(EquipType) << endl;
			outFile2 << "name: " << string2wstring(name) << endl;
			outFile2 << "can-streng: false" << endl;
			outFile2 << "unbreakable: true" << endl;
			outFile2.close();
			cout << "蓝装完毕" << endl;
			//黄装
			wofstream outFile3(YellowPath, ios::out);
			outFile3.imbue(china);
			if (!outFile3)
			{
				cout << "打开文件失败！" << endl;
				exit(1);
			}
			truelevel = 0;
			for (int i = 0; i < int(YellowLevel.size()); i++)
			{
				if (equiplevel == YellowLevel[i]) {
					truelevel = YellowLevel[i];
					break;
				}
				else if (equiplevel < YellowLevel[i]) {
					truelevel = YellowLevel[int(i - 1)];
					break;
				}
			}
			if (truelevel == 0)truelevel = YellowLevel[YellowLevel.size() - 1];

			outFile3 << _T("template: 黄装模板1") << endl;
			outFile3 << "damage: 0" << endl;
			outFile3 << "need-class: []" << endl;
			outFile3 << _T("equip-type: ");
			outFile3 << string2wstring(EquipType) << endl;;
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
			outFile3 << "custom: " << endl;
			outFile3 << _T("  装备类型: \'") << string2wstring(EquipType) << '\'' << endl;

			outFile3 << "sell: " << endl;
			outFile3 << "  score: \'{entry.basic}+{entry.random}+{gem}\'" << endl;
			outFile3 << "  money: \'";
			money = (equiplevel / 10) * 100 + 100;
			outFile3 << money << '\'' << endl;
			outFile3 << "custom-model-data: 0" << endl;
			outFile3 << "entry:" << endl;
			outFile3 << "  basic: " << string2wstring(name) << _T("基础属性") << endl;
			outFile3 << _T("  random: 黄_类别_") << EquipTypeNum << _T("_等级_") << string2wstring(to_string(truelevel)) << endl;
			outFile3 << "type: " << string2wstring(EquipEx) << endl;
			outFile3 << "gem:" << endl;
			outFile3 << "  driller: false" << endl;
			outFile3 << "hide: 63" << endl;

			outFile3 << "need-level: \'" << trunc(equiplevel * 0.75) + 1 << '\'' << endl;
			outFile3 << _T("template-not-appraisal: 随机") << string2wstring(EquipType) << endl;
			outFile3 << "name: " << string2wstring(name) << endl;
			outFile3 << "can-streng: false" << endl;
			outFile3 << "unbreakable: true" << endl;
			outFile3.close();
			cout << "黄装完毕" << endl;

		}
	}

	inFile.close();
}