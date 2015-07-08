// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FIZZBUZZ_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FIZZBUZZ_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FIZZBUZZ_EXPORTS
#define FIZZBUZZ_API __declspec(dllexport)
#else
#define FIZZBUZZ_API __declspec(dllimport)
#endif
#include <string>

// This class is exported from the FizzBuzz.dll
class FIZZBUZZ_API CFizzBuzz {
public:
	CFizzBuzz(void);
	// TODO: add your methods here.
	static std::string FizzBuzz(const int num);
};