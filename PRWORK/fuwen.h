#pragma once
#include"CommonFunction.h"

void outfuwen(string path);
void outfuwen(string path)
{
	string line;
	ifstream in("FWatt.txt", ios::in);

	for (int i = 0; i < 33; i++)
	{
		in >> line;
		stringstream ss(line);
		string temp;
		string name, ifsign, ifrange, num, attname, fnum1, fnum2, equiplevel;
		int sum;
		getline(ss, name, ',');
		cout << name << endl;
		getline(ss, equiplevel, ',');
		string rawpath1 = path;
		string rawpath10 = path;
		string rawpath2 = path;
		string rawpath20 = path;
		rawpath1.append("\\宝石\\符文\\词缀\\攻击_");
		rawpath1.append(name);
		rawpath1.append("基础属性.yml");
		rawpath10.append("\\宝石\\符文\\实体\\攻击_");
		rawpath10.append(name);
		rawpath10.append(".yml");
		rawpath2.append("\\宝石\\符文\\词缀\\防御_");
		rawpath2.append(name);
		rawpath2.append("基础属性.yml");
		rawpath20.append("\\宝石\\符文\\实体\\防御_");
		rawpath20.append(name);
		rawpath20.append(".yml");
		locale china("zh_CN.UTF-8");

		wofstream outatk(rawpath1, ios::out);
		wofstream outatk0(rawpath10, ios::out);
		wofstream outdef(rawpath2, ios::out);
		wofstream outdef0(rawpath20, ios::out);
		outatk.imbue(china);
		outatk0.imbue(china);
		outdef.imbue(china);
		outdef0.imbue(china);
		outatk0 << _T("template: 宝石符文模板") << endl;
		outatk0 << _T("damage: 0") << endl;
		outatk0 << _T("introduce:") << endl;
		outatk0 << _T("- \'&f符文是一种篆刻了神秘象形文字的小石头，\'") << endl;
		outatk0 << _T("- \'&f可以放入带孔装备中获取强大增益。传闻当\'") << endl;
		outatk0 << _T("- \'&f几个符文按照一定的顺序插入后，可以获得\'") << endl;
		outatk0 << _T("- \'&f加强大的综合属性。\'") << endl;
		outatk0 << "custom: {}" << endl;
		outatk0 << _T("gem-type: 符文-武器") << endl;
		outatk0 << "sell:" << endl;
		outatk0 << "  score: \'{entry.basic}\'" << endl;
		outatk0 << "custom-model-data: 0" << endl;
		outatk0 << "entry:" << endl;
		outatk0 << _T("  basic: 攻击_") << string2wstring(name) << _T("基础属性") << endl;
		outatk0 << "type: stone" << endl;
		outatk0 << "inlaid-equip-type:" << endl;
		outatk0 << _T("- 武器") << endl;
		outatk0 << "hide: 63" << endl;

		outatk0 << "need-level: \'" << string2wstring(equiplevel) << '\'' << endl;
		outatk0 << "name: " << string2wstring(name) << endl;
		outatk0 << "unbreakable: true" << endl;
		outatk0.close();

		outdef0 << _T("template: 宝石符文模板") << endl;
		outdef0 << _T("damage: 0") << endl;
		outdef0 << _T("introduce:") << endl;
		outdef0 << _T("- \'&f符文是一种篆刻了神秘象形文字的小石头，\'") << endl;
		outdef0 << _T("- \'&f可以放入带孔装备中获取强大增益。传闻当\'") << endl;
		outdef0 << _T("- \'&f几个符文按照一定的顺序插入后，可以获得\'") << endl;
		outdef0 << _T("- \'&f加强大的综合属性。\'") << endl;
		outdef0 << "custom: {}" << endl;
		outdef0 << _T("gem-type: 符文-防具") << endl;
		outdef0 << "sell:" << endl;
		outdef0 << "  score: \'{entry.basic}\'" << endl;
		outdef0 << "custom-model-data: 0" << endl;
		outdef0 << "entry:" << endl;
		outdef0 << _T("  basic: 防御_") << string2wstring(name) << _T("基础属性") << endl;
		outdef0 << "type: stone" << endl;
		outdef0 << "inlaid-equip-type:" << endl;
		outdef0 << _T("- 衣服") << endl;
		outdef0 << _T("- 盾牌") << endl;
		outdef0 << _T("- 头盔") << endl;
		outdef0 << _T("- 衣服") << endl;
		outdef0 << "hide: 63" << endl;
		outdef0 << "name: " << string2wstring(name) << endl;
		outdef0 << "unbreakable: true" << endl;
		outdef0.close();

		outatk << "entries:" << endl;
		outdef << "entries:" << endl;

		getline(ss, temp, ',');
		sum = atoi(temp.c_str());
		for (int j = 0; j < sum; j++)
		{
			getline(ss, ifsign, ',');
			getline(ss, ifrange, ',');
			getline(ss, attname, ',');
			outatk << _T("  词缀");
			outatk << j + 1;
			outatk << ":" << endl;
			outatk << "    type: attribute" << endl;
			outatk << "    data:" << endl;
			outatk << "      id: ";
			outatk << string2wstring(attname) << endl;
			if (ifrange[0] == '0')
			{
				getline(ss, num, ',');
				if (ifsign[0] == '0')
				{
					outatk << "      min: " << string2wstring(num) << endl;
					outatk << "      max: {min}" << endl;
					outatk << "      float: 0.0" << endl;
					outatk << "      sign: false" << endl;
				}
				else
				{
					outatk << "      min: " << string2wstring(num) << endl;
					outatk << "      max: {min}" << endl;
					outatk << "      float: 0.0" << endl;
					outatk << "      sign: true" << endl;
				}
			}
			else
			{
				getline(ss, fnum1, ',');
				getline(ss, fnum2, ',');
				outatk << "      min: " << string2wstring(fnum1) << endl;
				outatk << "      max: " << string2wstring(fnum2) << endl;
				outatk << "      float: 0.0" << endl;
			}
			outatk << "      display:" << endl;
			outatk << "      - \'&5&l" << _T("◈ &f[符文词缀]");
			outatk << "&b{attribute.name} &f{attribute.value}\'" << endl;
		}
		outatk.close();
		getline(ss, ifsign, ',');
		getline(ss, attname, ',');
		outdef << _T("  词缀") << ":" << endl;
		outdef << "    type: attribute" << endl;
		outdef << "    data:" << endl;
		outdef << "      id: ";
		outdef << string2wstring(attname) << endl;
		getline(ss, num, ',');
		if (ifsign[0] == '0')
		{

			outdef << "      min: " << string2wstring(num) << endl;
			outdef << "      max: {min}" << endl;
			outdef << "      float: 0.0" << endl;
			outdef << "      sign: false" << endl;
		}
		else
		{
			outdef << "      min: " << string2wstring(num) << endl;
			outdef << "      max: {min}" << endl;
			outdef << "      float: 0.0" << endl;
			outdef << "      sign: true" << endl;
		}
		outdef << "      display:" << endl;
		outdef << "      - \'&5&l" << _T("◈ &f[符文词缀]");
		outdef << "&b{attribute.name} &f{attribute.value}\'" << endl;
		outdef.close();
	}
}