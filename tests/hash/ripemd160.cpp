#include <libantelope/hash/ripemd160.hpp>
#include <string>
#include <vector>
#include <testing.h>

TEST_CASE("hash::ripemd160::ripemd160") {

	struct testcase {
		const char *name;
		std::string input;
		libantelope::ripemd160_t expected;
		bool valid;
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			"Morbi at egestas risus. Praesent blandit pharetra urna, nec porttitor risus sodales eu. Cras et volutpat elit, porta dapibus ipsum. Donec facilisis, eros nec imperdiet tristique, purus eros malesuada neque, quis interdum nisl risus nec leo.",
			{
				0xd9, 0x6a, 0x48, 0xf8, 0x2b, 0x39, 0xa9, 0x9f,
				0x22, 0xba, 0x3e, 0x01, 0x58, 0x5b, 0x15, 0xc7,
				0x7b, 0x0e, 0x5f, 0x50,
			},
			true
		},
		{
			"valid #2",
			"Donec eget mattis velit, vel vulputate sem. Suspendisse vulputate dolor vel est facilisis congue. Nulla non leo nulla. Proin lorem elit, sagittis eget congue in, pellentesque sed nisi. In pulvinar tortor fermentum suscipit varius.",
			{
				0x87, 0x1b, 0x87, 0xde, 0x2e, 0xb6, 0x8b, 0xb6,
				0xdc, 0x29, 0xe7, 0x40, 0xc3, 0xd1, 0x99, 0x42,
				0xad, 0x1a, 0xe3, 0x57
			},
			true
		}
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libantelope::ripemd160_t dgst;

			CHECK( libantelope::ripemd160((const unsigned char*) it->input.c_str(), it->input.size(), &dgst) == &dgst );

			CHECK_PRED(doctest::toString(dgst), doctest::toString(it->expected), it->valid);
		}
	}
}

TEST_CASE("hash::ripemd160::init/update/final") {

	struct testcase {
		const char *name;
		std::vector<std::string> inputs;
		libantelope::ripemd160_t expected;
#ifdef _MSC_VER
		char _; // ripemd160_t can't be last, wierd compiler bug on MSVC
#endif
	};

	std::vector<testcase> tests = {
		{
			"valid #1",
			{
				"tortor in congue luctus, tortor sapien condimentum quam, ac congue enim lacus vitae erat. Mauris dapibus eros bibendum",
				"Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae",
			},
			{
				0x30, 0x77, 0xaf, 0x6b, 0x43, 0x0b, 0x94, 0x8d,
				0x59, 0x4e, 0xc7, 0xbb, 0x1a, 0x2b, 0xc3, 0x08,
				0xaa, 0xf0, 0x75, 0x3a
			}
		},
		{
			"valid #2",
			{
				"Cras suscipit, mi sit amet pretium blandit, massa felis aliquet eros",
				"Aenean efficitur nibh quis enim mollis blandit",
				"Vestibulum posuere tempus mi nec cursus"
			},
			{
				0xf1, 0xcf, 0xea, 0xf7, 0xef, 0x3a, 0x0f, 0x80,
				0x26, 0x75, 0x40, 0x75, 0xe0, 0x9d, 0x89, 0x05,
				0xd1, 0x29, 0xe5, 0xf6
			}
		},
		{
			"valid #3",
			{
				"Donec nec blandit dui. Nulla et tempus odio, id fermentum neque. Nam vitae nunc leo. Aliquam dictum velit nec neque dignissim maximus nec at tellus",
				"Proin elementum porttitor odio, ut ullamcorper justo rutrum in. Proin dignissim nec diam a eleifend. Duis consequat ultrices purus sed finibus",
				"Donec eget ante dictum, scelerisque metus eget, mollis velit. Curabitur elementum fermentum lorem, a fringilla velit ultrices non"
			},
			{
				0xbb, 0x25, 0x58, 0xa9, 0xd0, 0xc1, 0x23, 0xef,
				0x55, 0xac, 0x2d, 0x8c, 0xd5, 0xd6, 0xe1, 0x49,
				0x00, 0x5d, 0x86, 0xe8
			}
		},
	};

	for(auto it = tests.begin(); it != tests.end(); it++) {
		SUBCASE(it->name) {
			libantelope::ripemd160_ctx_t ctx;
			libantelope::ripemd160_t dgst;

			CHECK_EQ(libantelope::ripemd160_init(&ctx), 1);

			for (auto in_it = it->inputs.begin(); in_it != it->inputs.end(); in_it++ ) {
				CHECK_EQ(libantelope::ripemd160_update(&ctx, (const unsigned char*) in_it->c_str(), in_it->size()), 1);
			}

			CHECK_EQ(libantelope::ripemd160_final(&ctx, &dgst), 1);

			CHECK( doctest::toString(dgst) == doctest::toString(it->expected) );
		}
	}

}