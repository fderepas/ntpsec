extern "C" {
#include "unity.h"
#include "unity_fixture.h"
}

TEST_GROUP(recvbuff);

TEST_SETUP(recvbuff) {}

TEST_TEAR_DOWN(recvbuff) {}

#include "libntptest.h"

extern "C" {
#include "recvbuff.h"
};

class recvbuffTest : public libntptest {
protected:
	virtual void SetUp() {
		init_recvbuff(RECV_INIT);
	}
};

TEST(recvbuff, Initialization) {
	TEST_ASSERT_EQUAL(RECV_INIT, free_recvbuffs());
	TEST_ASSERT_EQUAL(0, full_recvbuffs());
	TEST_ASSERT_FALSE(has_full_recv_buffer());
	TEST_ASSERT_TRUE(get_full_recv_buffer() == NULL);
}

TEST(recvbuff, GetAndFree) {
	int initial = free_recvbuffs();
	recvbuf_t* buf = get_free_recv_buffer();

	TEST_ASSERT_EQUAL(initial-1, free_recvbuffs());
	freerecvbuf(buf);
	TEST_ASSERT_EQUAL(initial, free_recvbuffs());
}

TEST(recvbuff, GetAndFill) {
	int initial = free_recvbuffs();
	recvbuf_t* buf = get_free_recv_buffer();

	add_full_recv_buffer(buf);
	TEST_ASSERT_EQUAL(1, full_recvbuffs());
	TEST_ASSERT_TRUE(has_full_recv_buffer());
	TEST_ASSERT_EQUAL(buf, get_full_recv_buffer());
}
