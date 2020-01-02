#include <stdio.h>

#include <iostream>

#include "gtest/gtest.h"

#include "../include/Flags.h"
#include "unitFlug.h"

enum class TestFlug8: uint8_t
{
  TestValue00 = BIT(0),
  TestValue01 = BIT(1),
  TestValue02 = BIT(2),
  TestValue03 = BIT(3),
  TestValue04 = BIT(4),
  TestValue05 = BIT(5),
  TestValue06 = BIT(6),
  TestValue07 = BIT(7)
};

enum class TestFlug16 : uint16_t
{
  TestValue00 = BIT(0),
  TestValue01 = BIT(1),
  TestValue02 = BIT(2),
  TestValue03 = BIT(3),
  TestValue04 = BIT(4),
  TestValue05 = BIT(5),
  TestValue06 = BIT(6),
  TestValue07 = BIT(7),
  TestValue08 = BIT(8),
  TestValue09 = BIT(9),
  TestValue10 = BIT(10),
  TestValue11 = BIT(11),
  TestValue12 = BIT(12),
  TestValue13 = BIT(13),
  TestValue14 = BIT(14),
  TestValue15 = BIT(15)
};

enum class TestFlug32 : uint32_t
{
  TestValue00 = BIT(0),
  TestValue01 = BIT(1),
  TestValue02 = BIT(2),
  TestValue03 = BIT(3),
  TestValue04 = BIT(4),
  TestValue05 = BIT(5),
  TestValue06 = BIT(6),
  TestValue07 = BIT(7),
  TestValue08 = BIT(8),
  TestValue09 = BIT(9),
  TestValue10 = BIT(10),
  TestValue11 = BIT(11),
  TestValue12 = BIT(12),
  TestValue13 = BIT(13),
  TestValue14 = BIT(14),
  TestValue15 = BIT(15),
  TestValue16 = BIT(16),
  TestValue17 = BIT(17),
  TestValue18 = BIT(18),
  TestValue19 = BIT(19),
  TestValue20 = BIT(20),
  TestValue21 = BIT(21),
  TestValue22 = BIT(22),
  TestValue23 = BIT(23),
  TestValue24 = BIT(24),
  TestValue25 = BIT(25),
  TestValue26 = BIT(26),
  TestValue27 = BIT(27),
  TestValue28 = BIT(28),
  TestValue29 = BIT(29),
  TestValue30 = BIT(30),
  TestValue31 = BIT(31)
};

enum class TestFlug64 : uint64_t
{
  TestValue00 = BIT(0),
  TestValue01 = BIT(1),
  TestValue02 = BIT(2),
  TestValue03 = BIT(3),
  TestValue04 = BIT(4),
  TestValue05 = BIT(5),
  TestValue06 = BIT(6),
  TestValue07 = BIT(7),
  TestValue08 = BIT(8),
  TestValue09 = BIT(9),
  TestValue10 = BIT(10),
  TestValue11 = BIT(11),
  TestValue12 = BIT(12),
  TestValue13 = BIT(13),
  TestValue14 = BIT(14),
  TestValue15 = BIT(15),
  TestValue16 = BIT(16),
  TestValue17 = BIT(17),
  TestValue18 = BIT(18),
  TestValue19 = BIT(19),
  TestValue20 = BIT(20),
  TestValue21 = BIT(21),
  TestValue22 = BIT(22),
  TestValue23 = BIT(23),
  TestValue24 = BIT(24),
  TestValue25 = BIT(25),
  TestValue26 = BIT(26),
  TestValue27 = BIT(27),
  TestValue28 = BIT(28),
  TestValue29 = BIT(29),
  TestValue30 = BIT(30),
  TestValue31 = BIT(31),
  TestValue32 = BIT(32),
  TestValue33 = BIT(33),
  TestValue34 = BIT(34),
  TestValue35 = BIT(35),
  TestValue36 = BIT(36),
  TestValue37 = BIT(37),
  TestValue38 = BIT(38),
  TestValue39 = BIT(39),
  TestValue40 = BIT(40),
  TestValue41 = BIT(41),
  TestValue42 = BIT(42),
  TestValue43 = BIT(43),
  TestValue44 = BIT(44),
  TestValue45 = BIT(45),
  TestValue46 = BIT(46),
  TestValue47 = BIT(47),
  TestValue48 = BIT(48),
  TestValue49 = BIT(49),
  TestValue50 = BIT(50),
  TestValue51 = BIT(51),
  TestValue52 = BIT(52),
  TestValue53 = BIT(53),
  TestValue54 = BIT(54),
  TestValue55 = BIT(55),
  TestValue56 = BIT(56),
  TestValue57 = BIT(57),
  TestValue58 = BIT(58),
  TestValue59 = BIT(59),
  TestValue60 = BIT(60),
  TestValue61 = BIT(61),
  TestValue62 = BIT(62),
  TestValue63 = BIT(63)
};

DECLARE_FLAGS_OPERATORS(TestFlug8, uint8_t)
DECLARE_FLAGS_OPERATORS(TestFlug16, uint16_t)
DECLARE_FLAGS_OPERATORS(TestFlug32, uint32_t)
DECLARE_FLAGS_OPERATORS(TestFlug64, uint64_t)

//int main2()
//{
//
//  FLAGS16(TestFlug16) TF1({ TestFlug16::TestValue00, TestFlug16::TestValue02});
//
//  FLAGS16(TestFlug16) TF2 = TF1 & TestFlug16::TestValue03;
//
//  FLAGS16(TestFlug16) TF3 = TF1 | TestFlug16::TestValue03;
//
//  FLAGS16(TestFlug16) TF4 = TF3 & (TestFlug16::TestValue03 | TestFlug16::TestValue02 );
//
//  FLAGS16(TestFlug16) TF5(TestFlug16::TestValue00 | TestFlug16::TestValue02 );
//
//  FLAGS16(TestFlug16) TF6;
//
//  int d = 4;
//  d++;
//
//  return 0;
//}

