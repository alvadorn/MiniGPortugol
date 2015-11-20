#ifndef __SYMBOLS_TABLE__
#define __SYMBOLS_TABLE__

#include <string>

class SymbolRow {
private:
	std::string lexem;
public:
	SymbolRow(std::string);
	~SymbolRow();
};

class SymbolsTable {
private:
	std::vector<SymbolRow> rows;
public:
	SymbolsTable();
	~SymbolsTable();

};

#endif // __SYMBOLS_TABLE__