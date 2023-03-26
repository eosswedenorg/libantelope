#include <libeosio/ec.hpp>
#include <vector>
#include <doctest.h>

TEST_CASE("ec::ecdsa_recover") {

	struct testcase {
		const char *name;
		libeosio::sha256_t dgst;
		libeosio::ec_signature_t sig;
		libeosio::ec_pubkey_t expected;
		int expectedRet;
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			{
				0xab, 0x53, 0x0a, 0x13, 0xe4, 0x59, 0x14, 0x98,
				0x2b, 0x79, 0xf9, 0xb7, 0xe3, 0xfb, 0xa9, 0x94,
				0xcf, 0xd1, 0xf3, 0xfb, 0x22, 0xf7, 0x1c, 0xea,
				0x1a, 0xfb, 0xf0, 0x2b, 0x46, 0x0c, 0x6d, 0x1d
			},
			// SIG_K1_KdgBih1poWj8DYZXwLxMdjaHMzYhuAVp7XshR9ZjrZSubZwsgSpiyUKXu44NmCtKgRFswmqKaioWLTuGZrXwYPsSNCSyyr
			{
				0x20, 0x44, 0x3f, 0x72, 0x22, 0xfd, 0x7a, 0x1f, 0x56, 0x2d, 0xef, 0x01, 0x55, 0x40, 0xcf, 0x50, 0x6f, 0x5f, 0xdd, 0xfe, 0x71, 0xd7, 0x18, 0xc9, 0xa8, 0xc8, 0xbe, 0x00, 0x96, 0xf8, 0x7c, 0xc7,
				0x1f, 0x2d, 0xd0, 0xd1, 0xfc, 0x4a, 0x22, 0x6a, 0x25, 0xc4, 0x7c, 0x99, 0xf9, 0xd8, 0x30, 0xfa, 0x8b, 0x5c, 0x33, 0x36, 0x61, 0xd7, 0xcf, 0x6d, 0x04, 0x97, 0x61, 0x76, 0x47, 0x65, 0x30, 0x7b,
				0x66
			},
			// Public Key: EOS6zjfj9Xjk9CYoucZDptdDZ6317eZd622pVvaYtv5q6gwEs9icD
			{ 0x03, 0x15, 0x93, 0x8a, 0x8e, 0x1d, 0x57, 0x84, 0x9f, 0xab, 0x07, 0x18, 0x67, 0xb5, 0x0c, 0xda, 0xb0, 0x77, 0x62, 0x29, 0xb6, 0x43, 0xb8, 0x67, 0x56, 0xc7, 0xb3, 0xe8, 0x7f, 0xe6, 0x08, 0xf8, 0x4b },
			0
		},
		{
			"valid #2",
			{
				0x19, 0xd3, 0xe0, 0x8b, 0xbb, 0xad, 0x5f, 0x02,
				0x35, 0xa8, 0xa8, 0xf8, 0x1a, 0x7f, 0xa1, 0xe0,
				0xf8, 0x50, 0xdd, 0x39, 0x12, 0xe3, 0xc6, 0x55,
				0xb4, 0x35, 0xd4, 0x78, 0x6b, 0x93, 0x64, 0xa6
			},
			// SIG_K1_K4XXx6oSYBzcwzscMstvSxruxdkTCinyN9dnRo4DuBkCCpQbCJQcJmbE7aAmNueBYCccHyyDK5JDfMpvewRF2rGUFtSE2y
			{
				0x1f, 0x46, 0xde, 0x7a, 0x7e, 0x87, 0xa7, 0xb0, 0x42, 0xce, 0xdc, 0x57, 0xc9, 0x0d, 0x64, 0x4c, 0xc7, 0x4d, 0xe6, 0x19, 0x5d, 0x34, 0x4e, 0xba, 0xfb, 0xdf, 0x26, 0x79, 0xa1, 0xc6, 0x99, 0x98,
				0xa7, 0x1f, 0x65, 0xcd, 0xab, 0x2d, 0x19, 0x75, 0x27, 0xdc, 0xb2, 0xc5, 0x46, 0x87, 0x5d, 0xbe, 0xc5, 0x8d, 0xb2, 0xb8, 0x7f, 0x15, 0x47, 0xd7, 0xc7, 0x94, 0x0a, 0xd5, 0x52, 0xd9, 0xe3, 0x93,
				0xd7
			},
			// Public Key: EOS6tVtKhTpM6yU7kkiRz1AecDJPcBQo2w4x4oytJbJi5PMV2Rcw2
			{ 0x03, 0x07, 0x69, 0xbb, 0xa5, 0x2c, 0xd2, 0xe1, 0x3b, 0x3e, 0x0a, 0x40, 0xb3, 0xa2, 0x44, 0xad, 0x71, 0x6e, 0x32, 0x64, 0x9c, 0x3a, 0x64, 0x27, 0x4f, 0x31, 0x86, 0x8a, 0x4c, 0x69, 0x58, 0x86, 0x49 },
			0
		},
		{
			"valid #3",
			{
				0x1b, 0x01, 0x0b, 0xe5, 0xce, 0x6a, 0x49, 0xc7,
				0xcd, 0x04, 0x86, 0x0d, 0xef, 0x63, 0x1c, 0x6a,
				0xcc, 0xd5, 0x17, 0x47, 0x2e, 0x74, 0x5b, 0xa6,
				0xc8, 0xaf, 0x26, 0x1b, 0x15, 0x7e, 0x11, 0xec
			},
			// SIG_K1_K54CVeQjFREm9Z92jutWESZWb9WQfCRZ2KfMtisfsnxedppeSMxTrZ9fYDLiJTfE79zvLCHb5NysAEcNdh7HiBvtU4Ahhh
			{
				0x1f, 0x4a, 0xe9, 0x04, 0x20, 0xfa, 0x7b, 0x9d, 0x56, 0xc6, 0x00, 0x5c, 0x83, 0x70, 0xa9, 0x26, 0x41, 0x7d, 0xe8, 0xeb, 0xe7, 0x75, 0xea, 0x6f, 0x75, 0xa7, 0x7c, 0x98, 0x10, 0x27, 0xbf, 0xce,
				0x48, 0x41, 0x74, 0xb0, 0xe3, 0xb1, 0x4b, 0x06, 0x2c, 0x53, 0x93, 0xbc, 0x35, 0xea, 0xac, 0xd7, 0x9e, 0x07, 0xa7, 0xa1, 0x2e, 0xac, 0xa0, 0x81, 0x45, 0xdb, 0xd4, 0x53, 0x68, 0xda, 0xaa, 0xc6,
				0xfc
			},
			// Public Key: EOS7Xtaa4y44gYapth4MH5bdtCvdtQvVLdsW7a8thVAuvNAkj8X7i
			{ 0x03, 0x5c, 0x50, 0x81, 0xef, 0xa6, 0x46, 0x00, 0x5a, 0xb9, 0xd8, 0x2b, 0xfe, 0xd8, 0xe1, 0x6d, 0x15, 0x42, 0x9e, 0x9a, 0xcb, 0xc9, 0xd6, 0xb3, 0x2e, 0x5a, 0xe3, 0xed, 0xa5, 0x8d, 0x6a, 0x42, 0x6c },
			0
		},
		{
			"not valid #1 (non valid signature)",
			{
				0xde, 0x01, 0x64, 0x03, 0x39, 0x01, 0x66, 0x8b,
				0xa0, 0x39, 0xef, 0x31, 0x61, 0xc7, 0xc8, 0x9d,
				0x15, 0x4b, 0xc6, 0x7b, 0x99, 0x5c, 0xba, 0x9b,
				0x23, 0x8a, 0x76, 0x4b, 0x81, 0xf2, 0xff, 0xeb
			},
			{
				0x1f, 0x4b, 0xe9, 0x04, 0x20, 0xfa, 0x7b, 0x9d, 0x56, 0xc6, 0x00, 0x5c, 0x83, 0x70, 0xa9, 0x26, 0x41, 0x7d, 0xe8, 0xeb, 0xe7, 0x75, 0xea, 0x6f, 0x75, 0xa7, 0x7c, 0x98, 0x10, 0x27, 0xbf, 0xce,
				0x48, 0x41, 0x74, 0xb0, 0xe3, 0xb1, 0x4b, 0x06, 0x2c, 0x53, 0x93, 0xbc, 0x35, 0xea, 0xac, 0xd7, 0x9e, 0x07, 0xa7, 0xa1, 0x2e, 0xac, 0xa0, 0x81, 0x45, 0xdb, 0xd4, 0x53, 0x68, 0xda, 0xaa, 0xc6,
				0xfe
			},
			{ },
			-1
		},
	};

	libeosio::ec_init();

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libeosio::ec_pubkey_t result;

			CHECK( libeosio::ecdsa_recover(&it->dgst, it->sig, result) == it->expectedRet );

			if (it->expectedRet == 0) {
				CHECK( result == it->expected );
			}
		}
	}
	libeosio::ec_shutdown();
}

