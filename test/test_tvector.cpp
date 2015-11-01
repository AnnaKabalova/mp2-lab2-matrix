#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(7);
	for (int i = 0; i < 7; i++)
		v[i] = i + 1;
	TVector<int> b(v);
	EXPECT_EQ(b, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(10);
	v1[7] = 1;
	TVector<int> v2(v1);
	v2[7] = 2;

	EXPECT_NE(v1, v2);

}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(7);
	ASSERT_ANY_THROW(v[-1] = 7);

}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(3);
	ASSERT_ANY_THROW(v[5] = 1);

}

TEST(TVector, can_assign_vector_to_itself)
{
	const int size = 7;
	TVector<int> vec(size);
	for (int i = 0; i < size; i++)
		vec[i] = i;
	vec = vec;
	EXPECT_EQ(vec, vec);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size = 7;
	TVector<int> a(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	b = a;
	EXPECT_EQ(b, a);

}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> a(7), b(5);
	a[1] = 1;
	b[2] = 2;
	a = b;

	EXPECT_EQ(a.GetSize(), b.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size)
{
	int size = 7;
	TVector<int> a(size + 3);
	TVector<int> b(size);
	TVector<int> c(size + 3);
	for (int i = 0; i < size + 3; i++)
		a[i] = i;
	b = a;
	for (int i = 0; i < size + 3; i++)
		c[i] = i;
	EXPECT_EQ(b, c);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	int size = 7;
	TVector<int> a(size + 3);
	TVector<int> b(size);
	for (int i = 0; i < size + 3; i++)
		a[i] = i;
	b = a;
	EXPECT_EQ(true, b == a);

}

TEST(TVector, compare_vector_with_itself_return_true)
{
	int size = 7;
	TVector<int> a(size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	EXPECT_EQ(true, a == a);

}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	int size = 7;
	TVector<int> a(size + 3);
	TVector<int> b(size);
	for (int i = 0; i < size + 3; i++)
		a[i] = i;
	for (int i = 0; i < size; i++)
		b[i] = i + 1;
	EXPECT_EQ(true, b != a);

}

TEST(TVector, can_add_scalar_to_vector)
{
	int size = 7;
	TVector<int> a(size);
	a = a + 5;
	ASSERT_NO_THROW(a);

}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int size = 7;
	TVector<int> a(size);
	for (int i = 0; i < size; i++)
		a[i] = i + 3;
	a = a - 1;
	ASSERT_NO_THROW(a);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int size = 7;
	TVector<int> a(size);
	for (int i = 0; i < size; i++)
		a[i] = i + 3;
	a = a * 2;
	ASSERT_NO_THROW(a);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int size = 7;
	TVector<int> a(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	b = a + a;
	EXPECT_EQ(a + a, b);

}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	int size = 7;
	TVector<int> a(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + size;
	ASSERT_ANY_THROW(b + a);

}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int size = 7;
	TVector<int> a(size);
	TVector<int> c(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		a[i] = i + 1;
	for (int i = 0; i < size; i++)
		b[i] = i + 2;
	c = b;
	b = b - a;
	EXPECT_EQ(c - a, b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	int size = 7;
	TVector<int> a(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + 10;
	ASSERT_ANY_THROW(b - a);

}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int size = 7;
	int s = 0;
	TVector<int> a(size);
	TVector<int> c(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	for (int i = 0; i < size; i++)
		b[i] = i + 1;
	s = a*b;
	EXPECT_EQ(s, a*b);

}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int size = 7;
	TVector<int> a(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		a[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + 1;
	ASSERT_ANY_THROW(b + a);

}

