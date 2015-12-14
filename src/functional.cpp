#include <gur.hpp>
#include <sstream>

template<typename T>
std::string chars_of_type(const std::string &str, T method)
{
	gur::Word word = (gur::Word(str).*method)();

	std::string return_str("");
	for (auto &c : word)
	{
		return_str += c.str();
	}

	return return_str;
}

namespace gur
{
	std::string letters(const std::string &str)
	{
		return chars_of_type(str, &Word::letters);
	}

	const char* letters(const char* const &str)
	{
		return letters(std::string(str)).c_str();
	}

	std::string accents(const std::string &str)
	{
		return chars_of_type(str, &Word::accents);
	}

	const char* accents(const char* const &str)
	{
		return accents(std::string(str)).c_str();
	}

	std::string puncs(const std::string &str)
	{
		return chars_of_type(str, &Word::punctuations);
	}

	const char* puncs(const char* const &str)
	{
		return puncs(std::string(str)).c_str();
	}

	std::string digits(const std::string &str)
	{
		return chars_of_type(str, &Word::digits);
	}

	const char* digits(const char* const &str)
	{
		return digits(std::string(str)).c_str();
	}

	std::string symbols(const std::string &str)
	{
		return chars_of_type(str, &Word::symbols);
	}

	const char* symbols(const char* const &str)
	{
		return symbols(std::string(str)).c_str();
	}

	std::string comp(const std::string &str)
	{
		return chars_of_type(str, &Word::composition);
	}

	const char* comp(const char* const &str)
	{
		return comp(std::string(str)).c_str();
	}

	std::string clobber(const std::string &str)
	{
		gur::Word word(str);
		std::ostringstream oss;
		oss << word;

		return oss.str();
	}

	const char* clobber(const char* const &str)
	{
		return clobber(std::string(str)).c_str();
	}

	std::string unclobber(const std::string &str)
	{
		gur::Word word(str);
		std::ostringstream oss(std::ostringstream::ate);

		for (auto &c : word)
		{
			oss << c;
		}

		return oss.str();
	}

	const char* unclobber(const char* const &str)
	{
		return unclobber(std::string(str)).c_str();
	}
}
