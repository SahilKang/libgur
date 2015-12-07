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
	Symbol::Symbol() : Character() {}

	Symbol::Symbol(const Character &c) : Character(c) {}

	Symbol::Symbol(const std::string &c) : Character(c) {}

	Symbol::Symbol(std::string &&c) : Character(std::move(c)) {}

	Symbol::Symbol(const char* const &c) : Character(c) {}

	const std::array<const char* const, 2> Symbol::SYMBOLS
	{
		gur::J5,
		gur::M1
	};

	bool Symbol::is_valid(const char* const &c)
	{
		return util::contains(Symbol::SYMBOLS, c);
	}

	bool Symbol::is_valid(const std::string &s)
	{
		return Symbol::is_valid(s.c_str());
	}

	bool Symbol::is_valid() const
	{
		return Symbol::is_valid(this->character);
	}

	bool operator < (const Symbol &lhs, const Symbol &rhs)
	{
		return util::compare(Symbol::SYMBOLS, lhs.character.c_str(),
			rhs.character.c_str(),
			[] (const decltype(Symbol::SYMBOLS)::iterator &lhs_i,
			const decltype(Symbol::SYMBOLS)::iterator &rhs_i)
				-> bool
			{ return lhs_i < rhs_i; });
	}

	bool operator > (const Symbol &lhs, const Symbol &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Symbol &lhs, const Symbol &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Symbol &lhs, const Symbol &rhs)
	{
		return !(lhs < rhs);
	}
}

namespace std
{
	template<>
	struct hash<gur::Symbol>
	{
		typedef gur::Symbol argument_type;
		typedef std::size_t result_type;

		result_type operator ()(argument_type const &s) const
		{
			std::hash<std::string> h;
			return h(s.str());
		}
	};
}
