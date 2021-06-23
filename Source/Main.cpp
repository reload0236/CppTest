#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <initializer_list>

#include "Tests/Test.h"
#include "Tests/DebugSymbolTest.h"
#include "Tests/AllocatorTest.h"
#include "Tests/RightReferenceTest.h"
#include "Tests/FunctionTest.h"
#include "Tests/UnorderedMapTest.h"


int main()
{
	std::unordered_map<std::string, std::shared_ptr<Test>> testsMap;
	testsMap.insert( {"DebugSymbolTest", std::make_shared<DebugSymbolTest>()} );
	testsMap.insert( {"AllocatorTest", std::make_shared<AllocatorTest>()} );
	testsMap.insert( {"RightReferenceTest", std::make_shared<RightReferenceTest>()} );
	testsMap.insert( {"FunctionTest", std::make_shared<FunctionTest>()} );
	testsMap.insert( {"UnorderedMapTest", std::make_shared<UnorderedMapTest>()} );

	testsMap["UnorderedMapTest"]->Run();

	return 0;
}