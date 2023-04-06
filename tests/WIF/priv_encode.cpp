#include <libantelope/WIF.hpp>
#include <libantelope/ec.hpp>
#include <iostream>
#include <vector>
#include <doctest.h>

TEST_CASE("WIF::wif_priv_encode [Legacy]") {

	struct testcase {
		std::string name;
		const std::string prefix;
		libantelope::ec_privkey_t key;
		std::string expected;
	};

	std::vector<struct testcase> tests {
		{ "one", libantelope::WIF_PVT_LEG, { 0x0C, 0x28, 0xFC, 0xA3, 0x86, 0xC7, 0xA2, 0x27, 0x60, 0x0B, 0x2F, 0xE5, 0x0B, 0x7C, 0xAE, 0x11, 0xEC, 0x86, 0xD3, 0xBF, 0x1F, 0xBE, 0x47, 0x1B, 0xE8, 0x98, 0x27, 0xE1, 0x9D,0x72,0xAA,0x1D}, "5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ" },
		{ "two", libantelope::WIF_PVT_LEG, { 0x9F, 0xE3, 0xE3, 0x2B, 0x3C, 0x4B, 0x6B, 0x91, 0x6E, 0x20, 0x6C, 0xB0, 0x91, 0xDF, 0x1F, 0x5E, 0x34, 0x32, 0x88, 0x0B, 0x41, 0x33, 0x86, 0xBD, 0xF2, 0x92, 0xFF, 0x23, 0x06, 0x43, 0xF2, 0x8C}, "5K2hm8apqz281ANDQdtVzifpxcXFTqG5E7Fc6Q5V2ssqPRQ3urJ" },
		{ "three", libantelope::WIF_PVT_LEG, { 0x59, 0x3A, 0x51, 0xB5, 0x5D, 0x56, 0xAA, 0xF0, 0x5B, 0xD9, 0xD1, 0x0E, 0x6B, 0x88, 0x6D, 0xF9, 0xC4, 0x37, 0x09, 0xB2, 0x4C, 0xEC, 0xBB, 0x63, 0x68, 0x92, 0xC2, 0x94, 0x31, 0x48, 0x71, 0x8C}, "5JVanYq9HPvuKgr2FjATYB9NvTsJ4a3CAj5oPYKbr1Ja5MRLsZX" }
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {

		SUBCASE(it->name.c_str()) {
			CHECK( libantelope::wif_priv_encode(it->key, it->prefix) == it->expected );
		}
	}
}

TEST_CASE("WIF::wif_priv_encode [K1]") {

	struct testcase {
		std::string name;
		const std::string prefix;
		libantelope::ec_privkey_t key;
		std::string expected;
	};

	std::vector<struct testcase> tests {
		{ "one", libantelope::WIF_PVT_K1, { 0x0C, 0x28, 0xFC, 0xA3, 0x86, 0xC7, 0xA2, 0x27, 0x60, 0x0B, 0x2F, 0xE5, 0x0B, 0x7C, 0xAE, 0x11, 0xEC, 0x86, 0xD3, 0xBF, 0x1F, 0xBE, 0x47, 0x1B, 0xE8, 0x98, 0x27, 0xE1, 0x9D,0x72,0xAA,0x1D}, "PVT_K1_6Mcb23muAxyXaSMhmB6B1mqkvLdWhtuFZmnZsxDczHRvQdp32" },
		{ "two", libantelope::WIF_PVT_K1, { 0x9F, 0xE3, 0xE3, 0x2B, 0x3C, 0x4B, 0x6B, 0x91, 0x6E, 0x20, 0x6C, 0xB0, 0x91, 0xDF, 0x1F, 0x5E, 0x34, 0x32, 0x88, 0x0B, 0x41, 0x33, 0x86, 0xBD, 0xF2, 0x92, 0xFF, 0x23, 0x06, 0x43, 0xF2, 0x8C}, "PVT_K1_2DRBT8jmXT8k9ywNSSbufvhk1hLFhPzWJBpsE2jo12CDoFhcc1" },
		{ "three", libantelope::WIF_PVT_K1, { 0x59, 0x3A, 0x51, 0xB5, 0x5D, 0x56, 0xAA, 0xF0, 0x5B, 0xD9, 0xD1, 0x0E, 0x6B, 0x88, 0x6D, 0xF9, 0xC4, 0x37, 0x09, 0xB2, 0x4C, 0xEC, 0xBB, 0x63, 0x68, 0x92, 0xC2, 0x94, 0x31, 0x48, 0x71, 0x8C}, "PVT_K1_gJCsP4CwMv4gTkDXiZT8QFhs3NrSB7Sv22ANGrc8Svun9uC9C" }
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {

		SUBCASE(it->name.c_str()) {
			CHECK( libantelope::wif_priv_encode(it->key, it->prefix) == it->expected );
		}
	}
}
