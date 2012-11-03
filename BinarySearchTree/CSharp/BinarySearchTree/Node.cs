using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree
{
    public class Node<T> : IEquatable<Node<T>>
    {
        private readonly T _item;

        public T Item { get { return _item; } }
        public Node<T> Left { get; set; }
        public Node<T> Right { get; set; }

        public Node(T item)
        {
            _item = item;
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
                _item.Equals(other.Item);
        }
    }
}