template<typename EnumClass, typename EnumClassBaseType>
struct TesterFlugs
{
  //operator() =
  static void TestBasicAssignment(){
    EnumClass A = static_cast<EnumClass>(0);
    GTEST_ASSERT_EQ(static_cast<EnumClassBaseType>(A), 0 );
    GTEST_ASSERT_NE(A, EnumClass::TestValue00);
    A = EnumClass::TestValue07;
    GTEST_ASSERT_EQ(A, EnumClass::TestValue07);
    GTEST_ASSERT_NE(A, EnumClass::TestValue05);
    GTEST_ASSERT_NE(A, EnumClass::TestValue00);
    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> B(0);
    GTEST_ASSERT_EQ(B, static_cast<EnumClass>(0));
    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> C(-1);
    GTEST_ASSERT_NE(C, static_cast<EnumClass>(0));
    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> D;
    GTEST_ASSERT_EQ(D, static_cast<EnumClass>(0));
  }

  static void TestLogicalNegation()
  {
    EnumClass A = static_cast<EnumClass>(4);
    EnumClass B = static_cast<EnumClass>(8);

    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> a(EnumClass::TestValue02);
    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> b(EnumClass::TestValue03);

    GTEST_ASSERT_EQ(A != EnumClass::TestValue03, true);
    GTEST_ASSERT_EQ(A != B, true);
    GTEST_ASSERT_EQ(b != EnumClass::TestValue02, true);
    GTEST_ASSERT_EQ(b != A, true);

    B = EnumClass::TestValue02;
    b = EnumClass::TestValue02;

    GTEST_ASSERT_EQ(A != EnumClass::TestValue02, false);
    GTEST_ASSERT_EQ(A != B, false);
    GTEST_ASSERT_EQ(a != EnumClass::TestValue02, false);
    GTEST_ASSERT_EQ(b != A, false);
  }

  static void TestLogicalAND()
  {
    EnumClass A = static_cast<EnumClass>(4);
    EnumClass B = static_cast<EnumClass>(8);

    A &= B;

    uint64_t RawA_1 = static_cast<uint64_t>(A);

    GTEST_ASSERT_EQ(RawA_1, 0);

    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> a(EnumClass::TestValue02 | EnumClass::TestValue03 | EnumClass::TestValue01);

    EnumClassBaseType Rawa_1 = a;

    GTEST_ASSERT_EQ(Rawa_1, 14);
  }

  static void TestLogicalXOR()
  {
    EnumClass A = static_cast<EnumClass>(0xf0);
    EnumClass B = static_cast<EnumClass>(0x0f);

    uint8_t RawA_1 = static_cast<uint8_t>(A^B);

    GTEST_ASSERT_EQ(RawA_1, 0xff);

    EnumClassFlags::Flags<EnumClass, EnumClassBaseType> a(EnumClass::TestValue02 | EnumClass::TestValue03 | EnumClass::TestValue01);

    a^=0xff;

    EnumClassBaseType Rawa_1 = a;

    GTEST_ASSERT_EQ(static_cast<uint8_t>(Rawa_1), 241);
  }

  static void TestLogicalBitwises()
  {
    EnumClass A = EnumClass::TestValue02 << 1;
    EnumClass B = EnumClass::TestValue03;

    GTEST_ASSERT_EQ(A, B);

    A <<= 1;
    B <<= 1+1;
    A <<= 1;

    GTEST_ASSERT_EQ(A, B);

  }

};

TEST(Flags, BasicAssignment)
{
  TesterFlugs<TestFlug8, uint8_t>::TestBasicAssignment();
  TesterFlugs<TestFlug16, uint16_t>::TestBasicAssignment();
  TesterFlugs<TestFlug32, uint32_t>::TestBasicAssignment();
  TesterFlugs<TestFlug64, uint64_t>::TestBasicAssignment();
}

TEST(Flags, TestLogicalNegation)
{
  TesterFlugs<TestFlug8, uint8_t>::TestLogicalNegation();
  TesterFlugs<TestFlug16, uint16_t>::TestLogicalNegation();
  TesterFlugs<TestFlug32, uint32_t>::TestLogicalNegation();
  TesterFlugs<TestFlug64, uint64_t>::TestLogicalNegation();
}

TEST(Flags, TestLogical_AND_OR)
{
  TesterFlugs<TestFlug8, uint8_t>::TestLogicalAND();
  TesterFlugs<TestFlug16, uint16_t>::TestLogicalAND();
  TesterFlugs<TestFlug32, uint32_t>::TestLogicalAND();
  TesterFlugs<TestFlug64, uint64_t>::TestLogicalAND();
}

TEST(Flags, TestLogical_XOR)
{
  TesterFlugs<TestFlug8,  uint8_t>::TestLogicalXOR();
  TesterFlugs<TestFlug16, uint16_t>::TestLogicalXOR();
  TesterFlugs<TestFlug32, uint32_t>::TestLogicalXOR();
  TesterFlugs<TestFlug64, uint64_t>::TestLogicalXOR();
}

TEST(Flags, TestLogicalBitwises)
{
  TesterFlugs<TestFlug8,  uint8_t>::TestLogicalBitwises();
  TesterFlugs<TestFlug16, uint16_t>::TestLogicalBitwises();
  TesterFlugs<TestFlug32, uint32_t>::TestLogicalBitwises();
  TesterFlugs<TestFlug64, uint64_t>::TestLogicalBitwises();
}

//Subscript

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
