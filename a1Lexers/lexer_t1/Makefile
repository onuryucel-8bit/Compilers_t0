cppVersion = -std=c++20
compilerType = g++

cppFiles = Source.cpp \
		Lexer.cpp
		

includeFiles = -I..\LibsLocal\magic_enum\*.hpp

run:
	$(compilerType) $(cppVersion) $(cppFiles) $(includeFiles) -o lexer.exe