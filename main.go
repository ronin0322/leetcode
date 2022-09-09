package main

import (
	"fmt"
	"sync"
)

type Node struct {
	k, v int
}

func main() {
	wg := sync.WaitGroup{}
	ch := make(chan int)
	ch2 := make(chan int)
	wg.Add(2)
	go func() {
		defer func() {
			wg.Done()
		}()
		for {
			idx := <-ch
			fmt.Println(idx)
			ch2 <- idx + 1
			if idx == 99 {
				return
			}
		}
	}()
	go func() {
		defer func() {
			wg.Done()
		}()
		for {
			idx := <-ch2
			fmt.Println(idx)
			if idx == 100 {
				return
			}
			ch <- idx + 1
		}
	}()
	ch <- 1
	wg.Wait()
}
