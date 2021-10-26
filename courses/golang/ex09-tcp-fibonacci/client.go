package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net"
	"os"
	"strconv"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	handleError(err)

	defer conn.Close()

	// var resp Response
	scan := bufio.NewScanner(os.Stdin)
	for scan.Scan() {
		input, err := strconv.ParseInt(scan.Text(), 10, 64)
		handleError(err)
		request := RequestFib{Number: int(input)}

		encoder := json.NewEncoder(conn)
		handleError(encoder.Encode(request))

		var resp ResponseFib
		decoder := json.NewDecoder(conn)
		handleError(decoder.Decode(&resp))

		fmt.Printf("%s %d\n", resp.Time, resp.Fib)
	}
}
