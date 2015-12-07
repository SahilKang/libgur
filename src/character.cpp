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
#include <typeinfo>
#include <cstdint>

namespace gur
{
	Character::Character() : character("") {}

	Character::Character(const std::string &c) : character(c) {}

	Character::Character(std::string &&c) : character(std::move(c)) {}

	Character::Character(const char* const &c) : character(c) {}

	Character::Character(const Character &c) : character(c.character) {}

	Character::Character(Character &&c) noexcept :
		character(std::move(c.character)) {}

	std::string Character::str() const
	{
		return this->character;
	}

	Character& Character::operator = (const Character &c)
	{
		if (this != &c)
		{
			this->character = c.character;
		}

		return *this;
	}

	Character& Character::operator = (Character &&c) noexcept
	{
		if (this != &c)
		{
			this->character = std::move(c.character);
		}

		return *this;
	}

	std::ostream& operator << (std::ostream &out, const Character &c)
	{
		out.write(c.character.c_str(), c.character.size());

		return out;
	}

	std::istream& operator >> (std::istream &in, Character &character)
	{
		character.character = "";

		char c;
		in.get(c);

		unsigned int bytes = [&c] () -> unsigned int
			{
				unsigned int count(0);
				std::uint8_t mask = 0x80;

				while (c & mask)
				{
					++count;
					mask = mask >> 1;
				}

				return count;
			}();

		character.character += c;

		if (bytes > 0)
		{
			--bytes;

			while (bytes > 0 && in.get(c))
			{
				character.character += c;

				--bytes;
			}
		}

		if (!character.is_valid())
		{
			in.setstate(std::ios::failbit);
		}

		else if (in.eof())
		{
			in.setstate(std::ios::eofbit);
		}

		else if (in.bad())
		{
			in.setstate(std::ios::badbit);
		}

		else
		{
			in.clear();
		}

		return in;
	}

	bool operator == (const Character &lhs, const Character &rhs)
	{
		if (typeid(lhs) == typeid(rhs))
		{
			return lhs.character == rhs.character;
		}

		else
		{
			return false;
		}
	}

	bool operator != (const Character &lhs, const Character &rhs)
	{
		return ((typeid(lhs) == typeid(rhs)) ? !(lhs == rhs) : false);
	}

	bool operator < (const Character &lhs, const Character &rhs)
	{
		return ((typeid(lhs) == typeid(rhs)) ? (lhs < rhs) : false);
	}

	bool operator > (const Character &lhs, const Character &rhs)
	{
		return ((typeid(lhs) == typeid(rhs)) ? (lhs > rhs) : false);
	}

	bool operator <= (const Character &lhs, const Character &rhs)
	{
		return ((typeid(lhs) == typeid(rhs)) ? (lhs <= rhs) : false);
	}

	bool operator >= (const Character &lhs, const Character &rhs)
	{
		return ((typeid(lhs) == typeid(rhs)) ? (lhs >= rhs) : false);
	}
}
