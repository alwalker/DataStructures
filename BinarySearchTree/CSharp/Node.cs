using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree
{
    public class Node<T> : IEquatable<Node<T>>
    {
        public T Item { get; set; }
        public Node<T> Left { get; set; }
        public Node<T> Right { get; set; }
        public Node<T> Parent { get; set; }

        public Node(T item)
        {
            Item = item;
        }

        public bool Equals(Node<T> other)
        {
            if (other == null)
            {
                return false;
            }

            return
                object.ReferenceEquals(Right, other.Right) &&
                object.ReferenceEquals(Left, other.Left) &&
                Item.Equals(other.Item);
        }
    }
}
