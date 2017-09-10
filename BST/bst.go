/*
 * +===============================================
 * | Author:        Tara Tandel (Tara.tandel.94@gmail.com)
 * |
 * | Creation Date: 12-01-2017
 * |
 * | File Name:     bst.go
 * +===============================================
 */

package main

type Comparer interface {
	Compare(Comparer) int
}

type node struct {
	right *node
	left  *node
	value Comparer
	times int
}

type BST struct {
	root *node
}

func (b *BST) Insert(v Comparer) {
	var n node
	n.value = v
	n.times = 1

	if b.root == nil {
		b.root = &n
		return
	}

	it := b.root
	for {
		c := it.value.Compare(v)

		if c < 0 {
			if it.left == nil {
				it.left = &n
				return
			}
			it = it.left
		} else if c > 0 {
			if it.right == nil {
				it.right = &n
				return
			}
			it = it.right
		} else {
			it.times++
			return
		}
	}
}

func (b *BST) Find(v Comparer) int {
	it := b.root
	for it != nil {
		c := it.value.Compare(v)

		if c < 0 {
			it = it.left
		} else if c > 0 {
			it = it.right
		} else {
			return it.times
		}
	}

	return 0
}
