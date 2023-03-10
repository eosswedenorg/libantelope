#include <libeosio/WIF.hpp>
#include <libeosio/ec.hpp>
#include <iostream>
#include <vector>
#include <doctest.h>

TEST_CASE("WIF::wif_pub_encode") {
	struct testcase {
		const char* name;
		std::string key;
		libeosio::ec_pubkey_t expected;
		bool expectedRet;
	};

	std::vector<struct testcase> tests {
		{ "one",   "EOS7kzJ5iFBmQWWT1LiWgAiocESD7TTNuuPCdYREUQysruq8VeFKy", { 0x03, 0x7a, 0x0e, 0x6b, 0xfd, 0xe4, 0xf1, 0xad, 0x36, 0x3f, 0x3a, 0xf9, 0xe0, 0x93, 0x63, 0x5a, 0xa9, 0x99, 0x21, 0x15, 0xbc, 0x23, 0x35, 0x75, 0x13, 0x69, 0x55, 0xee, 0x3f, 0xf8, 0xfd, 0x97, 0xec }, true },
		{ "two",   "EOS5c9HkNCJLDebe2Wvapp8bpB38Pf1QWNpkrsFy3mshg7DZfPNeA", { 0x02, 0x5e, 0x94, 0xa5, 0xe7, 0x9f, 0x66, 0x37, 0x55, 0x7e, 0xc2, 0x28, 0x30, 0x40, 0x82, 0x9a, 0x38, 0x72, 0x10, 0x96, 0x6e, 0x15, 0xb7, 0xa5, 0x8a, 0x27, 0x9a, 0x71, 0x06, 0xa7, 0x64, 0x23, 0x30 }, true },
		{ "three", "EOS8SwZMY8DChbbmRKS3wdHCAbv1VWgTRmQEDSaLyJk8pG4wm8BJF", { 0x03, 0xd4, 0xc6, 0x2a, 0xdc, 0x11, 0x1c, 0x65, 0x7a, 0x9f, 0x5b, 0xba, 0x96, 0x3f, 0xbb, 0x2a, 0x69, 0x2e, 0xc5, 0x4a, 0x48, 0x3b, 0xa3, 0x5f, 0x2a, 0x37, 0x6c, 0x59, 0x95, 0xb1, 0x95, 0x1c, 0xc9 }, true },
		{ "wrong_checksum", "EOS8SwZMY8DChbbmRKS3wdHCAbv1VWgTRmQEDSaLyJk8pG4wm8EgC", { 0x0 }, false },
		{ "wrong_length", "EOS7kzJ5iFBmQWWT1LiWgAiocESD7TT", { 0x0 }, false },
		{ "not_base58", "EOS7IIIIIOOOO", { 0x0 }, false }
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {

		SUBCASE(it->name) {
			libeosio::ec_pubkey_t result = { 0x0 };

			CHECK( libeosio::wif_pub_decode(result, it->key) == it->expectedRet );
			CHECK( result == it->expected );
		}
	}
}