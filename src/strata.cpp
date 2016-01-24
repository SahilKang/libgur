/******************************************************************************
 * Copyright (C) 2015, 2016 Sahil Singh Kang <sahil.kang@asilaycomputing.com>
 *
 * This file is part of libgur.
 *
 * libgur is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libgur is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with libgur.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <gur.hpp>
#include <utility.hpp>
#include <set>

static std::vector<std::string> vec(const gur::String &str)
{
	std::vector<std::string> v;
	for (auto &c : str)
	{
		v.push_back(c);
	}

	return v;
}

namespace gur
{
	String letters(const String &str)
	{
		std::vector<std::string> letters;
		util::strata(vec(str),
			std::move(letters),
			(bool (*)(const std::string&))is_letter);

		String output;
		for (auto &c : letters)
		{
			output += c;
		}

		return output;
	}

	std::string letters(const std::string &str)
	{
		return letters(String(str)).str();
	}

	const char* letters(const char* const &str)
	{
		return letters(String(str)).str().c_str();
	}

	String accents(const String &str)
	{
		std::vector<std::string> accents;
		util::strata(vec(str),
			std::move(accents),
			(bool (*)(const std::string&))is_accent);

		String output;
		for (auto &c : accents)
		{
			output += c;
		}

		return output;
	}

	std::string accents(const std::string &str)
	{
		return accents(String(str)).str();
	}

	const char* accents(const char* const &str)
	{
		return accents(String(str)).str().c_str();
	}

	String puncs(const String &str)
	{
		std::vector<std::string> puncs;
		util::strata(vec(str),
			std::move(puncs),
			(bool (*)(const std::string&))is_punc);

		String output;
		for (auto &c : puncs)
		{
			output += c;
		}

		return output;
	}

	std::string puncs(const std::string &str)
	{
		return puncs(String(str)).str();
	}

	const char* puncs(const char* const &str)
	{
		return puncs(String(str)).str().c_str();
	}

	String digits(const String &str)
	{
		std::vector<std::string> digits;
		util::strata(vec(str),
			std::move(digits),
			(bool (*)(const std::string&))is_digit);

		String output;
		for (auto &c : digits)
		{
			output += c;
		}

		return output;
	}

	std::string digits(const std::string &str)
	{
		return digits(String(str)).str();
	}

	const char* digits(const char* const &str)
	{
		return digits(String(str)).str().c_str();
	}

	String symbols(const String &str)
	{
		std::vector<std::string> symbols;
		util::strata(vec(str),
			std::move(symbols),
			(bool (*)(const std::string&))is_symbol);

		String output;
		for (auto &c : symbols)
		{
			output += c;
		}

		return output;
	}

	std::string symbols(const std::string &str)
	{
		return symbols(String(str)).str();
	}

	const char* symbols(const char* const &str)
	{
		return symbols(String(str)).str().c_str();
	}

	String comp(const String &str)
	{
		std::set<std::string> letters;
		std::set<std::string> accents;
		std::set<std::string> puncs;
		std::set<std::string> digits;
		std::set<std::string> symbols;

		util::strata(vec(str),
			std::move(letters),
			std::move(accents),
			std::move(puncs),
			std::move(digits),
			std::move(symbols),
			(bool (*)(const std::string&))is_letter,
			(bool (*)(const std::string&))is_accent,
			(bool (*)(const std::string&))is_punc,
			(bool (*)(const std::string&))is_digit,
			(bool (*)(const std::string&))is_symbol);

		String output;
		for (auto &c : letters)
		{
			output += c;
		}
		for (auto &c : accents)
		{
			output += c;
		}
		for (auto &c : puncs)
		{
			output += c;
		}
		for (auto &c : digits)
		{
			output += c;
		}
		for (auto &c : symbols)
		{
			output += c;
		}

		return output;
	}

	std::string comp(const std::string &str)
	{
		return comp(String(str)).str();
	}

	const char* comp(const char* const &str)
	{
		return comp(String(str)).str().c_str();
	}
}
