#include "headers.h"


class Solution
{
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    ListNode LR;
    ListNode* pO = &LR;

    while (list1 != nullptr || list2 != nullptr) {
      if (nullptr == list1)
      {
        pO->next = list2;
        break;
      }

      if (nullptr == list2) 
      {
        pO->next = list1;
        break;
      }

      if (list1->val < list2->val) {
        pO->next = list1;
        pO = pO->next;
        list1 = list1->next;
      } else {
        pO->next = list2;
        pO = pO->next;
        list2 = list2->next;
      }
    }

    return LR.next;
  }
};

TEST(mergeTwoLists, mergeTwoLists_1)
{
    Solution s;
    List in1 = {1, 2, 4};
    List in2 = {1, 3, 4};
    List ans = {1, 1, 2, 3, 4, 4};

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(in1.head, in2.head), ans.head));
}

TEST(mergeTwoLists, mergeTwoLists_2)
{
    Solution s;
    List in1 = {};
    List in2 = {};
    List ans = {};

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(in1.head, in2.head), ans.head));
}

TEST(mergeTwoLists, mergeTwoLists_3)
{
    Solution s;
    List in1 = {};
    List in2 = {0};
    List ans = {0};

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(in1.head, in2.head), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
