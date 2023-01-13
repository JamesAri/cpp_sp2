#ifndef CPP_SP2_TESTS_H
#define CPP_SP2_TESTS_H

#include "emulator/MPInt.h"

// TODO: some negative tests

void arithmeticOperatorsTest() {
    MPInt<MPINT_UNLIMITED> num1(3);
    MPInt<MPINT_UNLIMITED> num2(10);
    assert(num2 - num1 == 7);
    assert(num2 + num1 == 13);
    assert(num2 / num1 == 3);
    assert(num2 * num1 == 30);

    assert(num2 - "3" == 7);
    assert(num2 + "3" == 13);
    assert(num2 / "3" == 3);
    assert(num2 * "3" == 30);

    assert(num2 - 3 == 7);
    assert(num2 + 3 == 13);
    assert(num2 / 3 == 3);
    assert(num2 * 3 == 30);
}

void relationalOperatorsTest() {
    MPInt<MPINT_UNLIMITED> num1(5);
    MPInt<MPINT_UNLIMITED> num2(10);

    assert(num1 != num2);
    assert(5 != num2);
    assert("5" != num2);
    assert(num1 != 10);
    assert(num1 != "10");

    assert(num2 > num1);
    assert(10 > num1);
    assert("10" > num1);
    assert(num2 > 5);
    assert(num2 > "5");

    assert(num1 < num2);
    assert(5 < num2);
    assert("5" < num2);
    assert(num1 < 10);
    assert(num1 < "10");

    num2 = num1;
    assert(num1 == num2);
    assert(5 == num2);
    assert("5" == num2);
    assert(num1 == 5);
    assert(num1 == "5");

    assert(num2 <= num1);
    assert(5 <= num1);
    assert("5" <= num1);
    assert(num2 <= 5);
    assert(num2 <= "5");

    assert(num2 >= num1);
    assert(5 >= num1);
    assert("5" >= num1);
    assert(num2 >= 5);
    assert(num2 >= "5");

    num1 += num2;
    assert(num1 == 10);
    num1 -= 5;
    assert(num1 == 5);
    num1 *= "2";
    assert(num1 == 10);
    num1 /= 3;
    assert(num1 == 3);
}

void streamsTest() {
    std::stringstream ss{"12345"};
    MPInt<MPINT_UNLIMITED> a;
    ss >> a;
    assert(a == 12345);

    ss.clear();
    ss << a;
    assert(ss.str() == "12345");
}

void toStringAndUnaryTest() {
    MPInt<MPINT_UNLIMITED> a = 100;
    assert("100" == a.to_string());
    a = -a;
    assert("-100" == a.to_string());
    a += -a;
    assert("0" == a.to_string());
}

void assigmentTest() {
    MPInt<MPINT_UNLIMITED> a;
    a = 100;
    assert(a == 100);
    assert(100 == a);
    a = "-50";
    assert(a == -50);
    assert(-50 == a);
    MPInt<MPINT_UNLIMITED> b;
    b = a;
    assert(b == -50);
    assert(-50 == b);
}

void constructorsTest() {
    MPInt<MPINT_UNLIMITED> a(10);
    MPInt<MPINT_UNLIMITED> b("20");
    MPInt<MPINT_UNLIMITED> c(a);
    assert(a == 10);
    assert(b == 20);
    assert(c == 10);
}

void overflowTest() {
    bool gotException = false;
    try {
        MPInt<4> a(INT_MAX);
        a += 1;
    } catch (OverflowException &ex) {
        gotException = true;
    }
    assert(gotException);
}

void unlimitedTest() {
    MPInt<MPINT_UNLIMITED> a(100);
    assert(factorial(a) ==
           "9332621544394415268169923885626670049071596826438162146859296389521759999322991"
           "5608941463976156518286253697920827223758251185210916864000000000000000000000000");
}

void runTests() {
    arithmeticOperatorsTest();
    relationalOperatorsTest();
    streamsTest();
    toStringAndUnaryTest();
    assigmentTest();
    constructorsTest();
    overflowTest();
    unlimitedTest();
}

#endif //CPP_SP2_TESTS_H
