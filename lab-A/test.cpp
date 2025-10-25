#include "pch.h"
#include "DoublyLinkedList.h"
#include <gtest/gtest.h>
#include <cstring>

// ==================== createNode TESTS ====================

TEST(CreateNode_ValidString_ReturnValidNode_no1) {
    // Arrange
    const char* test_data = "test_string";

    // Act
    linkedListNode* result = createNode(test_data);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "test_string");
    EXPECT_EQ(result->next, nullptr);
    EXPECT_EQ(result->prev, nullptr);

    // Cleanup
    free(result->data);
    free(result);
}

TEST(CreateNode_EmptyString_ReturnValidNode_no2) {
    // Arrange
    const char* test_data = "";

    // Act
    linkedListNode* result = createNode(test_data);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "");
    EXPECT_EQ(result->next, nullptr);
    EXPECT_EQ(result->prev, nullptr);

    // Cleanup
    free(result->data);
    free(result);
}

TEST(CreateNode_LongString_ReturnValidNode_no3) {
    // Arrange
    const char* test_data = "very_long_string_abcdefghijklmnopqrstuvwxyz";

    // Act
    linkedListNode* result = createNode(test_data);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "very_long_string_abcdefghijklmnopqrstuvwxyz");
    EXPECT_EQ(result->next, nullptr);
    EXPECT_EQ(result->prev, nullptr);

    // Cleanup
    free(result->data);
    free(result);
}

// ==================== appendNode TESTS ====================

TEST(AppendNode_EmptyList_ReturnNewNode_no4) {
    // Arrange
    linkedListNode* head = nullptr;
    const char* test_data = "first_element";

    // Act
    linkedListNode* result = appendNode(head, test_data);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "first_element");
    EXPECT_EQ(result->next, nullptr);
    EXPECT_EQ(result->prev, nullptr);

    // Cleanup
    freeList(result);
}

TEST(AppendNode_SingleElementList_ReturnHeadWithNewNode_no5) {
    // Arrange
    linkedListNode* head = createNode("first");

    // Act
    linkedListNode* result = appendNode(head, "second");

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "first");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "second");
    EXPECT_EQ(result->next->prev, result);
    EXPECT_EQ(result->next->next, nullptr);

    // Cleanup
    freeList(result);
}

TEST(AppendNode_MultipleElements_ReturnHeadWithCorrectLinks_no6) {
    // Arrange
    linkedListNode* head = createNode("first");
    head = appendNode(head, "second");

    // Act
    linkedListNode* result = appendNode(head, "third");

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "first");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "second");
    ASSERT_NE(result->next->next, nullptr);
    EXPECT_STREQ(result->next->next->data, "third");
    EXPECT_EQ(result->next->next->prev, result->next);
    EXPECT_EQ(result->next->next->next, nullptr);

    // Cleanup
    freeList(result);
}

// ==================== listLength TESTS ====================

TEST(ListLength_EmptyList_ReturnZero_no7) {
    // Arrange
    linkedListNode* head = nullptr;

    // Act
    int result = listLength(head);

    // Assert
    EXPECT_EQ(result, 0);
}

TEST(ListLength_SingleElement_ReturnOne_no8) {
    // Arrange
    linkedListNode* head = createNode("single");

    // Act
    int result = listLength(head);

    // Assert
    EXPECT_EQ(result, 1);

    // Cleanup
    freeList(head);
}

TEST(ListLength_ThreeElements_ReturnThree_no9) {
    // Arrange
    linkedListNode* head = createNode("first");
    head = appendNode(head, "second");
    head = appendNode(head, "third");

    // Act
    int result = listLength(head);

    // Assert
    EXPECT_EQ(result, 3);

    // Cleanup
    freeList(head);
}

// ==================== bubbleSort TESTS ====================

TEST(BubbleSort_EmptyList_ReturnNull_no10) {
    // Arrange
    linkedListNode* head = nullptr;

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    EXPECT_EQ(result, nullptr);
}

