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
	std::size_t Word::size() const
	{
		return this->word.size();
	}

	Word::iterator Word::begin()
	{
		return Word::iterator(std::move(this->word.begin()));
	}

	Word::iterator Word::end()
	{
		return Word::iterator(std::move(this->word.end()));
	}

	Word::const_iterator Word::begin() const
	{
		return Word::const_iterator(std::move(this->word.begin()));
	}

	Word::const_iterator Word::end() const
	{
		return Word::const_iterator(std::move(this->word.end()));
	}
}
