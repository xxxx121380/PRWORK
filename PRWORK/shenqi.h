#pragma once
#include "CommonFunction.h"
using namespace std;
void outshenqiCZ(string path);

void outshenqiCZ(string path)
{
	path.append("\\暗金\\");
	string line;
	ifstream in("暗金数据.txt", ios::in);
	//读入原始词缀
	if (!in)
	{
		exit(-1);
	}
	locale china("zh_CN.UTF-8");
	wofstream outFile("shenqiinfo.txt", ios::out);
	outFile.imbue(china);
	while (!in.eof())
	{
		string bigtype;
		string typenum;
		in >> bigtype;
		in >> typenum;
		int typenum0 = atoi(typenum.c_str());
		outFile << string2wstring(bigtype) << endl;
		outFile << string2wstring(typenum) << endl;
		for (int i = 0; i < typenum0; i++)
		{
			string name, type, level,introduce;
			cizhui tmphz;
			vector<cizhui> sq;//后缀
			int sum;
			in >> name;
			in >> type;
			in >> level;
			in >> sum;
			cout << name<<endl;
			outFile << string2wstring(name) << ',';
			outFile << string2wstring(level) << ',';
			outFile << string2wstring(type) << endl;

			string title = path;
			title.append("词缀\\");
			title.append(name.c_str());
			title.append("词缀.yml");
			locale china("zh_CN.UTF-8");
			wofstream out(title);
			out.imbue(china);
			out << "random-amount: \'" << sum << '\'' << endl;
			out << "entries:" << endl;
			for (int i = 0; i < sum; i++)
			{
				in >> line;
				stringstream ss(line);
				string tmp, a1, a2, a3, a4;
				getline(ss, tmp, ',');
				tmphz.setname(tmp);
				getline(ss, tmp, ',');
				//cout << tmp << endl;
				tmphz.setcolor(tmp.c_str()[0]);
				getline(ss, tmp, ',');
				tmphz.setsi(bool(atoi(tmp.c_str())));
				getline(ss, a1, ',');
				getline(ss, a2, ',');
				getline(ss, a3, ',');
				getline(ss, a4, ',');
				tmphz.setsj(a1, a2, a3, a4);

				out << _T("  词缀");
				out << i + 1;
				out << ":" << endl;
				out << "    type: attribute" << endl;
				out << "    data:" << endl;
				out << "      id: ";
				out << string2wstring(tmphz.getname()) << endl;
				bool iffloat = false, sign = false;
				double floatmin, floatmax, floatmin2, floatmax2;
				iffloat = tmphz.getfloat();
				sign = tmphz.getsign();
				floatmin = tmphz.getfloatmin();
				floatmax = tmphz.getfloatmax();
				floatmin2 = tmphz.getfloatmin2();
				floatmax2 = tmphz.getfloatmax2();
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
				out << "      - \'&" << tmphz.getcolor() << _T("◈ [固有词缀]");
				out << "  &";
				out << tmphz.getcolor();
				out << string2wstring(tmphz.getname());
				out << "&f {attribute.streng.summary}\'" << endl;
				out << "      order: " <<sum-i<< endl;
				out << "      weight: 1" << endl;
				out << "      maximum : 1" << endl;
			}
			out.close();
		}
	}
}
void outshenqiequip(string path);
void outshenqiequip(string path)
{

}
