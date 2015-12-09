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
#include <utility>
#include <sstream>

namespace gur
{
	Word::Word() : word(0) {}

	Word::Word(const Word &w) : word(0)
	{
		for (std::size_t i = 0; i != w.size(); ++i)
		{
			this->add(w[i]);
		}
	}
	
	Word::Word(Word &&w) noexcept : word(std::move(w.word)) {}

	Word::Word(const Character &c) : word(0)
	{
		this->add(c);
	}

	Word::Word(Character &&c) noexcept : word(0)
	{
		this->add(std::move(c));
	}

	Word::Word(const std::string &s) : word(0)
	{
		std::istringstream iss(s);
		iss >> *this;
	}

	Word::Word(std::string &&s) : word(0)
	{
		std::istringstream iss(std::move(s));
		iss >> *this;
	}

	Word::Word(const char* const &c) : word(0)
	{
		std::istringstream iss(c);
		iss >> *this;
	}

	Word::~Word() {}

	Word& Word::operator = (const Word &w)
	{
		if (this != &w)
		{
			Word tmp(w);

			std::swap(this->word, tmp.word);
		}

		return *this;
	}

	Word& Word::operator = (Word &&w) noexcept
	{
		if (this != &w)
		{
			std::swap(this->word, w.word);
			w.word.clear();
		}

		return *this;
	}

	Word& Word::operator = (const Character &c)
	{
		this->word.clear();
		this->add(c);

		return *this;
	}

	Word& Word::operator = (const std::string &s)
	{
		std::vector<std::unique_ptr<Character> > tmp(
			std::move(this->word));

		this->word.clear();

		try
		{
			this->deduce(s.c_str());
		}

		catch (std::invalid_argument &e)
		{
			this->word = std::move(tmp);

			throw;
		}

		return *this;
	}

	Word& Word::operator = (const char* const &c)
	{
		std::vector<std::unique_ptr<Character> > tmp(
			std::move(this->word));

		this->word.clear();

		try
		{
			this->deduce(c);
		}

		catch (std::invalid_argument &e)
		{
			this->word = std::move(tmp);

			throw;
		}

		return *this;
	}
}
