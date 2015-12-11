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
	std::ostream& operator << (std::ostream &out, const Word &w)
	{
		std::function<bool(const Character&,
			const char* const)> temp_bool =
		[] (const Character &character, const char* const c) -> bool
		{
			if (std::strcmp(character.str().c_str(), c) == 0)
			{
				return true;
			}

			else
			{
				return false;
			}
		};

		if (w.size() == 0)
		{
			return out;
		}

		Word tmp;

		for (std::size_t i = 0; i < w.size(); ++i)
		{
			if (i != w.size() - 1 && (temp_bool(w[i], gur::A2)
				&& (temp_bool(w[i +1], gur::H3)
					|| temp_bool(w[i + 1], gur::I4)
					|| temp_bool(w[i + 1], gur::J1))))
			{
				if (temp_bool(w[i + 1], gur::H3))
				{
					tmp += Letter(gur::M2);
				}

				else if (temp_bool(w[i + 1], gur::I4))
				{
					tmp += Letter(gur::N3);
				}

				else if (temp_bool(w[i + 1], gur::J1))
				{
					tmp += Letter(gur::N5);
				}

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::A3)
				&& (temp_bool(w[i + 1], gur::H4)
					|| temp_bool(w[i + 1], gur::H5)
					|| temp_bool(w[i + 1], gur::I3))))
			{
				if (temp_bool(w[i + 1], gur::H4))
				{
					tmp += Letter(gur::M3);
				}

				else if (temp_bool(w[i + 1], gur::H5))
				{
					tmp += Letter(gur::M4);
				}

				else if (temp_bool(w[i + 1], gur::I3))
				{
					tmp += Letter(gur::N2);
				}

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::A1)
				&& (temp_bool(w[i + 1], gur::I1)
					|| temp_bool(w[i + 1], gur::I2)
					|| temp_bool(w[i + 1], gur::I5))))
			{
				if (temp_bool(w[i + 1], gur::I1))
				{
					tmp += Letter(gur::M5);
				}

				else if (temp_bool(w[i + 1], gur::I2))
				{
					tmp += Letter(gur::N1);
				}

				else if (temp_bool(w[i + 1], gur::I5))
				{
					tmp += Letter(gur::N4);
				}

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::G3)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::O3);

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::A4)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::O4);

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::B2)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::P1);

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::B3)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::P2);

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::C3)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::P3);

				++i;
			}

			else if (i != w.size() - 1 && (temp_bool(w[i], gur::F2)
				&& (temp_bool(w[i + 1], gur::H2))))
			{
				tmp += Letter(gur::P4);

				++i;
			}

			else
			{
				tmp += w[i];
			}
		}

		for (auto &character : tmp.word)
		{
			out << *character;
		}

		return out;
	}
}
