#pragma once
#include <stack>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>
#include <string> 
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int const quadEq = 3;

enum class caseSols { //look!
	zeroSols,
	oneSol,
	twoSols,
	complexSols
};

enum coef {
	A, B, C
};

class Coeffs {
public:
	double* coeff = nullptr;
	int countOfCoeffs = 0;

	Coeffs(int count);

	void parseCoeffs(ifstream& filestream);
	void parseCoeffs(string coeffs);
};

class QuadEq {
public:

	QuadEq();

	void setQuadEq(ifstream& filestream);
	void setQuadEq(string equality);
	string getQuadEq();
	string getQuadEqSol();

	void solveQuadEq();

private:
	Coeffs* abc = nullptr;
	double* solution = nullptr;
	std::complex<double> sol[2];

	double discriminant;

	caseSols checkDiscriminant();
};

struct Letter {
private:
	string quadEq;
	string solution;
	string name;
public:
	string getQuadEq();
	string getSolution();
	string getName();

	void setLetter(string equality, string sol, string studname);
	void printLetter();
};

enum studClassificator {
	studGood = 1,
	studBad,
	studUgly
};

class Student {
private:
	string name;
public:
	Student() {}
	Student(string studname);

	virtual Letter solveEq(QuadEq equality) = 0;
	string getName();
};

class TheGood : virtual public Student {
public:
	TheGood() {}
	TheGood(string& studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class TheBad : virtual public Student {
public:
	TheBad() {}
	TheBad(string& studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class TheUgly : public TheBad, public TheGood {
public:
	TheUgly(string& studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class Teacher { // eeann o?eoaeu
public:

	void StartExam(const char* tasks, vector <Student*> studGroup, stack <Letter>& LetterStack);
	void checkLetter(Letter studLetter, map <string, int>& ReportMap);
	void createReport(stack <Letter> LetterStack, map <string, int>& ReportMap);

	void printReport(map <string, int> ReportMap);
	void printReport(const char* filenameReport, map <string, int> ReportMap);

};

