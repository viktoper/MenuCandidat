// candidat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class CandidatClass
{
//	static int CountOfCandidat;
public:
	CandidatClass();
	~CandidatClass();
	void setPercentOfVoice(int);
	int  getPercentOfVoice();

private:
	int OrderNum;                // autoincrement
	string CandidatLastName;     // read from file
	string CandidatInitials;     // read from file
	int PercentOfVoice;          // read from file
};

CandidatClass::CandidatClass()
{
	PercentOfVoice = 0;
//	CountOfCandidat = 0;
}

CandidatClass::~CandidatClass()
{
}

void CandidatClass::setPercentOfVoice(int ValueOfPercent)
{
	PercentOfVoice = ValueOfPercent;
}

int CandidatClass::getPercentOfVoice()
{
	return PercentOfVoice;
}

int main()
{
	ifstream fileCandidat("candidat.txt");
	string str;

	CandidatClass *myCandidat = new CandidatClass();

	cout << "=== Start program CANDIDAT ===" << endl;

	// read file
	if (!fileCandidat.bad())
	{
		fileCandidat._Seekbeg;
		// Обработка строки str
		while (fileCandidat) 
		    {
			getline(fileCandidat,str);
			cout << str.substr(0, str.find('#')) << " ";
			cout << str.substr(str.find('#')+1, str.find('%')-str.find('#')-1) << " ";
			cout << str.substr(str.find('%')+1, 2) << endl;
		    }
  	    fileCandidat.close();
	}
	else
	{
		cout << endl << "ERROR: file 'candidat.txt' not found!" << endl;
		return 1;
	}


//	cout << "CountOfCandidat" << myCandidat->CountOfCandidat << endl;
	
	cout << "PercentOfVoice=" << myCandidat->getPercentOfVoice() << endl;
	myCandidat->setPercentOfVoice(20);
	cout << "PercentOfVoice=" << myCandidat->getPercentOfVoice() << endl;

	myCandidat->~CandidatClass();
    return 0;
}

