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

typedef std::vector<std::unique_ptr<gur::Character> >::const_iterator
	const_char_iterator;

namespace gur
{
	Word::const_iterator::const_iterator() : iter() {}

	Word::const_iterator::const_iterator(const Word::const_iterator &i) :
		iter(i.iter) {}

	Word::const_iterator::const_iterator(Word::const_iterator &&i)
		noexcept : iter(std::move(i.iter)) {}

	Word::const_iterator::const_iterator(const const_char_iterator &i) :
		iter(i) {}

	Word::const_iterator::const_iterator(const_char_iterator &&i)
		noexcept : iter(std::move(i)) {}

	const Character& Word::const_iterator::operator []
		(const std::ptrdiff_t &n) const
	{
		return *(this->iter[n]);
	}

	Word::const_iterator& Word::const_iterator::operator ++()
	{
		++(this->iter);

		return *this;
	}

	Word::const_iterator Word::const_iterator::operator ++(int)
	{
		Word::const_iterator tmp = *this;
		++(*this);

		return tmp;
	}

	Word::const_iterator& Word::const_iterator::operator --()
	{
		--(this->iter);

		return *this;
	}

	Word::const_iterator Word::const_iterator::operator --(int)
	{
		Word::const_iterator tmp = *this;
		--(*this);

		return tmp;
	}

	const Character& Word::const_iterator::operator *()
	{
		return **(this->iter);
	}

	Word::const_iterator& Word::const_iterator::operator += (
		const std::ptrdiff_t &n)
	{
		this->iter += n;

		return *this;
	}

	Word::const_iterator& Word::const_iterator::operator -= (
		const std::ptrdiff_t &n)
	{
		this->iter -= n;

		return *this;
	}

	Word::const_iterator& Word::const_iterator::operator = (
		const Word::const_iterator &i)
	{
		if (this != &i)
		{
			Word::const_iterator tmp(i);
			std::swap(this->iter, tmp.iter);
		}

		return *this;
	}

	Word::const_iterator& Word::const_iterator::operator = (
		Word::const_iterator &&i) noexcept
	{
		if (this != &i)
		{
			std::swap(this->iter, i.iter);
		}

		return *this;
	}

	Word::const_iterator::~const_iterator() {}

	bool operator == (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return lhs.iter == rhs.iter;
	}

	bool operator != (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return !(lhs == rhs);
	}

	bool operator < (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return lhs.iter < rhs.iter;
	}

	bool operator > (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs)
	{
		return !(lhs < rhs);
	}

	Word::const_iterator operator + (Word::const_iterator lhs,
		const std::ptrdiff_t &n)
	{
		lhs += n;

		return lhs;
	}

	Word::const_iterator operator - (Word::const_iterator lhs,
		const std::ptrdiff_t &n)
	{
		lhs -= n;

		return lhs;
	}

	std::ptrdiff_t operator - (Word::const_iterator lhs,
		const Word::const_iterator &rhs)
	{
		return lhs - rhs;
	}
}
