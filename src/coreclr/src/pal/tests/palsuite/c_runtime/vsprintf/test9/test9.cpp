// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

/*=====================================================================
**
** Source:    test9.c
**
** Purpose:   Test #9 for the vsprintf function.
**
**
**===================================================================*/

#include <palsuite.h>
#include "../vsprintf.h"

/*
 * Notes: memcmp is used, as is strlen.
 */


PALTEST(c_runtime_vsprintf_test9_paltest_vsprintf_test9, "c_runtime/vsprintf/test9/paltest_vsprintf_test9")
{
    int neg = -42;
    int pos = 42;
    INT64 l = 42;
    
    if (PAL_Initialize(argc, argv) != 0)
    {
        return(FAIL);
    }

    DoNumTest("foo %i", pos, "foo 42");
    DoNumTest("foo %li", 0xFFFF, "foo 65535");
    DoNumTest("foo %hi", 0xFFFF, "foo -1");
    DoNumTest("foo %Li", pos, "foo 42");
    DoI64Test("foo %I64i", l, "42", "foo 42");
    DoNumTest("foo %3i", pos, "foo  42");
    DoNumTest("foo %-3i", pos, "foo 42 ");
    DoNumTest("foo %.1i", pos, "foo 42");
    DoNumTest("foo %.3i", pos, "foo 042");
    DoNumTest("foo %03i", pos, "foo 042");
    DoNumTest("foo %#i", pos, "foo 42");
    DoNumTest("foo %+i", pos, "foo +42");
    DoNumTest("foo % i", pos, "foo  42");
    DoNumTest("foo %+i", neg, "foo -42");
    DoNumTest("foo % i", neg, "foo -42");

    PAL_Terminate();
    return PASS;
}
