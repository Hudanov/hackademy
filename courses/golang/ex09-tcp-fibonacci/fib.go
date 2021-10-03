package main

import (
	"fmt"
	"math/big"
	"time"
)

type RequestFib struct {
	Number int
}

type ResponseFib struct {
	Number int
	Fib    *big.Int
	Time   time.Duration
}

var fibCache map[int]*big.Int

func fib(num int) *big.Int {
	if num < 0 {
		panic("num < 0")
	}

	if val, ok := fibCache[num]; ok {
		return val
	}

	size := len(fibCache)
	a := fibCache[size-2]
	b := fibCache[size-1]

	for i := size; i <= num; i++ {
		a.Add(a, b)
		fibCache[i] = a
		a, b = b, a
	}
	return b
}

func handleError(err error) {
	if err == nil {
		return
	}
	fmt.Println("Error: ", err.Error())
}
