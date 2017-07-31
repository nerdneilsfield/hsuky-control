package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

type control_data struct {
	Command string `json:"Command"`
}

func handler(rw http.ResponseWriter, req *http.Request) {
	decoder := json.NewDecoder(req.Body)
	var t control_data
	err := decoder.Decode(&t)
	if err != nil {
		panic(err)
	}
	err = ioutil.WriteFile("/var/ros/controller", []byte(t.Command), 0644)
	check(err)
	defer req.Body.Close()
	log.Println(t.Command)
	fmt.Fprintf(rw, "Hi there, I got command %s!", t.Command)
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":38080", nil))
}
