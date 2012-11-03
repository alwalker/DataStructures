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
                        return;
                    }
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
    }
}
