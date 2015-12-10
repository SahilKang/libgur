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
#include <typeinfo>

namespace gur
{
	void Word::add(const Character &c)
	{
		if (typeid(c) == typeid(Letter))
		{
			this->word.push_back(std::make_unique<Letter>(c));
		}

		else if (typeid(c) == typeid(Accent))
		{
			this->word.push_back(std::make_unique<Accent>(c));
		}
		
		else if (typeid(c) == typeid(Punctuation))
		{
			this->word.push_back(std::make_unique<Punctuation>(c));
		}

		else if (typeid(c) == typeid(Digit))
		{
			this->word.push_back(std::make_unique<Digit>(c));
		}

		else if (typeid(c) == typeid(Symbol))
		{
			this->word.push_back(std::make_unique<Symbol>(c));
		}
	}

	void Word::add(Character &&c)
	{
		if (typeid(c) == typeid(Letter))
		{
			this->word.push_back(
				std::make_unique<Letter>(std::move(c)));
		}

		else if (typeid(c) == typeid(Accent))
		{
			this->word.push_back(
				std::make_unique<Accent>(std::move(c)));
		}
		
		else if (typeid(c) == typeid(Punctuation))
		{
			this->word.push_back(
				std::make_unique<Punctuation>(std::move(c)));
		}

		else if (typeid(c) == typeid(Digit))
		{
			this->word.push_back(
				std::make_unique<Digit>(std::move(c)));
		}

		else if (typeid(c) == typeid(Symbol))
		{
			this->word.push_back(
				std::make_unique<Symbol>(std::move(c)));
		}

		c.character.clear();
	}
}
