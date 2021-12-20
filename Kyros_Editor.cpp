///////////////////////
//FREE LICENSE//
///////////////////////

////////////////////////
//		      //
//    	KYROS         //
//   LIBIL2CPP EDITOR //
//	   BY XYRIX   //
//		      //
////////////////////////

/*
—-——————-———————-—-—————--———
BETA VERSION
——-——-————-———--—————-———-———
*/

//%========================%
//% POWERED BY NIKITA XYRIX%
//%========================%

//! https://t.me/zxcminimalized
//! https://vk.com/xyrix
//! https://github.com/sodasleeping
//! https://pastebin.com/u/Xyrix

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;
void clearCout(bool hide)
{
	if(hide == false)
	{
	#ifdef _WIN32
	system("cls");
	#endif
	#ifdef linux
	system("clear");
	#endif
	#ifdef __ANDROID_API__
	system("clear");
	#endif
	}
}
int main()
{
	cout << "# > Kyros libil2cpp Editor by Xyr1x #" << endl << endl << "https://github.com/sodasleeping\nhttps://t.me/zxcminimalized" << endl << endl;
	sleep(1);
	clearCout(false);
	string path;
	cout << "libil2cpp.so path: ";
	cin >> path;
	bool contin = true;
	if(path.find("libil2cpp.so") == -1)
	{

		string yn;
		cout << endl << "WARNING! Your input don't contains libil2cpp.so name in own name. Continue? (y/n): ";
		cin >> yn;
		if(yn == "y")
		{
			contin = true;
			cout << "Ok" << endl;
		}
		else
		{
			contin = false;
		}
	}
	if(contin == true)
	{
		int mode;
		clearCout(false);
		cout << endl << "Modes:\n1 - Search by HEX\n2 - Search by offset\n3 - Edit hex by offset" << endl << endl;
		cout << "SELECT MODE > ";
		cin >> mode;
		if(mode == 1)
		{
			clearCout(false);
			cout << "Hex code to search in file: ";
			string cut;
			cin >> cut;
			int n = cut.length();
			char symb[n + 1];
			strcpy(symb, cut.c_str());
			FILE* fileopen;
			fileopen = fopen(path.c_str(), "rb");
			fseek(fileopen, 0, SEEK_END);
			const int size = ftell(fileopen);
			fseek(fileopen, 0, SEEK_SET);
			if(size < 16)
			{
				cout << "ERROR! File size is too low. This can cause unnecessary insertions of code from places that do not exist." << endl << endl;
				sleep(2);
			exit(-1);
			}
			clearCout(true);
			unsigned char buffs[size];
			
			fread(&buffs, sizeof(buffs), 1, fileopen);
			string result;
			stringstream h;
			string realhex;
			stringstream forrealhex;
			vector<unsigned int> editHex = {};
			vector<unsigned int> fileHex = {};
			for(int i = 0; i < size; i++)
			{
				if(i % 2 == 0)
				h << " ";
				h << uppercase << hex << (int)buffs[i];
			fileHex.push_back(buffs[i]);
			forrealhex << hex << (int)buffs[i];
			}
			clearCout(true);
			result = h.str().erase(0, 1);
			realhex = forrealhex.str();
			transform(cut.begin(), cut.end(), cut.begin(), ::toupper);
			if(result.find(cut) == -1)
			{
				cout << "ERROR! File don't contains this hex in own hex. Exiting..." << endl;
				sleep(2);
				exit(-1);
			}
			else
			{
			cout << "HEX FOUND!\n\n";
			size_t hexpos = result.find(cut);
			cout << realhex[hexpos-2];
			cout << realhex[hexpos-1];
			for(int i = 0; i < 16; i++)
			cout << realhex[hexpos+i];
			}
			fclose(fileopen);
		}
		if(mode == 2)
		{
			// NOTHING
		}
		if(mode == 3)
		{
			// NOTHING
		}
		if(mode != 1 && mode != 2 && mode != 3)
		{
			clearCout(true);
			exit(-1);
		}
	}
	#ifdef _WIN32
	system("pause");
	#endif
	return 0;
}
