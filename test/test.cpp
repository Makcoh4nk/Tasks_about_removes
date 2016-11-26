#include "gtest/gtest.h"
#include "TaskAboutDelete.h"

TEST(DeleteElemFromEnd, correct_delete)
{
	List *temp = NULL;
	int a[4], b[4] = { 1,2,3,5 };
	int count = 0;
	int j = 0;

	for (int i = 1; i <6; ++i)
		Add(&temp, i);
	deleteElemFromEnd(temp, 2);

	while (temp != NULL)
	{	
		a[j] = temp->data;
		temp = temp->next;
		++j;
	}
	
	for (int i = 0; i < 5; ++i)
		if (a[i] != b[i]) count = 1;
	EXPECT_EQ(count, 0);
}

TEST(DeleteElemFromEnd, incorrect_delete)
{
	List *temp = NULL;
	int a[4], b[4] = { 1,2,4,5 };
	int count = 0;
	int j = 0;

	for (int i = 1; i <6; ++i)
		Add(&temp, i);
	deleteElemFromEnd(temp, 2);

	while (temp != NULL)
	{
		a[j] = temp->data;
		temp = temp->next;
		++j;
	}

	for (int i = 0; i < 5; ++i)
		if (a[i] != b[i]) count = 1;
	EXPECT_EQ(count, 1);
}

TEST(DeleteElemFromEnd, can_not_delete_elem_with_negative_index)
{
	List *temp = NULL;
	for (int i = 1; i <4; ++i)
		Add(&temp, i);
	EXPECT_ANY_THROW(deleteElemFromEnd(temp, -1));
}

TEST(DeleteElemFromEnd, can_not_delete_elem_with_zero_index)
{
	List *temp = NULL;
	for (int i = 1; i <4; ++i)
		Add(&temp, i);
	EXPECT_ANY_THROW(deleteElemFromEnd(temp, 0));
}

TEST(DeleteElemFromEnd, can_not_delete_elem_with_too_big_index)
{
	List *temp = NULL;
	for (int i = 1; i <4; ++i)
		Add(&temp, i);
	EXPECT_ANY_THROW(deleteElemFromEnd(temp, 5));
}

TEST(DeleteElemFromEnd, can_not_delete_elem_from_empty_list)
{
	List *empty = NULL;
	EXPECT_ANY_THROW(deleteElemFromEnd(empty, 1));
}

//---------------------------------------------------------------------

TEST(DeleteRepeatElem, correct_delete)
{
	List *temp = NULL;
	int a[3], b[3] = { 1,2,3 };
	int count = 0;
	int j = 0;

	Add(&temp, 1);
	Add(&temp, 2);
	Add(&temp, 2);
	Add(&temp, 2);
	Add(&temp, 3);
	Add(&temp, 3);

	deleteRepeats(temp);

	while (temp != NULL)
	{
		a[j] = temp->data;
		temp = temp->next;
		++j;
	}

	for (int i = 0; i < 5; ++i)
		if (a[i] != b[i]) count = 1;
	EXPECT_EQ(count, 0);
}

TEST(DeleteRepeatElem, incorrect_delete)
{
	List *temp = NULL;
	int a[3], b[3] = { 1,2 };
	int count = 0;
	int j = 0;

	Add(&temp, 1);
	Add(&temp, 2);
	Add(&temp, 2);
	Add(&temp, 2);
	Add(&temp, 3);
	Add(&temp, 3);

	deleteRepeats(temp);

	while (temp != NULL)
	{
		a[j] = temp->data;
		temp = temp->next;
		++j;
	}

	for (int i = 0; i < 5; ++i)
		if (a[i] != b[i]) count = 1;
	EXPECT_EQ(count, 1);
}



TEST(DeleteRepeatElem, can_not_delete_elem_from_empty_list)
{
	List *empty = NULL;
	EXPECT_ANY_THROW(deleteRepeats(empty));
}



