#include <gtest/gtest.h>
#include <ForwardList/ForwardList.h>

// Test fixture class for setting up the list before each test
class ForwardListTest : public ::testing::Test {
protected:
    ForwardList<int> list;

    void SetUp() override {
        // Optional: Code here will run before each test.
    }

    void TearDown() override {
        // Optional: Code here will be called after each test.
    }
};

// Test: Verificar si la lista está vacía al inicio
TEST_F(ForwardListTest, ListIsEmptyInitially) {
    EXPECT_TRUE(list.empty());
}

// Test: Agregar elementos al frente y verificar tamaño
TEST_F(ForwardListTest, PushFrontIncreasesSize) {
    list.push_front(10);
    EXPECT_EQ(list.size(), 1);
    list.push_front(20);
    EXPECT_EQ(list.size(), 2);
}

// Test: Agregar elementos al final y verificar tamaño
TEST_F(ForwardListTest, PushBackIncreasesSize) {
    list.push_back(30);
    EXPECT_EQ(list.size(), 1);
    list.push_back(40);
    EXPECT_EQ(list.size(), 2);
}

// Test: Acceder a los elementos usando front() y back()
TEST_F(ForwardListTest, AccessElementsFrontAndBack) {
    list.push_front(10);
    list.push_back(20);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
}

// Test: Acceder a elementos por índice
TEST_F(ForwardListTest, AccessElementsByIndex) {
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    EXPECT_EQ(list[0], 20);
    EXPECT_EQ(list[1], 10);
    EXPECT_EQ(list[2], 30);
    EXPECT_EQ(list[3], 40);
}

// Test: Remover elementos del frente
TEST_F(ForwardListTest, PopFrontRemovesElement) {
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.pop_front(), 20);
    EXPECT_EQ(list.front(), 10);
}

// Test: Remover elementos del final
TEST_F(ForwardListTest, PopBackRemovesElement) {
    list.push_back(30);
    list.push_back(40);
    EXPECT_EQ(list.pop_back(), 40);
    EXPECT_EQ(list.back(), 30);
}

// Test: Verificar el tamaño de la lista después de eliminar
TEST_F(ForwardListTest, SizeAfterRemovals) {
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.pop_front();
    list.pop_back();
    EXPECT_EQ(list.size(), 1);
}

// Test: Invertir la lista
TEST_F(ForwardListTest, ReverseList) {
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.reverse();

    EXPECT_EQ(list[0], 30);
    EXPECT_EQ(list[1], 10);
    EXPECT_EQ(list[2], 20);
}

// Test: Limpiar la lista
TEST_F(ForwardListTest, ClearList) {
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}