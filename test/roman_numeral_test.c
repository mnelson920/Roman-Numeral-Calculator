/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "check_rncalc.check" instead.
 */

#include <check.h>

#line 1 "check_rncalc.check"
#include "../src/roman_numeral.h"

START_TEST(romanLetterValue_test)
{
#line 4
    ck_assert_int_eq(romanLetterValue('I'), 1);
    ck_assert_int_eq(romanLetterValue('V'), 5);
    ck_assert_int_eq(romanLetterValue('X'), 10);
    ck_assert_int_eq(romanLetterValue('L'), 50);
    ck_assert_int_eq(romanLetterValue('C'), 100);
    ck_assert_int_eq(romanLetterValue('D'), 500);
    ck_assert_int_eq(romanLetterValue('M'), 1000);

}
END_TEST

START_TEST(romanToInt_test)
{
#line 13
    ck_assert_int_eq(romanToInt("IX"), 9);
    ck_assert_int_eq(romanToInt("VI"), 6);
    ck_assert_int_eq(romanToInt("III"), 3);
    ck_assert_int_eq(romanToInt("LXVIII"), 68);
    ck_assert_int_eq(romanToInt("XXXXIX"), 49);

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, romanLetterValue_test);
    tcase_add_test(tc1_1, romanToInt_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
