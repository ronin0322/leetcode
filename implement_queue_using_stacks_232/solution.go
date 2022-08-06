/*
 * @Author: ronin0322
 * @Date: 2022-08-06 10:33:32
 * @LastEditors: ronin0322
 * @LastEditTime: 2022-08-06 10:33:32
 * @FilePath: /leetcode/implement_queue_using_stacks_232/solution.go
 * @Description:
 *
 * Copyright (c) 2022 by ronin0322, All Rights Reserved.
 */
package implement_queue_using_stacks_232

type MyQueue struct {
	stack1, stack2 []int
}

func Constructor() MyQueue {
	return MyQueue{
		stack1: []int{},
		stack2: []int{},
	}
}

func (this *MyQueue) Push(x int) {
	this.stack1 = append(this.stack1, x)
}

func (this *MyQueue) Pop() int {
	res := this.Peek()
	this.stack2 = this.stack2[:len(this.stack2)-1]
	return res
}

func (this *MyQueue) Peek() int {
	if len(this.stack2) == 0 {
		for len(this.stack1) > 0 {
			this.stack2 = append(this.stack2, this.stack1[len(this.stack1)-1])
			this.stack1 = this.stack1[:len(this.stack1)-1]
		}
	}
	res := this.stack2[len(this.stack2)-1]
	return res
}

func (this *MyQueue) Empty() bool {
	return len(this.stack1) == 0 && len(this.stack2) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
