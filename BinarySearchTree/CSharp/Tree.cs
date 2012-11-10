using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree
{
    public class Tree<T> where T : IComparable
    {
        private Node<T> _root;

        public Node<T> Root { get { return _root; } }

        public void Add(T item)
        {
            if (_root == null)
            {
                _root = new Node<T>(item);
                return;
            }

            var currentNode = _root;

            while (currentNode != null)
            {
                if (currentNode.Item.CompareTo(item) > 0)
                {
                    if (currentNode.Left != null)
                    {
                        currentNode = currentNode.Left;
                    }
                    else
                    {
                        currentNode.Left = new Node<T>(item);
                        currentNode.Left.Parent = currentNode;
                        return;
                    }
                }
                else if (currentNode.Item.CompareTo(item) < 0)
                {
                    if (currentNode.Right != null)
                    {
                        currentNode = currentNode.Right;
                    }
                    else
                    {
                        currentNode.Right = new Node<T>(item);
                        currentNode.Right.Parent = currentNode;
                        return;
                    }
                }
                else
                {
                    return;
                }
            }
        }

        public Node<T> Find(T item)
        {
            Node<T> result = null;
            var currentNode = _root;

            while (currentNode != null)
            {
                if (currentNode.Item.CompareTo(item) > 0)
                {
                    currentNode = currentNode.Left;
                }
                else if (currentNode.Item.CompareTo(item) < 0)
                {
                    currentNode = currentNode.Right;
                }
                else
                {
                    result = currentNode;
                    break;
                }
            }

            return result;
        }

        public void Delete(T item)
        {
            InnerDelete(_root, item);
        }

        private void InnerDelete(Node<T> node, T item)
        {
            if (node == null)
            {
                return;
            }
            else if (item.CompareTo(node.Item) == 0)
            {
                if (node.Left != null && node.Right != null)
                {
                    node.Item = node.Left.Item;
                    InnerDelete(node.Left, node.Left.Item);
                }

                if (node.Parent == null)
                {
                    if (node.Left == null && node.Right == null)
                    {
                        _root = null;
                    }
                    else if (node.Left != null && node.Right == null)
                    {
                        _root = node.Left;
                    }
                    else if (node.Right != null && node.Left == null)
                    {
                        _root = node.Right;
                    }
                }
                else if (node.Parent.Left == node)
                {
                    if (node.Left == null && node.Right == null)
                    {
                        node.Parent.Left = null;
                    }
                    else if (node.Left != null && node.Right == null)
                    {
                        node.Parent.Left = node.Left;
                    }
                    else if (node.Right != null && node.Left == null)
                    {
                        node.Parent.Left = node.Right;
                    }
                }
                else
                {
                    if (node.Left == null && node.Right == null)
                    {
                        node.Parent.Right = null;
                    }
                    else if (node.Left != null && node.Right == null)
                    {
                        node.Parent.Right = node.Left;
                    }
                    else if (node.Right != null && node.Left == null)
                    {
                        node.Parent.Right = node.Right;
                    }
                }
            }
            else if (item.CompareTo(node.Item) < 0)
            {
                InnerDelete(node.Left, item);
            }
            else
            {
                InnerDelete(node.Right, item);
            }
        }

        public void InOrderTraversal(Action<T> callback)
        {
            InnerInOrder(callback, _root);
        }

        private void InnerInOrder(Action<T> callback, Node<T> node)
        {
            if (node == null)
            {
                return;
            }

            InnerInOrder(callback, node.Left);
            callback(node.Item);
            InnerInOrder(callback, node.Right);
        }
    }
}
