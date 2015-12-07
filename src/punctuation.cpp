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
	Punctuation::Punctuation() : Character() {}

	Punctuation::Punctuation(const Character &c) : Character(c) {}

	Punctuation::Punctuation(const std::string &c) : Character(c) {}

	Punctuation::Punctuation(std::string &&c) : Character(std::move(c)) {}

	Punctuation::Punctuation(const char* const &c) : Character(c) {}

	const std::array<const char* const, 5> Punctuation::PUNCTUATIONS
	{
		gur::O2,
		gur::Q1, gur::Q2,
		"\u2019", "\u2018"
	};

	bool Punctuation::is_valid(const char* const &c)
	{
		return util::contains(Punctuation::PUNCTUATIONS, c);
	}

	bool Punctuation::is_valid(const std::string &s)
	{
		return Punctuation::is_valid(s.c_str());
	}

	bool Punctuation::is_valid() const
	{
		return Punctuation::is_valid(this->character);
	}

	bool operator < (const Punctuation &lhs, const Punctuation &rhs)
	{
		return util::compare(Punctuation::PUNCTUATIONS,
			lhs.character.c_str(), rhs.character.c_str(),
			[] (const decltype(Punctuation::PUNCTUATIONS)::
				iterator &lhs_i,
			const decltype(Punctuation::PUNCTUATIONS)::
				iterator &rhs_i) -> bool
			{ return lhs_i < rhs_i; });
	}

	bool operator > (const Punctuation &lhs, const Punctuation &rhs)
	{	
		return rhs < lhs;
	}

	bool operator <= (const Punctuation &lhs, const Punctuation &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Punctuation &lhs, const Punctuation &rhs)
	{
		return !(lhs < rhs);
	}
}

namespace std
{
	template<>
	struct hash<gur::Punctuation>
	{
		typedef gur::Punctuation argument_type;
		typedef std::size_t result_type;

		result_type operator ()(argument_type const &s) const
		{
			std::hash<std::string> h;
			return h(s.str());
		}
	};
}
