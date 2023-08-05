#include "RequestsWithArguments.h"

class Upload
{
	cpr::Response r;
	cpr::Payload p;
	std::map<std::string, std::string> arguments;

public:

	void setP(std::string key, std::string value)
	{
		p.Add(cpr::Pair(key, value));
	}

	void setArguments(std::string key, std::string value)
	{
		arguments.insert(std::make_pair(key, value));
	}

	void getCPR()
	{
		std::cout << "Get!" << std::endl;
		r = cpr::Get(cpr::Url{"http://httpbin.org/get"});
	}

	void postCPR()
	{
		std::cout << "Post!" << std::endl;
		r = cpr::Post(cpr::Url{"http://httpbin.org/post"}, p);
	}

	void out()
	{
		std::cout << r.text << std::endl;
	}

	void run()
	{

	}
};
int main()
{
	std::cout << "Hello CMake." << std::endl;
	
}
