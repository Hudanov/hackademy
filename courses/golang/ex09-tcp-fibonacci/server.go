package main

import (
	"encoding/json"
	"fmt"
	"math/big"
	"net"
	"time"
)



func main() {
	fibCache = make(map[int]*big.Int)
	fibCache[0] = big.NewInt(0)
	fibCache[1] = big.NewInt(1)

	fmt.Println("Booting up server...")
	const port string = "8080"

	ln, err := net.Listen("tcp", ":"+port)
	handleError(err)
	fmt.Printf("Listening on localhost:%v\n", port)
	conn, err := ln.Accept()
	handleError(err)

	for {
		var request RequestFib
		decoder := json.NewDecoder(conn)
		handleError(decoder.Decode(&request))

		start := time.Now()
		resp := ResponseFib{
			Number: request.Number,
			Fib:    fib(request.Number),
			Time:   time.Since(start),
		}

		enc := json.NewEncoder(conn)
		handleError(enc.Encode(resp))
	}
}
