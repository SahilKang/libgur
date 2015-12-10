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

namespace gur
{
	Character& Word::operator [] (const std::size_t &i)
	{
		return *this->word[i];
	}

	const Character& Word::operator [] (const size_t &i) const
	{
		return *this->word[i];
	}

	Word& Word::operator += (const Word &w)
	{
		for (auto &i : w.word)
		{
			this->add(*i);
		}

		return *this;
	}

	Word& Word::operator += (const Character &c)
	{
		this->add(c);

		return *this;
	}

	Word& Word::operator += (const std::string &s)
	{
		Word tmp(s);
		*this += tmp;

		return *this;
	}

	Word& Word::operator += (const char* const &c)
	{
		Word tmp(c);
		*this += tmp;

		return *this;
	}

	Word operator + (Word lhs, const Word &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Word operator + (Word lhs, const Character &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Word operator + (Word lhs, const std::string &rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Word operator + (Word lhs, const char* const &rhs)
	{
		lhs += rhs;

		return lhs;
	}
}
