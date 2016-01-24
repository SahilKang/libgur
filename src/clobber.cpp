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
#include <gurmukhi.hpp>
#include <unordered_map>
#include <cstring>

struct Pair
{
	Pair(const char* const f, const char* const s) : first(f), second(s) {}
	const char* const first;
	const char* const second;
};

bool operator == (const Pair &lhs, const Pair &rhs);
bool operator == (const Pair &lhs, const Pair &rhs)
{
	return (std::strcmp(lhs.first, rhs.first) == 0
		&& std::strcmp(lhs.second, rhs.second) == 0);
}

namespace std
{
	template<>
	struct hash<Pair>
	{
		std::size_t operator ()(const Pair &p) const
		{
			std::string s(p.first);
			s += p.second;

			std::hash<std::string> hasher;
			return hasher(s);
		}
	};

	template<>
	struct hash<const char* const>
	{
		std::size_t operator ()(const char* const &c) const
		{
			std::hash<std::string> hasher;
			return hasher(std::string(c));
		}
	};
}

static const std::unordered_map<Pair, const char* const>
pair_to_char =
{
	{ Pair(gur::A1, gur::I1), gur::M5 },
	{ Pair(gur::A1, gur::I2), gur::N1 },
	{ Pair(gur::A1, gur::N4), gur::N4 },
	{ Pair(gur::A2, gur::H3), gur::M2 },
	{ Pair(gur::A2, gur::I4), gur::N3 },
	{ Pair(gur::A2, gur::J1), gur::N5 },
	{ Pair(gur::A3, gur::H4), gur::M3 },
	{ Pair(gur::A3, gur::H5), gur::M4 },
	{ Pair(gur::A3, gur::I3), gur::N2 },
	{ Pair(gur::G3, gur::H2), gur::O3 },
	{ Pair(gur::A4, gur::H2), gur::O4 },
	{ Pair(gur::B2, gur::H2), gur::P1 },
	{ Pair(gur::B3, gur::H2), gur::P2 },
	{ Pair(gur::C3, gur::H2), gur::P3 },
	{ Pair(gur::F2, gur::H2), gur::P4 }
};

static const std::unordered_map<const char* const, Pair>
char_to_pair =
{
	{ gur::M5, Pair(gur::A1, gur::I1) },
	{ gur::N1, Pair(gur::A1, gur::I2) },
	{ gur::N4, Pair(gur::A1, gur::N4) },
	{ gur::M2, Pair(gur::A2, gur::H3) },
	{ gur::N3, Pair(gur::A2, gur::I4) },
	{ gur::N5, Pair(gur::A2, gur::J1) },
	{ gur::M3, Pair(gur::A3, gur::H4) },
	{ gur::M4, Pair(gur::A3, gur::H5) },
	{ gur::N2, Pair(gur::A3, gur::I3) },
	{ gur::O3, Pair(gur::G3, gur::H2) },
	{ gur::O4, Pair(gur::A4, gur::H2) },
	{ gur::P1, Pair(gur::B2, gur::H2) },
	{ gur::P2, Pair(gur::B3, gur::H2) },
	{ gur::P3, Pair(gur::C3, gur::H2) },
	{ gur::P4, Pair(gur::F2, gur::H2) }
};

namespace gur
{
	String clobber(const String &str)
	{
		String output;
		for (unsigned int i = 0; i < str.size() - 1; i += 2)
		{
			Pair pair(str[i].c_str(), str[i + 1].c_str());
			auto found = pair_to_char.find(pair);

			if (found != pair_to_char.end())
			{
				output += found->second;
			}

			else
			{
				output += str[i];
				output += str[i + 1];
			}
		}

		if (str.size() % 2 == 1)
		{
			output += str[str.size() - 1];
		}

		return output;
	}

	std::string clobber(const std::string &str)
	{
		return clobber(String(str)).str();
	}

	const char* clobber(const char* const &str)
	{
		return clobber(String(str)).str().c_str();
	}

	String unclobber(const String &str)
	{
		String output;
		for (auto &c : str)
		{
			auto found = char_to_pair.find(c.c_str());

			if (found != char_to_pair.end())
			{
				output += found->second.first;
				output += found->second.second;
			}

			else
			{
				output += c;
			}
		}

		return output;
	}

	std::string unclobber(const std::string &str)
	{
		return unclobber(String(str)).str();
	}

	const char* unclobber(const char* const &str)
	{
		return unclobber(String(str)).str().c_str();
	}
}
