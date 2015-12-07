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

#ifndef UTILITY_H
#define UTILITY_H

#include <array>
#include <vector>
#include <functional>
#include <cstring>
#include <algorithm>
#include <memory>

namespace util
{
	template<std::size_t length>
	bool compare(const std::array<const char* const, length> &arr,
		const char* const &lhs, const char* const &rhs,
		const std::function<bool(
			const typename std::array<const char* const,
				length>::iterator,
			const typename std::array<const char* const,
				length>::iterator)> &operation)
	{
		auto lhs_iterator = std::find_if(arr.begin(), arr.end(),
			[&lhs] (const char* const &c) -> bool
			{ return std::strcmp(lhs, c) == 0; });

		auto rhs_iterator = std::find_if(arr.begin(), arr.end(),
			[&rhs] (const char* const &c) -> bool
			{ return std::strcmp(rhs, c) == 0; });

		if (lhs_iterator == arr.end() || rhs_iterator == arr.end())
		{
			return false; //maybe throw exception
		}

		else
		{
			return operation(lhs_iterator, rhs_iterator);
		}
	}

	template<std::size_t length>
	constexpr bool contains(
		const std::array<const char* const, length> &arr,
		const char* const &character)
	{
		return std::find_if(arr.begin(), arr.end(),
			[&character] (const char* const &c) -> bool
			{
				return std::strcmp(character, c) == 0;
			}) != arr.end();
	}

	template <typename C, typename T>
	auto insert(C &c, T &&t) ->
		decltype(static_cast<void>(
			c.push_back(std::forward<T>(t))), void())
	{
		c.push_back(std::forward<T>(t));
	}

	template <typename C, typename T>
	auto insert(C &c, T &&t) ->
		decltype(static_cast<void>(
			c.insert(std::forward<T>(t))), void())
	{
		c.insert(std::forward<T>(t));
	}

	template <class W, class L, class A, class P, class D, class S>
	void strata(const std::vector<std::unique_ptr<W> > &word,
		L &&l, A &&a, P &&p, D &&d, S &&s,
		const std::function<bool(const std::unique_ptr<W>*)>
			&is_letter,
		const std::function<bool(const std::unique_ptr<W>*)>
			&is_accent,
		const std::function<bool(const std::unique_ptr<W>*)>
			&is_punc,
		const std::function<bool(const std::unique_ptr<W>*)>
			&is_digit,
		const std::function<bool(const std::unique_ptr<W>*)>
			&is_symbol)
	{
		for (auto &c : word)
		{
			if (is_letter(&c))
			{
				insert(l, *c);
			}

			else if (is_accent(&c))
			{
				insert(a, *c);
			}

			else if (is_punc(&c))
			{
				insert(p, *c);
			}

			else if (is_digit(&c))
			{
				insert(d, *c);
			}

			else if (is_symbol(&c))
			{
				insert(s, *c);
			}
		}
	}

	template <class W, class L>
	void strata(const std::vector<std::unique_ptr<W> > &word,
		L &&l,
		const std::function<bool(const std::unique_ptr<W>*)> &pred)
	{
		for (auto &c : word)
		{
			if (pred(&c))
			{
				insert(l, *c);
			}
		}
	}
}

#endif
