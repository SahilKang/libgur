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

#ifndef GUR_H
#define GUR_H

#include <iostream>
#include <string>
#include <vector>

namespace gur
{
	class String {
	public:
		String();
		String(const String &w);
		String(String &&w);
		String(const std::string &s);
		String(const char* const &s);

		std::size_t size() const;
		std::string str() const;
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();
		std::vector<std::string>::const_iterator begin() const;
		std::vector<std::string>::const_iterator end() const;

		std::string& operator [] (const std::size_t &i);
		const std::string& operator [] (const std::size_t &i) const;
		String& operator += (const String &w);
		String& operator += (const std::string &s);
		String& operator += (const char* const &s);

		String& operator = (const String &w);
		String& operator = (String &&w);
		String& operator = (const std::string &s);
		String& operator = (const char* const &s);

		~String();
	private:
		std::vector<std::string> word;

		friend std::istream& operator >> (std::istream &in, String &w);
		friend std::ostream& operator << (std::ostream &out,
			const String &w);
		friend bool operator == (const String &lhs, const String &rhs);
		friend bool operator < (const String &lhs, const String &rhs);
	};

	std::istream& operator >> (std::istream &in, String &w);
	std::ostream& operator << (std::ostream &out, const String &w);
	String operator + (String lhs, const String &rhs);
	String operator + (String lhs, const std::string &rhs);
	String operator + (String lhs, const char* const &rhs);
	bool operator == (const String &lhs, const String &rhs);
	bool operator != (const String &lhs, const String &rhs);
	bool operator < (const String &lhs, const String &rhs);
	bool operator > (const String &lhs, const String &rhs);
	bool operator <= (const String &lhs, const String &rhs);
	bool operator >= (const String &lhs, const String &rhs);

	String letters(const String &str);
	std::string letters(const std::string &str);
	const char* letters(const char* const &str);

	String accents(const String &str);
	std::string accents(const std::string &str);
	const char* accents(const char* const &str);

	String puncs(const String &str);
	std::string puncs(const std::string &str);
	const char* puncs(const char* const &str);

	String digits(const String &str);
	std::string digits(const std::string &str);
	const char* digits(const char* const &str);

	String symbols(const String &str);
	std::string symbols(const std::string &str);
	const char* symbols(const char* const &str);

	String comp(const String &str);
	std::string comp(const std::string &str);
	const char* comp(const char* const &str);

	String clobber(const String &str);
	std::string clobber(const std::string &str);
	const char* clobber(const char* const &str);

	String unclobber(const String &str);
	std::string unclobber(const std::string &str);
	const char* unclobber(const char* const &str);

	bool is_letter(const String &str);
	bool is_letter(const std::string &str);
	bool is_letter(const char* const &str);

	bool is_accent(const String &str);
	bool is_accent(const std::string &str);
	bool is_accent(const char* const &str);

	bool is_punc(const String &str);
	bool is_punc(const std::string &str);
	bool is_punc(const char* const &str);

	bool is_digit(const String &str);
	bool is_digit(const std::string &str);
	bool is_digit(const char* const &str);

	bool is_symbol(const String &str);
	bool is_symbol(const std::string &str);
	bool is_symbol(const char* const &str);
}

#endif
