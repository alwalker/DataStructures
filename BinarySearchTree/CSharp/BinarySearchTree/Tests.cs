using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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

            t.Add(23);
            t.Add(20);
            t.Add(25);
            t.Add(24);
            t.Add(33);
            t.Add(10);
            t.Add(7);
            t.Add(8);

            Assert.AreEqual(23, t.Root.Item);
            Assert.AreEqual(20, t.Root.Left.Item);
            Assert.AreEqual(10, t.Root.Left.Left.Item);
            Assert.AreEqual(7, t.Root.Left.Left.Left.Item);
            Assert.AreEqual(8, t.Root.Left.Left.Left.Right.Item);
            Assert.AreEqual(25, t.Root.Right.Item);
            Assert.AreEqual(24, t.Root.Right.Left.Item);
            Assert.AreEqual(33, t.Root.Right.Right.Item);
        }
    }
}
