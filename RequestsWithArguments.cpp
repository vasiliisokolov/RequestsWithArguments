#include "RequestsWithArguments.h"

class Upload
{
	cpr::Response r;
	cpr::Payload p;
	std::map<std::string, std::string> arguments;

public:

	void setP()
	{
		std::map<std::string, std::string>::iterator it;
		for (it = arguments.begin(); it != arguments.end(); it++)
		{
			p.Add(cpr::Pair(it->first, it->second));
		}
	}

	void setArguments(std::string key, std::string value)
	{
		arguments.insert(std::make_pair(key, value));
	}

	void getCPR()
	{
		std::cout << "Get!" << std::endl;
		std::string add ="?";
		std::map<std::string, std::string>::iterator it;
		for (it = arguments.begin(); it != arguments.end(); it++)
		{
			if (it != arguments.end())
			{
				add += it->first + "=" + it->second + "&";
			}
			else
			{
				add += it->first + "=" + it->second;
			}
		}
		r = cpr::Get(cpr::Url{"http://httpbin.org/get" + add});
		out();
	}

	void postCPR()
	{
		setP();
		std::cout << "Post!" << std::endl;
		r = cpr::Post(cpr::Url{"http://httpbin.org/post"}, p);
		out();
	}

	void out()
	{
		std::cout << r.text << std::endl;
	}

	void run()
	{

	}

	Upload()
	{
		p.GetContent

	};
		
};
int main()
{
	Upload upl;
	std::cout << "Hello CMake." << std::endl;
	
}
