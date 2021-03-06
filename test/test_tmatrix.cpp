#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(7);
	for (int i = 0; i < 7; i++)
		m[i][i] = i;
	TMatrix<int> n(m);
	EXPECT_EQ(m, n);

}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(7);
	m[1][2] = 3;
	TMatrix<int> n(m);
	n[1][2] = 5;

	EXPECT_NE(m[1][2], n[1][2]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m.GetSize());
	EXPECT_EQ(5, m.GetSize());

}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][2] = 3;
	EXPECT_EQ(3, m[1][2]);

}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(7);
	ASSERT_ANY_THROW(m[1][10] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5), n(5);
	m[2][3] = 1;
	n[2][3] = 1;
	ASSERT_NO_THROW(m = m);
	m = m;
	EXPECT_EQ(m, n);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(7), n(7), a(7);
	m[1][1] = 5;
	a[1][1] = 5;
	ASSERT_NO_THROW(n = m);
	EXPECT_EQ(a, n);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), n(7);
	m[1][1] = 5;
	ASSERT_NO_THROW(n = m);
	EXPECT_EQ(5, n.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), n(7), a(5);
	m[1][1] = 5;
	a[1][1] = 5;
	ASSERT_NO_THROW(n = m);
	EXPECT_EQ(a, n);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), n(5);
	m[1][1] = 5;
	n[1][1] = 5;
	ASSERT_TRUE(m == n);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(7);
	m[1][1] = 5;
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), n(7);
	m[1][1] = 7;
	n[1][1] = 7;
	EXPECT_NE(m, n);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), n(5), a(5);
	m[1][1] = 5;
	m[2][3] = 1;

	n[1][1] = 5;
	n[2][3] = 4;
	n[3][1] = 1;

	a[1][1] = 10;
	a[2][3] = 5;
	a[3][1] = 1;
	EXPECT_EQ(a, m + n);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), n(10);
	m[1][1] = 5;

	n[2][3] = 4;
	n[1][1] = 5;
	n[2][3] = 4;
	ASSERT_ANY_THROW(m + n);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), n(5), a(5);
	m[1][1] = 7;
	m[2][3] = 8;
	m[3][1] = 9;

	n[1][1] = 4;
	n[2][3] = 3;
	n[3][1] = 1;

	a[1][1] = 3;
	a[2][3] = 5;
	a[3][1] = 8;
	EXPECT_EQ(a, m - n);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), n(3);
	m[4][4] = 2;
	n[1][2] = 3;
	n[2][2] = 10;
	ASSERT_ANY_THROW(m - n);

}