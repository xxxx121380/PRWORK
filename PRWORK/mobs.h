#pragma once
#include "CommonFunction.h"
void outmobs(string path);
void outmobs(string path)
{
	ifstream inFile("С��.txt", ios::in);
	if (!inFile)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		exit(-1);
	}
	int i = 0;
	string line, level, tempstr, hp, mp, damagemin, damagemax, exp, bjl, zql, gdl, defense;
	string field;
	string name, khmin, kbmin, ksdmin, kdmin, kwlmin, kmfmin, khmax, kbmax, ksdmax, kdmax, kwlmax, kmfmax;
	locale china("zh_CN.UTF-8");
	ofstream mobdata("mobdata.txt", ios::out);
	while (i < 100)//getline(inFile, line)��ʾ���ж�ȡCSV�ļ��е�����
	{
		
		string field;
		istringstream sin;
		getline(inFile, line);

		level = line.substr(2);

		getline(inFile, line);
		name = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		hp = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		mp = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		exp = line;

		getline(inFile, line, ':');
		getline(inFile, line, '-');
		damagemin = line;
		getline(inFile, line);
		damagemax = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		zql = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		bjl = line;

		getline(inFile, line);

		getline(inFile, line, ':');
		getline(inFile, line);
		defense = line;

		getline(inFile, line, ':');
		getline(inFile, line);
		gdl = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		khmin = line;
		getline(inFile, line);
		khmax = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		kbmin = line;
		getline(inFile, line);
		kbmax = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		ksdmin = line;
		getline(inFile, line);
		ksdmax = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		kdmin = line;
		getline(inFile, line);
		kdmax = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		kwlmin = line;
		getline(inFile, line);
		kwlmax = line;

		getline(inFile, line, ':');
		getline(inFile, line, '~');
		kmfmin = line;
		getline(inFile, line);
		kmfmax = line;
		string mobpath = path;
		string entity = path;
		mobpath.append("\\����\\");
		mobpath.append(name);
		mobpath.append("��������.yml");
		wofstream outFile(mobpath, ios::out);
		outFile.imbue(china);
		mobdata << exp << endl;
		entity.append("\\ʵ��\\PT");
		entity.append(name);
		entity.append(".yml");
		wofstream outFile2(entity, ios::out);
		outFile2.imbue(china);
		if (!outFile)
		{
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(-1);
		}
		if (!outFile2)
		{
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(-1);
		}

		outFile << "entries:" << endl;
		outFile << _T("  ����ȼ�:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����ȼ�") << endl;
		outFile << "      min: \'" << string2wstring(level) << '\'' << endl;
		outFile << "      max: {min}"  << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ��������ֵ:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ��������ֵ") << endl;
		outFile << "      min: \'" << string2wstring(hp) << '\'' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  �����˺�:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: �����˺�") << endl;
		outFile << "      min: \'" << string2wstring(damagemin) << '\'' << endl;
		outFile << "      max: \'" << string2wstring(damagemax) << '\'' << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ׼ȷ��:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ׼ȷ��") << endl;
		outFile << "      min: \'" << string2wstring(zql) << '\'' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ������:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ������") << endl;
		int bj = stoi(bjl);
		double bjl0 = bj / 100.0;
		outFile << "      min: \'" << setprecision(3) << bjl0 << '\'' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ����ֵ:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����ֵ") << endl;
		outFile << "      min: \'" << string2wstring(defense) << '\'' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: false" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ����:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����") << endl;
		int gd = stoi(gdl);
		double gdl0 = gd / 100.0;
		outFile << "      min: \'" << setprecision(3) << gdl0 << '\'' << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ����:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����") << endl;
		int khmi = stoi(khmin);
		int khma = stoi(khmax);
		double khmin0 = khmi / 100.0;
		double khmax0 = khma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << khmin0 << ',' << setprecision(3) << khmax0 << ")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'")<< endl;

		outFile << _T("  ����:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����") << endl;
		int kbmi = stoi(kbmin);
		int kbma = stoi(kbmax);
		double kbmin0 = kbmi / 100.0;
		double kbmax0 = kbma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << kbmin0 << ',' << setprecision(3) << kbmax0 << ")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ����:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����") << endl;
		int ksdmi = stoi(ksdmin);
		int ksdma = stoi(ksdmax);
		double ksdmin0 = ksdmi / 100.0;
		double ksdmax0 = ksdma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << ksdmin0 << ',' << setprecision(3) << ksdmax0 << ")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ����:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ����") << endl;
		int kdmi = stoi(kdmin);
		int kdma = stoi(kdmax);
		double kdmin0 = kdmi / 100.0;
		double kdmax0 = kdma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << kdmin0 << ',' << setprecision(3) << kdmax0 << ")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ������:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ������") << endl;
		int kwlmi = stoi(kwlmin);
		int kwlma = stoi(kwlmax);
		double kwlmin0 = kwlmi / 100.0;
		double kwlmax0 = kwlma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << kwlmin0 << ',' << setprecision(3) << kwlmax0 << ")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile << _T("  ��ħ��:") << endl;
		outFile << "    type: attribute" << endl;
		outFile << "    data:" << endl;
		outFile << _T("      id: ��ħ��") << endl;
		int kmfmi = stoi(kmfmin);
		int kmfma = stoi(kmfmax);
		double kmfmin0 = kmfmi / 100.0;
		double kmfmax0 = kmfma / 100.0;
		outFile << "      min: \'random(" << setprecision(3) << kmfmin0 << ','<< setprecision(3) << kmfmax0<<")\'" << endl;
		outFile << "      max: {min}" << endl;
		outFile << "      float: 0.0" << endl;
		outFile << "      sign: true" << endl;
		outFile << "      display:" << endl;
		outFile << _T("      - \'&7[&b��������&7] &b{attribute.name}: &f{attribute.value}\'") << endl;

		outFile.close();

		outFile2 << "drops:" << endl;
		outFile2 << _T("- ��ͨ_")<< i+1<<_T("�������") << endl;
		outFile2 << _T("health: \'{att.��������ֵ}\'") << endl;
		outFile2 << "entry:" << endl;
		outFile2 << "  basic: "<<string2wstring(name)<<_T("��������") << endl;
		outFile2 << "damage-types:" << endl;
		outFile2 << "  player:" << endl;
		outFile2 << "    mmskill: {}" << endl;
		outFile2 << "    skillapi: {}" << endl;
		outFile2 << "    damage:" << endl;
		outFile2 << _T("      �����˺�: true") << endl;
		outFile2 << "    projectile:" << endl;
		outFile2 << "      arrow:" << endl;
		outFile2 <<    "        damage:" << endl;
		outFile2 << _T("          �����˺�: true") << endl;
		outFile2 << "  mobs:" << endl;
		outFile2 << "    mmskill: {}" << endl;
		outFile2 << "    skillapi: {}" << endl;
		outFile2 << "    damage:" << endl;
		outFile2 << _T("      �����˺�: true") << endl;
		outFile2 << "    projectile:" << endl;
		outFile2 << "      arrow:" << endl;
		outFile2 << "        damage:" << endl;
		outFile2 << _T("          �����˺�: true") << endl;
		outFile2 << "fight-formula:" << endl;
		outFile2 << "  player:" << endl;
		outFile2 << "    mmskill: {}" << endl;
		outFile2 << "    skillapi: {}" << endl;
		outFile2 << "    damage:" << endl;
		outFile2 << _T("      �����˺�:") << endl;
		outFile2 << "        damage:" << endl;
		outFile2 << _T("          hit: '%papi_c:�˺�.����.�ִ���.����%'") << endl;
		outFile2 << _T("          value: '%papi_c:�˺�.����.�ִ���.�����˺�%'") << endl;
		outFile2 << "    projectile:" << endl;
		outFile2 << "      arrow:" << endl;
		outFile2 << "        damage:" << endl;
		outFile2 << _T("      �����˺�:") << endl;
		outFile2 << "        damage:" << endl;
		outFile2 << _T("          hit: '%papi_c:�˺�.����.�ִ���.����%'") << endl;
		outFile2 << _T("          value: '%papi_c:�˺�.����.�ִ���.�����˺�%'") << endl;
		outFile2 << "  mob:" << endl;
		outFile2 << "    mmskill: {}" << endl;
		outFile2 << "    skillapi: {}" << endl;
		outFile2 << "    damage:" << endl;
		outFile2 << _T("      �����˺�:") << endl;
		outFile2 << "        damage:" << endl;
		outFile2 << _T("          hit: '%papi_c:�˺�.����.�ִ���.����%'") << endl;
		outFile2 << _T("          value: '%papi_c:�˺�.����.�ִ���.�����˺�%'") << endl;
		outFile2 << "    projectile:" << endl;
		outFile2 << "      arrow:" << endl;
		outFile2 <<    "        damage:" << endl;
		outFile2 << _T("          �����˺�:") << endl;
		outFile2 <<    "            damage:" << endl;
		outFile2 << _T("              hit: '%papi_c:�˺�.����.�ִ���.����%'") << endl;
		outFile2 << _T("              value: '%papi_c:�˺�.����.�ִ���.�����˺�%'") << endl;
		outFile2.close();
		getline(inFile, line);
		i++;
	}
	mobdata.close();
	inFile.close();
}
