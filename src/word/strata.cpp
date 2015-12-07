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
#include <utility.hpp>
#include <typeinfo>
#include <set>

namespace gur
{
	void Word::strata(
		std::vector<Letter> &&letters,
		std::vector<Accent> &&accents,
		std::vector<Punctuation> &&punctuations,
		std::vector<Digit> &&digits,
		std::vector<Symbol> &&symbols) const
	{
		util::strata<Character>(this->word,
			std::move(letters),
			std::move(accents),
			std::move(punctuations),
			std::move(digits),
			std::move(symbols),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Letter); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Accent); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Punctuation); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Digit); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Symbol); }
		);
	}

	Word Word::composition() const
	{
		std::set<Letter> letters;
		std::set<Accent> accents;
		std::set<Punctuation> puncs;
		std::set<Digit> digits;
		std::set<Symbol> symbols;

		util::strata<Character>(this->word,
			std::move(letters),
			std::move(accents),
			std::move(puncs),
			std::move(digits),
			std::move(symbols),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Letter); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Accent); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Punctuation); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Digit); },
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Symbol); }
		);

		Word w;

		for (auto &c : letters)
		{
			w += c;
		}

		for (auto &c : accents)
		{
			w += c;
		}

		for (auto &c : puncs)
		{
			w += c;
		}

		for (auto &c : digits)
		{
			w += c;
		}

		for (auto &c : symbols)
		{
			w += c;
		}

		return w;
	}

	Word Word::letters() const
	{
		std::vector<Letter> letters;

		util::strata<Character>(this->word,
			std::move(letters),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Letter); }
		);

		Word w;

		for (auto &c : letters)
		{
			w += c;
		}

		return w;
	}

	Word Word::accents() const
	{
		std::vector<Accent> accents;

		util::strata<Character>(this->word,
			std::move(accents),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Accent); }
		);

		Word w;

		for (auto &c : accents)
		{
			w += c;
		}

		return w;
	}

	Word Word::punctuations() const
	{
		std::vector<Punctuation> puncs;

		util::strata<Character>(this->word,
			std::move(puncs),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Punctuation); }
		);

		Word w;

		for (auto &c : puncs)
		{
			w += c;
		}

		return w;
	}

	Word Word::digits() const
	{
		std::vector<Digit> digits;

		util::strata<Character>(this->word,
			std::move(digits),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Digit); }
		);

		Word w;

		for (auto &c : digits)
		{
			w += c;
		}

		return w;
	}

	Word Word::symbols() const
	{
		std::vector<Symbol> symbols;

		util::strata<Character>(this->word,
			std::move(symbols),
			[] (const std::unique_ptr<Character> *c) -> bool
				{ return typeid(**c) == typeid(Symbol); }
		);

		Word w;

		for (auto &c : symbols)
		{
			w += c;
		}

		return w;
	}
}
