using System;
using System.Collections.Generic;
using System.Linq;
using NUnit.Framework;

namespace BinarySearchTree
{
    [TestFixture]
    public class Tests
    {
        [Test]
        public void ConstructorReturnsEmtpyRoot()
        {
            var t = new Tree<int>();

            Assert.IsNull(t.Root);
        }

        [Test]
        public void FirstAddIsRoot()
        {
            var t = new Tree<int>();

            t.Add(23);

            Assert.AreEqual(23, t.Root.Item);
        }

        [Test]
        public void AddingTwo_SmallerGoesToLeft()
        {
            var t = new Tree<int>();

            t.Add(23);
            t.Add(1);

            Assert.AreEqual(1, t.Root.Left.Item);
        }

        [Test]
        public void AddingTwo_LargerGoesToRight()
        {
            var t = new Tree<int>();

            t.Add(23);
            t.Add(78);

            Assert.AreEqual(78, t.Root.Right.Item);
        }

        [Test]
        public void MultipleAdds()
        {
            var t = new Tree<int>();

            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
        }

        [Test]
        public void DuplicateAdd()
        {
            var t = new Tree<int>();

            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);
            t.Add(20);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
        }

        [Test]
        public void FindInLeafNode()
        {
            var t = new Tree<int>();

            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            var actual = t.Find(8);

            Assert.AreEqual(t.Root.Left.Left.Left.Right, actual);
        }

        [Test]
        public void FindInMiddle()
        {
            var t = new Tree<int>();

            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            var actual = t.Find(10);

            Assert.AreEqual(t.Root.Left.Left, actual);
        }

        [Test]
        public void FindNonExistingKeyReturnsNull()
        {
            var t = new Tree<int>();

            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            var actual = t.Find(101);

            Assert.IsNull(actual);
        }

        [Test]
        public void DeleteRootWithNoChildrenShouldSetRootToNull()
        {
            var t = new Tree<int>();
            t.Add(22);

            t.Delete(22);

            Assert.IsNull(t.Root);
        }

        [Test]
        public void DeleteRootOnlyOneChildSetsChildAsRoot_Left()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(20);

            t.Delete(23);

            Assert.AreEqual(20, t.Root.Item);
            Assert.IsNull(t.Root.Left);
            Assert.IsNull(t.Root.Right);
        }

        [Test]
        public void DeleteRootOnlyOneChildSetsChildAsRoot_Right()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(28);

            t.Delete(23);

            Assert.AreEqual(28, t.Root.Item);
            Assert.IsNull(t.Root.Left);
            Assert.IsNull(t.Root.Right);
        }

        [Test]
        public void DeleteRootTwoChildren()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            t.Delete(23);

            Assert.AreEqual(20, t.Root.Item);
            Assert.AreEqual(10, t.Root.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Right.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
        }

        [Test]
        public void DeleteLeaf_LeftChild()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            t.Delete(8);

            Assert.AreEqual(23, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
            Assert.IsNull(t.Find(8));
        }

        [Test]
        public void DeleteLeaf_RightChild()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            t.Delete(33);

            Assert.AreEqual(23, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.IsNull(t.Find(33));
        }

        [Test]
        public void DeleteNodeWithSingleChild_LeftParentRightChild()
        {
            var t = new Tree<int>();
            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            t.Delete(7);

            Assert.AreEqual(23, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
            Assert.IsNull(t.Find(7));
        }

        [Test]
        public void DeleteNodeWithSingleChild_LeftParentLeftChild()
        {
            var t = new Tree<int>();
            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);

            t.Delete(24);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
            Assert.IsNull(t.Find(24));
        }

        [Test]
        public void DeleteNodeWithSingleChild_RightParentLeftChild()
        {
            var t = new Tree<int>();
            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);
            t.Add(27);

            t.Delete(33);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(27, t.Root.Right.Right.Item);
            Assert.IsNull(t.Find(33));
        }

        [Test]
        public void DeleteNodeWithSingleChild_RightParentRightChild()
        {
            var t = new Tree<int>();
            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);
            t.Add(35);

            t.Delete(33);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(35, t.Root.Right.Right.Item);
            Assert.IsNull(t.Find(33));
        }

        [Test]
        public void DeleteNodeWithTwoChildren()
        {
            var t = new Tree<int>();
            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);
            t.Add(35);

            t.Delete(25);

            Assert.AreEqual(22, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);

            Assert.AreEqual(24, t.Root.Right.Item);
            Assert.AreEqual(23, t.Root.Right.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
            Assert.AreEqual(35, t.Root.Right.Right.Right.Item);

            Assert.IsNull(t.Find(25));
        }

        [Test]
        public void InOrderTraversal()
        {
            var items = new List<int>();
            var t = new Tree<int>();
            t.Add(22);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);
            t.Add(23);
            t.Add(35);

            t.InOrderTraversal(i => items.Add(i));

            Assert.AreEqual(7, items[0]);
            Assert.AreEqual(8, items[1]);
            Assert.AreEqual(10, items[2]);
            Assert.AreEqual(20, items[3]);
            Assert.AreEqual(22, items[4]);
            Assert.AreEqual(23, items[5]);
            Assert.AreEqual(24, items[6]);
            Assert.AreEqual(25, items[7]);
            Assert.AreEqual(33, items[8]);
            Assert.AreEqual(35, items[9]);
        }

        [Test]
        public void NodeEquality()
        {
            var left = new Node<int>(27);
            var right = new Node<int>(28);

            var n = new Node<int>(1);
            n.Left = left;
            n.Right = right;

            var equal = new Node<int>(1);
            equal.Left = left;
            equal.Right = right;

            var notEqualItem = new Node<int>(33);
            notEqualItem.Left = left;
            notEqualItem.Right = right;

            var notEqualNodes = new Node<int>(1);
            notEqualNodes.Left = right;
            notEqualNodes.Right = left;

            Assert.IsTrue(n.Equals(equal));
            Assert.IsFalse(n.Equals(notEqualItem));
            Assert.IsFalse(n.Equals(notEqualNodes));
        }
    }
}
