#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

std::string readFile()
{
	std::fstream file("program.txt");
	
	if (!file.is_open())
	{
		std::cout << "ERROR:: couldnt open the file\n";
		return "";
	}

	std::stringstream ss;

	ss << file.rdbuf();

	return ss.str();
}


int main()
{
	std::string program = readFile();
		
	std::cout << program << "\n";
	
}