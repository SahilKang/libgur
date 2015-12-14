#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <string>

namespace gur
{
	std::string letters(const std::string &str);
	const char* letters(const char* const &str);

	std::string accents(const std::string &str);
	const char* accents(const char* const &str);

	std::string puncs(const std::string &str);
	const char* puncs(const char* const &str);

	std::string digits(const std::string &str);
	const char* digits(const char* const &str);

	std::string symbols(const std::string &str);
	const char* symbols(const char* const &str);

	std::string comp(const std::string &str);
	const char* comp(const char* const &str);

	std::string clobber(const std::string &str);
	const char* clobber(const char* const &str);

	std::string unclobber(const std::string &str);
	const char* unclobber(const char* const &str);


}

#endif
