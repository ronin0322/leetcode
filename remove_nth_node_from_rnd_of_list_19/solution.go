package removenthnodefromrndoflist19

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	prehead := &ListNode{0, head}
	fast, slow := prehead, prehead
	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	slow.Next = slow.Next.Next
	return prehead.Next
}
