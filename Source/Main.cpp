#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <initializer_list>

#include "../Include/Version.h"
#include "../Include/Tests/Test.h"
#include "../Include/Tests/DebugSymbolTest.h"
#include "../Include/Tests/AllocatorTest.h"
#include "../Include/Tests/RightReferenceTest.h"
#include "../Include/Tests/FunctionTest.h"
#include "../Include/Tests/UnorderedMapTest.h"


int main()
{
	std::cout << CPP_TESTS_VERSION << std::endl;

	std::unordered_map<std::string, std::shared_ptr<Test>> testsMap;
	testsMap.insert( {"DebugSymbolTest", std::make_shared<DebugSymbolTest>()} );
	testsMap.insert( {"AllocatorTest", std::make_shared<AllocatorTest>()} );
	testsMap.insert( {"RightReferenceTest", std::make_shared<RightReferenceTest>()} );
	testsMap.insert( {"FunctionTest", std::make_shared<FunctionTest>()} );
	testsMap.insert( {"UnorderedMapTest", std::make_shared<UnorderedMapTest>()} );

	// testsMap["UnorderedMapTest"]->Run();

	return 0;
}