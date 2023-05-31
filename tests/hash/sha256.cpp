#include <libantelope/hash/sha256.hpp>
#include <string>
#include <vector>
#include <testing.h>

TEST_CASE("hash::sha256::sha256") {

	struct testcase {
		const char *name;
		std::string input;
		libantelope::sha256_t expected;
		bool valid;
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			"Suspendisse ut tincidunt quam. Praesent scelerisque risus vitae est consectetur, sed facilisis sem luctus. Praesent aliquet eros quis leo sodales, eget blandit diam scelerisque.",
			{
				0x1e, 0x54, 0x96, 0x86, 0x2f, 0x39, 0x44, 0xea,
				0x42, 0xa9, 0x0f, 0xad, 0x56, 0x79, 0x4b, 0x77,
				0x8f, 0xcc, 0x54, 0xf7, 0x7a, 0x32, 0x60, 0x37,
				0x4b, 0xac, 0xd5, 0x65, 0x74, 0xf7, 0xcf, 0x6c
			},
			true
		},
		{
			"valid #2",
			"Phasellus consectetur augue vitae massa vulputate placerat. Pellentesque nec eros a velit bibendum venenatis sit amet et augue. Morbi malesuada facilisis consequat.",
			{
				0x7c, 0x79, 0x4a, 0xf4, 0x9b, 0x5b, 0xb4, 0x0c,
				0xef, 0x4f, 0xaa, 0x65, 0xa4, 0x7c, 0x5f, 0xc5,
				0x95, 0x69, 0x49, 0x99, 0x6b, 0x08, 0x9b, 0xc0,
				0x40, 0x2d, 0x57, 0x8a, 0x90, 0x02, 0x42, 0x32,
			},
			true
		}
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libantelope::sha256_t dgst;

			CHECK( libantelope::sha256((const unsigned char*) it->input.c_str(), it->input.size(), &dgst) == &dgst );

			CHECK_PRED(doctest::toString(dgst), doctest::toString(it->expected), it->valid);
		}
	}
}

TEST_CASE("hash::sha256::sha256d") {

	struct testcase {
		const char *name;
		std::string input;
		libantelope::sha256_t expected;
#ifdef _MSC_VER
		char _; // sha256_t can't be last, wierd compiler bug on MSVC
#endif
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			"Suspendisse ut tincidunt quam. Praesent scelerisque risus vitae est consectetur, sed facilisis sem luctus. Praesent aliquet eros quis leo sodales, eget blandit diam scelerisque.",
			{
				0x4b, 0x6f, 0xa1, 0xf6, 0x30, 0x1e, 0xbe, 0x4a,
				0xc7, 0xef, 0x1e, 0x55, 0x3e, 0xdb, 0xc1, 0x31,
				0x1f, 0x6b, 0xf5, 0xc8, 0x04, 0xe9, 0x0e, 0xe3,
				0xbe, 0x66, 0x01, 0xbf, 0x70, 0x9f, 0x8e, 0x80,
			}
		},
		{
			"valid #2",
			"Vivamus ut elementum justo. Vestibulum lobortis rutrum libero sollicitudin aliquet. Nullam tempor urna non odio iaculis, sed pretium quam porttitor. Pellentesque pretium, justo vitae tristique porttitor, diam massa pulvinar neque, sed lacinia mi nulla sed nisi.",
			{
				0x1f, 0x3f, 0x1c, 0x48, 0xf6, 0xee, 0x24, 0x1f,
				0x6c, 0x41, 0x86, 0x69, 0xe3, 0x2f, 0x5e, 0x4d,
				0xa5, 0x51, 0x04, 0x8b, 0x11, 0x35, 0x47, 0xad,
				0x7e, 0xd9, 0xfb, 0x2e, 0x59, 0xee, 0x66, 0x21,
			}
		},
		{
			"valid #3",
			"Praesent ultrices consequat risus luctus faucibus.",
			{
				0xd5, 0x5f, 0x9c, 0xda, 0x2d, 0x93, 0x32, 0xc2,
				0x9b, 0xb1, 0xbb, 0x14, 0x55, 0x80, 0x72, 0xb7,
				0xba, 0x13, 0xa8, 0xc6, 0xa6, 0xbc, 0x65, 0xfc,
				0x49, 0xe0, 0x3b, 0x23, 0x04, 0x2a, 0x92, 0x8d,
			}
		}
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libantelope::sha256_t dgst;

			CHECK( libantelope::sha256d((const unsigned char*) it->input.c_str(), it->input.size(), &dgst) == &dgst );

			CHECK( doctest::toString(dgst) == doctest::toString(it->expected) );
		}
	}
}

