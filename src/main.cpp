#include "stdafx.h"

std::shared_ptr<PLH::BreakPointHook> bpHook;

NOINLINE int hookMe() {
	volatile int i = 0;
	i += 1;
	i += 2;
	return i;
}

NOINLINE int hookMeCallback() {
	auto protObj = bpHook->getProtectionObject();
	volatile int i = 0;
	i += 1;

	return hookMe();
}

int main(int, const char*[])
{
	bpHook = std::make_shared<PLH::BreakPointHook>(reinterpret_cast<char*>(&hookMe), reinterpret_cast<char*>(&hookMeCallback));

	if (!bpHook->hook())
	{
		std::cout << "[!] hook failed" << std::endl;
		return 1;
	}

	std::cout << "[+] calling hooked fn" << std::endl;
	const int result = hookMe();

	if (result == 3) {
		std::cout << "[+] test succeeded" << std::endl;
	}

	bpHook->unHook();
	getchar();

	return 0;
}
