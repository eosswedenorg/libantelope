#include <libeosio/WIF.hpp>
#include <libeosio/ec.hpp>
#include <iostream>
#include <vector>
#include <doctest.h>

struct wip_decode_testcase {
	std::string name;
	std::string key;
	libeosio::ec_privkey_t expected;
};

TEST_CASE("WIF::wif_priv_decode") {
	std::vector<struct wip_decode_testcase> tests {
		{ "one", "5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ",   { 0x0C, 0x28, 0xFC, 0xA3, 0x86, 0xC7, 0xA2, 0x27, 0x60, 0x0B, 0x2F, 0xE5, 0x0B, 0x7C, 0xAE, 0x11, 0xEC, 0x86, 0xD3, 0xBF, 0x1F, 0xBE, 0x47, 0x1B, 0xE8, 0x98, 0x27, 0xE1, 0x9D, 0x72, 0xAA, 0x1D } },
		{ "two", "5K2hm8apqz281ANDQdtVzifpxcXFTqG5E7Fc6Q5V2ssqPRQ3urJ",   { 0x9F, 0xE3, 0xE3, 0x2B, 0x3C, 0x4B, 0x6B, 0x91, 0x6E, 0x20, 0x6C, 0xB0, 0x91, 0xDF, 0x1F, 0x5E, 0x34, 0x32, 0x88, 0x0B, 0x41, 0x33, 0x86, 0xBD, 0xF2, 0x92, 0xFF, 0x23, 0x06, 0x43, 0xF2, 0x8C } },
		{ "three", "5JVanYq9HPvuKgr2FjATYB9NvTsJ4a3CAj5oPYKbr1Ja5MRLsZX", { 0x59, 0x3A, 0x51, 0xB5, 0x5D, 0x56, 0xAA, 0xF0, 0x5B, 0xD9, 0xD1, 0x0E, 0x6B, 0x88, 0x6D, 0xF9, 0xC4, 0x37, 0x09, 0xB2, 0x4C, 0xEC, 0xBB, 0x63, 0x68, 0x92, 0xC2, 0x94, 0x31, 0x48, 0x71, 0x8C } }
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {

		SUBCASE(it->name.c_str()) {

			libeosio::ec_privkey_t result;

			CHECK( libeosio::wif_priv_decode(result, it->key) );
			CHECK( result == it->expected );
		}
	}

}