TEST(BubbleSort_SingleElement_ReturnSameList_no11) {
    // Arrange
    linkedListNode* head = createNode("single");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "single");
    EXPECT_EQ(result->next, nullptr);
    EXPECT_EQ(result->prev, nullptr);

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_TwoElementsSorted_ReturnSameOrder_no12) {
    // Arrange
    linkedListNode* head = createNode("apple");
    head = appendNode(head, "banana");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "apple");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "banana");
    EXPECT_EQ(result->next->prev, result);

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_TwoElementsUnsorted_ReturnSortedOrder_no13) {
    // Arrange
    linkedListNode* head = createNode("banana");
    head = appendNode(head, "apple");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "apple");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "banana");
    EXPECT_EQ(result->next->prev, result);

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_ThreeElementsRandom_ReturnSortedOrder_no14) {
    // Arrange
    linkedListNode* head = createNode("cherry");
    head = appendNode(head, "apple");
    head = appendNode(head, "banana");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "apple");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "banana");
    ASSERT_NE(result->next->next, nullptr);
    EXPECT_STREQ(result->next->next->data, "cherry");
    EXPECT_EQ(result->next->prev, result);
    EXPECT_EQ(result->next->next->prev, result->next);

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_DuplicateElements_ReturnSortedOrder_no15) {
    // Arrange
    linkedListNode* head = createNode("beta");
    head = appendNode(head, "alpha");
    head = appendNode(head, "beta");
    head = appendNode(head, "gamma");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "alpha");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "beta");
    ASSERT_NE(result->next->next, nullptr);
    EXPECT_STREQ(result->next->next->data, "beta");
    ASSERT_NE(result->next->next->next, nullptr);
    EXPECT_STREQ(result->next->next->next->data, "gamma");

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_ReverseSorted_ReturnSortedOrder_no16) {
    // Arrange
    linkedListNode* head = createNode("delta");
    head = appendNode(head, "charlie");
    head = appendNode(head, "bravo");
    head = appendNode(head, "alpha");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "alpha");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "bravo");
    ASSERT_NE(result->next->next, nullptr);
    EXPECT_STREQ(result->next->next->data, "charlie");
    ASSERT_NE(result->next->next->next, nullptr);
    EXPECT_STREQ(result->next->next->next->data, "delta");

    // Cleanup
    freeList(result);
}

TEST(BubbleSort_SpecialCharacters_ReturnSortedOrder_no17) {
    // Arrange
    linkedListNode* head = createNode("123");
    head = appendNode(head, "!@#");
    head = appendNode(head, "abc");

    // Act
    linkedListNode* result = bubbleSort(head);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result->data, "!@#");
    ASSERT_NE(result->next, nullptr);
    EXPECT_STREQ(result->next->data, "123");
    ASSERT_NE(result->next->next, nullptr);
    EXPECT_STREQ(result->next->next->data, "abc");

    // Cleanup
    freeList(result);
}

// ==================== printList TESTS ====================
// Note: printList outputs to stdout, so we need to capture output

TEST(PrintList_EmptyList_PrintNull_no18) {
    // Arrange
    linkedListNode* head = nullptr;

    // Act & Assert
    testing::internal::CaptureStdout();
    printList(head);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, " -> NULL\n");
}

TEST(PrintList_SingleElement_PrintCorrectFormat_no19) {
    // Arrange
    linkedListNode* head = createNode("test");

    // Act & Assert
    testing::internal::CaptureStdout();
    printList(head);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "test -> NULL\n");

    // Cleanup
    freeList(head);
}

TEST(PrintList_MultipleElements_PrintCorrectFormat_no20) {
    // Arrange
    linkedListNode* head = createNode("first");
    head = appendNode(head, "second");
    head = appendNode(head, "third");

    // Act & Assert
    testing::internal::CaptureStdout();
    printList(head);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "first <-> second <-> third -> NULL\n");

    // Cleanup
    freeList(head);
}

// ==================== freeList TESTS ====================
// Note: freeList doesn't return anything, so we mainly test that it doesn't crash

TEST(FreeList_EmptyList_NoCrash_no21) {
    // Arrange
    linkedListNode* head = nullptr;

    // Act & Assert (should not crash)
    EXPECT_NO_FATAL_FAILURE(freeList(head));
}

TEST(FreeList_SingleElement_NoCrash_no22) {
    // Arrange
    linkedListNode* head = createNode("test");

    // Act & Assert (should not crash)
    EXPECT_NO_FATAL_FAILURE(freeList(head));
}

TEST(FreeList_MultipleElements_NoCrash_no23) {
    // Arrange
    linkedListNode* head = createNode("first");
    head = appendNode(head, "second");
    head = appendNode(head, "third");

    // Act & Assert (should not crash)
    EXPECT_NO_FATAL_FAILURE(freeList(head));
}