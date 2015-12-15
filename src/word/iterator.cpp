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

typedef std::vector<std::unique_ptr<gur::Character> >::iterator char_iterator;

namespace gur
{
	Word::iterator::iterator() : begin(), iter() {}

	Word::iterator::iterator(const Word::iterator &i) : begin(i.iter),
		iter(i.iter) {}

	Word::iterator::iterator(Word::iterator &&i) noexcept : begin(i.iter),
		iter(std::move(i.iter)) {}

	Word::iterator::iterator(const char_iterator &i) : begin(i), iter(i) {}

	Word::iterator::iterator(char_iterator &&i) noexcept : begin(i),
		iter(std::move(i)) {}

	Character& Word::iterator::operator [](const std::size_t &n)
	{
		return *(this->iter[n]);
	}

	Word::iterator& Word::iterator::operator ++()
	{
		++(this->iter);

		return *this;
	}

	Word::iterator Word::iterator::operator ++(int)
	{
		Word::iterator tmp = *this;
		++(*this);

		return tmp;
	}

	Word::iterator& Word::iterator::operator --()
	{
		--(this->iter);

		return *this;
	}

	Word::iterator Word::iterator::operator --(int)
	{
		Word::iterator tmp = *this;
		--(*this);

		return tmp;
	}

	Character& Word::iterator::operator *()
	{
		return **(this->iter);
	}

	Word::iterator& Word::iterator::operator += (const std::ptrdiff_t &n)
	{
		this->iter += n;

		return *this;
	}

	Word::iterator& Word::iterator::operator -= (const std::ptrdiff_t &n)
	{
		this->iter -= n;

		return *this;
	}

	Word::iterator::operator std::ptrdiff_t() const
	{
		return std::ptrdiff_t(std::distance(this->begin, this->iter));
	}

	Word::iterator& Word::iterator::operator = (
		const Word::iterator &i)
	{
		if (this != &i)
		{
			Word::iterator tmp(i);
			std::swap(this->iter, tmp.iter);
		}

		return *this;
	}

	Word::iterator& Word::iterator::operator = (
		Word::iterator &&i) noexcept
	{
		if (this != &i)
		{
			std::swap(this->iter, i.iter);
		}

		return *this;
	}

	Word::iterator::~iterator() {}

	bool operator == (const Word::iterator &lhs,
		const Word::iterator &rhs)
	{
		return lhs.iter == rhs.iter;
	}

	bool operator != (const Word::iterator &lhs,
		const Word::iterator &rhs)
	{
		return !(lhs == rhs);
	}

	bool operator < (const Word::iterator &lhs, const Word::iterator &rhs)
	{
		return lhs.iter < rhs.iter;
	}

	bool operator > (const Word::iterator &lhs, const Word::iterator &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Word::iterator &lhs, const Word::iterator &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Word::iterator &lhs, const Word::iterator &rhs)
	{
		return !(lhs < rhs);
	}

	Word::iterator operator + (Word::iterator lhs,
		const std::ptrdiff_t &n)
	{
		lhs += n;

		return lhs;
	}

	Word::iterator operator - (Word::iterator lhs,
		const std::ptrdiff_t &n)
	{
		lhs -= n;

		return lhs;
	}

	Word::iterator operator + (Word::iterator lhs,
		const Word::iterator &rhs)
	{	
		lhs += std::distance(lhs.iter, rhs.iter);

		return lhs;
	}

	Word::iterator operator - (Word::iterator lhs,
		const Word::iterator &rhs)
	{
		lhs -= std::distance(lhs.iter, rhs.iter);

		return lhs;
	}
}
