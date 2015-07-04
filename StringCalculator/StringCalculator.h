// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the STRINGCALCULATOR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// STRINGCALCULATOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef STRINGCALCULATOR_EXPORTS
#define STRINGCALCULATOR_API __declspec(dllexport)
#else
#define STRINGCALCULATOR_API __declspec(dllimport)
#endif
#include <string>
#include <vector>

#define STRING_REGEX ",|\n"

// This class is exported from the StringCalculator.dll
class STRINGCALCULATOR_API CStringCalculator {
public:
	static int calc(const std::string s);
private:
	static std::vector<int> splitToInt(const std::string &s);
	static void CStringCalculator::throwError(const std::vector<int> &v);
};