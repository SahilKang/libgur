/******************************************************************************
 * Copyright (C) 2015, 2016 Sahil Singh Kang <sahil.kang@asilaycomputing.com>
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
#include <array>

static const std::array<const std::string, 35> LETTERS
{
	gur::A1, gur::A2, gur::A3, gur::A4, gur::A5,
	gur::B1, gur::B2, gur::B3, gur::B4, gur::B5,
	gur::C1, gur::C2, gur::C3, gur::C4, gur::C5,
	gur::D1, gur::D2, gur::D3, gur::D4, gur::D5,
	gur::E1, gur::E2, gur::E3, gur::E4, gur::E5,
	gur::F1, gur::F2, gur::F3, gur::F4, gur::F5,
	gur::G1, gur::G2, gur::G3, gur::G4, gur::G5
};

static const std::array<const std::string, 17> ACCENTS
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

static const std::array<const std::string, 3> PUNCS
{
	gur::O2,
	gur::Q1, gur::Q2
};

static const std::array<const std::string, 10> DIGITS
{
	gur::K1, gur::K2, gur::K3, gur::K4, gur::K5,
	gur::L1, gur::L2, gur::L3, gur::L4, gur::L5
};

static const std::array<const std::string, 2> SYMBOLS
{
	gur::J5,
	gur::M1
};

namespace gur
{
	bool is_letter(const String &str)
	{
		return is_letter(str.str().c_str());
	}

	bool is_letter(const std::string &str)
	{
		return is_letter(str.c_str());
	}

	bool is_letter(const char* const &str)
	{
		return util::contains(LETTERS, str);
	}

	bool is_accent(const String &str)
	{
		return is_accent(str.str().c_str());
	}

	bool is_accent(const std::string &str)
	{
		return is_accent(str.c_str());
	}

	bool is_accent(const char* const &str)
	{
		return util::contains(ACCENTS, str);
	}

	bool is_punc(const String &str)
	{
		return is_punc(str.str().c_str());
	}

	bool is_punc(const std::string &str)
	{
		return is_punc(str.c_str());
	}

	bool is_punc(const char* const &str)
	{
		return util::contains(PUNCS, str);
	}

	bool is_digit(const String &str)
	{
		return is_digit(str.str().c_str());
	}

	bool is_digit(const std::string &str)
	{
		return is_digit(str.c_str());
	}

	bool is_digit(const char* const &str)
	{
		return util::contains(DIGITS, str);
	}

	bool is_symbol(const String &str)
	{
		return is_symbol(str.str().c_str());
	}

	bool is_symbol(const std::string &str)
	{
		return is_symbol(str.c_str());
	}

	bool is_symbol(const char* const &str)
	{
		return util::contains(SYMBOLS, str);
	}
}
