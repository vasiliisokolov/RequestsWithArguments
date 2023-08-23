#include "RequestsWithArguments.h"

class Upload
{
	cpr::Response r;
	
	std::map<std::string, std::string> arguments;

public:

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
		std::cout << "Post!" << std::endl;
		std::map<std::string, std::string>::iterator it;
		for (it = arguments.begin(); it != arguments.end(); it++)
		{
			r = cpr::Post(cpr::Url{"http://httpbin.org/post"}, cpr::Payload{{it->first, it-second}});
		}
		out();
	}

	void out()
	{
		std::cout << r.text << std::endl;
	}

};
int main()
{
	std::string input1 = "";
	std::string input2 = "";

	Upload upl;
	
	while (input1 != "post" || input1 != "get")
	{
		std::cout << "Enter the arguments: ";
		std::cin >> input1 >> input2;
		upl.setArguments(input1, input2);
	}
	
	if (input1 == "get")
	{
		upl.getCPR();
	}
	else if (input1 == "post")
	{
		upl.postCPR();
	}
	
}