TEST_CASE("hash::sha256::init/update/final") {

	struct testcase {
		const char *name;
		std::vector<std::string> inputs;
		libantelope::sha256_t expected;
#ifdef _MSC_VER
		char _; // sha256_t can't be last, wierd compiler bug on MSVC
#endif
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			{
				"Donec vestibulum enim commodo, faucibus nisi non, mattis quam.",
				"Nam sed nunc dapibus, auctor risus placerat, aliquet dolor",
			},
			{
				0x48, 0xc2, 0x34, 0x93, 0x3d, 0xae, 0x0d, 0xd0,
				0x28, 0xff, 0x5c, 0xa0, 0xca, 0xb1, 0x0a, 0xa3,
				0xe2, 0xa0, 0xa4, 0x7e, 0xb2, 0x71, 0xa5, 0x28,
				0x41, 0x03, 0x72, 0x20, 0xb5, 0x23, 0xc3, 0x67,
			}
		},
		{
			"valid #2",
			{
				"In tempus, lectus ac molestie venenatis, enim purus suscipit tortor",
				"sed sodales massa condimentum a",
				"Integer sit amet pretium magna",
				"Aenean non accumsan eros. Donec imperdiet justo tempor magna tincidunt malesuada",
				"Duis eu tortor ac massa sagittis elementum"
			},
			{
				0xfb, 0x12, 0x31, 0x9c, 0x2c, 0xe4, 0x94, 0x29,
				0xc9, 0xd3, 0xc7, 0x84, 0x0c, 0x58, 0x3d, 0x4c,
				0xde, 0xb5, 0x36, 0x59, 0x46, 0x69, 0xe1, 0x63,
				0xc5, 0x75, 0xb6, 0x94, 0x41, 0x5a, 0xd4, 0x62,
			}
		},
		{
			"valid #3",
			{
				"Donec tempus pellentesque lobortis. Integer pellentesque feugiat enim ac suscipit. Curabitur urna quam, condimentum sed bibendum eu",
				"Nullam lacinia ligula at ex gravida fermentum. Integer scelerisque accumsan iaculis. Suspendisse quis eros ut orci sollicitudin dignissim",
				"Nulla ligula tortor, tristique eget feugiat non, vehicula sit amet velit. Proin fermentum sagittis tincidunt. Nullam condimentum dapibus magna",
			},
			{
				0x19, 0xfb, 0x71, 0xb1, 0x47, 0x01, 0x7f, 0xf5,
				0xeb, 0xda, 0xc2, 0xd8, 0xe7, 0xab, 0xc9, 0xcb,
				0xea, 0x7d, 0x13, 0xa0, 0x2e, 0xe8, 0x48, 0x94,
				0x67, 0xc5, 0x14, 0xbf, 0x7d, 0x6f, 0x96, 0x83,
			}
		},
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libantelope::sha256_ctx_t ctx;
			libantelope::sha256_t dgst;

			CHECK_EQ(libantelope::sha256_init(&ctx), 1);

			for (auto in_it = it->inputs.begin(); in_it != it->inputs.end(); in_it++ ) {
				CHECK_EQ(libantelope::sha256_update(&ctx, (const unsigned char*) in_it->c_str(), in_it->size()), 1);
			}

			CHECK_EQ(libantelope::sha256_final(&ctx, &dgst), 1);

			CHECK( doctest::toString(dgst) == doctest::toString(it->expected) );
		}
	}

}