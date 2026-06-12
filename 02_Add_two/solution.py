# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode(0)
        carry = 0
        current = dummy_head

        while l1 is not None or l2 is not None or carry != 0:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            total = val1 + val2 + carry

            # use // to get the whole number result
            # use / to get the decimal result (more precise)
            carry = total // 10

            new_digit = total % 10
            
            # Attach the new node to the result list
            current.next = ListNode(new_digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2: 
                l2 = l2.next
        
        # the data structure now look like this:
        # head -> Node (7) -> Node (0) -> Node (8) -> None
        # dummy_head.next will return Node (7) and then it looks at its `.next` node to return (0) and then (8)
        return dummy_head.next