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
	bool operator != (const Word &lhs, const Word &rhs)
	{
		return !(lhs == rhs);
	}

	bool operator > (const Word &lhs, const Word &rhs)
	{
		return rhs < lhs;
	}

	bool operator <= (const Word &lhs, const Word &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator >= (const Word &lhs, const Word &rhs)
	{
		return !(lhs < rhs);
	}

	bool operator == (const Word &lhs, const Word &rhs)
	{
		if (lhs.size() != rhs.size())
		{
			return false;
		}

		else
		{
			for (std::size_t i = 0; i != lhs.size(); ++i)
			{
				if (lhs[i] != rhs[i])
				{
					return false;
				}
			}

			return true;
		}
	}

	/**************************************************************
	 * If letters are not equal, lex_compare on letters;
	 * else if accents are not equal, lex_compare on accents;
	 * else if puncs are not equal, lex_compare on puncs;
	 * else if digits are not equal, lex_compare on digits;
	 * else if symbols are not equal, lex_compare on symbols;
	**************************************************************/
	bool operator < (const Word &lhs, const Word &rhs)
	{
		std::vector<Letter> lhs_letters;
		std::vector<Accent> lhs_accents;
		std::vector<Punctuation> lhs_puncs;
		std::vector<Digit> lhs_digits;
		std::vector<Symbol> lhs_symbols;

		std::vector<Letter> rhs_letters;
		std::vector<Accent> rhs_accents;
		std::vector<Punctuation> rhs_puncs;
		std::vector<Digit> rhs_digits;
		std::vector<Symbol> rhs_symbols;

		lhs.strata(
			std::move(lhs_letters),
			std::move(lhs_accents),
			std::move(lhs_puncs),
			std::move(lhs_digits),
			std::move(lhs_symbols));

		rhs.strata(
			std::move(rhs_letters),
			std::move(rhs_accents),
			std::move(rhs_puncs),
			std::move(rhs_digits),
			std::move(rhs_symbols));

		if (lhs_letters != rhs_letters)
		{
			return std::lexicographical_compare(
				lhs_letters.begin(), lhs_letters.end(),
				rhs_letters.begin(), rhs_letters.end());
		}

		else if (lhs_accents != rhs_accents)
		{
			return std::lexicographical_compare(
				lhs_accents.begin(), lhs_accents.end(),
				rhs_accents.begin(), rhs_accents.end());
		}

		else if (lhs_puncs != rhs_puncs)
		{
			return std::lexicographical_compare(
				lhs_puncs.begin(), lhs_puncs.end(),
				rhs_puncs.begin(), rhs_puncs.end());
		}

		else if (lhs_digits != rhs_digits)
		{
			return std::lexicographical_compare(
				lhs_digits.begin(), lhs_digits.end(),
				rhs_digits.begin(), rhs_digits.end());
		}

		else if (lhs_symbols != rhs_symbols)
		{
			return std::lexicographical_compare(
				lhs_symbols.begin(), lhs_symbols.end(),
				rhs_symbols.begin(), rhs_symbols.end());
		}

		else
		{
			return std::lexicographical_compare(lhs.begin(),
				lhs.end(), rhs.begin(), rhs.end());
		}
	}
}
