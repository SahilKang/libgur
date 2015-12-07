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
#include <cstring>

namespace gur
{
	std::istream& operator >> (std::istream &in, Word &w)
	{
		std::function<bool(const Letter&, const char* const)>
			temp_bool =
		[] (const Letter &letter, const char* const c) -> bool
		{
			if (std::strcmp(letter.str().c_str(), c) == 0)
			{
				return true;
			}

			else
			{
				return false;
			}
		};

		w.word.clear();

		Letter letter;

		while (true)
		{
			in >> letter;

			const char* const c = letter.str().c_str();

			if (Letter::is_valid(c))
			{
				w.add(letter);
				in.clear();
			}

			else if (temp_bool(letter, gur::M2))
			{
				Letter l(gur::A2);
				Accent a(gur::H3);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::M3))
			{
				Letter l(gur::A3);
				Accent a(gur::H4);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::M4))
			{
				Letter l(gur::A3);
				Accent a(gur::H5);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::M5))
			{
				Letter l(gur::A1);
				Accent a(gur::I1);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::N1))
			{
				Letter l(gur::A1);
				Accent a(gur::I2); w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::N2))
			{
				Letter l(gur::A3);
				Accent a(gur::I3);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::N3))
			{
				Letter l(gur::A2);
				Accent a(gur::I4);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::N4))
			{
				Letter l(gur::A1);
				Accent a(gur::I5);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::N5))
			{
				Letter l(gur::A2);
				Accent a(gur::J1);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::O3))
			{
				Letter l(gur::G3);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::O4))
			{
				Letter l(gur::A4);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::P1))
			{
				Letter l(gur::B2);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::P2))
			{
				Letter l(gur::B3);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::P3))
			{
				Letter l(gur::C3);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (temp_bool(letter, gur::P4))
			{
				Letter l(gur::F2);
				Accent a(gur::H2);
				w.add(l);
				w.add(a);
				in.clear();
			}

			else if (Accent::is_valid(c))
			{
				w.add(Accent(c));
				in.clear();
			}

			else if (Punctuation::is_valid(c))
			{
				w.add(Punctuation(c));
				in.clear();
			}

			else if (Digit::is_valid(c))
			{
				w.add(Digit(c));
				in.clear();
			}

			else if (Symbol::is_valid(c))
			{
				w.add(Symbol(c));
				in.clear();
			}

			else if (temp_bool(letter, " ")
				|| temp_bool(letter, "\t")
				|| temp_bool(letter, "\n")
				|| temp_bool(letter, "\r")
				|| temp_bool(letter, "\r\n"))
			{
				in.clear();

				break;
			}

			else if (in.eof())
			{
				in.setstate(std::ios::eofbit);

				break;
			}
			
			else
			{
				w.add(Symbol(c));
				in.clear();
			}
		}

		return in;
	}
}
