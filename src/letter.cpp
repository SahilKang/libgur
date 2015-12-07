/******************************************************************************
 * Copyright (C) 2015 Sahil Kang <sahil.kang@asilaycomputing.com>
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
#include <utility.hpp>
#include <string>

namespace gur
{
	Letter::Letter() : Character() {}

	Letter::Letter(const Character &c) : Character(c) {}

	Letter::Letter(const std::string &c) : Character(c) {}

	Letter::Letter(std::string &&c) : Character(std::move(c)) {}

	Letter::Letter(const char* const &c) : Character(c) {}

	const std::array<const char* const, 35> Letter::LETTERS
	{
		gur::A1, gur::A2, gur::A3, gur::A4, gur::A5,
		gur::B1, gur::B2, gur::B3, gur::B4, gur::B5,
		gur::C1, gur::C2, gur::C3, gur::C4, gur::C5,
		gur::D1, gur::D2, gur::D3, gur::D4, gur::D5,
		gur::E1, gur::E2, gur::E3, gur::E4, gur::E5,
		gur::F1, gur::F2, gur::F3, gur::F4, gur::F5,
		gur::G1, gur::G2, gur::G3, gur::G4, gur::G5
	};

	bool Letter::is_valid(const char* const &c)
	{
		return util::contains(Letter::LETTERS, c);
	}

	bool Letter::is_valid(const std::string &s)
	{
		return Letter::is_valid(s.c_str());
	}

	bool Letter::is_valid() const
	{
		return Letter::is_valid(this->character);
	}

	bool operator < (const Letter &lhs, const Letter &rhs)
	{
		return util::compare(Letter::LETTERS, lhs.character.c_str(),
			rhs.character.c_str(),
			[] (const decltype(Letter::LETTERS)::iterator &lhs_i,
			const decltype(Letter::LETTERS)::iterator &rhs_i)
				-> bool
			{ return lhs_i < rhs_i; });
	}

	bool operator > (const Letter &lhs, const Letter &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Letter &lhs, const Letter &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Letter &lhs, const Letter &rhs)
	{
		return !(lhs < rhs);
	}
}

namespace std
{
	template<>
	struct hash<gur::Letter>
	{
		typedef gur::Letter argument_type;
		typedef std::size_t result_type;

		result_type operator ()(argument_type const &s) const
		{
			std::hash<std::string> h;
			return h(s.str());
		}
	};
}
