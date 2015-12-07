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

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <gur.hpp>
#include <gurmukhi.hpp>
#include <sstream>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(Word)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Word word;

		BOOST_REQUIRE_EQUAL(word.size(), 0);
	}

	BOOST_AUTO_TEST_CASE(Character)
	{
		gur::Letter letter(gur::A1);

		gur::Word word(letter);

		BOOST_REQUIRE_EQUAL(letter.str().c_str(), gur::A1);
		BOOST_REQUIRE_EQUAL(word[0], letter);
	}

	BOOST_AUTO_TEST_CASE(CharacterMove)
	{
		gur::Letter letter(gur::A1);

		gur::Word word(std::move(letter));

		BOOST_REQUIRE_EQUAL(letter.str(), "");
		BOOST_REQUIRE_EQUAL(word[0], gur::Letter(gur::A1));
	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string letter(gur::A1);
		std::string unknown("unknown");

		gur::Word word_one(letter);

		BOOST_CHECK_THROW(
			gur::Word word_two(unknown),
			std::invalid_argument);
		BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A1);
		BOOST_CHECK_EQUAL(letter, word_one[0].str());
		BOOST_CHECK_EQUAL(unknown, "unknown");
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const letter = gur::A1;
		const char* const unknown = "unknown";

		gur::Word word_one(letter);

		BOOST_CHECK_THROW(
			gur::Word word_two(unknown),
			std::invalid_argument);
		BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A1);
		BOOST_CHECK_EQUAL(letter, word_one[0].str().c_str());
		BOOST_CHECK_EQUAL(unknown, "unknown");
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(word_one);

		BOOST_REQUIRE_EQUAL(word_one[0], gur::Letter(gur::A1));
		BOOST_REQUIRE_EQUAL(word_two[0], word_one[0]);
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(std::move(word_one));

		BOOST_REQUIRE_EQUAL(word_one.size(), 0);
		BOOST_REQUIRE_EQUAL(word_two[0], gur::Letter(gur::A1));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Size)
	{
		gur::Word word_one;

		BOOST_REQUIRE_EQUAL(word_one.size(), 0);

		gur::Word word_two(gur::Letter(gur::A1));

		BOOST_REQUIRE_EQUAL(word_two.size(), 1);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A2));

		word_two = word_one;

		BOOST_REQUIRE_EQUAL(word_one[0], gur::Letter(gur::A1));
		BOOST_REQUIRE_EQUAL(word_two[0], word_one[0]);
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A2));

		word_two = std::move(word_one);

		BOOST_REQUIRE_EQUAL(word_one.size(), 0);
		BOOST_REQUIRE_EQUAL(word_two[0], gur::Letter(gur::A1));
	}

	BOOST_AUTO_TEST_CASE(AssignmentCharacter)
	{
		gur::Word word(gur::Letter(gur::A1));

		gur::Letter letter(gur::A2);

		word = letter;

		BOOST_REQUIRE_EQUAL(word[0].str().c_str(), gur::A2);
		BOOST_REQUIRE_EQUAL(letter, word[0]);
	}

	BOOST_AUTO_TEST_CASE(AssignmentString)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A1));

		std::string letter(gur::A2);
		std::string unknown("unknown");

		word_one = letter;

		BOOST_CHECK_THROW(word_two = unknown, std::invalid_argument);
		BOOST_CHECK_EQUAL(word_two[0], gur::Letter(gur::A1));
		BOOST_CHECK_EQUAL(unknown, "unknown");
		BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A2);
		BOOST_CHECK_EQUAL(letter, word_one[0].str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentCharPointer)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A1));

		const char* const letter = gur::A2;
		const char* const unknown = "unknown";

		word_one = letter;

		BOOST_CHECK_THROW(word_two = unknown, std::invalid_argument);
		BOOST_CHECK_EQUAL(word_two[0], gur::Letter(gur::A1));
		BOOST_CHECK_EQUAL(unknown, "unknown");
		BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A2);
		BOOST_CHECK_EQUAL(letter, word_one[0].str().c_str());
	}

	BOOST_AUTO_TEST_SUITE(Addition)
		BOOST_AUTO_TEST_CASE(AssignmentWord)
		{
			gur::Word word_one(gur::Letter(gur::A1));
			gur::Word word_two(gur::Letter(gur::A2));

			word_one += word_two;

			BOOST_REQUIRE_EQUAL(word_one[0], gur::Letter(gur::A1));
			BOOST_REQUIRE_EQUAL(word_two[0], gur::Letter(gur::A2));
			BOOST_REQUIRE_EQUAL(word_one[1], gur::Letter(gur::A2));
		}

		BOOST_AUTO_TEST_CASE(AssignmentCharacter)
		{
			gur::Word word;
			gur::Letter letter(gur::A1);

			word += letter;

			BOOST_REQUIRE_EQUAL(letter.str().c_str(), gur::A1);
			BOOST_REQUIRE_EQUAL(word[0], letter);
		}

		BOOST_AUTO_TEST_CASE(AssignmentString)
		{
			std::string letter(gur::A2);
			std::string unknown("unknown");

			gur::Word word_one(gur::A1);
			gur::Word word_two(gur::A1);
			
			word_one += letter;

			BOOST_CHECK_THROW(
				word_two += unknown,
				std::invalid_argument);
			BOOST_CHECK_EQUAL(word_two[0].str().c_str(), gur::A1);
			BOOST_CHECK_EQUAL(unknown, "unknown");
			BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A1);
			BOOST_CHECK_EQUAL(word_one[1].str().c_str(), gur::A2);
			BOOST_CHECK_EQUAL(letter, word_one[1].str());
		}

		BOOST_AUTO_TEST_CASE(AssignmentCharPointer)
		{
			const char* const letter = gur::A2;
			const char* const unknown = "unknown";

			gur::Word word_one(gur::A1);
			gur::Word word_two(gur::A1);
			
			word_one += letter;

			BOOST_CHECK_THROW(
				word_two += unknown,
				std::invalid_argument);
			BOOST_CHECK_EQUAL(word_two[0].str().c_str(), gur::A1);
			BOOST_CHECK_EQUAL(unknown, "unknown");
			BOOST_CHECK_EQUAL(word_one[0].str().c_str(), gur::A1);
			BOOST_CHECK_EQUAL(word_one[1].str().c_str(), gur::A2);
			BOOST_CHECK_EQUAL(letter, word_one[1].str().c_str());
		}

		BOOST_AUTO_TEST_CASE(Word)
		{
			gur::Word word_one(gur::Letter(gur::A1));
			gur::Word word_two(gur::Letter(gur::A2));
			gur::Word word_three;

			word_three = word_one + word_two;

			BOOST_REQUIRE_EQUAL(word_one[0], gur::Letter(gur::A1));
			BOOST_REQUIRE_EQUAL(word_two[0], gur::Letter(gur::A2));
			BOOST_REQUIRE_EQUAL(word_three[0], word_one[0]);
			BOOST_REQUIRE_EQUAL(word_three[1], word_two[0]);
		}

		BOOST_AUTO_TEST_CASE(Character)
		{
			gur::Word word_one(gur::Letter(gur::A1));
			gur::Letter letter(gur::A2);
			gur::Word word_two;

			word_two = letter + word_one;

			BOOST_REQUIRE_EQUAL(word_one[0], gur::Letter(gur::A1));
			BOOST_REQUIRE_EQUAL(letter.str().c_str(), gur::A2);
			BOOST_REQUIRE_EQUAL(word_two[0], letter);
			BOOST_REQUIRE_EQUAL(word_two[1], word_one[0]);
		}

		BOOST_AUTO_TEST_CASE(String)
		{
			std::string letter(gur::A2);
			std::string unknown("unknown");

			gur::Word word_one(gur::Letter(gur::A1));
			gur::Word word_two(gur::Letter(gur::A1));
			gur::Word word_three(gur::Letter(gur::A1));

			word_two = word_one + letter;

			BOOST_CHECK_THROW(
				word_three = word_one + unknown,
				std::invalid_argument);
			BOOST_CHECK_EQUAL(word_three[0], gur::Letter(gur::A1));
			BOOST_CHECK_EQUAL(unknown, "unknown");
			BOOST_CHECK_EQUAL(word_two[0], gur::Letter(gur::A1));
			BOOST_CHECK_EQUAL(word_two[1].str().c_str(), gur::A2);
			BOOST_CHECK_EQUAL(letter, word_two[1].str());
			BOOST_CHECK_EQUAL(word_one[0], gur::Letter(gur::A1));

			BOOST_CHECK_EQUAL(word_one.size(), 1);
			BOOST_CHECK_EQUAL(word_two.size(), 2);
			BOOST_CHECK_EQUAL(word_three.size(), 1);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			const char* const letter = gur::A2;
			const char* const unknown = "unknown";

			gur::Word word_one(gur::Letter(gur::A1));
			gur::Word word_two(gur::Letter(gur::A1));
			gur::Word word_three(gur::Letter(gur::A1));

			word_two = word_one + letter;

			BOOST_CHECK_THROW(
				word_three = word_one + unknown,
				std::invalid_argument);
			BOOST_CHECK_EQUAL(word_three[0], gur::Letter(gur::A1));
			BOOST_CHECK_EQUAL(unknown, "unknown");
			BOOST_CHECK_EQUAL(word_two[0], gur::Letter(gur::A1));
			BOOST_CHECK_EQUAL(word_two[1].str().c_str(), gur::A2);
			BOOST_CHECK_EQUAL(letter, word_two[1].str());
			BOOST_CHECK_EQUAL(word_one[0], gur::Letter(gur::A1));

			BOOST_CHECK_EQUAL(word_one.size(), 1);
			BOOST_CHECK_EQUAL(word_two.size(), 2);
			BOOST_CHECK_EQUAL(word_three.size(), 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;

		gur::Word word(gur::Letter(gur::A1));
		word += gur::Accent(gur::I1);
		word += gur::Letter(gur::A4);
		word += gur::Letter(gur::E3);
		word += gur::Accent(gur::H5);
		word += gur::Letter(gur::A2);
		word += gur::Accent(gur::H3);
		word += gur::Accent(gur::H1);

		out << word;

		std::string rendered("");
		rendered += gur::M5;
		rendered += gur::A4;
		rendered += gur::E3;
		rendered += gur::H5;
		rendered += gur::M2;
		rendered += gur::H1;

		BOOST_CHECK(out.is_equal(rendered));

		BOOST_CHECK_EQUAL(word[0], gur::Letter(gur::A1));
		BOOST_CHECK_EQUAL(word[1], gur::Accent(gur::I1));
		BOOST_CHECK_EQUAL(word[2], gur::Letter(gur::A4));
		BOOST_CHECK_EQUAL(word[3], gur::Letter(gur::E3));
		BOOST_CHECK_EQUAL(word[4], gur::Accent(gur::H5));
		BOOST_CHECK_EQUAL(word[5], gur::Letter(gur::A2));
		BOOST_CHECK_EQUAL(word[6], gur::Accent(gur::H3));
		BOOST_CHECK_EQUAL(word[7], gur::Accent(gur::H1));
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::string rendered("");
		rendered += gur::M5;
		rendered += gur::A4;
		rendered += gur::E3;
		rendered += gur::H5;
		rendered += gur::M2;
		rendered += gur::H1;

		std::istringstream iss(rendered);
		gur::Word word(gur::Letter(gur::A2));

		iss >> word;

		BOOST_CHECK_EQUAL(word[0], gur::Letter(gur::A1));
		BOOST_CHECK_EQUAL(word[1], gur::Accent(gur::I1));
		BOOST_CHECK_EQUAL(word[2], gur::Letter(gur::A4));
		BOOST_CHECK_EQUAL(word[3], gur::Letter(gur::E3));
		BOOST_CHECK_EQUAL(word[4], gur::Accent(gur::H5));
		BOOST_CHECK_EQUAL(word[5], gur::Letter(gur::A2));
		BOOST_CHECK_EQUAL(word[6], gur::Accent(gur::H3));
		BOOST_CHECK_EQUAL(word[7], gur::Accent(gur::H1));
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A1));
		gur::Word word_three(gur::Letter(gur::A2));

		BOOST_REQUIRE_EQUAL(word_one == word_two, true);
		BOOST_REQUIRE_EQUAL(word_one == word_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Word word_one(gur::Letter(gur::A1));
		gur::Word word_two(gur::Letter(gur::A2));
		gur::Word word_three(gur::Letter(gur::A1));

		BOOST_REQUIRE_EQUAL(word_one != word_two, true);
		BOOST_REQUIRE_EQUAL(word_one != word_three, false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Iterators)
	BOOST_AUTO_TEST_CASE(RangeBasedForLoop)
	{
		gur::Word sahil(gur::Letter(gur::A4));
		sahil += gur::Accent(gur::H3);
		sahil += gur::Letter(gur::A5);
		sahil += gur::Accent(gur::H4);
		sahil += gur::Letter(gur::G3);

		unsigned int count = 0;
		for (auto &&c : sahil)
		{
			switch (count)
			{
				case 0 : BOOST_CHECK_EQUAL(
					c, gur::Letter(gur::A4)); break;
				case 1 : BOOST_CHECK_EQUAL(
					c, gur::Accent(gur::H3)); break;
				case 2 : BOOST_CHECK_EQUAL(
					c, gur::Letter(gur::A5)); break;
				case 3 : BOOST_CHECK_EQUAL(
					c, gur::Accent(gur::H4)); break;
				case 4 : BOOST_CHECK_EQUAL(
					c, gur::Letter(gur::G3)); break;
			};

			++count;
		}
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
