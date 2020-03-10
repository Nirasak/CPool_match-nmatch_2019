/*
** EPITECH PROJECT, 2019
** test_match.c
** File description:
** tests match
*/

#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

Test(match, test_one)
{
    cr_assert_eq(match("test", "test"), 1);
}

Test(match, test_two)
{
    cr_assert_eq(match("Test", "*est"), 1);
}

Test(match, test_three)
{
    cr_assert(match("", ""));
}

Test(match, test_four)
{
    cr_assert_eq(match("test", "********"), 1);
}

Test(match, test_five)
{
    cr_assert_not(match("Test", ""));
    cr_assert_not(match("Test", "test"));
}

Test(match, test_six)
{
    cr_assert_eq(match("", "********"), 1);
}
