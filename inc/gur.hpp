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

#ifndef GUR_H
#define GUR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <array>
#include <iterator>

namespace gur
{
	class Word;

	class Character {
	public: Character();
		Character(const Character &c);
		Character(Character &&c) noexcept;
		Character(const std::string &c);
		Character(std::string &&c);
		Character(const char* const &c);

		std::string str() const;

		Character& operator = (const Character &c);
		Character& operator = (Character &&c) noexcept;

		virtual ~Character() {}

		std::string character;
		virtual bool is_valid() const = 0;

		friend class Word;

		friend std::ostream& operator << (std::ostream &out,
			const Character &c);
		friend std::istream& operator >> (std::istream &in,
			Character &c);
		friend bool operator == (const Character &lhs,
			const Character &rhs);
	};

	std::ostream& operator << (std::ostream &out, const Character &c);
	std::istream& operator >> (std::istream &in, Character &c);
	bool operator == (const Character &lhs, const Character &rhs);
	bool operator != (const Character &lhs, const Character &rhs);
	bool operator < (const Character &lhs, const Character &rhs);
	bool operator > (const Character &lhs, const Character &rhs);
	bool operator <= (const Character &lhs, const Character &rhs);
	bool operator >= (const Character &lhs, const Character &rhs);

	class Letter : public Character {
	public:
		Letter();
		Letter(const Character &c);
		Letter(const std::string &c);
		Letter(std::string &&c);
		Letter(const char* const &c);

		static bool is_valid(const char* const &c);
		static bool is_valid(const std::string &s);

		friend bool operator < (const Letter &lhs, const Letter &rhs);
	private:
		static const std::array<const char* const, 35> LETTERS;
		virtual bool is_valid() const;
	};

	bool operator < (const Letter &lhs, const Letter &rhs);
	bool operator > (const Letter &lhs, const Letter &rhs);
	bool operator <= (const Letter &lhs, const Letter &rhs);
	bool operator >= (const Letter &lhs, const Letter &rhs);

	class Accent : public Character {
	public:
		Accent();
		Accent(const Character &c);
		Accent(const std::string &c);
		Accent(std::string &&c);
		Accent(const char* const &c);

		static bool is_valid(const char* const &c);
		static bool is_valid(const std::string &s);

		friend bool operator < (const Accent &lhs, const Accent &rhs);
	private:
		static const std::array<const char* const, 17> ACCENTS;
		virtual bool is_valid() const;
	};

	bool operator < (const Accent &lhs, const Accent &rhs);
	bool operator > (const Accent &lhs, const Accent &rhs);
	bool operator <= (const Accent &lhs, const Accent &rhs);
	bool operator >= (const Accent &lhs, const Accent &rhs);

	class Punctuation : public Character {
	public:
		Punctuation();
		Punctuation(const Character &c);
		Punctuation(const std::string &c);
		Punctuation(std::string &&c);
		Punctuation(const char* const &c);

		static bool is_valid(const char* const &c);
		static bool is_valid(const std::string &s);

		friend bool operator < (const Punctuation &lhs,
			const Punctuation &rhs);
	private:
		static const std::array<const char* const, 5> PUNCTUATIONS;
		virtual bool is_valid() const;
	};

	bool operator < (const Punctuation &lhs, const Punctuation &rhs);
	bool operator > (const Punctuation &lhs, const Punctuation &rhs);
	bool operator <= (const Punctuation &lhs, const Punctuation &rhs);
	bool operator >= (const Punctuation &lhs, const Punctuation &rhs);

	class Digit : public Character {
	public:
		Digit();
		Digit(const Character &c);
		Digit(const std::string &c);
		Digit(std::string &&c);
		Digit(const char* const &c);

		static bool is_valid(const char* const &c);
		static bool is_valid(const std::string &s);

		friend bool operator < (const Digit &lhs, const Digit &rhs);
	private:
		static const std::array<const char* const, 10> DIGITS;
		virtual bool is_valid() const;
	};

	bool operator < (const Digit &lhs, const Digit &rhs);
	bool operator > (const Digit &lhs, const Digit &rhs);
	bool operator <= (const Digit &lhs, const Digit &rhs);
	bool operator >= (const Digit &lhs, const Digit &rhs);

	class Symbol : public Character {
	public:
		Symbol();
		Symbol(const Character &c);
		Symbol(const std::string &c);
		Symbol(std::string &&c);
		Symbol(const char* const &c);

		static bool is_valid(const char* const &c);
		static bool is_valid(const std::string &s);

		friend bool operator < (const Symbol &lhs, const Symbol &rhs);
	private:
		static const std::array<const char* const, 2> SYMBOLS;
		virtual bool is_valid() const;
	};

	bool operator < (const Symbol &lhs, const Symbol &rhs);
	bool operator > (const Symbol &lhs, const Symbol &rhs);
	bool operator <= (const Symbol &lhs, const Symbol &rhs);
	bool operator >= (const Symbol &lhs, const Symbol &rhs);

	class Word {
	public:
		Word();
		Word(const Word &w);
		Word(Word &&w) noexcept;
		Word(const Character &c);
		Word(Character &&c) noexcept;
		Word(const std::string &s);
		Word(std::string &&s);
		Word(const char* const &c);

		std::size_t size() const;
		Word composition() const;
		Word letters() const;
		Word accents() const;
		Word punctuations() const;
		Word digits() const;
		Word symbols() const;
		void strata(
			std::vector<Letter> &&letters,
			std::vector<Accent> &&accents,
			std::vector<Punctuation> &&punctuations,
			std::vector<Digit> &&digits,
			std::vector<Symbol> &&symbols) const;

