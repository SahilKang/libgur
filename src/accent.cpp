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
	Accent::Accent() : Character() {}

	Accent::Accent(const Character &c) : Character(c) {}

	Accent::Accent(const std::string &c) : Character(c) {}

	Accent::Accent(std::string &&c) : Character(std::move(c)) {}

	Accent::Accent(const char* const &c) : Character(c) {}

	const std::array<const char* const, 17> Accent::ACCENTS
	{
		gur::H3, gur::H4, gur::H5,
		gur::I1, gur::I2, gur::I3, gur::I4, gur::I5,
		gur::J1, gur::J3, gur::J4,
		gur::H1,
		gur::J2,
		gur::P5,
		gur::O5, gur::O1,
		gur::H2
	};

	bool Accent::is_valid(const char* const &c)
	{
		return util::contains(Accent::ACCENTS, c);
	}

	bool Accent::is_valid(const std::string &s)
	{
		return Accent::is_valid(s.c_str());
	}

	bool Accent::is_valid() const
	{
		return Accent::is_valid(this->character);
	}

	bool operator < (const Accent &lhs, const Accent &rhs)
	{
		return util::compare(Accent::ACCENTS, lhs.character.c_str(),
			rhs.character.c_str(),
			[] (const decltype(Accent::ACCENTS)::iterator &lhs_i,
			const decltype(Accent::ACCENTS)::iterator &rhs_i)
				-> bool
			{ return lhs_i < rhs_i; });
	}

	bool operator > (const Accent &lhs, const Accent &rhs)
	{	
		return rhs < lhs;
	}

	bool operator <= (const Accent &lhs, const Accent &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Accent &lhs, const Accent &rhs)
	{
		return !(lhs < rhs);
	}
}

namespace std
{
	template<>
	struct hash<gur::Accent>
	{
		typedef gur::Accent argument_type;
		typedef std::size_t result_type;

		result_type operator ()(argument_type const &s) const
		{
			std::hash<std::string> h;
			return h(s.str());
		}
	};
}
