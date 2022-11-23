#include <iostream>
#include <map>

using dictionary = std::map<std::string, std::string>;

class word_processor
{
	bool loadingmakro;
	dictionary dict;

public:
	word_processor()
	{
		loadingmakro = false;
	}


	const std::string& replace_string(const std::string& input)//chtěl jsem ji definovat uvnitř process_string, ale ani přes lambdu mi to nešlo (nechtělo se tomu vidět dict)
	{
		const auto i = dict.find(input);
			if (i != dict.end())
			{
				return i->second;
			}
			return input;
	}
	const std::string& process_string(std::string& input)
	{
		 
		input= replace_string(input);
		static std::string indicatorToBe;//can be static cause word_processor is only used to process a file at a time.
		static std::string makrobody;//same here
		if (!loadingmakro)
		{
			if((input[0] == '#')&&(input.length()!=1)&&(std::isalpha(input[1])))
			{//gotta check alnum();
				loadingmakro=true;
				indicatorToBe = input.substr(1);
				input ="";
				return input;
			}
			else return input;
		}
		else{
			if(input=="#")
			{
				dict.insert(indicatorToBe,makrobody);
				loadingmakro=false;
			}
			else
			{
				makrobody+=input;
			}
			input ="";
			return input;
		}
		
	}
};

int main()
{
	
	word_processor wp;
	std::string input;
	while (!std::cin.eof())
	{
		std::cin >> input;
		std::cout <<wp.process_string(input);
	}
}
