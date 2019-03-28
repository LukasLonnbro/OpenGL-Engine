#pragma once

#include <vector>
#include <string>

constexpr auto FATALERROR = 1;
constexpr auto NONFATALERROR = 2;

class errorhandler
{
public:
	errorhandler();
	~errorhandler();

	static void addError(const void* error, const int type, const char* beautifier = "");

	inline static const std::vector<const void*> getErrors() { return errorList; }

	static void clear() { errorhandler::errorList.clear(); errorhandler::errorImpact = 0; }

	inline static int getErrorImpact() { return errorhandler::errorImpact; }

private:
	static std::vector<const void*> errorList;
	static int errorImpact;
};

