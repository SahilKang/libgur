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

namespace gur
{
	Digit::Digit() : Character() {}

	Digit::Digit(const Character &c) : Character(c) {}

	Digit::Digit(const std::string &c) : Character(c) {}

	Digit::Digit(std::string &&c) : Character(std::move(c)) {}

	Digit::Digit(const char* const &c) : Character(c) {}

	const std::array<const char* const, 10> Digit::DIGITS
	{
		gur::K1, gur::K2, gur::K3, gur::K4, gur::K5,
		gur::L1, gur::L2, gur::L3, gur::L4, gur::L5
	};

	bool Digit::is_valid(const char* const &c)
	{
		return util::contains(Digit::DIGITS, c);
	}

	bool Digit::is_valid(const std::string &s)
	{
		return Digit::is_valid(s.c_str());
	}

	bool Digit::is_valid() const
	{
		return Digit::is_valid(this->character);
	}

	bool operator < (const Digit &lhs, const Digit &rhs)
	{
		return util::compare(Digit::DIGITS, lhs.character.c_str(),
			rhs.character.c_str(),
			[] (const decltype(Digit::DIGITS)::iterator &lhs_i,
			const decltype(Digit::DIGITS)::iterator &rhs_i) -> bool
			{ return lhs_i < rhs_i; });
	}

	bool operator > (const Digit &lhs, const Digit &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Digit &lhs, const Digit &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Digit &lhs, const Digit &rhs)
	{
		return !(lhs < rhs);
	}
}

namespace std
{
	template<>
	struct hash<gur::Digit>
	{
		typedef gur::Digit argument_type;
		typedef std::size_t result_type;

		result_type operator ()(argument_type const &s) const
		{
			std::hash<std::string> h;
			return h(s.str());
		}
	};
}
