#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using dictionary = std::map<std::string, std::string>;

class word_processor
{
	bool loadingmakro;
	dictionary dict;
public:
	bool errorflag;
	word_processor()
	{
		loadingmakro = false;
		errorflag = false;
	}
	void IO(int argc,char ** argv)
	{
		if(!isstringalnum(argv[1])){errorflag= true;return;}
		std::string replacee;
		for(int i =2;i<argc-1;i++)
		{
			replacee+= argv[i];
			replacee+=" ";
		}
		replacee+=argv[argc-1];//Lazy way to avoid trailing space
		dict.insert({std::string(argv[1]),replacee});
		
	}
	static bool isntalnum(const char c){return !isalnum(c);} //IDE told me that (!isalnum) was going to always return true so I made my own function just in case
	static bool isstringalnum(const std::string& input)
	{
		return std::find_if(input.begin()+1, input.end(), isntalnum) == input.cend();
	}

	const std::string& replace_string(const std::string& input)//I wanted to define this inside process_string, but it didn't work using lambda (wasn't able to see dict no matter what offerings I sacrificed)
	{
		const auto i = dict.find(input);
			if (i != dict.end())
			{
				return i->second;
			}
			return input;
	}
	const std::string& process_string(std::string& input,const std::string del)
	{
		 
		input= replace_string(input);
		static std::string indicator_to_be;//can be static because word_processor is only used to process a file at a time.
		if (!loadingmakro)
		{
			if(input[0] == '#')
			{
				if(input.length()>1){
					if((!isstringalnum(input)&&(!std::isalpha(input[1])))){errorflag= true;return input="Error";}}
				loadingmakro=true;
				indicator_to_be = input.substr(1);
				return input="";
			}
			else return input+=del; //I keep the else for clarity despite it being redundant (just the keyword not the return)
		}
		else{
			static std::string makrobody;
			if(input=="#")
			{
				if (indicator_to_be!="")
					dict.insert({indicator_to_be,makrobody});
				else return input="Error";
				makrobody = "";
				loadingmakro=false;
				input=del;
			}
			else
			{
				if(input[0]=='#'){errorflag= true;return input="Error";}//think this one may be necessary. If not just check if none tries to declare makro inside
				makrobody+=input+del;
				input="";
			}
			return input;
		}
		
	}
};

int main(int argc,char ** argv)
{
	
	word_processor wp;
	if(argc>1)wp.IO(argc,argv);
	if(wp.errorflag)return 0;
	std::string input;
	std::string  delimiter;
	while (!std::cin.eof())
	{
		std::cin >> input;
		while (isspace(std::cin.peek())){
			if(std::cin.peek()=='\r'){std::cin.get();}
			delimiter+= std::cin.get();}
		std::cout <<wp.process_string(input,delimiter);
		delimiter="";
		if(wp.errorflag)break;//To truly separate IO from the logic one could just make it so that while the error flag is on the process_string returns just empty strings however this is faster so I take that sacrifice
	}
}
