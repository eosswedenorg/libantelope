#include <libantelope/ec.hpp>
#include <doctest.h>

TEST_CASE("ec::generate") {

	libantelope::ec_init();

	libantelope::ec_pubkey_t result;
	libantelope::ec_keypair pair;
	CHECK(libantelope::ec_generate_key(&pair) == 0);

	// Can't test much because... well the private key should be random :)
	// But alteast verify that the public key belongs to the private key.
	CHECK(libantelope::ec_get_publickey(&pair.secret, &result) == 0);
	CHECK( result == pair.pub );

	libantelope::ec_shutdown();
}