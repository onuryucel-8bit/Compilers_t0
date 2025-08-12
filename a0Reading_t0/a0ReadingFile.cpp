#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<optional>

std::string program;

std::optional<std::string> readFile()
{
	std::fstream file("program.txt");
	
	if (!file.is_open())
	{
		std::cout << "ERROR:: couldnt open the file\n";
		return std::nullopt;
	}

	std::stringstream ss;

	ss << file.rdbuf();

	return ss.str();
}


int main()
{
	std::optional<std::string> program = readFile();
	if (program.has_value())
	{
		std::cout << program.value() << "\n";
	}
}