		class iterator;
		class const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		Character& operator [] (const std::size_t &i);
		const Character& operator [] (const std::size_t &i) const;
		Word& operator += (const Word &w);
		Word& operator += (const Character &c);
		Word& operator += (const std::string &s);
		Word& operator += (const char* const &c);

		Word& operator = (const Word &w);
		Word& operator = (Word &&w) noexcept;
		Word& operator = (const Character &c);
		Word& operator = (const std::string &s);
		Word& operator = (const char* const &c);

		~Word();
	private:
		std::vector<std::unique_ptr<Character> > word;

		void add(const Character &c);
		void add(Character &&c);

		friend std::ostream& operator << (std::ostream& out,
			const Word &w);
		friend std::istream& operator >> (std::istream& in, Word &w);
		friend bool operator == (const Word &lhs, const Word &rhs);
		friend bool operator < (const Word &lhs, const Word &rhs);
	};

	std::ostream& operator << (std::ostream& out, const Word &w);
	std::istream& operator >> (std::istream& in, Word &w);
	Word operator + (Word lhs, const Word &rhs);
	Word operator + (Word lhs, const Character &rhs);
	Word operator + (Word lhs, const std::string &rhs);
	Word operator + (Word lhs, const char* const &rhs);
	bool operator == (const Word &lhs, const Word &rhs);
	bool operator != (const Word &lhs, const Word &rhs);
	bool operator < (const Word &lhs, const Word &rhs);
	bool operator > (const Word &lhs, const Word &rhs);
	bool operator <= (const Word &lhs, const Word &rhs);
	bool operator >= (const Word &lhs, const Word &rhs);

	class Word::iterator :
		public std::iterator<std::random_access_iterator_tag,
		Character> {
	public:
		iterator();
		iterator(const iterator &i);
		iterator(iterator &&i) noexcept;
		iterator(const std::vector<std::unique_ptr<Character> >
			::iterator &i);
		iterator(std::vector<std::unique_ptr<Character> >
			::iterator &&i) noexcept;
		iterator& operator ++();
		iterator operator ++(int);
		iterator& operator --();
		iterator operator --(int);
		Character& operator *();
		iterator& operator += (const std::ptrdiff_t &n);
		iterator& operator -= (const std::ptrdiff_t &n);
		explicit operator std::ptrdiff_t() const;
		iterator& operator = (const iterator &i);
		iterator& operator = (iterator &&i) noexcept;
		~iterator();
	private:
		const std::vector<std::unique_ptr<Character> >::iterator begin;
		std::vector<std::unique_ptr<Character> >::iterator iter;
		friend bool operator == (const iterator &lhs,
			const iterator &rhs);
		friend bool operator < (const iterator &lhs,
			const iterator &rhs);
		friend iterator operator + (iterator lhs, const iterator &rhs);
		friend iterator operator - (iterator lhs, const iterator &rhs);
	};

	bool operator == (const Word::iterator &lhs,
		const Word::iterator &rhs);
	bool operator != (const Word::iterator &lhs,
		const Word::iterator &rhs);
	bool operator < (const Word::iterator &lhs, const Word::iterator &rhs);
	bool operator > (const Word::iterator &lhs, const Word::iterator &rhs);
	bool operator <= (const Word::iterator &lhs,
		const Word::iterator &rhs);
	bool operator >= (const Word::iterator &lhs,
		const Word::iterator &rhs);
	Word::iterator operator + (Word::iterator lhs,
		const std::ptrdiff_t  &n);
	Word::iterator operator - (Word::iterator lhs,
		const std::ptrdiff_t  &n);
	Word::iterator operator + (Word::iterator lhs,
		const Word::iterator &rhs);
	Word::iterator operator - (Word::iterator lhs,
		const Word::iterator &rhs);

	class Word::const_iterator :
		public std::iterator<std::random_access_iterator_tag,
		Character> {
	public:
		const_iterator();
		const_iterator(const const_iterator &i);
		const_iterator(const_iterator &&i) noexcept;
		const_iterator(const std::vector<std::unique_ptr<Character> >
			::const_iterator &i);
		const_iterator(std::vector<std::unique_ptr<Character> >
			::const_iterator &&i) noexcept;
		const_iterator& operator ++();
		const_iterator operator ++(int);
		const_iterator& operator --();
		const_iterator operator --(int);
		const Character& operator *();
		const_iterator& operator += (const std::ptrdiff_t &n);
		const_iterator& operator -= (const std::ptrdiff_t &n);
		explicit operator std::ptrdiff_t() const;
		const_iterator& operator = (const const_iterator &i);
		const_iterator& operator = (const_iterator &&i) noexcept;
		~const_iterator();
	private:
		const std::vector<std::unique_ptr<Character> >
			::const_iterator begin;
		std::vector<std::unique_ptr<Character> >::const_iterator iter;
		friend bool operator == (const const_iterator &lhs,
			const const_iterator &rhs);
		friend bool operator < (const const_iterator &lhs,
			const const_iterator &rhs);
		friend const_iterator operator + (const_iterator lhs,
			const const_iterator &rhs);
		friend const_iterator operator - (const_iterator lhs,
			const const_iterator &rhs);
	};

	bool operator == (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	bool operator != (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	bool operator < (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	bool operator > (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	bool operator <= (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	bool operator >= (const Word::const_iterator &lhs,
		const Word::const_iterator &rhs);
	Word::const_iterator operator + (Word::const_iterator lhs,
		const std::ptrdiff_t &n);
	Word::const_iterator operator - (Word::const_iterator lhs,
		const std::ptrdiff_t &n);
	Word::const_iterator operator + (Word::const_iterator lhs,
		const Word::const_iterator &rhs);
	Word::const_iterator operator - (Word::const_iterator lhs,
		const Word::const_iterator &rhs);
}

#endif
