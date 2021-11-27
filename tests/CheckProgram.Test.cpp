#include <gtest/gtest.h>

TEST(WriteBinaryAddressTests, Test1)
{
  Address address;
  
  ASSERT_EQ(sizeof(Address), 84);
  
  strcpy(address.City, "Moscow");
  strcpy(address.Street, "Vernadsky prospect");
  address.BuildingNo = 78;
  
  WriteBinaryAddress("Mirea.bin", &address);
}

TEST(ReadBinaryAddressTests, Test1)
{
  Address address;
  
  ReadBinaryAddress("Mirea.bin", &address);
  
  ASSERT_STREQ(address.City, "Moscow");
  ASSERT_STREQ(address.Street, "Vernadsky prospect");
  ASSERT_EQ(address.BuildingNo, 78);
}

TEST(WriteTextAddressTests, Test1)
{
  Address address;
  
  strcpy(address.City, "Moscow");
  strcpy(address.Street, "Vernadsky prospect");
  address.BuildingNo = 78;
  
  WriteTextAddress("Mirea.txt", &address);
}

TEST(ReadTextAddressTests, Test1)
{
  Address address;
  
  ReadTextAddress("Mirea.txt", &address);
  
  ASSERT_STREQ(address.City, "Moscow");
  ASSERT_STREQ(address.Street, "Vernadsky prospect");
  ASSERT_EQ(address.BuildingNo, 78);
}

TEST(ReadTextAddressTests, Test2)
{
  Address address;
  
  ReadTextAddress("M.txt", &address);
  
  ASSERT_STREQ(address.City, "Moscow");
  ASSERT_STREQ(address.Street, "Red Square");
  ASSERT_EQ(address.BuildingNo, 9);
}
