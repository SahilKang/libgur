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
#include <cstdint>
#include <utility>
#include <functional>

static std::vector<std::string> utf8_str(const std::string &s) noexcept
{
	std::function<unsigned int(const char&)>
	count_bytes =
		[] (const char &c) -> unsigned int
		{
			unsigned int count(0);
			std::uint8_t mask(0x80);

			while (c & mask)
			{
				++count;
				mask >>= 1;
			}

			return count;
		};

	std::vector<std::string> word;

	for (unsigned int i = 0; i < s.size();)
	{
		unsigned int bytes(count_bytes(s[i]));

		if (bytes == 0)
		{
			word.push_back(s.substr(i, 1));
			++i;
		}

		else
		{
			word.push_back(s.substr(i, bytes));
			i += bytes;
		}
	}

	return word;
}

namespace std
{
	template<>
	struct hash<gur::String>
	{
		std::size_t operator ()(const gur::String &str) const
		{
			std::hash<std::string> hasher;
			return hasher(gur::unclobber(str).str());
		}
	};
}

namespace gur
{
	String::String() : word(0) {}

	String::String(const String &w) : word(w.word) {}

	String::String(String &&w) : word(std::move(w.word)) {}

	String::String(const std::string &s) : word(utf8_str(s)) {}

	String::String(const char* const &s) : word(utf8_str(std::string(s))){}

	size_t String::size() const
	{
		return this->word.size();
	}

	std::string String::str() const
	{
		std::string str("");

		for (auto &s : this->word)
		{
			str += s;
		}

		return str;
	}

	std::vector<std::string>::iterator String::begin()
	{
		return this->word.begin();
	}

	std::vector<std::string>::iterator String::end()
	{
		return this->word.end();
	}

	std::vector<std::string>::const_iterator String::begin() const
	{
		return this->word.begin();
	}

	std::vector<std::string>::const_iterator String::end() const
	{
		return this->word.end();
	}

	std::string& String::operator [] (const std::size_t &i)
	{
		return this->word[i];
	}

	const std::string& String::operator [] (const std::size_t &i) const
	{
		return this->word[i];
	}

	String& String::operator += (const String &w)
	{
		for (auto &c : w)
		{
			this->word.push_back(c);
		}

		return *this;
	}

	String& String::operator += (const std::string &s)
	{
		return *this += String(s);
	}

	String& String::operator += (const char* const &s)
	{
		return *this += String(s);
	}

	String& String::operator = (const String &w)
	{
		if (this != &w)
		{
			String tmp(w);
			std::swap(this->word, tmp.word);
		}

		return *this;
	}

	String& String::operator = (String &&w)
	{
		if (this != &w)
		{
			std::swap(this->word, w.word);
		}

		return *this;
	}

	String& String::operator = (const std::string &s)
	{
		return *this = String(s);
	}

	String& String::operator = (const char* const &s)
	{
		return *this = String(s);
	}

	String::~String() {}

	String operator + (String lhs, const String &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	String operator + (String lhs, const std::string &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	String operator + (String lhs, const char* const &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	bool operator == (const String &lhs, const String &rhs)
	{
		return lhs.word == rhs.word;
	}

	bool operator != (const String &lhs, const String &rhs)
	{
		return !(lhs == rhs);
	}

	bool operator < (const String &lhs, const String &rhs)
	{
		return lhs < rhs;
	}

	bool operator > (const String &lhs, const String &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const String &lhs, const String &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const String &lhs, const String &rhs)
	{
		return !(lhs < rhs);
	}

	std::istream& operator >> (std::istream &in , String &w)
	{
		std::string str("");
		in >> str;

		w = unclobber(str);

		return in;
	}

	std::ostream& operator << (std::ostream &out, const String &w)
	{
		std::string clobbered = clobber(w).str();
		out.write(clobbered.c_str(), clobbered.size());

		return out;
	}
}
