/*
 * +===============================================
 * | Author:        Tara Tandel (Tara.tandel.94@gmail.com)
 * |
 * | Creation Date: 12-01-2017
 * |
 * | File Name:     main.go
 * +===============================================
 */

package main

import "fmt"

type T struct {
	value int
}

func (left T) Compare(object Comparer) int {
	right, ok := object.(T)
	if !ok {
		return 0
	}
	return left.value - right.value
}

func main() {
	bst := BST{}

	bst.Insert(T{10})
	bst.Insert(T{10})
	bst.Insert(T{10})
	bst.Insert(T{10})
	bst.Insert(T{20})
	bst.Insert(T{20})
	bst.Insert(T{20})

	fmt.Println(bst.Find(T{10}))
}
