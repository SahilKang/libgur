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

struct Pair
{
	Pair(const std::string &f, const std::string &s) :
		first(f), second(s) {}
	std::string first;
	std::string second;
};

bool operator == (const Pair &lhs, const Pair &rhs);
bool operator == (const Pair &lhs, const Pair &rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second;
}

namespace std
{
	template<>
	struct hash<Pair>
	{
		std::size_t operator ()(const Pair &p) const
		{
			std::hash<std::string> hasher;
			return hasher(p.first + p.second);
		}
	};
}

static const std::unordered_map<Pair, std::string>
pair_to_str =
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

static const std::unordered_map<std::string, Pair>
str_to_pair =
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
		for (std::size_t i = 0; i < str.size();)
		{
			if (i != str.size() - 1)
			{
				Pair pair(str[i], str[i + 1]);
				auto found = pair_to_str.find(pair);

				if (found != pair_to_str.end())
				{
					output += found->second;
					i += 2;
				}

				else
				{
					output += str[i];
					++i;
				}
			}

			else
			{
				output += str[i];
				++i;
			}
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
			auto found = str_to_pair.find(c);

			if (found != str_to_pair.end())
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
