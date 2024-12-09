#include "tmatrix.h"
#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v1(5);
	for (int i = 0; i < 5; ++i) v1[i] = i;
	TDynamicVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);
	EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[-1] = 10);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[5] = 10);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(4);
	v[0] = 4;
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(4), v2(4);
	v1[0] = 4;
	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(v2[0], v1[0]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(4), v2(2);
	v1[0] = 4;
	v2 = v1;
	EXPECT_EQ(4, v2.size());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; ++i) v1[i] = v2[i] = i;
	EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(4);
	for (int i = 0; i < 4; ++i) v[i] = i;
	v = v + 5;
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(6, v[1]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; ++i) v1[i] = v2[i] = i;
	TDynamicVector<int> v3 = v1 + v2;
	EXPECT_EQ(0, v3[0]);
	EXPECT_EQ(2, v3[1]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; ++i) v1[i] = v2[i] = i;
	TDynamicVector<int> v3 = v1 - v2;
	EXPECT_EQ(0, v3[0]);
	EXPECT_EQ(0, v3[1]);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 3;
	v2[0] = 4; v2[1] = 5; v2[2] = 6;

	int expected_result = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	EXPECT_EQ(expected_result, v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(v1 * v2);
}