#include <iostream>
#include <string>
#include <cmath>
#include <vector>

void welcomeScreen();
void checkFormula(std::string &formula);
int calculateFormula(std::vector<std::string> partialFormula);
void setOperatorsPrecedence(std::vector<std::string> &partialFormula);

std::vector<std::string> partialFormula;

int main()
{
	std::string formula;
	
	welcomeScreen();
	std::cout << "Please enter your mathematical formula:\n" << "-> ";
	std::cin >> formula;

	checkFormula(formula);
	
	for (auto x : partialFormula) {
		std::cout << x << std::endl;
	}
	std::cout<<std::endl;

	setOperatorsPrecedence(partialFormula);

	for (auto x : partialFormula) {
		std::cout << x << std::endl;
	}

	welcomeScreen();

	std::cout << "Result: " << calculateFormula(partialFormula) << std::endl;
}

void welcomeScreen()
{
	//system("cls");
	std::cout << "\n\tNOT SO SIMPLE CALCULATOR\n\n" << std::endl;
}

void checkFormula(std::string& formula) {
	
	if (formula.length() == 3) {
		partialFormula.push_back(formula);
		formula.clear();
	}
	else if(formula.find('(') == std::string::npos) {
		partialFormula.push_back(formula.substr(0, 3));
		formula.erase(0, 3);

		while (!formula.empty()) {
			partialFormula.push_back(formula.substr(0, 2));
			formula.erase(0, 2);
		}
	}
	else {
		std::cout << "\nParenteses not implemented yet." << std::endl;
	}
}

int calculateFormula(std::vector<std::string> partialFormula)
{
	int sum{ 0 }, val1{ 0 };                                  // bad idea for calculating, doesn't work yet
	char operand;
	std::string temp;

	for (int i = 0; i < partialFormula.size(); ++i) {

		if (partialFormula.at(i).size() == 3) {
			temp = partialFormula.at(i);
			sum = (int)temp[0];
			operand = temp[1];
			val1 = (int)temp[2];
		}

		val1 = (int)temp[0];
		operand = temp[1];

		switch (operand)
		{
		case '+':
		{
			sum + val1;
			break;
		}
		case '-':
		{
			sum - val1;
			break;
		}
		case '*':
		{
			sum* val1;
			break;
		}
		case '/':
		{
			sum / val1;
			break;
		}
		case '^':
		{
			pow(sum, val1);
			break;
		}
		default:
		{
			break;
		}

		return sum;
		}
	}
}

void setOperatorsPrecedence(std::vector<std::string>& partialFormula)
{
	std::vector<std::string> temp;

	for (int i = 0; i < partialFormula.size(); ++i) {
		if (partialFormula.at(i).find('^') != std::string::npos) {
			temp.push_back(partialFormula.at(i));
		}
	}
	for (int i = 0; i < partialFormula.size(); ++i) {
		if (partialFormula.at(i).find('*') != std::string::npos) {
			temp.push_back(partialFormula.at(i));
		}

	}
	for (int i = 0; i < partialFormula.size(); ++i) {
		if (partialFormula.at(i).find('/') != std::string::npos) {
			temp.push_back(partialFormula.at(i));
		}
	}
	for (int i = 0; i < partialFormula.size(); ++i) {
		if (partialFormula.at(i).find('+') != std::string::npos) {
			temp.push_back(partialFormula.at(i));
		}

	}
	for (int i = 0; i < partialFormula.size(); ++i) {
		if (partialFormula.at(i).find('-') != std::string::npos) {
			temp.push_back(partialFormula.at(i));
		}
	}
	partialFormula = temp;
}